#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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
