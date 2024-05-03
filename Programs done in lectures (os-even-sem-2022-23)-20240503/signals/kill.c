#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	printf("%d %d\n", SIGSTOP, SIGCONT);	
	printf("%d\n", atoi(argv[2]));
	return kill(atoi(argv[1]), atoi(argv[2]));
}
