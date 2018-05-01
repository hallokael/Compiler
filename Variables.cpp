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
			cout << s << " is declared as int" << endl;
			return true;
		}
		if (setVar.find( s ) != setVar.end()) {
			cout << s << " is declared as str" << endl;
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
			cout << "Success to declare " << s << " as " << v.s << endl;
			map<string,Vari>::iterator iter;
			if (mapVar.begin()== mapVar.end()) {
				cout << "ERROR Declare failed" << endl;
			}
			for (iter = mapVar.begin(); iter != mapVar.end(); iter++)
				cout << iter->first << ' ' << iter->second.s << endl;
			return true;
		}
		if (v.type == INT) {
			mapVar[s] = v;
			setVar.insert(s);
			cout << "Success to declare " << s << " as " << v.num << endl;
			map<string,Vari>::iterator iter;
			if (mapVar.begin() == mapVar.end()) {
				cout << "ERROR Declare failed" << endl;
			}
			for (iter = mapVar.begin(); iter != mapVar.end(); iter++) {
				cout << iter->first << ' ' << iter->second.num << endl;
			}
				
			return true;
		}
		return false;
	}
	Vari GetVariable(string s) {
		if (IsExist(s)) {
			return mapVar[s];
		}
		else {
			cout << s << " not defined ERROR" << endl;
		}
	}
};