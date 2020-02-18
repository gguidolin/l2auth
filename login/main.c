#include <stdlib.h>
#include <time.h>
#include <socket_strategy/socket_strategy_linux.c>
#include <core/l2_socket.c>
#include <core/l2_server.c>

int main()
{
        struct L2SocketStrategy* socket_strategy = calloc(1, sizeof(struct L2SocketStrategy));
        struct L2Socket* server = calloc(1, sizeof(struct L2Socket));

        srand((unsigned int) time(NULL));

        socket_strategy_linux(socket_strategy);
        l2_server_create(server, socket_strategy, 2106);

        //while (1) {
                l2_server_wait_and_accept_connections(server);
        //}

        l2_client_close(server); 

        return 0;
}