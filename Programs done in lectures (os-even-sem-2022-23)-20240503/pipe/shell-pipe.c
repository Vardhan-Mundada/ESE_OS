#include <stdio.h>
#include <unistd.h> 
/* cat /etc/passwd | head -2 */
int main() {
	char string[128], buf[16];
	int pid;
	int pfd[2];
	//printf("%d %d\n", pfd[0], pfd[1]);
	while(1) {
		pipe(pfd);
		pid = fork(); // child is created, all FDs are inherited! 
		if(pid == 0) {
			close(0);
			dup(pfd[0]);
			close(pfd[1]);
			execl("/usr/bin/head", "/usr/bin/head", "-2", NULL);
		} else {
			pid = fork();
			if(pid == 0) {
				close(1);
				dup(pfd[1]);
				close(pfd[0]);
				execl("/usr/bin/cat", "/usr/bin/cat", "/etc/passwd", NULL);
			} else {
				close(pfd[0]);
				close(pfd[1]);
				exit(0);
			}
		}
	}
}

/* 


*/
