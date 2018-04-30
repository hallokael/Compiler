#include"Calculator.h"
using namespace std;
class Calculator {
	string Plus(string Ls,string Rs) {
		return Ls + Rs;
	}
	string Plus(string Ls, int Rs) {
		return Ls + to_string(Rs);
	}
	string Plus(int Ls, string Rs) {
		return to_string(Ls) + Rs;
	}
	int Plus(int Ls, int Rs) {
		return Ls + Rs;
	}
};