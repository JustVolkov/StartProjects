#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include <stdbool.h>
#include <assert.h>

#include "libs/data_structures/string_/string_.h"

// #17.1

// Возвращает длину строки s (не считая ноль-символа).
size_t strlen(char* begin) {
    char* end = begin;
    while (*end != '\0') {
        end++;
    }
    return end - begin;
}

// Тестирование функции strlen.
void strlen_test(int(strlen)(char* begin)) {
    char s1[] = "ABCDEF";
    char s2[] = "CAT";
    char s3[] = "A";
    char s4[] = "";
    assert(strlen(s1) == 6);
    assert(strlen(s2) == 3);
    assert(strlen(s3) == 1);
    assert(strlen(s4) == 0);
}

// #17.2

// Возвращает указатель на первый элемент с кодом ch, расположенный
// (на ленте памяти) между адресами begin и end (не включая end);
// если символ не найден, возвращает значение end.
char* find(char* begin, char* end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

// Тестирование функции find.
void find_test(char*(find)(char* begin, char* end, int ch)) {
    char s[] = "ISDAAAT";
    char* p_begin = &s[0];
    char* p_end = &s[strlen(s)];
    // Числовые коды и соответствующие им символы (в ASCII):
    int ch1 = 65;	// A
    int ch2 = 73;	// I
    int ch3 = 61;	// =
    assert(find(p_begin, p_end, ch1) == &s[3]);
    assert(find(p_begin, p_end, ch2) == &s[0]);
}

// #17.3

// Возвращает указатель на первый символ, отличный от пробельных,
// расположенный (на ленте памяти) начиная с begin и заканчивая ноль-символом.
// Если адрес не найден, возвращает адрес первого ноль-символа.
char* findNonSpace(char* begin) {
    while (isspace(*begin) != 0 && *begin != '\0') {
        begin++;
    }
    return begin;
}

// Тестирование функции findNonSpace.
void findNonSpace_test(char* (findNonSpace)(char* s)) {
    char s1[] = "\n\n\nWFFB";
    char s2[] = "\nillf";
    assert(findNonSpace(s1) == &s1[3]);
    assert(findNonSpace(s2) == &s2[1]);
}

// # 17.4

// Возвращает указатель на первый пробельный символ, расположенный (на ленте памяти)
// начиная с begin или на первый ноль-символ.
char* findSpace(char* begin) {
    while (isspace(*begin) == 0 && *begin != '\0') {
        begin++;
    }
    return begin;
}

// Тестирование функции findSpace.
void findSpace_test(char* (findSpace)(char* s)) {
    char s1[] = "\n\n\nWFFB";
    char s2[] = "code3\nx\n";
    assert(findSpace(s1) == &s1[0]);
    assert(findSpace(s2) == &s2[5]);
}

// #17.5, 17.6

// Возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный (на летне памяти) начиная с rbegin и заканчивая rend;
// если символ не найден, возвращает rend.
char* findNonSpaceReverse(char* rbegin, char* rend) {
    while (rbegin > rend)
    {
        if (isspace(*rbegin) == 0)
            return rbegin;
        rbegin--;
    }
    return rend;
}

// Возвращает указатель на первый справа пробельный символ, расположенный (на летне памяти)
// начиная с rbegin и заканчивая rend; если символ не найден, возвращает rend.
char* findSpaceReverse(char* rbegin, char* rend) {
    while (rbegin > rend)
    {
        if (isspace(*rbegin) != 0)
            return rbegin;
        rbegin--;
    }
    return rend;
}

// #17.7

// Проверяет строки lhs и rhs на равенство: если код символа lhs больше,
// чем код соответствующего символа rsh возвращает 1, если меньше - -1;
// если строки оказались равны, возвращает 0.
int strcmpAnalog(char* lhs, char* rhs) {
    while (*lhs != '\0' && *rhs != '\0') {
        if (*lhs != *rhs) {
            if (*lhs > * rhs)
                return 1;
            else
                return -1;
        }
        lhs++;
        rhs++;
    }
    return 0;
}

// Тестирование функции strcmpAnalog.
void strcmpAnalog_test(int(strcmpAnalog)(char* lhs, char* rhs)) {
    char s1[] = "cooper";	// p    112
    char s2[] = "cover";	// o	111,	v	118
    char s3[] = "cooler";	// l	108
    char s4[] = "cooler";	// l	108
    assert(strcmpAnalog(s1, s3) == 1);
    assert(strcmpAnalog(s1, s2) == -1);
    assert(strcmpAnalog(s3, s4) == 0);
}

// #17.8

// Записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource
// до endSource. Возвращает указатель на следующий свободный фрагмент памяти в beginDestination.
char* copy(const char* beginSource, const char* endSource, char* beginDestination) {
    int size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);
    return beginDestination + size;
}

// Тестирование функции copy.
void copy_test(char* (copy)(const char* beginSource, const char* endSource, char* beginDestination)) {
    char s[8] = "EXAMPLE";		// Длина - 8
    char* beginSource = &s[0];
    char* endSource= &s[strlen(s)];
    char beginDestination[8];	// Длина как минимум 8 (как и у исходной строки)
    copy(beginSource, endSource, beginDestination);
    assert(*beginDestination == *s);
}

// #17.9, 17.10

// Функция-предикат - проверка на то, является ли символ s
// строчной или заглавной буквой латинского алфавита.
bool isLetter(char s) {
    return((s >= 65 && s <= 90) || (s >= 97 && s <= 122));
}

// Записывает по адресу beginDestination элементы из фрагмента памяти
// начиная с beginSource до endSource, удовлетворяющие функции-пердикату isLetter.
// Возвращает указатель на следующий свободный фрагмент в памяти.
char* copyIf(char* beginSource, const char* endSource, char* beginDestination, bool(isLetter)(char s)) {
    int i = 0;
    while (beginSource < endSource && *beginSource != '\0')
    {
        if (isLetter(*beginSource) == true) {
            *(beginDestination + i) = *beginSource;
            i++;
        }
        beginSource++;
    }
    return beginDestination + i;
}

// Тестирование функции copyIf.
void copyIf_test(char*(copyIf)(char* beginSource, const char* endSource, char* beginDestination, bool(isLetter)(char s))){
    char s1[9] = "YEAR2002";
    char* beginSource1 = &s1[0];
    char* endSource1= &s1[strlen(s1)];
    char beginDestination1[9];

    copyIf(beginSource1, endSource1, beginDestination1, isLetter);

    assert(beginDestination1[0] == 'Y' &&
           beginDestination1[1] == 'E' &&
           beginDestination1[2] == 'A' &&
           beginDestination1[3] == 'R');

    char s2[] = "50Y2H!!BT";
    char* beginSource2 = &s2[0];
    char* endSource2 = &s2[strlen(s2)];
    char beginDestination2[9];

    copyIf(beginSource2, endSource2, beginDestination2, isLetter);

    assert(beginDestination2[0] == 'Y' &&
           beginDestination2[1] == 'H' &&
           beginDestination2[2] == 'B' &&
           beginDestination2[3] == 'T');
}

// Записывает по адресу beginDestination элементы из фрагмента памяти
// начиная с rbeginSource до rendSource, удовлетворяющие функции-пердикату isLetter.
// Возвращает значение beginDestination.
char* copyIfReverse(char* rbeginSource, const char* rendSource, char* beginDestination, bool(isLetter)(char s)) {
    int i = 0;
    while (rbeginSource > rendSource)
    {
        if (isLetter(*rbeginSource) == true) {
            *(beginDestination + i) = *rbeginSource;
            i++;
        }
        rbeginSource--;
    }
    return beginDestination;
    // return beginDestination + i;
}

// Тестирование функции copyIfReverse.
void copyIfReverse_test(char* (copyIfReverse)(char* beginSource, const char* endSource, char* beginDestination, bool(isLetter)(char s))) {
    char s1[] = "1t113kg";
    char* rbeginSource1 = &s1[0];
    char* rendSource1 = &s1[strlen(s1)];
    char beginDestination1[8];

    copyIfReverse(rendSource1, rbeginSource1, beginDestination1, isLetter);

    assert(beginDestination1[0] == 'g' && beginDestination1[1] == 'k' && beginDestination1[2] == 't');

    char s2[] = "60km/h";
    char* rbeginSource2 = &s2[0];
    char* rendSource2 = &s2[strlen(s2)];
    char beginDestination2[7];

    copyIfReverse(rendSource2, rbeginSource2, beginDestination2, isLetter);

    assert(beginDestination2[0] == 'h' && beginDestination2[1] == 'm' && beginDestination2[2] == 'k');
}