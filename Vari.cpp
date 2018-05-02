#pragma once
#include"Vari.h"
using namespace std;
//dynamic type: string and int
class Vari {
public:
	int num;
	string s;
	int type;
	string name="";
	Vari(int nu,string ss,int ty) {
		num = nu;
		s = ss;
		type = ty;
	}

	Vari() {
		//cout << "Create a Vari" << endl;
	}
};

//template is not suit for the problem

//template <typename T>
//class Vari {
//public:
//	T Var;
//	int type;
//	Vari(T a,int t) {
//		Var = a;
//		type = t;
//	}
//	Vari() {
//		cout << "Create a Vari" << endl;
//	}
//};