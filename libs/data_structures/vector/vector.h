#ifndef STARTPROJECTS_VECTOR_H
#define STARTPROJECTS_VECTOR_H

#endif //STARTPROJECTS_VECTOR_H

// #14.1

typedef struct vector {
    int* data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//---

vector createVector(size_t  capacity);

//---

void reserve(vector* v, size_t newCapacity);

void test_reserve();

//---

void clear(vector* v);

void shrinkToFit(vector* v);

void deleteVector(vector* v);

//---

bool isEmpty(vector* v);

void test_isEmpty();

bool isFull(vector* v);

void test_isFull();

//---

int getVectorValue(vector* v, size_t i);

void test_getVectorValue();

//---

void pushBack(vector* v, int x);

void test_pushBack();

void popBack(vector* v);

void test_popBack();

//

int* front(vector* v);

void test_front();

int* back(vector* v);

void test_back();

//---

int* atVector(vector* v, size_t index);

void test_atVector();