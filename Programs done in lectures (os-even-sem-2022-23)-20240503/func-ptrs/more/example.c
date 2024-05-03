/*  Function pointers - are pointers to functions.
 *  It is a variable - stores the address of a "function code" 
 *  So you can say ptr = func-name;
 *  Func-name is address of function
 *  p() on a function pointer, will call the function it is
 *  pointing to.
 * 
 *
 */
#include <stdio.h>
int min(int *a, int n) {
	int minpos = 0, i;
	for(i = 1; i < n; i++)
		if(a[i] < a[minpos]) 
			minpos = i;
	return minpos;
}
int f(int a) {
	return a + 5;
}
int g(int a) {
	return a + 10;
}
void try(int (*q)(int), int a) {
	printf("%d\n", q(a));
}
int main() {
	int (*p)(int a);
	p = f;
	printf("%d\n", p(10));
	try(p, 10);
	p = g;
	printf("%d\n", p(10));
	return 0;	
}
