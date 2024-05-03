#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
int main(int argc, char *argv[]) {
	int fd;
	char ch;
	close(1);
	fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	assert(fd == 1);
	assert(fd != -1);
	printf("hello\n");
		
	close(fd);
	return 0;
}
