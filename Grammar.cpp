#include"stdio.h"
#include"string.h"
#include"utils.h"

#define CALC 1
#define SETVALUE 2
#define GETVALUE 3
#define ISEQUAL 4

class Grammar{
	public:
		char allwords[100][20] ;
		int leftvalue,rightvalue ;
		int global;
		int statmode ;
		Grammar(char s[][20],int gl){
			for(int i =0;i<gl;i++){
				strcpy(allwords[i],s[i]);
			}
//			*allwords=*s;
			leftvalue=rightvalue=0;
			global=gl;
		}
		
		// Show words
		void PrintAllWords(){
		    printf("%d Words:\n",global) ;
		    for(int i =0 ;i<global ;i+=1){
		        printf("%s\n",allwords[i]) ;
		    }
		}
		int ActToAll(){
		    int u=0 ;
		    char c='+' ;
		    for(int i=0 ;i<global ;i++){
		        if(strcmp(allwords[i],"+")==0){
		            c='+' ;
		        }
		        if(strcmp(allwords[i],"-")==0){
		            c='-' ;
		        }
		        if(strcmp(allwords[i],"==")==0){
		            leftvalue=u ;
		            u=0 ;
		        }
		        if(!IsDigit(allwords[i][0]))
		            continue ;
		        if(c=='+'){
		            u+=Str2Int(allwords[i]) ;
		            //printf("temp : %d\n",u) ;
		        }else if(c=='-'){
		            u-=Str2Int(allwords[i]) ;
		        }
		    }
		    if(statmode==ISEQUAL){
		        if(u>leftvalue)
		            return 1 ;
		        if(u<leftvalue)
		            return -1 ;
		        if(u==leftvalue)
		            return 0 ;
		    }
		    return u ;
		}
		void calc(){
		    PrintAllWords() ;
		    printf("result : %d\n",ActToAll()) ;
		}
		void CheckPattern(){
		    calc() ;
		}
		void Calc(){
		    printf("result : %d\n",ActToAll()) ;
		    printf("MODE : %d\n",statmode) ;
		}
};
