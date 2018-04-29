
#include"stdio.h"
#include"utils.h"
#include"string.h"

class Parser{
	public:

		char s[100];
		char allwords[100][20] ;
		int splitmode;
		int global;
		
		
		Parser(char *ss){
			global=0;
			splitmode=-1;
			strcpy(s,ss);
		}
		
		void Split(){
		    int FirstFlag=-1 ;
		    for(int i=0 ;s[i]!='\0' ;i+=1){
		        if(!IsAllowedWords(s[i],splitmode)){
		            if(FirstFlag!=-1){
		                SplitToAll(s,FirstFlag,i-1) ;
		                if(s[i]==' ')
		                    FirstFlag=-1 ;
		                else
		                    FirstFlag=i ;
		            }
		        }else if(FirstFlag==-1){
		            FirstFlag=i ;
		        }
		        if(s[i+1]=='\0' && FirstFlag!=-1){
		            SplitToAll(s,FirstFlag,i) ;
		        }
		        if(s[i]==' '){
		            splitmode=-1 ;
		        }else splitmode=getmode(s[i]) ;
		    }
		}
		bool IsAllowedWords(char c,int mode){
		    if(c!=' '){
		        if(mode==-1)
		            return true ;
		        if(mode==getmode(c))
		            return true ; 
		    }return false ;
		}
		// Save words and Count words 
		void SplitToAll(char s[],int start,int end){
		    printf("start end %d %d\n",start,end) ;
		    for(int i=0 ;i<end-start+1 ;i++){
		        allwords[global][i]=s[start+i] ;
		    }
		    allwords[global][end-start+1]='\0' ;
		    global+=1 ;
		}

};
