#include"Grammar.h"
#include"GLOBAL.h"
using namespace std;
class Grammar{
	public:
		string Ss[100] ;
		int leftvalue,rightvalue ;
		int global;
		int statmode,eqmode ;
		Variables V;
		string ERROR;
		Grammar() {
			cout << "Create Grammar" << endl;
		}
		void Get(char s[][100],int gl){
			for(int i =0;i<gl;i++){
				Ss[i] = s[i];
			}
			leftvalue=rightvalue=0;
			global=gl;
			statmode=0,eqmode=0;
		}
		// Show words
		void PrintAllWords(){
		    printf("%d Words:\n",global) ;
		    for(int i =0 ;i<global ;i+=1){
				cout << Ss[i] << endl;
		    }
		}
		void CheckPattern(){
			vector< pair<int, int> > p = SepToSub();
			vector< Vari > pR = SubToResult(p);
			
			GetTotalResult(p,pR);
	
			PrintAllWords();
		}
		void GetTotalResult(vector< pair<int, int> >p, vector< Vari > pR) {
			int Total = 1;
			if (p.size() == 1) {
				return;
			}
			for (int i = p.size() - 1; i >= 1; i--) {
				int tempT = Connect(pR[i],pR[i-1],Ss[p[i].second+1]);
			}
		}
		int Connect(Vari LeftV,Vari RightV,string Connector) {
			cout << "Connect   " << LeftV.num << " " << LeftV.s << "   " << RightV.num << " " << RightV.s << "   " << Connector << endl;
			if (Connector == "=") {
				if (LeftV.name != "") {
					RightV.name = LeftV.name;
					V.AddVariable(LeftV.name, RightV);
					cout << "Assignment OK  :" << LeftV.name << endl;
				}
				else {
					cout << "Assignment ERROR" << endl;
				}
			}
			return 1;
		}
		//split statement to substatement
		vector< pair<int, int> > SepToSub() {
			vector< pair<int, int> > p;
			int leftSep = 0, rightSep = global - 1;
			for (int i = global - 1; i >= 0; i--) {
				for (int j = 0; j < 7; j++) {    //...........
					if (Ss[i] == compare[j]) {
						leftSep = i + 1;
						p.push_back(pair<int, int>(leftSep, rightSep));
						rightSep = i - 1;
					}
				}
			}
			p.push_back(pair<int, int>(0, rightSep));
			//cout << to_string(p.size()) << " SubStateMent" << endl;
			//for (int i = 0; i < p.size(); i++) {
			//	cout << "SubStateMent " << i << " " << p[i].first << " " << p[i].second << endl;
			//}
			return p;
		}
		//get result of all substatement
		vector< Vari > SubToResult(vector< pair<int, int> > p) {
			vector<Vari> vVari;
			for (int i = 0; i < p.size(); i++) {
				SubStateMent sub(Ss, p[i].first, p[i].second,V);
				vVari.push_back(sub.GetResult());
				cout << "vVari Cal:" << vVari[i].num << "  " << vVari[i].s << endl;
			}
			return vVari;
		}
};
