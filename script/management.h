#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define MAXLINE 10000
#define MAXSUBLINE 100

void server_on(int* lockerlen);
void basic_info(const int fd);
void terminate(const int clientFd);
void wrong(const int clientFd);
int selection(const int clientFd, const int lockerlen);
