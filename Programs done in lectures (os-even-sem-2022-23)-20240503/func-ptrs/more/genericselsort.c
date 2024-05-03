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
void selectionsort(int *a, int n) {
	int i, j, minpos;
	for(i = 0; i < n; i++) {
		minpos = 0;
		for(j = i + 1; j < n; j++) {
			if(a[j] < a[minpos])
				minpos = j;
		}
		//swap(a[j], a[minpos]);
	}
}
void selsort(void *base, size_t nmemb, size_t size,
	int (*compare) (const void *a, const void *b)) {

	int i, j;
	void *minptr, *currptr, *a;
	void *temp  = malloc(size);

	for(i = 0; i < nmemb; i++) {
		minptr = (base + size * i);
		for(j = i + 1; j < nmemb; j++)  {
			currptr = (base  + size * j);
			if(compare(currptr, minptr) < 0)
				minptr = currptr;
		}
		a = (base  + size * i);
		memcpy(temp, a, size);
		memcpy(a, minptr, size);
		memcpy(minptr, temp, size);
	}
} 
int main() {
	int a[16];
	int i = 0, n;
	while(scanf("%d", &a[i]) != EOF)
		i++;
	n = i;

	printf("After:\n");
	selsort(a, n, sizeof(int), icmp);	
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	i = 0;
	while(scanf("%d%s", &(sa[i].age), sa[i].name) != EOF)
		i++;
	n = i;
	selsort(sa, n, sizeof(sa[i]), stcmp);
	for(i = 0; i < n; i++)
		printf("%s %d\n", sa[i].name, sa[i].age);
	printf("---------\n");
	/* */	
	selsort(sa, n, sizeof(sa[i]), stagecmp); 
	for(i = 0; i < n; i++)
		printf("%d %s\n", sa[i].age, sa[i].name);
	return 0;	
}
