#include "ArraySort.h"

clock_t Sort_5(int p, int m, int n)
//Алгоритм сортування методом вибору №1
{
	int i, j, y, min, Ly, Lx, Rx, Ry, end, begin, imin, jmin,k;

	clock_t start = clock();

	for (k = 0; k < p; k++) {
		Lx = 0;
		Ly = 0;
		Rx = n - 1;
		Ry = m - 1;
		while (Ly<Ry || Lx<Rx) {
			min = A[k][Ly][Lx];
			jmin = Lx;
			imin = Ly;
			end = n - 1;
			if (Ly == Ry) { // Випадок, коли рядки зійшлися
				end = Rx;
			}
			i = Ly;
			begin = Lx + 1;
			while (i <= Ry) {
				for (y = begin; y <= end; y++) {
					if (A[k][i][y] < min)
					{
						min = A[k][i][y];
						imin = i;
						jmin = y;
					}
				}
				i++;
				begin = 0;
				if (i != Ry) {
					end = n - 1;
				}
				else {
					end = Rx;
				}
			}
			A[k][imin][jmin] = A[k][Ly][Lx];
			A[k][Ly][Lx] = min;
			Lx++;
			if (Lx == n) {
				Lx = 0;
				Ly++;
			}
		}
	}
	clock_t stop = clock();
	return stop - start;
}

clock_t Sort_6(int p, int m, int n)
//алгоритм сортування методом вибору №2
{
	int k, i, jmin, b, j, Ly, Lx, Rx, Ry, end, begin, imin;

	clock_t start = clock();

	for (k = 0; k<p; k++) {
		Lx = 0;
		Ly = 0;
		Rx = n - 1;
		Ry = m - 1;
		while (Ly<Ry || Lx<Rx) {
			jmin = Lx;
			imin = Ly;
			end = n - 1;
			if (Ly == Ry) end = Rx;
			i = Ly;
			begin = Lx + 1;
			while (i <= Ry) {
				for (j = begin; j <= end; j++) {
					if (A[k][i][j] < A[k][imin][jmin]) {
						jmin = j;
						imin = i;
					}

				}
				i++;
				begin = 0;
				if (i != Ry) end = n - 1;
				else end = Rx;
			}
			b = A[k][imin][jmin];
			A[k][imin][jmin] = A[k][Ly][Lx];
			A[k][Ly][Lx] = b;
			Lx++;
			if (Lx == n) {
				Lx = 0;
				Ly++;
			}
		}
	}

	clock_t stop = clock();
	return stop - start;
}

clock_t Sort_18(int p, int m, int n)
//гібридний алгоритм сортування (Вибір №1 - Обмін)
{
	int min, i, j, b, Ly, Lx, Rx, Ry, end, begin, k;

	clock_t start = clock();

	for (k = 0; k < p; k++) {
		Lx = 0;
		Ly = 0;
		Rx = n - 1;
		Ry = m - 1;
		while ((Ly < Ry) || (Lx < Rx)) {
			min = A[k][Ly][Lx];
			end = n - 1;
			if (Ly == Ry) end = Rx;
			i = Ly;
			begin = Lx + 1;
			while (i <= Ry) {
				for (j = begin; j <= end; j++) {
					if (A[k][i][j] < min) {
						min = A[k][i][j];
						A[k][i][j] = A[k][Ly][Lx];
						A[k][Ly][Lx] = min;
					}
				}
				i++;
				begin = 0;
				if (i != Ry) end = n - 1;
				else end = Rx;
			}
			Lx++;
			if (Lx == n) {
				Lx = 0;
				Ly++;
			}
		}
	}
	clock_t stop = clock();
	return stop - start;
}

clock_t Sort_19(int p, int m, int n)
//гібридний алгоритм сортування (Вибір №2 - Обмін)
{
	int i, k, j, b, jmin, Ly, Lx, Rx, Ry, end, begin, imin;

	clock_t start = clock();

	for (k = 0; k < p; k++) {
		Lx = 0;
		Ly = 0;
		Rx = n - 1;
		Ry = m - 1;
		while (Ly < Ry || Lx < Rx) {
			jmin = Lx;
			imin = Ly;
			end = n - 1;
			if (Ly == Ry) end = Rx;
			i = Ly;
			begin = Lx + 1;
			while (i <= Ry) {
				for (j = begin; j <= end; j++) {
					if (A[k][i][j] < A[k][Ly][Lx]) {
						b = A[k][i][j];
						A[k][i][j] = A[k][Ly][Lx];
						A[k][Ly][Lx] = b;
					}
				}
				i++;
				begin = 0;
				if (i != Ry) end = n - 1;
				else end = Rx;
			}
			Lx++;
			if (Lx == n) {
				Lx = 0;
				Ly++;
			}
		}

	}

	clock_t stop = clock();
	return stop - start;
}