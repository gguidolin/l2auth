#include <assert.h>
#include <string.h>
#include <log/log.h>
#include <core/l2_server.h>
#include <core/l2_client.h>
#include <core/l2_raw_packet.h>
#include <game/entity/location.h>
#include <game/action/character_info/response.h>
#include <game/service/character/movement.h>
#include <game/service/crypt/packet/encrypt.h>
#include "response.h"
#include "handler.h"

void game_action_validate_position_handler
(
        struct L2Server* server,
        struct L2Client* client,
        l2_raw_packet* request,
        unsigned char* encrypt_key
)
{
        assert(server);
        assert(client);
        assert(request);
        assert(encrypt_key);

        struct GameEntityLocation location;
        int heading = 0;
        l2_packet* response;

        memcpy(&location.x, request + 3, sizeof(location.x));
        memcpy(&location.y, request + 3 + sizeof(location.x), sizeof(location.y));
        memcpy(&location.z, request + 3 + sizeof(location.x) + sizeof(location.y), sizeof(location.z));
        memcpy(&heading, request + 3 + sizeof(location.x) + sizeof(location.y) + sizeof(location.z), sizeof(heading));

        log_info(
                "Validating position - x: %d, y: %d, z: %d",
                location.x,
                location.y,
                location.z
        );

        game_service_character_movement_validate_and_update(
                l2_client_get_char(client),
                &location
        );

        response = game_action_validate_position_response(
                client,
                l2_client_get_char(client)->current_location,
                heading
        );
        l2_server_broadcast_packet_to_clients(server, response);

        // (franco.montenegro) Refactor, validate shouldn't
        // send this response, there should be a handler
        // managing this response
        response = game_action_character_info_response(client);
        l2_server_broadcast_packet(server, client, response);
}