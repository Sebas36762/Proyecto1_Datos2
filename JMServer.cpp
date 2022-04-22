#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
//Iniciando variables a utilizar
int main() {

    int client, server;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;
    socklen_t size;


    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) {
        cout << "\nError" << endl;
        exit(1);
    }


    cout << "\n=> Se creo partida" << endl;


    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

//Creando conexion con el socket
    if ((bind(client, (struct sockaddr *) &server_addr, sizeof(server_addr))) < 0) {
        cout << "=> Error " << endl;
        return -1;
    }


    size = sizeof(server_addr);
    cout << "=> Buscando Jugadores" << endl;


    listen(client, 1);


    int clientCount = 1;
    server = accept(client, (struct sockaddr *) &server_addr, &size);


    if (server < 0)
        cout << "=> Error" << endl;

    while (server > 0) {
        strcpy(buffer, "=> Partida creada\n");
        send(server, buffer, bufsize, 0);
        cout << "Conectado" << clientCount << "Iniciando" << endl;
        cout << "\n=> # para terminar partida\n" << endl;


        cout << "Jugador2: ";
        do {
            recv(server, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != '*');

        do {
            cout << "\nJugador1: ";
            do {
                cin >> buffer;
                send(server, buffer, bufsize, 0);
                if (*buffer == '#') {
                    send(server, buffer, bufsize, 0);
                    *buffer = '*';
                    isExit = true;
                }
            } while (*buffer != '*');

            cout << "Jugador2: ";
            do {
                recv(server, buffer, bufsize, 0);
                cout << buffer << " ";
                if (*buffer == '#') {
                    *buffer == '*';
                    isExit = true;
                }
            } while (*buffer != '*');
        } while (!isExit);


        cout << "\n\n=> Partida Terminada" << inet_ntoa(server_addr.sin_addr);
        close(server);
        cout << "\nGG" << endl;
        isExit = false;
        exit(1);
    }

    close(client);
    return 0;
}