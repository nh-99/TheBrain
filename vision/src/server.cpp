#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include "rapidjson/document.h"
#include "main.h"

using namespace std;

rapidjson::Document jsonData;
int sock;
int port;
int bytes_read;
socklen_t addr_len;
char recv_data[1024];
struct sockaddr_in server_addr , client_addr;

int main() {
    Main mainVt;
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero),8);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Bind");
        exit(1);
    }

    addr_len = sizeof(struct sockaddr);
    cout << "\nUDPServer Waiting for client on port 5000" << endl;

    while (1) {
        bytes_read = recvfrom(sock, recv_data, 1024, 0, (struct sockaddr *)&client_addr, &addr_len);
        recv_data[bytes_read] = '\0'; // recv_data is the data to parse
        jsonData.Parse(recv_data);
        string image = jsonData["image"].GetString();
        if(jsonData["command"].GetString() == "Autonomous") {
            thread t1(Main::run, image);
        }
    }
    return 0;
}
