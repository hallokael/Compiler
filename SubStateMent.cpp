#include"SubStateMent.h"

//SubStateMent is splited from statement by words such as "== > < ="
//so all SubStateMent must have a result (except assignment operation) 
class SubStateMent {
public:
	string s[100];
	int length;
	string calcs = "+*/%^!";
	Variables* V;
	SubStateMent(string Ss[],int start,int end,Variables &vv) {
		for (int i = start; i <= end; i++) {
			s[i - start] = Ss[i];
		}
		length = end - start+1;
		V = &vv;
		//cout << "length = " << length << endl;
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
		Vari v(0,"",STR);
		Vari tempv(0,"",STR);
		char c = '+';
		for (int i = 0; i < length; i++) {
			//Declare
			if (length == 1 && getmode(s[i])==LETTER) {
				if (!V->IsExist(s[i])) {
					cout << "Return Assignment" << endl;
					Vari vT(0, "", STR);
					vT.name = s[i];
					return vT;
				}
			}
			//Change operator
			if (s[i].length() == 1 && calcs.find(s[i]) != std::string::npos ) {
				c = s[i][0];
				continue;
			}
			//Calc by mode
			switch (getmode(s[i]))
			{
			case NUMBER:
				tempv = ToVari(Str2Int(s[i]));
				if (c == '+') {
					v=C.Plus(v,tempv);
				}
				if (c == '-') {
					tempv.num *= (-1);
					v = C.Plus(v,tempv);
				}
				break;
			case LETTER:
				if (c == '+') {
					//cout << "WHYYYYYY    " << i << "   " << s[i] << endl;
					tempv=V->GetVariable(s[i]);
					v = C.Plus(v,tempv);
				}
				break;
			case STRING:
				tempv = ToVari(s[i]);
				if (c == '+') {
					v = C.Plus(v,tempv);
				}
				break;
			default:
				break;
			}
		}
		//cout << "GetResultEnd" << endl;
		return v;
	}
};