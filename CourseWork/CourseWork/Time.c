#include "Time.h"
#include "InputeArray.h"
#include "InputeVector.h"
#include "ArraySort.h"
#include "VectorSort.h"

void MeasurementProcessing()
{
	//функція для обрахування точно часу роботи алгоритму шляхом відкидання трьох мінімумів та трьох максимумів з масиву часу
	long int Sum, Min1, Min2, Min3, Max1, Max2, Max3;
	int imin1, imin2, imin3, imax1, imax2, imax3;

	// Два перших виміри (0-й та 1-й) відкидаються 
	// Серед інших елементів знаходимо три мінімальних та три максимальних 
	// елементи і віднімаємо їх значення із загальної суми 
	// Знаходимо мінімальний та максимальний елементи і виключаємо їх з наступних 
	// пошуків, встановивши їм значення -1

	Sum = Res[2]; Min1 = Res[2]; Max1 = Res[2]; imin1 = 2; imax1 = 2;

	for (int i = 3; i < measure_number; i++)
	{
		Sum = Sum + Res[i];
		if (Res[i] > Max1) {
			Max1 = Res[i];
			imax1 = i;
		}
		else if (Res[i] < Min1) {
			Min1 = Res[i];
			imin1 = i;
		}
	}
	Res[imin1] = -1; Res[imax1] = -1;
	// Знаходимо другий мінімальний та другий максимальний елементи 
	// і виключаємо їх з наступних пошуків, встановивши їм значення -1

	if (Res[2] == -1) {
		Min2 = Res[3];
		imin2 = 3;
	}
	else {
		Min2 = Res[2];
		imin2 = 2;
	}

	Max2 = Res[2]; imax2 = 2;

	for (int i = 3; i < measure_number; i++)
	{
		if (Res[i] > Max2) {
			Max2 = Res[i];
			imax2 = i;
		}
		else if (Res[i] < Min2 && Res[i] != -1) {
			Min2 = Res[i];
			imin2 = i;
		}
	}

	Res[imin2] = -1; Res[imax2] = -1;

	//знаходимо третій мінімальний та третій максимальний елементи
	if (Res[2] == -1)
		if (Res[3] == -1) {
			Min3 = Res[4];
			imin3 = 4;
		}
		else {
			Min3 = Res[3]; imin3 = 3;
		}
	else {
		Min3 = Res[2];
		imin3 = 2;
	}

	Max3 = Res[2]; imax3 = 2;

	for (int i = 3; i < measure_number; i++)
	{
		if (Res[i] > Max3) {
			Max3 = Res[i];
			imax3 = i;
		}
		else if (Res[i] < Min3 && Res[i] != -1) {
			Min3 = Res[i];
			imin3 = i;
		}
	}

	// Сума всіх вимірів мінус три максимальних та три мінімальних значення буде записана до 0-го елемента масива Result
	Res[0] = Sum - Min1 - Min2 - Min3 - Max1 - Max2 - Max3;
}

void ProcessingMeasure1(int mode)
//функція для виклику функції виміру часу роботи алгоритму вибору №1, яка в якості параметрів приймає режим заповнення масиву
{
	Measure1(P, M, N, mode);
	MeasurementProcessing();
}


void Measure1(int p, int m, int n, int mode)
//виміри часу алгоритма вибору№1
{
	for (int i = 0; i <= measure_number; i++) {
		InputMass(P, M, N, mode);//заповнення масива А відповідним режимом
		Res[i] = Sort_5(P, M, N);
	}
}

void ProcessingMeasure2(int mode)
//функція для виклику функції виміру часу роботи алгоритму вибору №2, яка в якості параметрів приймає режим заповнення масиву
{
	Measure2(P, M, N, mode);
	MeasurementProcessing();
}


void Measure2(int p, int m, int n, int mode)
//виміри часу алгоритма вибору№2
{
	for (int i = 0; i <= measure_number; i++) {
		InputMass(P, M, N, mode);//заповнення масива А відповідним режимом
		Res[i] = Sort_6(P, M, N);
	}
}


void ProcessingMeasure3(int mode)
//функція для виклику функції виміру часу роботи алгоритму вибору №1 - обміну, яка в якості параметрів приймає режим заповнення масиву
{
	Measure3(P, M, N, mode);
	MeasurementProcessing();
}


void Measure3(int p, int m, int n, int mode)
//виміри часу алгоритма "вибір №1 - Обмін"
{
	for (int i = 0; i <= measure_number; i++) {
		InputMass(P, M, N, mode);//заповнення масива А відповідним режимом
		Res[i] = Sort_18(P, M, N);
	}
}

void ProcessingMeasure4(int mode)
//функція для виклику функції виміру часу роботи алгоритму вибору №2 - обміну, яка в якості параметрів приймає режим заповнення масиву
{
	Measure4(P, M, N, mode);
	MeasurementProcessing();
}


void Measure4(int p, int m, int n, int mode)
//виміри часу алгоритма "вибір №2 - Обмін"
{
	for (int i = 0; i <= measure_number; i++) {
		InputMass(P, M, N, mode);//заповнення масива А відповідним режимом
		Res[i] = Sort_19(P, M, N);
	}
}

void ProcessingMeasure1Vect(int mode)
//функція для виклику функції виміру часу роботи алгоритму вибору №1, яка в якості параметрів приймає режим заповнення вектора
{
	Measure1Vect(Nvect, mode);
	MeasurementProcessing();
}


void Measure1Vect(int n, int mode)
//виміри часу алгоритма вибору№1 (vector)
{
	for (int i = 0; i <= measure_number; i++) {
		InputeVector(Nvect, mode);//заповнення вектора B відповідним режимом
		Res[i] = Select1Vect(Nvect);
	}
}

void ProcessingMeasure2Vect(int mode)
//функція для виклику функції виміру часу роботи алгоритму Вибору №2, яка в якості параметрів приймає режим заповнення вектора
{
	Measure2Vect(Nvect, mode);
	MeasurementProcessing();
}


void Measure2Vect(int n, int mode)
//виміри часу алгоритма вибору№2 (vector)
{
	for (int i = 0; i <= measure_number; i++) {
		InputeVector(Nvect, mode);//заповнення вектора B відповідним режимом
		Res[i] = Select2Vect(Nvect);
	}
}

void ProcessingMeasure3Vect(int mode)
//функція для виклику функції виміру часу роботи алгоритму вибору№1-Обміну, яка в якості параметрів приймає режим заповнення вектора
{
	Measure3Vect(Nvect, mode);
	MeasurementProcessing();
}


void Measure3Vect(int n, int mode)
//виміри часу алгоритма вибору№1 - Обміну (vector)
{
	for (int i = 0; i <= measure_number; i++) {
		InputeVector(Nvect, mode);//заповнення вектора B відповідним режимом
		Res[i] = Sel1Ex(Nvect);
	}
}

void ProcessingMeasure4Vect(int mode)
//функція для виклику функції виміру часу роботи алгоритму вибору№2-Обміну, яка в якості параметрів приймає режим заповнення вектора
{
	Measure4Vect(Nvect, mode);
	MeasurementProcessing();
}

void Measure4Vect(int n, int mode)
//виміри часу алгоритма вибору№2 - Обміну (vector)
{
	for (int i = 0; i <= measure_number; i++) {
		InputeVector(Nvect, mode);//заповнення вектора B відповідним режимом
		Res[i] = Sel2Ex(Nvect);
	}
}