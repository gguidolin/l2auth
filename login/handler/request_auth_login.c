#include <assert.h>
#include <log/log.h>
#include <core/l2_packet.h>
#include <login/server.h>
#include <login/client.h>
#include <login/helper.h>
#include <login/packet/ok.h>
#include <core/session_key.h>
#include <login/handler/request_auth_login.h>

void login_handler_request_auth_login
(
        struct LoginServer* server,
        struct LoginClient* client,
        l2_packet* packet
)
{
        assert(server);
        assert(client);
        assert(packet);

        unsigned char username[14];
        unsigned char password[16];

        login_helper_username_from_packet(packet, username);
        login_helper_password_from_packet(packet, password);

        log_info("Username %s", username);
        log_info("Password %s", password);

        login_client_encrypt_and_send_packet(
                client,
                login_packet_ok(client)
        );
}
