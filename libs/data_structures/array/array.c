#include "stdio.h"
#include "stdbool.h"
#include "math.h"

#include "libs/data_structures/array/array.h"

#define PI 3.1415926535

// #16.5

// Возвращает сумму массива a размера n.
int getSum(int* a, int n) {
    int sumOfArray = 0;
    for (int i = 0; i < n; i++) {
        sumOfArray += a[i];
    }
    return sumOfArray;
}

// Возвращает True, если массив a не содержит одинаковых элементов, False в противном случае.
bool isUnique(int* a, int n) {
    int i = 0;
    while (i < n - 1) {
        int j = i + 1;
        while (j < n) {
            if (a[i] == a[j])
                return false;
            j++;
        }
        i++;
    }
    return true;
}

// #16.17

// Возвращает скалярное произведение векторов (т. е. массивов) a и b размера n.
double getScalarProduct(int* a, int* v, int sizeOfVectors) {
    double scalarProduct = 0;
    for (int i = 0; i < sizeOfVectors; i++) {
        scalarProduct += (double)(a[i] * v[i]);
    }
    return scalarProduct;
}

// Возвращает модуль вектора a размера sizeOfVector.
double getVectorLength(int* a, int sizeOfVector) {
    double vectorLength = 0;
    for (int i = 0; i < sizeOfVector; i++) {
        vectorLength += (double)(a[i] * a[i]);
    }
    return sqrt(vectorLength);
}

// Возвращает косинус угла между векторами (a - текущий вектор, b - вектор U,
// n - количество элементов в строке (ширина матрицы), module_U - модуль вектора U (вычисленный заранее).
double getCosine(int* a, int* v, int sizeOfVectors, double Lenght_v) {
    double scalarProduct = getScalarProduct(a, v, sizeOfVectors);
    double vectorLength = getVectorLength(a, sizeOfVectors);
    double cos = scalarProduct / (vectorLength * Lenght_v);
    return cos;
}

// Возвращает арккосинус значения cos, т. е. соответствующий такому значению угол (в радианах),
// причём итоговое значение всегда будет <= PI (а значит, <= 180 градусов).
double angleEqualOrLessThanPI(double cos) {
    double angle = acos(cos);
    if (angle > PI)
        angle -= (angle / PI) * PI;
    return angle;
}