#pragma once
#include"Vari.h"
using namespace std;
//dynamic type: string and int
class Vari {
public:
	int num;
	string s;
	int type;
	Vari(int nu,string ss,int ty) {
		num = nu;
		s = ss;
		type = ty;
	}

	Vari() {
		cout << "Create a Vari" << endl;
	}
};