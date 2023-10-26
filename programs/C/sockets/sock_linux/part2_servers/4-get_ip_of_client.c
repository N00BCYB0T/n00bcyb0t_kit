/*
 * You can get the IP address of client and the port of connection by using the sockaddr_in structure
 * passed to accept() function. It is very simple:
 *
 */
char *client_ip = inet_ntoa(client.sin_addr);
int client_port = ntohs(client.sin_port);

