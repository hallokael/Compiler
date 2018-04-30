#include"utils.h"
#define LOW 1
#define CAP 2

using namespace std;
bool IsDigit(char c){
    if(c>='0' && c<='9')return true ;
    else return false ;
}
bool IsLetter(char c,int mode=1){
    if(mode=1){
        if((c>='a' && c<='z')||(c>='A' && c<='Z'))return true ;
        else return false ;
    }
    if(mode=LOW){
        if(c>='a' && c<='z')return true ;
        else return false ;
    }
    if(mode=CAP){
        if(c>='A' && c<='Z')return true ;
        else return false ;
    }
}

int Str2Int(char str[]){
    int u=0 ;
    for(int i=0 ;str[i]!='\0' ;i++){
        if(!IsDigit(str[i]))
            return 0 ;
        u+=(str[i]-'0') ;
        u*=10 ;
    }
    return u/=10 ;
}
int Str2Int(string str) {
	int u = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (!IsDigit(str[i]))
			return 0;
		u += (str[i] - '0');
		u *= 10;
	}
	return u /= 10;
}



int getmode(char c){
    if(c<='9' && c>='0')
        return 1;
    else if(c<='z' && c>='a')
        return 2;
    return 3 ;
}
// Mode
// Number 1
// Letter 2
// String 3  like "njdeclsek"
// Other  4
int getmode(string s) {
	if (s[0] <= '9' && s[0] >= '0')
		return 1;
	else if (s[0] <= 'z' && s[0] >= 'a')
		return 2;
	else if (s[0] == '\"')
		return 3;
	else if (s[0]=='(')
		return 4;
}