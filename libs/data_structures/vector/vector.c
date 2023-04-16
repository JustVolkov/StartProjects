#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdint.h>		// Для MAX_SIZE
#include <stddef.h>		// Для NULL

#include "T:\CLionProjects\StartProjects\libs\data_structures\vector\vector.h"

// #14.2

// Возвращает структуру-дескриптор вектор из capacity значений.
vector createVector(size_t  capacity) {
    vector v = { (int*)malloc(sizeof(int) * capacity), capacity, capacity };

    if (!(v.data)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

// #14.4

// Изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector* v, size_t newCapacity) {
    v->capacity = newCapacity;

    if (newCapacity == 0)
        v->data = NULL;
    else {
        v->data = realloc(v->data, sizeof(int) * newCapacity);

        if (!(v->data)) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        if (newCapacity < v->size)
            v->size = newCapacity;
    }
}

// #14.5

void test_reserve() {
    vector v_notEmpty = createVector(4);
    vector v_Empty = createVector(0);

    assert((v_notEmpty.size == 4) && (v_notEmpty.capacity == 4));
    assert((v_Empty.size == 0) && (v_Empty.capacity == 0));

    free(v_Empty.data);
    free(v_notEmpty.data);
}