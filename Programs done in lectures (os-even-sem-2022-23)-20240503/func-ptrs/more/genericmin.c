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
#include <string.h>
struct data {
	int age;
	char name[16];
}sa[16];
int icmp(void *p, int x, int y) {
	int *a = p;
	if(a[x] < a[y]) return -1;
	if(a[x] == a[y]) return 0;
	return 1;
} 
int stcmp(void *p, int x, int y) {
	struct data *a = p;	
	return strcmp(a[x].name, a[y].name);
}
int stagecmp(void *p, int x, int y){
	struct data *a = p;
	if(a[x].age < a[y].age) return -1;
	if(a[x].age == a[y].age) return 0;
	return 1;
}
int genmin(void *a, int n, int (*cmp)(void *p, int x, int y)) {
	int minpos = 0, i;
	for(i = 1; i < n; i++)
		if(cmp(a, i, minpos) == -1)
			minpos = i;
	return minpos;
}
int main() {
	int a[16];
	int i = 0;
	/*while(scanf("%d", &a[i]) != EOF)
		i++;
	printf("%d\n", genmin(a, i, icmp));*/

	i = 0;
	while(scanf("%d%s", &(sa[i].age), sa[i].name) != EOF)
		i++;
	printf("%d\n", genmin(sa, i, stcmp));
	printf("%d\n", genmin(sa, i, stagecmp));
	return 0;	
}
