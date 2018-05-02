#include"Variables.h"
#include<string>
#include<string.h>
#pragma once
using namespace std;
//store variables there
class Variables {
public:
	map<string, Vari> mapVar;
	set< string > setVar;
	set< string >::iterator ite1;
	//Vari v;
	bool IsExist(string s) {
		if (setVar.find( s ) != setVar.end()) {
			cout << s << " is declared" << endl;
			return true;
		}
		cout << s << " is not declared" << endl;
		return false;
	}
	//Declare new variables
	bool AddVariable(string s,Vari v){
		
		if (v.type == STR) {
			mapVar[s] = v;
			setVar.insert(s);
			cout << "STR:Success to declare " << s << " as " << v.s << endl;

			PrintmapVar();

			return true;
		}
		if (v.type == INT) {
			mapVar[s] = v;
			setVar.insert(s);
			cout << "INT:Success to declare " << s << " as " << v.num << endl;
			
			PrintmapVar();
				
			return true;
		}
		return false;
	}
	Vari GetVariable(string s) {
		cout << "GetVariable  " << s << endl;
		if (IsExist(s)) {
			Vari v = mapVar[s];
			cout << "Variable Attribute:" << v.name << "  " << to_string(v.num) << "   " << v.s << "  " << to_string(v.type) << endl;
			return v;
		}
		else {
			cout << s << " not defined ERROR" << endl;
		}
		PrintmapVar();
		return Vari(0, "", INT);
	}
	void PrintmapVar() {
		cout << "PrintmapVar" << endl;
		map<string, Vari>::iterator iter;
		for (iter = mapVar.begin(); iter != mapVar.end(); iter++) {
			cout << iter->first << ' ' << iter->second.num << endl;
		}
	}
	Variables() {
		cout << "Create Variables" << endl;
	}
};