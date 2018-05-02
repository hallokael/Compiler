#include"Grammar.h"
using namespace std;
class Grammar {
public:
	string Ss[100];
	int leftvalue, rightvalue;
	int global;
	int statmode, eqmode;
	Variables V;
	string ERROR;
	Calculator C;
	Grammar() {
		//cout << "Create Grammar" << endl;
	}
	void Get(char s[][100], int gl) {
		for (int i = 0; i < gl; i++) {
			Ss[i] = s[i];
		}
		leftvalue = rightvalue = 0;
		global = gl;
		statmode = 0, eqmode = 0;
	}
	// Show words
	void PrintAllWords() {
		printf("%d Words:\n", global);
		for (int i = 0; i < global; i += 1) {
			cout << Ss[i] << endl;
		}
	}
	void CheckPattern() {
		vector< pair<int, int> > p = SepToSub();
		vector< Vari > pR = SubToResult(p);

		GetFinalResult(p, pR);

		PrintAllWords();
	}

	// GetFinalResult : from right to left
	void GetFinalResult(vector< pair<int, int> >p, vector< Vari > pR) {
		int Total = 1;
		// In every loop , del two sub and add a new sub include them
		// new sub'name is "Y" or "N"
		// The amount of data is very small, so I choose a simple algorithm
		while (1) {
			if (p.size() == 1) {
				break;
			}
			for (int j = 0; j < NUMBER_OF_COMPARE; j++) {
				for (int i = p.size() - 1; i >= 1; i--) {
					string con = Ss[p[i-1].second + 1];
					if (Compare[j] == con) {
						Vari tempT = Connect(pR[i-1], pR[i], con);

						p.insert(p.begin() + i - 1, pair<int, int>(p[i - 1].first, p[i].second));
						p.erase(p.begin() + i, p.begin() + i+2);
						pR.insert(pR.begin() + i - 1, tempT);
						pR.erase(pR.begin() + i, pR.begin() + i+2);
						for (auto a = p.begin(); a != p.end(); a++) {
							cout << "vector p:" << a->first << "  " << a->second << endl;
						}
						break;
					}

				}
			}
		}
		Vari Final = pR[0];

		if (pR[0].name != "N") {
			cout << "True" << endl;
		}
		else {
			cout << "False" << endl;
		}
	}
	Vari Connect(Vari LeftV, Vari RightV, string Connector) {

		//cout << "Connect   " << LeftV.num << " " << LeftV.s << "   " << RightV.num << " " << RightV.s << "   " << Connector << endl;
		//cout << "LEFTV" << endl;
		//LeftV.show();
		//cout << "RIGHTV" << endl;
		//RightV.show();

		// Vari's name is used for TAG to show the result
		// return LeftV

		//  part =
		if (Connector == "=") {
			if (LeftV.name != "") {
				RightV.name = LeftV.name;
				V.AddVariable(LeftV.name, RightV);
				cout << "Assignment OK  :" << LeftV.name << endl;
			}
			else {
				cout << "Assignment ERROR" << endl;
			}
			if (LeftV.name=="N" || RightV.name == "N") {
				LeftV.name = "N";
			}
			else {
				LeftV.name = "Y";
			}
			
		}
		// part equal
		string tempCom[] = { "==",">=","<=","<",">" };
		for (int i = 0; i < 5; i++) {
			if (Connector == tempCom[i]) {
				DealEqualCon(LeftV, RightV, Connector);
			}
		}


		return LeftV;
	}
	void DealEqualCon(Vari &LeftV,Vari &RightV,string Connector) {
		//cout << "DealEqualCon" << endl;
		//LeftV.show();
		//RightV.show();
		if (LeftV.name == "N" || RightV.name == "N") {
			LeftV.name = "N";
			return;
		}
		map < string, vector<int> > m;
		vector<int> v;
		v.push_back(EQ); v.push_back(-1);
		m["=="] = v;
		v.clear();
		v.push_back(EQ); v.push_back(GT); v.push_back(-1);
		m[">="] = v;
		v.clear();
		v.push_back(EQ); v.push_back(LT); v.push_back(-1);
		m["<="] = v;
		v.clear();
		v.push_back(GT); v.push_back(-1);
		m[">"] = v;
		v.clear();
		v.push_back(LT); v.push_back(-1);
		m["<"] = v;
		for (int i = 0; m[Connector][i]!=-1; i++) {
			cout << "mConnector : " << m[Connector][i] << endl;
			if (C.Equal(LeftV, RightV) == m[Connector][i]) {
				cout << "Change LeftV to Y" << endl;
				LeftV.name = "Y";
				return;
			}
			else {
				LeftV.name = "N";
			}
		}

	}
	//split statement to substatement : from left to right
	vector< pair<int, int> > SepToSub() {
		vector< pair<int, int> > p;
		int leftSep = 0, rightSep = global - 1;
		for (int i = 0; i < global; i++) {
			for (int j = 0; j < NUMBER_OF_COMPARE; j++) {    //...........
				if (Ss[i] == Compare[j]) {
					rightSep = i - 1;
					p.push_back(pair<int, int>(leftSep, rightSep));
					leftSep = i + 1;
				}
			}
		}
		p.push_back(pair<int, int>(leftSep, global - 1));
		//cout << to_string(p.size()) << " SubStateMent" << endl;
		//for (int i = 0; i < p.size(); i++) {
		//	cout << "SubStateMent " << i << " " << p[i].first << " " << p[i].second << endl;
		//}
		return p;
	}
	//get result of all substatement : from left to right
	vector< Vari > SubToResult(vector< pair<int, int> > p) {
		vector<Vari> vVari;
		for (int i = 0; i < p.size(); i++) {
			SubStateMent sub(Ss, p[i].first, p[i].second, V);
			vVari.push_back(sub.GetResult());
			cout << "vVari Cal:" << vVari[i].num << "  " << vVari[i].s << endl;
		}
		return vVari;
	}
};
