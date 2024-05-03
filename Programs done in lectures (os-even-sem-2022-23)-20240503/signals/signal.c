#include <stdio.h>
#include <signal.h>
int *p = 1234, i = 1234;
void seghandler(int signo) {
	printf("Seg fault ocurred \n");
	exit(1);
	return;
}
void inthandler(int signo) {
	printf("INT signal received\n");
	return;
}
int main() {
	signal(SIGINT, inthandler);
	getchar(); // press ctrl-C during this 
	i = 10;
	signal(SIGSEGV, seghandler); 
	*p = 100; 
	return 0;
}
