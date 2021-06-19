#include <stdio.h>

int main() {
	int M, N, i, j, min[100], p = 0, sum = 0, m;
	scanf("%d", &M);
	scanf("%d", &N);
	for (i = M; i <= N; i++) {
		for (j = 0; j <= i; j++) {
			if (j*j == i) {
				min[p] = i;
				p++;
			}
		}
	}
	m = min[0];
	for (i = 0; i < p; i++) {
		sum += min[i];
		if (min[i] < m)
			m = min[i];
	}
	if (p == 0)
		printf("-1\n");
	else
		printf("%d\n%d", sum, m);
}