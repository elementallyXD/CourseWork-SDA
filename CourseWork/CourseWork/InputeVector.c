#include "InputeVector.h"

void InputeVector(int n, int mode)
	//Безтипова функція для заповнення вектора
{
		int  j;
		int temp = 1, temp1,var = N*M*P;
		//в залежності від мода, який ми вибираємо у меню, вводим у масив елементи
		switch (mode)
		{
		case 1:		for (j = 0; j < n; j++)
						B[j] = temp++;
			//прямо відсортовані
			break;
		
		case 2:		for (j = 0; j < n; j++)
						B[j] = 1 + rand() % var;
			//рандомні елементи від 1 до P*N*M + 1
			break;
		
		case 3:		temp1 = n;
					for (j = 0; j < n; j++)
						B[j] = temp1--;
			//обернено відсортовані
			break;

		default: break;
		}
}