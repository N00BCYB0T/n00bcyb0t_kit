/*
 * We accepted an incoming connection but closed it immediately. THis was not very productive. There
 * are lots of things that can be done after an incoming connection is established. Afterall the 
 * connection was established for the purpose of communication. So lets reply to the client.
 *
 * We can simply use the write() function to write something to the socket of the incoming connection and
 * the client should see it. Here is an example:
 *
 */
#include <stdio.h>
#include <string.h>	//strlen
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>	//write

int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	char *message;

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	//Bind
	if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0 )
	{
		puts("bind failed");
		return 1;
	}
	puts("bind one");

	//Listen
	listen(socket_desc, 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (new_socket<0)
	{
		perror("accept failed");
		return 1;
	}

	puts("COnnection accepted");

	//Reply to the client
	message = "Hello Client, I have received your connection. But I hae to go now, bye\n";
	write(new_socket, message, strlen(message));
	return 0;
}
	
/*
 * We can see that the connection is closed immediately adter that simply beacuse the server program
 * ends after accepting and sending reply. A server like www.google.com is always up to accept
 * incoming connections.
 *
 * It means that a server is supposed to be running all time. Afterall its a server meant to serve. So
 * we need to keep our server RUNNING non-stop. The simplest way to do ths is to put the accept() in a
 * loop so that it can receive incoming connections all the time.
 *
 */

