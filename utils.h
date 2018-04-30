#ifndef UTILS_H
#define UTILS_H
#include<string.h>
#include<string>
#include <iostream>
using namespace std;
bool IsDigit(char c);
bool IsLetter(char c,int mode);
int Str2Int(char str[]);
int Str2Int(string str);
int getmode(char c);

//statmode
#define INIT 0
#define CALC 1
#define SETVALUE 2
#define GETVALUE 3
#define ISEQUAL 4
//eqmode
#define GT 1
#define GTE 2
#define LT 3
#define LTE 4
#define EQ 5
//variable
#define STR 1
#define INT 2

#endif

