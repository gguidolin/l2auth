#include "response_fail.h"

#include <core/l2_packet.h>
#include <game/client.h>

l2_packet* game_request_action_fail_response(struct GameClient* client)
{
        l2_packet_type type = 0x25;
        unsigned char content[] = { 0, 0, 0, 0 };
        return game_client_create_packet(client, type, content, sizeof(content));
}
