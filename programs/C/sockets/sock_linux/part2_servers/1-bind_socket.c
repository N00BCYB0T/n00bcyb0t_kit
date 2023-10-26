/*
 * The bind() function can be used to bind a coket to particular "address and port" combination.
 * It needs a sockaddr_in structure similar to connect function.
 *
 */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;

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
		return -1;
	}
	puts("bind done");
	return 0;
}

/*
 * Now that bind is done, its time to make the socket listen to connections. We bind a socket to a
 * particular IP address and a certain port number. By doing this we ensure that all incoming data which
 * is directed towards this port number is received by this application.
 *
 * This makes it obvious that you cannot have 2 sockets bound to the same port.
 *
 */
