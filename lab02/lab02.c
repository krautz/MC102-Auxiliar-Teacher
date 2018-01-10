#include <stdio.h>

int main () {
	int A, B, C, D, E, F, G, H, I, J, K, minimo, atual;
	scanf("%d %d %d %d %d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &G, &H, &I, &J, &K);

	if (A < B && A < C) {
		minimo = A;
		if (E < D) {
			minimo += E;
			if (J < I) {
				minimo += J;
			} else {
				minimo = minimo + I + K;
			}
		} else {
			minimo += D;
			if (F < G) {
				minimo += F;
				if (J < I) {
					minimo += J;
				} else {
					minimo = minimo + I + K;
				}
			} else {
				minimo = minimo + G + K;
			}
		}
	} else if (B < A && B < C) {
		minimo = B;
		if (F < G) {
			minimo += F;
			if (J < I) {
				minimo += J;
			} else {
				minimo = minimo + I + K;
			}
		} else {
			minimo = minimo + G + K;
		}
	} else {
		minimo = C + H + K;
	}
	if (minimo % 6 == 0) {
		printf("0\n");
	} else {
		minimo = A + E + J;

		atual = A + E + I + K; 
		if (atual < minimo)
			minimo = atual;
	
		atual = A + D + F + J; 
		if (atual < minimo)
			minimo = atual;

		atual = A + D + G + K; 
		if (atual < minimo)
			minimo = atual;

		atual = A + D + F + I + K; 
		if (atual < minimo)
			minimo = atual;

		atual = B + F + J; 
		if (atual < minimo)
			minimo = atual;

		atual = B + F + I + K; 
		if (atual < minimo)
			minimo = atual;

		atual = B + G + K; 
		if (atual < minimo)
			minimo = atual;

		atual = C + H + K; 
		if (atual < minimo)
			minimo = atual;

		printf("%d\n", minimo);
	}

	return 0;
}

