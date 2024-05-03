#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main() {
	printf("Hi\n");
	execl("/usr/bin/ls", "/usr/bin/ls", "--color", "-F", NULL);	
	printf("Hello\n");
	return 0;
}

