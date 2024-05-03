#include <stdio.h>
#include <unistd.h> 
/* cat /etc/passwd | head -2 */
int main() {
	char string[128], buf[16];
	int pid;
	int pfd[2];
	pipe(pfd); // OS has created a buffer for pipe's data, and sent me 2 FDs , one for reading, one for writing.  pfd[0] is for reading, pfd[1] is for writing. 
	printf("%d %d\n", pfd[0], pfd[1]);
	pid = fork(); // child is created, all FDs are inherited! 
	if(pid == 0) {
		close(0);
		dup(pfd[0]);
		close(pfd[1]);
		execl("/usr/bin/head", "/usr/bin/head", "-2", NULL);
	} else {
		close(1);
		dup(pfd[1]);
		close(pfd[0]);
		execl("/usr/bin/cat", "/usr/bin/cat", "/etc/passwd", NULL);
	}
}

/* 


*/
