#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define  N 1024
int a[N];
int n;
typedef struct limit {
	int l, h, sum;
}limit;
void *add(void *arg) {
	limit *l = (limit *)arg;
	printf("l = %d h = %d\n", l->l, l->h);
	int sum = 0, i = 0;
	for(i = l->l; i <= l->h; i++)
		sum = sum + a[i];
	l->sum = sum;
	return NULL;
}
int main() {
	int i = 0, sum; 
	limit l[3];
	void *status;
	pthread_t  threads[10];
	while(scanf("%d", &a[i++]) != -1)
		;
	n = i;
	l[0].l = 0; 
	l[0].h = n/3;
	l[1].l = l[0].h + 1;
	l[1].h = 2 * n / 3;
	l[2].l = l[1].h + 1;
	l[2].h = n - 1;	
	for(i = 0; i < 3; i++) {
		pthread_create(&threads[i], NULL, add, (void *)&(l[i]));
	}
	for(i = 0; i < 3; i++) 
		pthread_join(threads[i], NULL);
	sum = l[0].sum + l[1].sum + l[2].sum;
	printf("%d\n", sum);
	return 0;	
}
