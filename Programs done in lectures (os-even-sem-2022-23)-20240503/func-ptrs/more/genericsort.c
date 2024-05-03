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
#include <stdlib.h>
struct data {
	int age;
	char name[16];
}sa[16];
int icmp(const void *p, const void *q) {
	const int *a = p;
	const int *b = q;
	if(*a < *b) return -1;
	if(*a == *b) return 0;
	return 1;
} 
int stcmp(const void *p, const void *q) {
	const struct data *a = p;	
	const struct data *b = q;	
	return strcmp(a->name, b->name);
}
int stagecmp(const void *p, const void *q){
	const struct data *a = p;
	const struct data *b = q;
	if(a->age < b->age) return -1;
	if(a->age == b->age) return 0;
	return 1;
}
void swap(int *a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;	
}
void bubblesort(int *a, int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n - i - 1; j++) {
			if(a[j + 1] < a [j])
				swap(a, j, j+1);
		}
	}
}
void bsort(void *base, size_t nmemb, size_t size,
	int (*compare) (const void *a, const void *b)) {
	int i, j;
	void *a, *b;
	void *temp  = malloc(size);
	for(i = 0; i < nmemb; i++) {
		for(j = 0; j < nmemb -i - 1; j++)  {
			a = (base + size * j);
			b = (base  + size * (j + 1));
			if(compare(b, a) == -1) {
				memcpy(temp, a, size);
				memcpy(a, b, size);
				memcpy(b, temp, size);
			}
		}
	}
} 
int main() {
	int a[16];
	int i = 0, n;
	/*while(scanf("%d", &a[i]) != EOF)
		i++;
	n = i;
	bsort(a, n, sizeof(int), icmp);	
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n"); */
	i = 0;
	while(scanf("%d%s", &(sa[i].age), sa[i].name) != EOF)
		i++;
	n = i;
	bsort(sa, n, sizeof(sa[i]), stcmp);
	for(i = 0; i < n; i++)
		printf("%s %d\n", sa[i].name, sa[i].age);
	printf("---------\n");
	/* */	
	bsort(sa, n, sizeof(sa[i]), stagecmp); 
	for(i = 0; i < n; i++)
		printf("%d %s\n", sa[i].age, sa[i].name);
	return 0;	
}
