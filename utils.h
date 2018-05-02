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
//variable
#define STR 1
#define INT 2
//Gstatemode
#define CALC 1
#define EQA 2
#define SET 3
#define DEF 4
//Calculator_Equal
#define ERR -1
#define EQ 1
#define GT 2
#define LT 3
// Word's Mode
// Number 1
// Letter 2
// String 3  like "njdeclsek"
// Other  4
#define NUMBER 1
#define LETTER 2
#define STRING 3
#define BRACKET 4

//KeyWords
#define NUMBER_OF_KEYWORDS 3
#define NUMBER_OF_OPERA 7
#define NUMBER_OF_COMPARE 9
string Keywords[] ;
string Opera[];
string Compare[];

//#include"Variables.cpp"
//Variables V;

#endif

