﻿#pragma once//директива препроцесора, щоб уникнути багаторазове ключання модулів
#include "size.h"
#include <time.h>

void Measure1(int p, int m, int n, int mode);
/* функція для вимірювання сумарного часу сортувань масиву А (методом вибору№1) ,
яка в якості параметрів приймає розмірності масиву, а повертає сумарний час роботи протягом всіх повторень*/

void Measure1Vect(int n, int mode);
/* функція для вимірювання сумарного часу сортувань вектора B (методом вибору№1) ,
яка в якості параметрів приймає розмірність вектора, а повертає сумарний час роботи протягом всіх повторень*/

void Measure2(int p, int m, int n, int mode);
/* функція для вимірювання сумарного часу сортувань масиву А (методом вибору №2) ,
яка в якості параметрів приймає розмірності масиву, а повертає сумарний час роботи протягом всіх повторень*/

void Measure2Vect(int n, int mode);
/* функція для вимірювання сумарного часу сортувань вектора B (методом вибору№2) ,
яка в якості параметрів приймає розмірність вектора, а повертає сумарний час роботи протягом всіх повторень*/

void Measure3(int p, int m, int n, int mode);
/* функція для вимірювання сумарного часу сортувань масиву А (гібридний алгоритм(Вибір№1-обмін)) ,
яка в якості параметрів приймає розмірності масиву, а повертає сумарний час роботи протягом всіх повторень*/

void Measure3Vect(int n, int mode);
/* функція для вимірювання сумарного часу сортувань вектора B (методом вибору№1 - обмін),
яка в якості параметрів приймає розмірність вектора, а повертає сумарний час роботи протягом всіх повторень*/

void Measure4(int p, int m, int n, int mode);
/* функція для вимірювання сумарного часу сортувань масиву А (гібридний алгоритм (Вибір№2 - обмін)) ,
яка в якості параметрів приймає розмірності масиву, а повертає сумарний час роботи протягом всіх повторень*/

void Measure4Vect(int n, int mode);
/* функція для вимірювання сумарного часу сортувань вектора B (методом Вибору№2 - обмін),
яка в якості параметрів приймає розмірність вектора, а повертає сумарний час роботи протягом всіх повторень*/

#define measure_number 28 // кількість вимірювань часу для кожного
clock_t Res[measure_number];

void MeasurementProcessing(); /* функція для обрахування точного часу роботи конкретного алгоритму шляхом відкидання трьох мінімумів 
та трьох максимумів з масива часу Res, та запису цього часу в Res[0] */

void ProcessingMeasure1(int mode);/* функція для виклику функцій вимірювання часу роботи алгоритму вибору №1 , 
яка в якості параметрів приймає режим заповнення масивa А */

void ProcessingMeasure1Vect(int mode);/* функція для виклику функцій вимірювання часу роботи алгоритму вибору №1,
яка в якості параметрів приймає режим заповнення вектора B */

void ProcessingMeasure2(int mode);/* функція для виклику функцій вимірювання часу роботи алгоритму вибору №2 ,
яка в якості параметрів приймає режим заповнення масивa А */

void ProcessingMeasure2Vect(int mode);/* функція для виклику функцій вимірювання часу роботи алгоритму вибору №2,
									  яка в якості параметрів приймає режим заповнення вектора B */

void ProcessingMeasure3(int mode);/* функція для виклику функцій вимірювання часу роботи алгоритму вибору №1 - Обміну ,
яка в якості параметрів приймає режим заповнення масивa А */

void ProcessingMeasure3Vect(int mode);/* функція для виклику функцій вимірювання часу роботи алгоритму вибору №1 - обмін,
									  яка в якості параметрів приймає режим заповнення вектора B */

void ProcessingMeasure4(int mode);/* функція для виклику функцій вимірювання часу роботи алгоритму вибору №2 - Обміну ,
яка в якості параметрів приймає режим заповнення масивa А */

void ProcessingMeasure4Vect(int mode);/* функція для виклику функцій вимірювання часу роботи алгоритму вибору №1 - обмін,
									  яка в якості параметрів приймає режим заповнення вектора B */
