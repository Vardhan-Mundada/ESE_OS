#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd, fd2;
	char str[1600];	
	int pfd[2];
	
	pipe(pfd);
	/*pfd[0] - read file descriptor	
	pfd[1] - write file descriptor	 */
	write(pfd[1], "hello\n", 6);
	read(pfd[0], str, 6);
	str[6] = '\0';
	printf("%s\n", str);
}
