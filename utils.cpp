
#define LOW 1
#define CAP 2
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

// Mode
// Number 1
// Letter 2
// Other  3

int getmode(char c){
    int mode ;
    if(c<='9' && c>='0')
        mode=1 ;
    else if(c<='z' && c>='a')
        mode=2 ;
    else mode=3 ;
    return mode ; 
}
