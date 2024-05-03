       #include <sys/types.h>
       #include <unistd.h>
       #include <sys/types.h>
       #include <unistd.h>
       #include <sys/types.h>
       #include <signal.h>
       #include <sys/types.h>
       #include <sys/wait.h>
	#include <stdio.h>

int main() {
	int pid, ppid;
	pid = fork();
	if(pid == 0) {
		sleep(2);
		ppid = getppid();
		kill(ppid, 9);
		printf("child after parent's termination\n");
	} else {
		printf("Parent\n");
		//getchar();
		printf("Parent after getchar\n");
		wait(NULL);
		printf("Parent after wait\n");
	}
	printf("Both parent and child should print this\n");
	return 0;
}
