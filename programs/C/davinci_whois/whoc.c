/*
 * Este programa faz a comunicação com o whois
 * e a partir dele faz a query
 * ex: ./whoc <ip/domínio do whois a ser utilizado> <port/dft:43> <query>
 */

#include <stdio.h>
#include <string.h>	//strlen
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <stdlib.h>	//atoi

int main(int argc, char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message, server_reply[4096];
	int port = atoi(argv[2]);

	if(argc < 2) {
		printf("********************************************************\n");
		printf("*      ccccc     cc cccc  cccc   cccc*   cccccc        *\n");
		printf("*      ccccc ccc cc cccc  cccc  cc  ccc cccccc         *\n");
		printf("*      ccccc ccc cc cccccccccc cc   ccc ccc            *\n");
		printf("*      cccccccccccc cccccccccc cc   ccc ccc            *\n");
		printf("*      ccccccccccc  cccc  cccc cc   ccc cccccc         *\n");
		printf("*      cccc   cc    cccc  cccc  ccccc    cccccc        *\n");
		printf("*                                                      *\n");
		printf("*                                         by: DaVin$I  *\n");
		printf("*   USAGE: ./whoc <whois server> <port>                *\n");
		printf("*                                                      *\n");
		printf("********************************************************\n");
		return 0;
	}
	printf("********************************************************\n");
	printf("*      ccccc     cc cccc  cccc   cccc*   cccccc        *\n");
	printf("*      ccccc ccc cc cccc  cccc  cc  ccc cccccc         *\n");
	printf("*      ccccc ccc cc cccccccccc cc   ccc ccc            *\n");
	printf("*      cccccccccccc cccccccccc cc   ccc ccc            *\n");
	printf("*      ccccccccccc  cccc  cccc cc   ccc cccccc         *\n");
	printf("*      cccc   cc    cccc  cccc  ccccc    cccccc        *\n");
	printf("*                                                      *\n");
	printf("*                                         by: DaVin$I  *\n");
	printf("*                                                      *\n");
	printf("********************************************************\n");
	
	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
		printf("Could not create socket");
	
	server.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	//Connect to remote server
	if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected\n");

	//Send some data
	message = strcat(argv[3],"\r\n");
	if (send(socket_desc, message, strlen(message), 0) < 0)
	{
		puts("Send failed");
		return -1;
	}
	puts("Data Send\n");

	//Receive a reply from the server
	if (recv(socket_desc, server_reply, 4096, 0) < 0)
		puts("recv failed");
	
	puts("Reply received\n");
	puts(server_reply);

	return 0;
}
