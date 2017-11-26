#include "VectorSort.h"

clock_t Select1Vect(int n)
//алгоритм сортування вектора методом Вибору№1
{
	int s, jmin, y, min;

	clock_t start = clock();

	for (s = 0; s < n - 1; s++) {
		min = B[s];
		jmin = s;
		for (y = s + 1; y < n; y++) {
			if (B[y]< min)
			{
				min = B[y];
				jmin = y;
			}
		}
		B[jmin] = B[s];
		B[s] = min;
	}

	clock_t stop = clock();
	return stop - start;
}

clock_t Select2Vect(int n)
//алгоритм сортування вектора методом Вибору№1
{
	int s, jmin, j, b;

	clock_t start = clock();

	for (s = 0; s <= n - 2; s++) {
		jmin = s;
		for (j = s + 1; j <= n - 1; j++) {
			if (B[j] < B[jmin]) jmin = j;
		}
		b = B[jmin];
		B[jmin] = B[s];
		B[s] = b;
	}

	clock_t stop = clock();
	return stop - start;
}

clock_t Sel1Ex(int n)
//алгоритм сортування вектора методом Вибору№1-Обміном
{
	int j, s, b, min;

	clock_t start = clock();

	for (s = 0; s < n - 1; s++) {
		min = B[s];
		for (j = s + 1; j < n; j++) {
			if (B[j] < min)
			{
				min = B[j];
				B[j] = B[s];
				B[s] = min;
			}
		}
	}

	clock_t stop = clock();
	return stop - start;
}

clock_t Sel2Ex(int n)
//алгоритм сортування вектора методом Вибору№1-Обміном
{
	int j, s, b;

	clock_t start = clock();

	for (s = 0; s <= n - 2; s++) {
		for (j = s + 1; j <= n - 1; j++) {
			if (B[j] < B[s])
			{
				b = B[j];
				B[j] = B[s];
				B[s] = b;
			}
		}
	}

	clock_t stop = clock();
	return stop - start;
}