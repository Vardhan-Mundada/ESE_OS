#include <stdio.h>
int f(int a) {
	return a + 5;
}
int g(int b) {
	return b + 10;
}
int main() {
	int (*func) (int);
	int choice;
	scanf("%d", &choice);
	if(choice == 1)
		func = f;
	else if(choice == 2)
		func = g;
	printf("%d\n", func(10));
	return 0;
}
