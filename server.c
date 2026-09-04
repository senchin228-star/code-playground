#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    //socket
    int server_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sock < 0){
        perror("Socket create ERR");
        return 1;
    }
    //server

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_port = htons(12345);
    server_addr.sin_family = AF_INET;

    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("bind ERR");
        return 1;
    }

    printf("waiting message on port: 12345\n");

    char buffer[1024];
    // client
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int bytes_received = recvfrom(server_sock, buffer, sizeof(buffer) - 1, 0,
                                  (struct sockaddr *)&client_addr, &client_addr_len);

    if (bytes_received < 0) {
        perror("receive err");
        return 1;
    }

    buffer[bytes_received] = '\0';

    char client_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

    int client_port = ntohs(client_addr.sin_port);

    printf("IP: %s, Port: %d\n", client_ip, client_port);
    printf("Message: %s\n", buffer);

    close(server_sock);
    return 0;
}
