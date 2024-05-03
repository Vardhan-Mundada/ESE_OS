#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main() {
	printf("Hi\n");
	fork();
	printf("Hello\n");
	fork();
	printf("Bye\n");
	return 0;
}

