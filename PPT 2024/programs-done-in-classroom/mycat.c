#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int fd;
	char ch;
	scanf("%d", &ch);
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("mycat: ");
		exit(errno);
	}
	while(read(fd, &ch, 1))
		putchar(ch);	
	return 0;
}
