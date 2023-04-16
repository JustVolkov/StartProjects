#ifndef STARTPROJECTS_MATRIX_H
#define STARTPROJECTS_MATRIX_H

#endif //STARTPROJECTS_MATRIX_H

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} Matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} Position;

void swap(int* a, int* b);

void swap_pointers(int** a, int** b);

Matrix createMatrixFromArray(int* a, int nRows, int nCols);

Matrix getMemMatrix(int nRows, int nCols);

Matrix* getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(Matrix m);

void freeMemMatrices(Matrix* m, int nRows);

void inputMatrix(Matrix m);

void outputMatrix(Matrix m);

void inputMatrices(Matrix* ms, int n);

void outputMatrices(Matrix* ms, int n);

void swapRows(Matrix m, int i1, int i2);

void test_swapRows();

void swapColumns(Matrix m, int j1, int j2);

void test_swapColumns();

bool isSquareMatrix(Matrix* m);

bool areTwoMatricesEqual(Matrix* m1, Matrix* m2);

bool isEMatrix(Matrix* m);

bool isSymmetricMatrix(Matrix* m);

void transposeSquareMatrix(Matrix* m);

void test_transposeSquareMatrix();

Matrix transposeMatrix(Matrix* m);

void test_transposeMatrix();

Position getMinValuePos(Matrix m);

Position getMaxValuePos(Matrix m);

Matrix* createArrayOfMatrixFromArray(const int* values, size_t nMatrices, size_t nRows, size_t nCols);

int countZeroRows(Matrix m);

void test_countZeroRows();

void toSquareIfMatrixIsSymmetrical(Matrix m, bool(*isSymmetricMatrix)(Matrix m));

int* getArrayOfSumsOfRows(Matrix* m, int(getSum)(int* a, int n));

void transposeMatrixHasNoEqualSumOfRows(Matrix m);

int getMinInArea(Matrix m);

int CountZeroRows(Matrix m);

int getVectorIndexWithMaxAngle(Matrix m, int* v);

int countValues(int* a, int i, int value);

void printMatrixWithMaxZeroRows(Matrix* ms, int nMatrix);