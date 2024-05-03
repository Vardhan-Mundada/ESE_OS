#include <pthread.h>
#include <stdio.h>
int x = 20;
void *f(void *arg) {
	int p = *(int *)arg;
	sleep(1);
	printf("%d x= %d\n", p, x);
	return NULL;
}
int main() {
	pthread_t tid[3];
	pthread_attr_t pattr[3];
	int args[3], j, k;
		
	for(k = 0; k < 3; k++) {
		args[k] = 10 + k;
		pthread_create(&tid[k], NULL, f, &args[k]);
	}
	for(k = 0; k < 3; k++) {
		pthread_join(tid[k], NULL);
	}
	return 0;
}
