#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
int main(int argc, char *argv[]) {
	int fd, fdw;
	char ch;
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("open failed:");
		printf("%d\n", errno);
		return errno;
	}
	fdw = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR);
	if(fdw == -1) {
		perror("open failed:");
		printf("%d\n", errno);
		return errno;
	}
	while(read(fd, &ch, 1))
		write(fdw, &ch, 1);
	return 0;
}
