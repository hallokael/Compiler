#include"MainCompiler.h"
using namespace std ;
char s[500],c ;
void getS(char s[]);
Grammar g;
void Get(){
    printf(">>>") ;
    getS(s) ;
}
bool Run(){
    if(strcmp(s,"e")==0){
        exit(0) ;
    }else{
    	Parser p(s);
    	p.Split();

    	g.Get(p.allwords,p.global);
        g.CheckPattern();
    }
}
int main(){
    do{
        Get() ;
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

