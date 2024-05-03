#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int compare(const void *m, const void *n) {
	int x = *(int *)m;
	int y = *(int *)n;
	if(x < y)
		return -1;
	if(x > y)
		return 1;
	return 0;
}
int main() {
	int *a, i, n, count = 0, num, size = 1024; 
	struct timeval tv1, tv2;
	a = (int *)malloc(sizeof(int) * size);
	while(scanf("%d", &num) != EOF) {
		a[count] = num;
		count++;
		if(count == size) {
			size *= 2;
			a = (int *)realloc(a, sizeof(int) * size);
			if(a == NULL) {
				printf("Failed for %d\n", size);
				exit(1);
			}
		}
	}
	gettimeofday(&tv1, NULL);
	qsort(a, count, sizeof(int), compare); 
	gettimeofday(&tv2, NULL);
/*	for(i = 0; i < count; i++)
		printf("%d\n", a[i]);*/
	for(i = 0; i < count; i++)
		printf("%d ", a[i]);
	printf("\n");
	printf(" %ld %ld %ld\n",
		(tv2.tv_sec - tv1.tv_sec)*1000000+(tv2.tv_usec - tv1.tv_usec),
		tv2.tv_sec - tv1.tv_sec, tv2.tv_usec - tv1.tv_usec);
	free(a);
	return 0;
}
