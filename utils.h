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
int getmode(string s);
struct vari;
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
//Gstatemode
#define CALC 1
#define EQA 2
#define SET 3
#define DEF 4

// Word's Mode
// Number 1
// Letter 2
// String 3  like "njdeclsek"
// Other  4
#define NUMBER 1
#define LETTER 2
#define STRING 3
#define BRACKET 4
string keywords[] ;
string opera[];
string compare[];

#endif

