#ifndef STARTPROJECTS_STRING__H
#define STARTPROJECTS_STRING__H

#endif //STARTPROJECTS_STRING__H

// #17.1

size_t strlen(char* begin);
void strlen_test(int(strlen)(char* begin));

// #17.2

char* find(char* begin, char* end, int ch);
void find_test(char*(find)(char* begin, char* end, int ch));

// #17.3

char* findNonSpace(char* begin);
void findNonSpace_test(char* (findNonSpace)(char* s));

// #17.4

char* findSpace(char* begin);
void findSpace_test(char* (findSpace)(char* s));

// #17.5

char* findNonSpaceReverse(char* rbegin, char* rend);
// #17.6

char* findSpaceReverse(char* rbegin, char* rend);

// #17.7

int strcmpAnalog(char* lhs, char* rhs);
void strcmpAnalog_test(int(strcmpAnalog)(char* lhs, char* rhs));

// #17.8

char* copy(const char* beginSource, const char* endSource, char* beginDestination);
void copy_test(char* (copy)(const char* beginSource, const char* endSource, char* beginDestination));

// #17.9, 17.10

bool isLetter(char s);

char* copyIf(char* beginSource, const char* endSource, char* beginDestination, bool(isLetter)(char s));
void copyIf_test(char*(copyIf)(char* beginSource, const char* endSource, char* beginDestination, bool(isLetter)(char s)));

char* copyIfReverse(char* rbeginSource, const char* rendSource, char* beginDestination, bool(isLetter)(char s));
void copyIfReverse_test(char* (copyIfReverse)(char* beginSource, const char* endSource, char* beginDestination, bool(isLetter)(char s)));