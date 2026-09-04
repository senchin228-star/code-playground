#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

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

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Неверный IP адрес");
        return 1;
    }

    char *message = "HELLO WORLD!";

    printf("Send message 127.0.0.1:12345...\n");

    int bytes_sent = sendto(sock, message, strlen(message), 0,
                            (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (bytes_sent < 0) {
        perror("SEND ERR");
    } else {
        printf("Send %d bytes!\n", bytes_sent);
    }

    close(sock);
    return 0;
}

