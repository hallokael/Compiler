#include"Calculator.h"

using namespace std;
class Calculator {
public:
	Vari Plus(string Ls,string Rs) {
		return Vari(0,Ls+Rs,STR);
	}
	Vari Plus(string Ls, int Rs) {
		return Vari(0,Ls+to_string(Rs),STR);
	}
	Vari Plus(int Ls, string Rs) {
		return Vari(0,to_string(Ls) + Rs,STR);
	}
	Vari Plus(int Ls, int Rs) {
		return Vari(Ls + Rs,"",INT);
	}
	Vari Plus(Vari Ls, Vari Rs) {
		if (Ls.type == INT && Rs.type==STR) {
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
	Calculator() {
		cout << "Create a Calculator" << endl;
	}
};