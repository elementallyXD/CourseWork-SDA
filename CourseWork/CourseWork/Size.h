#pragma once

#define M 30 // кількість рядків
#define N 30 // стовпців
#define P 3 // кількість перерізів
//розіміри масиву

#define Nvect P*N*M // розмір вектору

extern int A[P][M][N]; //виділення памяті для масива
extern int B[Nvect]; // виділення памяті для вектора