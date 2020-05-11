#include <log/log.h>
#include <core/l2_server.h>
#include <game/action/hot_code_reload_entry_point/handler.h>
#include <game/server.h>

void game_server_start_or_die(unsigned short port, size_t max_players)
{
        struct L2Server* server = l2_server_create(max_players);

        log_info("Starting gameserver");

        if (server == NULL) {
                log_fatal("Not able to allocate memory for gameserver");
                exit(1);
        }

        l2_server_start(server, port, game_action_hot_code_reload_entry_point_handler);
}
