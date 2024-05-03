#include <stdio.h>
#include <math.h>
#define MAX 30
int f(int, int);
int main() {
	int i, j, k;
	scanf("%d%d", &i, &j);
	k = f(i, j) + MAX + sqrt(i);
	printf("%d\n", k);
	return 0;
}
