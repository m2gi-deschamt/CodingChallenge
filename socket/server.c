#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/un.h>

int main(int argc, char const* argv[]) {

    int sockfd;
    if ((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_un s1;
    memset(&s1, 0, sizeof(s1));
    s1.sun_family = AF_UNIX;
    strncpy(s1.sun_path, "/tmp/echo.sock", sizeof(s1.sun_path) - 1);
    unlink(s1.sun_path);

    if (bind(sockfd, (struct sockaddr *)&s1, sizeof(s1)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }


    if(listen(sockfd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }


    while (1) {
        socklen_t sockSize = sizeof(s1);
        int client_fd = accept(sockfd, (struct sockaddr *)&s1, &sockSize);
        if(client_fd < 0) {
            perror("Accept failed");
            continue;
        }

        char buffer[100];
        int n;
        while ((n = read(client_fd, buffer, sizeof(buffer)-1)) > 0) {
            buffer[n] = '\0';
            printf("Received: %s\n", buffer);

            // renvoyer au client
            write(client_fd, buffer, n);
        }
        close(client_fd);
    }
    
}

