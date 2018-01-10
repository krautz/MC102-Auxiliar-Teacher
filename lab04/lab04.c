#include <stdio.h>

int main () {
	int n, i, j, i1, j1, i2, j2, i3, j3, i4, j4, i5, j5, k, count = 1, it = 1, alt_raio;
	int prox_raio, m;
	
	scanf("%d", &n);
	scanf("%d %d %d %d %d %d %d %d %d %d", &i1, &j1, &i2, &j2, &i3, &j3, &i4, &j4, &i5, &j5);
	scanf("%d", &k);
	
	alt_raio = n;
	while (count <= 10) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (i1 == i && j1 == j && j1 >= 1) {
					printf("* ");
				} else if (i2 == i && j2 == j && j2 >= 1) {
					printf("* ");
				} else if (i3 == i && j3 == j && j3 >= 1) {
					printf("* ");
				} else if (i4 == i && j4 == j && j4 >= 1) {
					printf("* ");
				} else if (i5 == i && j5 == j && j5 >= 1) {
					printf("* ");
				} else if (k == j && i == n) {
					printf ("X ");
				} else  if (i >= alt_raio && j == k) {
					printf("| ");
				} else {
					printf(". ");
				}
				if (j == n) {
					printf("\n");
				}
			}
		}
		
		printf("\n");
		if (it == 1 || it == 4) {
			if (j1 < n)
				j1++;
			if (j2 < n)
				j2++;	
			if (j3 < n)
				j3++;
			if (j4 < n)
				j4++;
			if (j5 < n)
				j5++;
		} else {
			if (j1 > 1)
				j1--;
			if (j2 > 1)
				j2--;	
			if (j3 > 1)
				j3--;
			if (j4 > 1)
				j4--;
			if (j5 > 1)
				j5--;
		}
		if (it < 4) {
			it++;
		} else {
			it = 1;
		}
		if (alt_raio > 1) {
			alt_raio--;
		}
		for (m = alt_raio, prox_raio = -1; m < n; m++) {
			if (j1 == k && i1 == m) {
				j1 = -10000000;
				prox_raio = m;
			} else if (j2 == k && i2 == m) {
				j2 = -10000000;
				prox_raio = m;
			} else if (j3 == k && i3 == m) {
				j3 = -10000000;
				prox_raio = m;
			} else if (j3 == k && i3 == m) {
				j3 = -10000000;
				prox_raio = m;
			} else if (j4 == k && i4 == m) {
				j4 = -10000000;
				prox_raio = m;
			} else if (j5 == k && i5 == m) {
				j5 = -10000000;
				prox_raio = m;
			}
		}
		if (prox_raio != -1)
			alt_raio = prox_raio + 1;		
		count++;
	}
				
	return 0;
}
