#ifndef L2AUTH_GAME_ACTION_VALIDATE_POSITION_HANDLER_H
#define L2AUTH_GAME_ACTION_VALIDATE_POSITION_HANDLER_H

#include <core/l2_server.h>
#include <core/l2_client.h>
#include <core/l2_raw_packet.h>

void game_action_validate_position_handler
(
        struct L2Server* server,
        struct L2Client* client,
        l2_raw_packet* request,
        unsigned char* encrypt_key
);

#endif