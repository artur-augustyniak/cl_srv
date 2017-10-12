#include "GameController.h"
#include <stdio.h>
#include <ctime>
#include "NetSock.h"
#include "ConsDisplay.h"
#include "BasicSlotGame.h"
#include <windows.h>
using namespace std;

void usage() {
    printf("usage: endpoint <dhost> <dport>\n");
}

int main(int argc, char** argv) {

    if (argc != 3) {
        usage();
        return 1;
    }

    unsigned short port;
    if (sscanf(argv[2], "%hu", &port) != 1) {
        usage();
        return 2;
    }

    const char *host = argv[1];

    NetSock::InitNetworking();
    NetSock s;
    Sleep( 3000 );   // sleep three seconds
    if (!s.Connect(host, port)) {
        perror("socket error");
        fprintf(stderr, "Could not connect!\n");
        return 3;
    }
    
    ConsDisplay cd;
    BasicSlotGame bsg(cd, time(NULL), 2);
    GameController gc(bsg);
    
    for (;;) {

        if (!gc.HandleRequest(s)) {
            break;
        }

    }
    s.Disconnect();
    return 0;
}






