#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main() {
	int pid;
	printf("Hi\n");
	pid = fork();
	if(pid == 0) {
		printf("in child pid  %d\n", getpid());
	} else {
		printf("in parent,child pid = %d, mypid =  %d\n", pid, getpid());
	}
	sleep(10);
	return 0;
}

