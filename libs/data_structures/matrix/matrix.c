#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "malloc.h"
#include "assert.h"
#include "math.h"

#include "libs/data_structures/matrix/matrix.h"

const double PI = 3.1415926535897931;
const double EPS = 0.000000001;

// Обмен значений переменных.
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Обмен значений переменных по указателям.
void swap_pointers(int** a, int** b) {
    int* t = *a;
    *a = *b;
    *b = t;
}

//------------

// Возвращает созданную из массива a матрицу размером nRows строк на nCols столбцов.
Matrix createMatrixFromArray(int* a, int nRows, int nCols){
    Matrix m = { ((int**)malloc(nRows)), nRows, nCols };
    int array_counter = 0;

    for (int iR = 0; iR < m.nRows; iR++) {
        m.values[iR] = (int*)malloc(sizeof(int) * m.nCols);
        for (int iC = 0; iC < m.nCols; iC++) {
            m.values[iR][iC] = *(a + (array_counter++));
        }
    }
    return m;
}

//------------

// Размещает в динамической памяти матрицу размером nRows на nCols. Возвращает матрицу.
Matrix getMemMatrix(int nRows, int nCols) {
    int** values = (int**)malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int*)malloc(sizeof(int) * nCols);
    return (Matrix) { values, nRows, nCols };
}

// Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
// Возвращает указатель на нулевую матрицу.
Matrix* getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    Matrix* ms = (Matrix*)malloc(sizeof(Matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

//------------

// Освобождает память, выделенную под хранение матрицы m:
void freeMemMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

// Освобождает память, выделенную под хранение массива ms из nMatrices матриц:
void freeMemMatrices(Matrix* m, int nRows) {
    for (int i = 0; i < nRows; i++) {
        freeMemMatrix(m[i]);
    }
    free(m);
}

//------------

// Ввод матрицы m:
void inputMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

// Вывод матрицы m:
void outputMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf(" %d ", m.values[i][j]);
        }
        printf("\n\n");
    }
}

//---

// Ввод массива из nMatrices матриц, хранящейся по адресу ms:
void inputMatrices(Matrix* ms, int n) {
    for (int i = 0; i < n; i++) {
        inputMatrix(ms[i]);
    }
}

// Вывод массива из nMatrices матриц, хранящейся по адресу ms:
void outputMatrices(Matrix* ms, int n) {
    for (int i = 0; i < n; i++) {
        outputMatrix(ms[i]);
    }
}

//------------

// Обмен строк с порядковыми номерами i1 и i2 в матрице m:
void swapRows(Matrix m, int i1, int i2) {
    assert(i1 >= 0 && i1 < m.nRows);
    assert(i2 >= 0 && i2 < m.nRows);

    swap_pointers(&m.values[i1], &m.values[i2]);
}

// Тестирование функции swapRows путём ввода произвольной матрицы
// и сравнения полученного результата с ожидаемым (с помощью assert):
/* void test_swapRows() {
    Matrix m = createMatrixFromArray((int[]) { 6, 5, 7, 0, 0, 0, 0, 0, 1,
                                               0, 0, 0, 11, 12, 113 }, 5, 3);
    int StartRowNo1[3] = { 6, 5, 7 };
    int StartRowNo4[3] = { 11, 12, 113 };
    int check;

    swap_pointers(&m.values[0], &m.values[4]);
    for (int i = 0; i < m.nCols; i++) {
        if ((StartRowNo1[i] == m.values[4][i]) && (StartRowNo4[i] == m.values[2][i]))
            check = 0;
        else
            check = 1;
        assert(check == 0);
    }
    free(StartRowNo1);
    free(StartRowNo4);
    freeMemMatrix(m);
}
*/

//---

// Обмен колонок с порядковыми номерами j1 и j2 в матрице m:
void swapColumns(Matrix m, int j1, int j2) {
    assert(j1 >= 0 && j1 < m.nRows);
    assert(j2 >= 0 && j2 < m.nRows);

    for (int i = 0; i < m.nRows; i++) {
        swap_pointers(&m.values[i][j1], &m.values[i][j2]);
    }
}

// Тестирование функции swapColumns путём ввода произвольной матрицы
// и сравнения полученного результата с ожидаемым (с помощью assert):
/*void test_swapColumns() {
    Matrix m = createMatrixFromArray((int[]) { 6, 5, 7, 1, 0, 7, 1, 0, 7, 1, 0, 7, 11, 12, 113 }, 5, 3);
    int startColNo0[5] = { 6, 1, 1, 1, 11 };
    int startColNo2[5] = { 7, 7, 7, 7, 113 };

    swapColumns(m, 0, 2);

    for (int i = 0; i < m.nRows; i++) {
        assert((startColNo2[i] == m.values[i][0]) && (startColNo0[i] == m.values[i][3]));
    }
    free(startColNo0);
    free(startColNo2);
    freeMemMatrix(m);
}
 */

//------------

// Возвращает значение «истина», если матрица m является квадратной,
// «ложь» – в противном случае:
bool isSquareMatrix(Matrix* m) {
    return m->nCols == m->nRows;
}

// Возвращает значение «истина», если матрицы m1 и m2 равны,
// «ложь» – в противном случае:
bool areTwoMatricesEqual(Matrix* m1, Matrix* m2) {
    if ((m1->nCols != m2->nCols) || (m1->nRows != m2->nRows))
        return false;
    else {
        for (int rowIndex = 0; rowIndex < m1->nRows; rowIndex++) {
            for (int colIndex = 0; colIndex < m1->nCols; colIndex++) {
                if (m1->values[rowIndex][colIndex] != m2-> values[rowIndex][colIndex])
                    return false;
            }
        }
        return true;
    }
}

// Возвращает значение «истина», если матрица m является единичной,
// «ложь» – в противном случае:
bool isEMatrix(Matrix* m) {
    if (m->nCols != m->nRows)
        return false;
    else {
        int sumOfRow = 0;
        for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
            for (int colIndex = 0; colIndex < m->nCols; colIndex++) {
                sumOfRow += m->values[rowIndex][colIndex];
            }
            if ((sumOfRow != 1) || (m->values[rowIndex][rowIndex] != 1))
                return false;
        }
        return false;
    }
}

// Возвращает значение «истина», если матрица m является симметричной,
// «ложь» – в противном случае:
bool isSymmetricMatrix(Matrix* m) {
    if (m->nCols != m->nRows)
        return false;
    else {
        for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
            for (int colIndex = 0; colIndex < m->nRows; colIndex++) {
                if (m->values[rowIndex][colIndex] != m-> values[colIndex][rowIndex])
                    return false;
            }
        }
        return true;
    }
}

//------------

// Транспонирование квадратной матрицы m:
void transposeSquareMatrix(Matrix* m) {
    int startIndexForNextIteration = 0;
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
        for (int colIndex = startIndexForNextIteration; colIndex < m->nRows; colIndex++) {
            swap_pointers(&m->values[rowIndex][colIndex], &m-> values[colIndex][rowIndex]);
        }
        startIndexForNextIteration++;
    }
}

// Тестирование функции transposeSquareMatrix путём ввода произвольной матрицы
// и сравнения полученного результата с ожидаемым (с помощью assert):
void test_transposeSquareMatrix() {
    Matrix m = createMatrixFromArray((int[]) { 1, 3, 7, 5, 63, 26, 19, 0, 1 }, 3, 3);
    transposeSquareMatrix(&m);
    Matrix transposed_m = createMatrixFromArray((int[]) { 1, 5, 19, 3, 63, 0, 7, 26, 1 }, 3, 3);
    for (int i = 0; i < m.nRows; i++) {
        for (int l = 0; l < m.nRows; l++) {
            assert(m.values[i][l] == transposed_m.values[i][l]);
        }
    }
}

// Транспонирование матрицы m. Возвращает транспонированную матрицу.
Matrix transposeMatrix(Matrix* m) {
    Matrix transposedMatrix = getMemMatrix(m->nCols, m->nRows);
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
        for (int colIndex = 0; colIndex < m->nCols; colIndex++) {
            transposedMatrix.values[colIndex][rowIndex] = m-> values[rowIndex][colIndex];
        }
    }
    return transposedMatrix;
}

// Тестирование функции transposeMatrix  путём ввода произвольной матрицы
// и сравнения полученного результата с ожидаемым (с помощью assert):
void test_transposeMatrix() {
    Matrix m = createMatrixFromArray((int[]) { 4, 14, 6, 65, 1, 5, 3, 17, 18, 0 }, 5, 2);
    Matrix m_transposed = transposeMatrix(&m);
    Matrix m_afterTranspExample = createMatrixFromArray((int[]) { 4, 6, 1, 3, 18, 14, 65, 5, 17, 0 }, 2, 5);

    for (int i = 0; i < m_transposed.nRows; i++) {
        for (int l = 0; l < m_transposed.nCols; l++) {
            assert(m_afterTranspExample.values[i][l] == m_transposed.values[i][l]);
        }
    }
    freeMemMatrix(m_transposed);
    freeMemMatrix(m_afterTranspExample);
}

//------------

// Возвращает позицию минимального элемента матрицы m:
Position getMinValuePos(Matrix m) {
    int minElement = m.values[0][0];
    int rowIndex, colIndex, j, i;
    for (rowIndex = 0; rowIndex < m.nRows; rowIndex++) {
        for (colIndex = 0; colIndex < m.nCols; colIndex++) {
            if (m.values[rowIndex][colIndex] <= minElement) {
                minElement = m.values[rowIndex][colIndex];
                j = rowIndex;
                i = colIndex;
            }
        }
    }
    Position ResultPosition;
    ResultPosition.rowIndex = i;
    ResultPosition.colIndex= j;
    return ResultPosition;
}

// Возвращает позицию максимального элемента матрицы m:
Position getMaxValuePos(Matrix m) {
    int maxElement = m.values[0][0];
    int rowIndex, colIndex, i, j;
    for (rowIndex = 0; rowIndex < m.nRows; rowIndex++) {
        for (colIndex = 0; colIndex < m.nCols; colIndex++) {
            if (m.values[rowIndex][colIndex] >= maxElement) {
                maxElement = m.values[rowIndex][colIndex];
                i = rowIndex;
                j = colIndex;
            }
        }
    }
    Position ResultPosition;
    ResultPosition.rowIndex = j;
    ResultPosition.colIndex = i;
    return ResultPosition;
}

//------------

// Возвращает матрицу размера nRows на nCols, построенную из элементов массива a:
Matrix* createArrayOfMatrixFromArray(const int* values, size_t nMatrices, size_t nRows, size_t nCols) {
    Matrix* ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;
}

// Один из возможных вариантов функции countZeroRows, впоследствии он будет протестирован:
int countZeroRows(Matrix m) {
    int sumOfRow = 0;
    int numberOfZeroRows = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int l = 0; l < m.nCols; l++) {
            sumOfRow += m.values[i][l];
        }
        if (sumOfRow == 0)
            numberOfZeroRows++;
        sumOfRow = 0;
    }
    return numberOfZeroRows;
}

// Тестирование функции countZeroRows:
void test_countZeroRows() {
    Matrix m = createMatrixFromArray
            ((int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            }, 5, 3);
    assert(countZeroRows(m) == 2);
    freeMemMatrix(m);
}

// Функции, которые были созданы для решения задач из  лаб. #16:

// #16.4

// Возводит каждый элемент квадратной матрицы m в квадрат, если она симметрична.
void toSquareIfMatrixIsSymmetrical(Matrix m, bool(*isSymmetricMatrix)(Matrix m)) {
    bool isSymmetrical = isSymmetricMatrix(m);
    if (isSymmetrical == true) {
        for (int rowIndex = 0; rowIndex < m.nRows; rowIndex++) {
            for (int colIndex = 0; colIndex < m.nRows; colIndex++) {
                m.values[rowIndex][colIndex] *= m.values[rowIndex][colIndex];
            }
        }
    }
}

// #16.5

int getSum(int* a, int n) {
    int sumOfArray = 0;
    for (int i = 0; i < n; i++) {
        sumOfArray += a[i];
    }
    return sumOfArray;
}

// Выделяет память и наполняет массив суммами элементов каждой строки a размера n матрицы m.
// Возвращает указатель на этот массив.
int* getArrayOfSumsOfRows(Matrix* m, int(getSum)(int* a, int n)) {
    int* sumsOfRows = malloc(sizeof(int) * m->nRows);
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
        sumsOfRows[rowIndex] = getSum(m->values[rowIndex], m->nRows);
    }
    return sumsOfRows;
}

// Получает на вход матрицу m, обрабатывает её и формирует массив sumsOfRows из сумм элементов её строк,
// если в этом массиве не будет повторяющихся элементов (т. е. isArrayUnique == true),
// матрица m будет транспонирована.
void transposeMatrixHasNoEqualSumOfRows(Matrix m) {
    int* sumsOfRows = getArrayOfSumsOfRows(&m, getSum);
    bool isArrayUnique = isUnique(sumsOfRows, m.nRows);
    if (isArrayUnique == true)
        transposeSquareMatrix(&m);
}

// #16.8

// Возвращает минимальный элемент из специальной области матрицы m.
int getMinInArea(Matrix m) {
    // Самый первый элемент матрицы назначается минимальным.
    // Далее в функции именно со значением этой переменной будут проводится сравнения всех остальных элементов.
    int min = m.values[0][0];
    int leftBorder, rightBorder;

    // Переменная sizeOfRow заменяет "магическую константу" 6 - ширину матрицы.
    int sizeOfRow = 6;

    for (int i = 0; i < 5; i++) {
        if (i < 2)
            leftBorder = 0, rightBorder = sizeOfRow;
        else if (i < 3)
            leftBorder = 1, rightBorder = sizeOfRow;
        else if (i < 4)
            leftBorder = 2, rightBorder = sizeOfRow - 1;
        else if (i < 5)
            leftBorder = 3, rightBorder = sizeOfRow - 2;
        int j = leftBorder;
        while (j < rightBorder) {
            if (m.values[i][j] < min)
                min = m.values[i][j];
            j++;
        }
    }
    return min;
}

// #16.14

// Возвращает количество строк матрицы m, которые полностью состоят из нулей.
int CountZeroRows(Matrix m) {
    int sumOfRow = 0;
    int numberOfZeroRows = 0;
    for (int rowIndex = 0; rowIndex < m.nRows; rowIndex++) {
        for (int colIndex = 0; colIndex < m.nCols; colIndex++) {
            sumOfRow += m.values[rowIndex][colIndex];
        }
        if (sumOfRow == 0) {
            numberOfZeroRows++;
        }
        sumOfRow = 0;
    }
    return numberOfZeroRows;
}

// #16.17

// Возвращает индекс того вектора из матрицы m, который образует наибольший угол с вектором v.
int getVectorIndexWithMaxAngle(Matrix m, int* v) {
    // Выделение памяти для хранения массива со значениями углов в радианах:
    double* anglesValuesInRadians = (double*)malloc(sizeof(double) * m.nRows);
    int angleIndex = 0;

    double Lenght_v = getVectorLength(v, m.nCols);

    for (int rowIndex = 0; rowIndex < m.nRows; rowIndex++) {
        double cos = getCosine(m.values[rowIndex], v, m.nCols, Lenght_v);
        cos = angleEqualOrLessThanPI(cos);
        anglesValuesInRadians[angleIndex++] = cos;
    }

    double maxAngle = maxElementOfArray(anglesValuesInRadians, angleIndex);

    // Проход по массиву углов (anglesValuesInRadians), сравнение вещественных чисел на равенство
    // и возврат индекса максимального элемента из этого массива.
    for (int i = 0; i < angleIndex; i++) {
        if (fabs(anglesValuesInRadians[i] - maxAngle) < EPS)
            free(anglesValuesInRadians);
        return i;
    }
}

// Возвращает индекс i того элемента массива a, который равен значению value,
// а если такого значения нет, не возвращает ничего.
int countValues(int* a, int i, int value) {
    if (a[i] == value)
        return i;
    return -1;
}

// Выводит из массива матриц ms размера nMatrix ту (или те) матрицы, в которой (-ых) наибольшее количество нулевых строк.
void printMatrixWithMaxZeroRows(Matrix* ms, int nMatrix) {
    int* arrayOfNumbersOfZeroRows = (int*)malloc(sizeof(int) * nMatrix);

    for (int mxIndex = 0; mxIndex < nMatrix; mxIndex++) {
        arrayOfNumbersOfZeroRows[mxIndex] = CountZeroRows(ms[mxIndex]);
    }
    int max = maxElementOfArray(arrayOfNumbersOfZeroRows, nMatrix);
    for (int mxIndex = 0; mxIndex < nMatrix; mxIndex++) {
        outputMatrix(ms[countValues(arrayOfNumbersOfZeroRows, mxIndex, max)]);
    }
    free(arrayOfNumbersOfZeroRows);
}
