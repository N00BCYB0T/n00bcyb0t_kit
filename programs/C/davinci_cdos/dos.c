#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	int my_sockfd;
	int connection;

	char * destination;
	destination = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in target;

	while(1) {
		my_sockfd = socket(AF_INET, SOCK_STREAM, 0);

		target.sin_family = AF_INET;
		target.sin_port = htons((u_short)port);
		target.sin_addr.s_addr = inet_addr(destination);

		connection = connect(my_sockfd, (struct sockaddr *)&target, sizeof target);

		if (connection == 0) 
			printf("Packet sent\n");
		else
			printf("Error\n");
	}
	return 0;
}
