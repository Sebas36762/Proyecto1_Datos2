#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;
//Inicializando Variables
int main()
{

    int client;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    char* ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);


    if (client < 0)
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }



    cout << "\n=> Se encontro partida..." << endl;



    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

//Creando conexion con el socket
    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Conectado con puerto:" << portNum << endl;

    cout << "=> Esperando Jugador" << endl;
    recv(client, buffer, bufsize, 0);
    cout << "=> Conectado";

    cout << "\n\n=> # para terminar la partida\n" << endl;



    do {
        cout << "Jugador2: ";
        do {
            cin >> buffer;
            send(client, buffer, bufsize, 0);
            if (*buffer == '#') {
                send(client, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != 42);

        cout << "Jugador1: ";
        do {
            recv(client, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }

        } while (*buffer != 42);
        cout << endl;

    } while (!isExit);



    cout << "\n=> Partida Terminada.\nGG\n";

    close(client);
    return 0;
}