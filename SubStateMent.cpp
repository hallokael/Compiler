#include"SubStateMent.h"


//SubStateMent is splited from statement by words such as "== > < ="
//so all SubStateMent must have a result (except assignment operation) 
class SubStateMent {
public:
	Variables V;
	string s[100];
	int length;
	string calcs = "+=*/%^!";
	SubStateMent(string Ss[],int start,int end,Variables vv) {
		for (int i = start; i <= end; i++) {
			s[i - start] = Ss[i];
		}
		length = end - start+1;
		V = vv;
	}

	// Word's Mode
	// Number 1
	// Letter 2
	// String 3  like "njdeclsek"
	// Other  4

	Vari ToVari(int nu) {
		return Vari(nu, "", INT);
	}
	Vari ToVari(string s) {
		return Vari(0, s.substr(1,s.length()-2), STR);
	}
	Vari GetResult() {
		Calculator C;
		Vari v(0,"",INT);
		Vari tempv;
		char c = '+';
		for (int i = 0; i < length; i++) {
			if (s[i].length() == 1 && calcs.find(s[i]) != std::string::npos ) {
				c = s[i][0];
				continue;
			}
			switch (getmode(s[i]))
			{
			case NUMBER:
				tempv = ToVari(Str2Int(s[i]));
				if (c == '+') {
					v=C.Plus(tempv, v);
				}
				if (c == '-') {
					tempv.num *= (-1);
					v = C.Plus(tempv, v);
				}
				break;
			case LETTER:
				if (c == '+') {
					tempv=V.GetVariable(s[i]);
					v = C.Plus(tempv, v);
				}
				break;
			case STRING:
				tempv = ToVari(s[i]);
				if (c == '+') {
					v = C.Plus(tempv, v);
				}
				break;
			default:
				break;
			}
			//Vari vTemp()
		}
		cout << "" << endl;
		return v;
	}
};