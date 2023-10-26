/*
 * To handle every connection we need a separate handling code to run along with the main
 * server accepting connections.
 * One way to achieve this is using threads. THe main server program accepts a connection
 * and creates a new thread to handle communication for the connection, and then the server
 * goes back to accept more connections.
 *
 * On Linux threading can be done with the pthread (posix threads) library. It would be good to
 * read some small tutorial about it if you dont know anything about it. However the usage is not very
 * complicated.
 *
 * We shall now use threads to create handlers for each connection the server accepts. Lets do it pal.
 *
 */
#include <stdio.h>
#include <string.h>	//strlen
#include <stdlib.h>	//strlen
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>	//write
#include <pthread.h> 	// for threading, link with lpthread

void *connection_handler(void *);

int main(int agrc, char *argv[])
{
	int socket_desc, new_socket, c, *new_sock;
	struct sockaddr_in server, client;
	char *message;

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
		printf("Could not create socket");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	//Bind
	if (bind(socket_desc,(struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("bind failed");
		return 1;
	}
	puts("bind some");

	//Listen
	listen(socket_desc, 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	while (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))
	{
		puts("Connection accepted");

		//Reply to the client
		message = "Hello Client, I have received your connection. And now I will assign a handler for you\n";
		write(new_socket, message, strlen(message));

		pthread_t sniffer_thread;
		new_sock = malloc(1);
		*new_sock = new_socket;

		if (pthread_create(&sniffer_thread, NULL, connection_handler, (void*) new_sock) < 0)
		{
			perror("could not create thread");
			return 1;
		}

		//Now join the thread, so that we dont terminate before the thread
		//pthread_join( sniffer_thread, NULL);
		puts("Handler assigned");
	}
	if (new_socket<0)
	{
		perror("accept failed");
		return 1;
	}
	return 0;
}

/*
 * THis will handle connection for each client
 */
/*
void *connection_handler(void *socket_desc)
{
	//Get the socket descriptor
	int sock = *(int*)socket_desc;

	char *message;

	//Send some messages to the client
	message = "Greeting! I am your connection handler\n";
	write(sock, message, strlen(message));

	//Free the socket pointer
	free(socket_desc);

	return 0;
}
*/
/*
 * This one looks good, but the communication handler is also quite dumb. After the greeting it
 * terminates. It should stay alive and keep communicating with the client.
 *
 * One way to do this is by making the connection handler wait for some message from a client as long
 * as the client is connected. If the client disconnects, the connection handler ends.
 *
 * So the connection handler can be rewritten like this:
 */
/*
 * THis will handle connection for each client
 *
 */
void *connection_handler(void *socket_desc)
{
	//Get the socket descriptor
	int sock = *(int*)socket_desc;
	int read_size;
	char *message, client_message[2000];

	//Send some messages to the client
	message = "Greetings! I am your connection handler\n";
	write(sock, message, strlen(message));

	message = "Now type something and I shall repeat what you type \n";
	write(sock, message, strlen(message));

	//Receive a message from client
	while ((read_size = recv(sock, client_message, 2000, 0)) > 0)
	{
		//Send the message back to client
		write(sock, client_message, strlen(client_message));
	}
	if(read_size == 0)
	{
		puts("Client disconnected");
		fflush(stdout);
	}
	else if(read_size == -1)
	{
		perror("recv failed");
	}

	//Free the socket pointer
	free(socket_desc);

	return 0;
}

