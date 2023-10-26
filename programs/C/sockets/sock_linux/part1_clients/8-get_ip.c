/* Description of data base entry for a single host. 
 *
 * 	struct hostent
 * 	{
 * 		char *h_name;		// Official name of host.
 * 		char **h_aliases;	// Alias list.
 * 		int h_addrtype;		// Host address type.
 * 		int h_length;		// Length of address.
 * 		char **h_addr_list;	// List of addresses from name server.
 * 	};
 *
 * The h_addr_list has the IP addresses. So now lets have some come to use them.
 */

#include <stdio.h>	// printf
#include <string.h>	// strcpy
#include <sys/socket.h>
#include <netdb.h>	// hostent
#include <arpa/inet.h>	// inet_ntoa

int main(int argc, char *argv[])
{
	char *hostname = argv[1];
	char ip[100];
	struct hostent *he;
	struct in_addr **addr_list;
	int i;

	if ((he = gethostbyname(hostname)) == NULL)
	{
		//gethostbyname failed
		herror("gethostbyname");
		return 1;
	}

	//Cast the h_addr_list to in_addr, since h_addr-list also has the 
	//ip address in long form format only
	addr_list = (struct in_addr **) he->h_addr_list;

	for (i=0; addr_list[i] != NULL; i++)
	{
		// Return the first one;
		strcpy(ip, inet_ntoa(*addr_list[i]));
	}

	printf("%s resolved to: %s", hostname, ip);
	return 0;
}

/*
 * Function inet_ntoa() will convert an IP address in long format to dotted format. This is just the opposite of inet_addr().
 *
 * So far we have see some important structures that are used. Lets revise them:
 *
 * 	1. sockaddr_in - COnnection information.USed by connect, send, recv etc.
 * 	2. in_addr - IP address in long format.
 * 	3. sockaddr
 * 	4. hostent - The ip addresses of a hostname. Used by gethostbyname.
 *
 * 	In the next part we shall look into creating servers using socket. Servers are the opposite of clients,
 * 	that instead.of connecting out to others, they wait for incoming connections.
 */
