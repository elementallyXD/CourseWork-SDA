#include "OutArray.h"

void OutputMass(int p, int m, int n)
//функція виводу троьвимірного масиву на екран
{
	int i, j, k;
	for (k = 0; k < p; k++) {
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				printf("%3.d ", A[k][i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
}