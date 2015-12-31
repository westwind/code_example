#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	struct addrinfo hints;
	struct addrinfo *servinfo, *p;
	char ipstr[INET6_ADDRSTRLEN];

	memset(&hints, 0 ,sizeof (hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if (getaddrinfo(argv[1], NULL, &hints, &servinfo) != 0) {
		printf("getaddrinfo error\n");
		exit(1);
	}

	printf("IP address for %s:\n\n",argv[1]);
	for(p = servinfo; p != NULL;p = p->ai_next) {
		void *addr;
		char *ipver;

		if(p->ai_family == AF_INET) { //IPv4
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		} else { //IPv6
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}

		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
		printf("%s: %s\n",ipver, ipstr);
	}

	freeaddrinfo(servinfo);
}
