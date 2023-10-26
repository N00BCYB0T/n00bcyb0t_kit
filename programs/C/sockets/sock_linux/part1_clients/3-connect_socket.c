#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>  // inet_addr - The inet_addr() function shall convert the string pointed to by cp, in the standard IPv4
			// dotted decimal notation, to an integer value suitable for use as an Internet address.

int main(int argc, char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
		printf("COuld not create socket");

	server.sin_addr.s_addr = inet_addr("200.160.2.3");
	server.sin_family = AF_INET;
	server.sin_port = htons(43);

	//Connect to remote server
	if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("Connect error");
		return 1;
	}

	puts("Connected");
	return 0;
}

