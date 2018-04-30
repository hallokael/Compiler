#include"Variable.h"
#pragma once
using namespace std;
class Variable {
public:
	map<string, int> mapVarInt;
	map<string, string> mapVarStr;
	set< pair<string, int> > setVar;
	set< pair<string,int> >::iterator ite1;
	bool IsExist(string s) {
		if (setVar.find( pair<string, int>(s,INT) ) != setVar.end()) {
			cout << s << " is declared as int" << endl;
			return true;
		}
		if (setVar.find(pair<string, int>(s, STR)) != setVar.end()) {
			cout << s << " is declared as str" << endl;
			return true;
		}
		cout << s << " is not declared" << endl;
		return false;
	}
	//Declare new variables
	bool AddVariable(string s,int num,string ss,int type){
		if (type == STR) {
			mapVarStr[s] = ss;
			cout << "Success to declare " << s << " as " << ss << endl;
			map<string, string>::iterator iter;
			for (iter = mapVarStr.begin(); iter != mapVarStr.end(); iter++)
				cout << iter->first << ' ' << iter->second << endl;
			return true;
		}
		if (type == INT) {
			mapVarInt[s] = num;
			cout << "Success to declare " << s << " as " << num << endl;
			map<string, int>::iterator iter;
			for (iter = mapVarInt.begin(); iter != mapVarInt.end(); iter++)
				cout << iter->first << ' ' << iter->second << endl;
			return true;
		}
		return false;
	}
};