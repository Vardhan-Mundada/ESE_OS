#include <pthread.h>
#include <stdio.h>
void *f(void *arg) {
	int p = *(int *)arg;
	printf("%d\n", p);
	return NULL;
}
int main() {
	pthread_t tid[3];
	int i, j, k;
	i = 10;
		
	for(k = 0; k < 3; k++) {
		pthread_create(&tid[k], NULL, f, &i);
		i++;
	}
	for(k = 0; k < 3; k++) {
		pthread_join(tid[k], NULL);
	}
	return 0;
}
