#include"Calculator.h"
#pragma once
using namespace std;
class Calculator {
public:
	Vari Plus(string Ls, string Rs) {
		return Vari(0, Ls + Rs, STR);
	}
	Vari Plus(string Ls, int Rs) {
		if (Ls != "") {
			return Vari(0, Ls + to_string(Rs), STR);
		}
		else {
			return Vari(Rs, "", INT);
		}
		//return Vari(0, Ls + to_string(Rs), STR);

	}
	Vari Plus(int Ls, string Rs) {
		if (Rs != "") {
			return Vari(0, Rs + to_string(Ls), STR);
		}
		else {
			return Vari(Ls, "", INT);
		}
	}
	Vari Plus(int Ls, int Rs) {
		return Vari(Ls + Rs, "", INT);
	}
	Vari Plus(Vari Ls, Vari Rs) {
		if (Ls.type == INT && Rs.type == STR) {
			return Plus(Ls.num, Rs.s);
		}
		if (Ls.type == STR && Rs.type == INT) {
			return Plus(Rs.num, Ls.s);
		}
		if (Ls.type == INT && Rs.type == INT) {
			return Plus(Ls.num, Rs.num);
		}
		if (Ls.type == STR && Rs.type == STR) {
			return Plus(Ls.s, Rs.s);
		}
	}
	int Equal(Vari Ls, Vari Rs) {
		if (Ls.type != Rs.type) {
			return ERR;
		}
		else if (Ls.type == INT) {
			if (Ls.num > Rs.num) {
				return GT;
			}
			else if (Ls.num == Rs.num) {
				return EQ;
			}
			else if (Ls.num < Rs.num) {
				return LT;
			}
		}
		else if (Ls.type == STR) {
			if (Ls.s > Rs.s) {
				return GT;
			}
			else if (Ls.s == Rs.s) {
				return EQ;
			}
			else if (Ls.s < Rs.s) {
				return LT;
			}
		}
		else {
			cout << "Calculator Equal ERROR" << endl;
		}
	}
	Calculator() {
		//cout << "Create a Calculator" << endl;
	}
};