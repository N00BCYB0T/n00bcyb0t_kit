/* So a live server will be alive for all time. Lets code this up: */
#include <stdio.h>
#include <string.h>	//strlen
#include <sys/socket.h>
#include <arpa/inet.h>  //inet_addr
#include <unistd.h>	//write

int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	char *message;

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
		printf("Could no create socket");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);
	
	//Bind
	if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("bind failed");
		return 1;
	}
	puts("bind done");

	//Listen
	listen(socket_desc, 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	while (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))
	{
		puts("Connection accepted");

		//Reply to the client
		message = "Hello CLient, I have received your connection. But I have to go now, bye\n";
		write(new_socket, message, strlen(message));
	}
	if (new_socket<0)
	{
		perror("accept failed");
		return 1;
	}

	return 0;
}
/*
 * We havent done a lot there. Just the accept was put in a loop.
 *
 * So now the server is running nonstop and the telnet terminals are also connected nonstop. Now close
 * the server program.
 * All telnet terminals would show "COnnection closed by foreign host."
 * Good so far. But still there is not effective communication between the server and the client.
 *
 * The server program accepts connections in a loop and just send them a reply, after that is does
 * nothing with them. Also it is not able to handle more than 1 connection at a time. So now its time to
 * handle the connections, and handle multiple connections together.
 */
