#ifndef STARTPROJECTS_VECTOR_H
#define STARTPROJECTS_VECTOR_H

#endif //STARTPROJECTS_VECTOR_H

// #14.1

typedef struct vector {
    int* data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;