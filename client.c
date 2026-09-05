#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int send_message(int sock ,const char* message, size_t message_len, struct sockaddr_in server_addr)
{

    printf("Send message 127.0.0.1:12345...\n");

    int bytes_sent = sendto(sock, message, message_len, 0,
                            (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (bytes_sent < 0) {
        perror("SEND ERR");
        return 1;
    }else {
        printf("Send %d bytes!\n", bytes_sent);
        return 0;
    }
}

int main() {
    // Create Socket. 
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket create ERR");
        return 1;
    }

    // server struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr)); // clear 
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_port = htons(12345); // PORT
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) { //addres
        perror("Неверный IP адрес");
        return 1;
    }

    while(1){
        printf("Enter a message\n");
        char mes[1024];
        if (fgets(mes, sizeof(mes), stdin) != NULL){
            mes[strcspn(mes, "\n")] = '\0';
            size_t msg_len = strlen(mes);
            send_message(sock,mes, msg_len, server_addr);
        }else continue;
    }
    close(sock);
    return 0;
}

