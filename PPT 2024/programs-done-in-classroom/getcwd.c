#include <stdio.h>
#include <unistd.h>
int main() {
	char str[128];
	getcwd(str, 128);
	printf("%s\n", str);
}
