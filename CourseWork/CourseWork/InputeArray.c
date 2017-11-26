#include "InputeArray.h"

void InputMass(int p, int m, int n, int mode)
//функція вводу масиву
{  
	int i, j, k,var = N*M*P;
	int temp = 1;
	int temp1;
	//в залежності від мода, який ми вибираємо у меню, вводим у масив елементи
	switch (mode)
	{
	case 1: 
		for (k = 0; k < p; k++)
			for (i = 0; i < m; i++)
				for (j = 0; j < n; j++)
					A[k][i][j] = temp++;
		//прямо відсортовані
		break;
	case 2: 
		for (k = 0; k < p; k++)
			for (i = 0; i < m; i++)
				for (j = 0; j < n; j++)
					A[k][i][j] = 1 + rand() % var;
		//рандомні елементи від 1 до P*N*M +1 
		break;
	case 3: 

		for (k = 0; k < p; k++) {
			temp1 = m*n;
			for (i = 0; i < m; i++)
				for (j = 0; j < n; j++)
					A[k][i][j] = temp1--;
		}
		//обернено відсортовані
		break;
	default: break;
	}
}