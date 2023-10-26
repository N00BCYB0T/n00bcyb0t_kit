// IPv4 AF_INET sockets:
struct sockaddr_in {
	short		sin_family; 	// e.g AF_INET, AF_INET6
	unsigned short	sin_port;   	// E.g htons(3490)
	struct in_addr	sin_addr;   	// see struct in_addr, below
	char		sin_zero[8];	// zero this if you want to
};

struct in_addr {
	unsigned long s_addr; 		// load with inet_pton()
};

struct sockaddr {
	unsigned short	sa_family;	// address family, AF_xxx
	char 		sa_data[14]; 	// 14 bytes of protocol address
};

// The sockaddr_in has a member called sin_addr of type in_addr which has a s_addr which is nothing but a long. It contains the IP address in long format.

// Function inet_addr is a very handy function to convert an IP address to a long format. This is how you do it:
	server.sin_addr.s_addr = inet_addr("200.160.2.3");


