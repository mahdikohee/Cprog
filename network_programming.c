//A simple c code example to get all networking devices with their lists 
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct ifaddrs *addrs;
    if (getifaddrs(&addrs) == -1) {
        perror("getifaddrs");
        return 1;
    }

    for (struct ifaddrs *addr = addrs; addr != NULL; addr = addr->ifa_next) {
        if (addr->ifa_addr == NULL) {
            continue;
        }

        int family = addr->ifa_addr->sa_family;
        if (family != AF_INET && family != AF_INET6) {
            continue;
        }

        char ip[NI_MAXHOST];
        int size;

        if (family == AF_INET) {
            size = sizeof(struct sockaddr_in);
        } else {
            size = sizeof(struct sockaddr_in6);
        }

        int ret = getnameinfo(addr->ifa_addr, size,
                              ip, sizeof(ip),
                              NULL, 0,
                              NI_NUMERICHOST);

        if (ret != 0) {
            fprintf(stderr, "getnameinfo failed: %s\n", gai_strerror(ret));
            continue;
        }

        printf("%s\t", addr->ifa_name);

        if (family == AF_INET) {
            printf("IPv4\t");
        } else {
            printf("IPv6\t");
        }

        printf("%s\n", ip);
    }

    freeifaddrs(addrs);
    return 0;
}
