#include"MainCompiler.h"
using namespace std ;
char s[500],c ;
Variables v;
void getS(char s[]);
void Init(){
    printf(">>>") ;
    getS(s) ;
}
bool Run(){
    if(strcmp(s,"e")==0){
        exit(0) ;
    }else{
    	Parser p(s);
    	p.Split();
    	
    	Grammar g(p.allwords,p.global,v);
        g.CheckPattern();
    }
}
int main(){
    do{
        Init() ;
    }while(Run()) ;
    return 0 ;
}
// Get statement
void getS(char s[]){
    for(int i=0 ; ;i+=1){
        char c=getchar() ;
        if(c=='\n'){
            s[i]='\0' ;
            return ;
        }else{
            s[i]=c ;
        }
    }
}

