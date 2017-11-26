#include "Time.h"
#include "Menu.h"
#include "InputeArray.h"
#include "InputeVector.h"
#include "OutArray.h"
#include "OutVector.h"
#include "ArraySort.h"
#include "VectorSort.h"


void gotoxy(int col, int row)
//функція, яка ставить курсор на потрібну позицію
{
	printf("\033[%d;%dH", row, col);
}

void zastavka()
//Виведення заставки.
{
system("cls");

gotoxy(50, 6);
printf("Couse work\n");

gotoxy(53, 7);
printf("CDA");

gotoxy(50, 10);
printf("Variant #24\n");

gotoxy(45, 12);
printf("Made by student KV-61:\n");

gotoxy(43, 13);
printf("Bidyak Mikhailo Andriyovuch\n");

gotoxy(51, 16);
printf("Kyev 2017\n");

gotoxy(49, 20);
printf("press any key...");

_getch();//закриття заставки після натискання будь-якою клавіші.
system("cls");
}

void goback()
//функція, яка запитує, чи повернутись в меню, чи вийти з програми
{
	int keys; // змінна яка потрібна для меню. Якщо 1 - повернутись у меню, 0 - вийти з прогр..
	printf("Back to menu(1 - yes, 0 - no):");
	scanf_s("%d", &keys);
	switch (keys)
	{
	case 1: system("cls"); menu(); break;
	case 0: exit(0);
	}
}

void menu()
//функція меню
{
	int mode, num, key;/*змінні, які нам потрібні будуть для меню:
							mode - як масив буде відсортований
							num - вибір спосіб сортування 
							key - перша сторінка меню*/
	printf("\n");
	printf(" ___________________________________________________________________\n");
	printf("|\t\t     \"Course Work\" by M.Bidyak\t\t           |\n");
	printf("|__________________________________________________________________|\n");
	printf("| Size Array:A[%3d][%3d][%3d];       \t\tSize Vector:B[%3d];|\n", P, M, N, Nvect);
	printf("|==================================================================|\n");
	printf("|\t\t\tSelect your choice.  \t                   |\n");
	printf("| 1 - Table Time of sorting array \t\t\t\t   |\n");
	printf("| 2 - Table Time of sorting vector \t\t\t\t   |\n");
	printf("| 3 - Massiv sorting \t\t\t\t\t\t   |\n");
	printf("| 4 - Vector sorting \t\t\t\t\t\t   |\n");
	printf("|==================================================================|\n");
	printf("| 5 - Exit \t\t\t\t\t\t\t   |\n");
	printf("|__________________________________________________________________|");
	printf(" \n\n Choose your choice: ");
	scanf_s("%d", &key);

	system("cls");
	/*
	перша сторінка меню. 
	1-Вивести таблицю часу роботи алгоритмів сортування масиву
	2-Вивести таблицю часу роботи алгоритмів сортування вектора
	3-Вибір заповнення масива, та алгоритму сортування
	4-Вибір заповнення вектора, та алгоритму сортування
	5- вихід із програми
	*/

	switch (key)
	{
	case 5: exit(0);  break;//вихід
	case 4: printf("\n Select the filling for vector: \n");
		printf("______________________________________\n");
		printf("|  1 - sorted                        |\n");
		printf("|  2 - random                        |\n");
		printf("|  3 - reverse-sorted                |\n");
		printf("|                                    |\n");
		printf("|(4-9)- Back to Menu                 |\n");
		printf("|____________________________________|\n");
		printf(" Your choice: ");
		scanf_s(" %d", &mode);
		system("cls");
		if ((mode >= 1) && (mode <= 3)) InputeVector(Nvect, mode);
		else menu();
		//вибираємо спосіб сортування ветктора
		printf("\n Select a kind of sorting: \n");
		printf("_____________________________________\n");
		printf("|  1 - Select1 (5)                   |\n");
		printf("|  2 - Select2 (6)                   |\n");
		printf("|  3 - Select1-Exchange (18)         |\n");
		printf("|  4 - Select2-Exchange (19)         |\n");
		printf("|                                    |\n");
		printf("|(5-9) - Back to Menu                |\n");
		printf("|____________________________________|\n");
		printf(" Your choice: ");
		scanf_s("%d", &num);
		system("cls");
		switch (num)
		{
		case 1://Сортування вектора методом вибору№1 
			printf(" Vector before sorting: \n\n");
			OutputVector(Nvect); // виводить вектор до сортування
			printf("\n\n"); Select1Vect(Nvect);// метод, яким буде сортуватись вектор
			printf(" Vector after sorting: \n\n");
			OutputVector(Nvect);//виводить вектор після сортування
			printf("\n\nTime = %.2lf\n", (float)Res[0] / 20); // рахуєм час сортування (для малих розмірів завжди буде 0.0)
			printf("\n");
			goback();
			break;
		case 2://Сортування вектор методом Вибору№2
			printf(" Vector before sorting: \n\n");
			OutputVector(Nvect);// виводить вектор до сортування
			printf("\n\n"); Select2Vect(Nvect);// метод, яким буде сортуватись вектор
			printf(" Vector after sorting: \n\n");
			OutputVector(Nvect);//виводить вектор після сортування
			printf("\n\nTime = %.2lf\n", (float)Res[0] / 20); // рахуєм час сортування (для малих розмірів завжди буде 0.0)
			printf("\n");
			goback();
			break;
		case 3://Сортування Гібридним алгоритмом (Вибір№1 - Обмін)
			printf(" Vector before sorting: \n\n");
			OutputVector(Nvect);// виводить вектор до сортування
			printf("\n\n"); Sel1Ex(Nvect);// метод, яким буде сортуватись вектор
			printf(" Vector after sorting: \n\n");
			OutputVector(Nvect);//виводить вектор після сортування
			printf("\n\nTime = %.2lf\n", (float)Res[0] / 20); // рахуєм час сортування (для малих розмірів завжди буде 0.0)
			printf("\n");
			goback();
			break;
		case 4://Сортування Гібридним алгоритмом (Вибір№2 - Обмін)
			printf(" Vector before sorting: \n\n");
			OutputVector(Nvect);// виводить вектор до сортування
			printf("\n\n"); Sel2Ex(Nvect); // метод, яким буде сортуватись вектор
			printf(" Vector after sorting: \n\n");
			OutputVector(Nvect);//виводить вектор після сортування
			printf("\n\nTime = %.2lf\n", (float)Res[0] / 20); // рахуєм час сортування (для малих розмірів завжди буде 0.0)
			printf("\n");
			goback();
			break;
		default: menu(); break;
		}
		break;
	case 3://вибираємо заповнення масиву
		printf("\n Select the filling for massive: \n");
		printf("______________________________________\n");
		printf("|  1 - sorted                        |\n");
		printf("|  2 - random                        |\n");
		printf("|  3 - reverse-sorted                |\n");
		printf("|                                    |\n");
		printf("|(4-9)- Back to Menu                 |\n");
		printf("|____________________________________|\n");
		printf(" Your choice: ");
		scanf_s(" %d", &mode);
		system("cls");
		if ((mode >=1)&&(mode<=3)) InputMass(P, M, N, mode);
		else menu();
		//вибираємо спосіб сортування
		printf("\n Select a kind of sorting: \n");
		printf("_____________________________________\n");
		printf("|  1 - Select1 (5)                   |\n");
		printf("|  2 - Select2 (6)                   |\n");
		printf("|  3 - Select1-Exchange (18)         |\n");
		printf("|  4 - Select2-Exchange (19)         |\n");
		printf("|                                    |\n");
		printf("|(5-9) - Back to Menu                |\n");
		printf("|____________________________________|\n");
		printf(" Your choice: ");
		scanf_s("%d", &num);
		system("cls");
		switch (num)
		{
		case 1://Сортування методом вибору№1
			printf(" Massive before sorting: \n\n");
			OutputMass(P, M, N);// виводить на екран масив до сортування
			printf("\n\n"); Sort_5(P, M, N);// метод, яким буде сортуватись масив
			printf(" Massive after sorting: \n\n");
			OutputMass(P, M, N);//виводить на екран масив після сортування
			printf("Time = %.2lf\n", (float)Res[0] / 20); // рахуєм час сортування (для малих розмірів завжди буде 0.0)
			printf("\n");
			goback();
			break;
		case 2://Сортування методом Вибору№2
			printf(" Massive before sorting: \n\n");
			OutputMass(P, M, N);// виводить на екран масив до сортування
			printf("\n\n"); Sort_6(P, M, N);// метод, яким буде сортуватись масив
			printf(" Massive after sorting: \n\n");
			OutputMass(P, M, N);//виводить на екран масив після сортування
			printf("Time = %.2lf\n", (float)Res[0] / 20); // рахуєм час сортування (для малих розмірів завжди буде 0.0)
			printf("\n");
			goback();
			break;
		case 3://Сортування Гібридним алгоритмом (Вибір№1 - Обмін)
			printf(" Massive before sorting: \n\n");
			OutputMass(P, M, N);// виводить на екран масив до сортування
			printf("\n\n"); Sort_18(P, M, N);// метод, яким буде сортуватись масив
			printf(" Massive after sorting: \n\n");
			OutputMass(P, M, N);//виводить на екран масив після сортування
			printf("Time = %.2lf\n", (float)Res[0] / 20); // рахуєм час сортування (для малих розмірів завжди буде 0.0)
			printf("\n");
			goback();
			break;
		case 4://Сортування Гібридним алгоритмом (Вибір№2 - Обмін)
			printf(" Massive before sorting: \n\n");
			OutputMass(P, M, N); // виводить на екран масив до сортування
			printf("\n\n"); Sort_19(P, M, N);// метод, яким буде сортуватись масив
			printf(" Massive after sorting: \n\n");
			OutputMass(P, M, N);//виводить на екран масив після сортування
			printf("Time = %.2lf\n", (float)Res[0] / 20); // рахуєм час сортування (для малих розмірів завжди буде 0.0)
			goback();
			break;
		default: menu(); break;
		}
		break;
	case 2:printf("\n_______________________________________________\n");
		printf("|   B[%3d]         | Sorted | Random | Reverse |\n", Nvect);
		printf("|----------------------------------------------|\n");
		ProcessingMeasure1Vect(1);//виклик функції для вимірювання часу роботи алгоритму для впорядкованого масиву
		printf("| Select1:         |%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure1Vect(2); // Виклик функції для вимірювання часу роботи алгоритму для рандомно-заповненого масиву
		printf("%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure1Vect(3); // Виклик функції для вимірювання часу роботи алгоритму для обернено-впорядкованого масиву
		printf("%9.2f|\n", (float)Res[0] / 20);
		printf("|----------------------------------------------|\n");
		ProcessingMeasure2Vect(1);//виклик функції для вимірювання часу роботи алгоритму для впорядкованого масиву
		printf("| Select2:         |%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure2Vect(2); // Виклик функції для вимірювання часу роботи алгоритму для рандомно-заповненого масиву
		printf("%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure2Vect(3); // Виклик функції для вимірювання часу роботи алгоритму для обернено-впорядкованого масиву
		printf("%9.2f|\n", (float)Res[0] / 20);
		printf("|----------------------------------------------|\n");
		ProcessingMeasure3Vect(1);//виклик функції для вимірювання часу роботи алгоритму для впорядкованого масиву
		printf("| Select1-Exchange:|%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure3Vect(2); // Виклик функції для вимірювання часу роботи алгоритму для рандомно-заповненого масиву
		printf("%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure3Vect(3); // Виклик функції для вимірювання часу роботи алгоритму для обернено-впорядкованого масиву
		printf("%9.2f|\n", (float)Res[0] / 20);
		printf("|----------------------------------------------|\n");
		ProcessingMeasure4Vect(1);//виклик функції для вимірювання часу роботи алгоритму для впорядкованого масиву
		printf("| Select2-Exchange:|%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure4Vect(2); // Виклик функції для вимірювання часу роботи алгоритму для рандомно-заповненого масиву
		printf("%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure4Vect(3); // Виклик функції для вимірювання часу роботи алгоритму для обернено-впорядкованого масиву
		printf("%9.2f|\n", (float)Res[0] / 20);
		printf("|______________________________________________|\n\n");
		goback();
		break;
	case 1://виведення таблиці вимірів часу на екран
		printf("\n_______________________________________________\n");
		printf("|A[%3d][%3d][%3d]  | Sorted | Random | Reverse |\n", P, M, N);
		printf("|----------------------------------------------|\n");
		ProcessingMeasure1(1);//виклик функції для вимірювання часу роботи алгоритму для впорядкованого масиву
		printf("| Select1:         |%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure1(2); // Виклик функції для вимірювання часу роботи алгоритму для рандомно-заповненого масиву
		printf("%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure1(3); // Виклик функції для вимірювання часу роботи алгоритму для обернено-впорядкованого масиву
		printf("%9.2f|\n", (float)Res[0] / 20);
		printf("|----------------------------------------------|\n");
		ProcessingMeasure2(1);//виклик функції для вимірювання часу роботи алгоритму для впорядкованого масиву
		printf("| Select2:         |%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure2(2); // Виклик функції для вимірювання часу роботи алгоритму для рандомно-заповненого масиву
		printf("%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure2(3); // Виклик функції для вимірювання часу роботи алгоритму для обернено-впорядкованого масиву
		printf("%9.2f|\n", (float)Res[0] / 20);
		printf("|----------------------------------------------|\n");
		ProcessingMeasure3(1);//виклик функції для вимірювання часу роботи алгоритму для впорядкованого масиву
		printf("| Select1-Exchange:|%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure3(2); // Виклик функції для вимірювання часу роботи алгоритму для рандомно-заповненого масиву
		printf("%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure3(3); // Виклик функції для вимірювання часу роботи алгоритму для обернено-впорядкованого масиву
		printf("%9.2f|\n", (float)Res[0] / 20);
		printf("|----------------------------------------------|\n");
		ProcessingMeasure4(1);//виклик функції для вимірювання часу роботи алгоритму для впорядкованого масиву
		printf("| Select2-Exchange:|%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure4(2); // Виклик функції для вимірювання часу роботи алгоритму для рандомно-заповненого масиву
		printf("%8.2f|", (float)Res[0] / 20);
		ProcessingMeasure4(3); // Виклик функції для вимірювання часу роботи алгоритму для обернено-впорядкованого масиву
		printf("%9.2f|\n", (float)Res[0] / 20);
		printf("|______________________________________________|\n\n");
		goback();
		break;

	default://при помилковому вводі з клавіатури
		printf(" ");
		printf("Error. Try again...\n");
		menu();
		break;
	}
}

