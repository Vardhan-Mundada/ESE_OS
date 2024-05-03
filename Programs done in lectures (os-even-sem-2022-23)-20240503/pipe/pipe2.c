#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
int main() {
	char cmd[128], string[16];
	int cpid, pfd[2];
	pipe(pfd);
	cpid = fork();
	if(cpid == 0) {
		close(pfd[0]);
		write(pfd[1], "hello\n", 6);
		exit(0);
	} else {
		close(pfd[1]);
		read(pfd[0], string, 6);
		string[6] = '\0';
		printf("Parent read %s\n", string);
	}
	return 0;
}

