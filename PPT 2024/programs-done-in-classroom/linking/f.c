int g(int);
#define ADD(a, b)	(a + b)
int f(int m, int n) {
	return ADD(m, n) + 5 + g(10);
}
