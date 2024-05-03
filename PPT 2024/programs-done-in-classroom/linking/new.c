#include <stdio.h>
#include <math.h>
int g(int);
#define ADD(a, b)	(a + b)
int f(int m, int n) {
	return ADD(m, n) + 5 + g(10);
}
#define MAX 30
//int f(int, int);
int main() {
	int i, j, k;
	scanf("%d%d", &i, &j);
	k = f(i, j) + MAX ;//+ sqrt(i);
	printf("%d\n", k);
	return 0;
}
