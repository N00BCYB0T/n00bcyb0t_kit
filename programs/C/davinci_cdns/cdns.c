#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	int i = 1;

	char *target;
	target = argv[1];	
	struct hostent *host;
	
	char *result;
	char txt[50];
	FILE *mouse;
	mouse = fopen(argv[2], "r");

	if(argc < 2) {
		printf("********************************************************\n");
		printf("*          cccc cccc     cccc   ccc     ccccc          *\n");
		printf("*        ccc    cccccc   ccccc  ccc  ccccccc           *\n");
		printf("*	ccc	cc  ccc	 cccccc ccc  cccc              *\n");
		printf("*	ccc	cc  ccc  cccccccccc   ccssss           *\n");
		printf("*	ccc	cccccc   ccccc  ccc    cccccc          *\n");
		printf("*	 ccccc	cccc     ccccc  ccc  ccccccc           *\n");
		printf("*                                                      *\n");
		printf("*                                         by: DaVin$I  *\n");
		printf("*   USAGE: ./cdns <target/url> <wordlist>              *\n");
		printf("*                                                      *\n");
		printf("********************************************************\n");
		return 0;
	}
	printf("********************************************************\n");
	printf("*          cccc cccc     cccc   ccc     ccccc          *\n");
	printf("*        ccc    cccccc   ccccc  ccc  ccccccc           *\n");
	printf("*	ccc	cc  ccc	 cccccc ccc  cccc              *\n");
	printf("*	ccc	cc  ccc  cccccccccc   ccssss           *\n");
	printf("*	ccc	cccccc   ccccc  ccc    cccccc          *\n");
	printf("*	 ccccc	cccc     ccccc  ccc  ccccccc           *\n");
	printf("*                                                      *\n");
	printf("*                                         by: DaVin$I  *\n");
	printf("*                                                      *\n");
	printf("********************************************************\n");

	while (fscanf(mouse, "%s", &txt) != EOF) {
		result = (char *) strcat(txt,target);
		host = gethostbyname(result);
	
		if (host == NULL){
//			printf("Attempt %d# - %s\n", i++, host);
			continue;
		}
		printf("HOST FOUND: %s \t==> IP: %s\n", result, inet_ntoa(*((struct in_addr *)host->h_addr)));
		++i;
	}
return 0;
}



