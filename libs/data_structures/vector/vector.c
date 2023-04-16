#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdint.h>		// Для MAX_SIZE
#include <stddef.h>		// Для NULL
#include <stdbool.h>

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

// #14.6

// Удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector* v) {
    for (int i = 0; i < v->size; i++) {
        v->data[i] = NULL;
    }

    v->size = 0;
}

// #14.7

// Освобождает память, выделенную под неиспользуемые элементы.
void shrinkToFit(vector* v) {
    for (int i = 0; i < v->capacity; i++) {
        v->data[i] = NULL;
    }
    v->capacity = v->size;
    // "Удаляет неиспользуемые элементы ("запас", т. е. capacity, приравнивается к size).
}

// #14.8

// Освобождает память, выделенную вектору.
void deleteVector(vector* v) {
    v->data = realloc(v->data, v->size);
    v->capacity = v->size;
}

// #14.9

// Является ли вектор "пустым"?
bool isEmpty(vector* v) {
    return v->size == 0;
}

void test_isEmpty() {
    vector v_notEmpty = createVector(3);
    vector v_Empty = createVector(0);
    assert((isEmpty(&v_notEmpty) == false) && (isEmpty(&v_Empty) == true));

    free(v_Empty.data);
    free(v_notEmpty.data);
}

// #14.10

// Является ли вектор "полным"?
bool isFull(vector* v) {
    return v->size == v->capacity;
}

void test_isFull() {
    vector v_notFull = createVector(3);
    v_notFull.capacity++;
    vector v_Full = createVector(3);
    assert((isFull(&v_Full) == true) && (isFull(&v_notFull) == false));

    free(v_notFull.data);
    free(v_Full.data);
}

// #14.11

// Возвращает i-ый элемент вектора v.
int getVectorValue(vector* v, size_t i) {
    return v->data[i];
}

void test_getVectorValue() {
    vector v = createVector(4);
    {
        v.data[0] = 2;
        v.data[1] = 4;
        v.data[2] = 8;
        v.data[3] = 16;
    }
    {
        assert(getVectorValue(&v, 0) == 2);
        assert(getVectorValue(&v, 1) == 4);
        assert(getVectorValue(&v, 2) == 8);
        assert(getVectorValue(&v, 3) == 16);
    }
    free(v.data);
}

// #14.12

// Добавляет элемент x в конец вектора
// (при необходимости capacity увеличивается по спец. правилам).
void pushBack(vector* v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (v->size == v->capacity)
        reserve(v, (v->capacity * 2));
    v->data[v->size] = x;
    v->size++;
}

void test_pushBack() {
    vector v = createVector(0);
    assert((v.capacity == 0) && (v.size == 0));

    {
        pushBack(&v, 66);
        assert((v.capacity == 1) && (v.size == 1) && (v.data[0] == 66));

        pushBack(&v, 24);
        assert((v.capacity == 2) && (v.size == 2) && (v.data[1] == 24));

        pushBack(&v, 12);
        assert((v.capacity == 4) && (v.size == 3) && (v.data[2] == 12));

        pushBack(&v, 3);
        assert((v.capacity == 4) && (v.size == 4) && (v.data[3] == 3));

        pushBack(&v, 1);
        assert((v.capacity == 8) && (v.size == 5) && (v.data[4] == 1));
    }
    free(v.data);
}
