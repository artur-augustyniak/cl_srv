#include <stdio.h>
#include <stdlib.h>
#include "NetSock.h"

using namespace std;

void usage() {
    printf("usage: console <endpoint_path> <bind_ip> <port>\n"
    );
}

void protocol() {
    printf( "Commands followed by return:\n" \
            "R\t- game round\n" \
            "M[txt]\t- send msg.\n" \
            "T\t- terminate / end game\n"
    );
}

int main( int argc, char *argv[] )
{
    if (argc != 4) {
        usage();
        return 1;
    }

    const char *endpoint_path = argv[1];
    const char *bind_ip = argv[2];

    unsigned short port;
    if (sscanf(argv[3], "%hu", &port) != 1) {
        usage();
        return 2;
    }

    NetSock::InitNetworking();
    NetSock s;

    if (!s.Listen(port, bind_ip)) {
        perror("socket error");
        return 3;
    }
    char buff[1024];

    snprintf(buff, 1024, "start %s %s %d",endpoint_path, bind_ip, port);
    puts(buff);

    system(buff);

    NetSock* endpoint_conn =  s.Accept();
    printf("Start typing:\n");
    protocol();
    char out_char, in_char = 0;
    for(;;){
        out_char = getchar();
        in_char = 0;
        if(-1 == endpoint_conn->Write(&out_char, 1) || 'T' == out_char ){
            endpoint_conn->Disconnect();
            break;
        }
        if('R' == out_char){
            while ('\n' != in_char) {
                if (endpoint_conn->Read(&in_char, 1) != 1) {
                    puts("disconnected");
                    break;
                }
                printf("%c", in_char);
            }
        }
    }
    s.Disconnect();
    return 0;
}
