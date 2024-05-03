#include <pthread.h>
#include <stdio.h>
struct limits {
	int l, h, res;
};
void *f(void *arg) {
	struct limits *p = (struct limits *)arg;
	int prod = 1, k;
	for(k = p->l; k <= p->h; k++)
		prod *= k;
	p->res = prod;
	//sleep(2);
	return NULL;
}
int main() {
	pthread_t tid[2];
	pthread_attr_t pattr[2];
	int j, k, n;
	struct limits lim[2];
	scanf("%d", &n);	
	lim[0].l = 1;
	lim[0].h = n/2;	
	lim[1].l = n/2 + 1;
	lim[1].h = n;	
	pthread_create(&tid[0], NULL, f, &lim[0]);
	pthread_create(&tid[1], NULL, f, &lim[1]);
	for(k = 0; k < 2; k++) {
		pthread_join(tid[k], NULL);
	}
	printf("%d\n", lim[0].res * lim[1].res);
	return 0;
}
