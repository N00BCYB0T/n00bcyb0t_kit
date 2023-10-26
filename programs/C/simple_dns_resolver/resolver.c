#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: ./resolver <url>\n");
		return 0;
	} else { 
		struct hostent *target = gethostbyname(argv[1]);
		
		if (target == NULL) {
			printf("[Error]\n");
		} else {
			printf("IP: %s\n", inet_ntoa(*((struct in_addr *)target->h_addr)));
		}
	}
	return 0;
}
