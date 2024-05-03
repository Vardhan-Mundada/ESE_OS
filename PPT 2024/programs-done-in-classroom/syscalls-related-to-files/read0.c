#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	char ch;
	read(0, &ch, 1); // ch = getchar();
	write(1, &ch, 1); // putchar(ch);
	write(2, &ch, 1); // fprintf(stderr, "%c", ch); 
	return 0;
}
