#include"Grammar.h"
#include <iostream>  
using namespace std;
class Grammar{
	public:
		char allwords[100][100] ;
		int leftvalue,rightvalue ;
		int global;
		int statmode,eqmode ;
		map<string, int> mapVarInt;
		map<string,string> mapVarStr;
		Grammar(char s[][100],int gl){
			for(int i =0;i<gl;i++){
				strcpy(allwords[i],s[i]);
			}
			leftvalue=rightvalue=0;
			global=gl;
			statmode=0,eqmode=0;
		}
		
		//Declare new variables
		void Declare(string s,int number,string ss,int type){
			if(type==STR){
				mapVarStr[s]=ss;
//			    map<string, string>::iterator iter;  
//			    for(iter = mapVarStr.begin(); iter != mapVarStr.end(); iter++)  
//			        cout<<iter->first<<' '<<iter->second<<endl;  
			}
			if(type==INT){
				mapVarInt[s]=number;
//			    map<string, int>::iterator iter;  
//			    for(iter = mapVarInt.begin(); iter != mapVarInt.end(); iter++)  
//			        cout<<iter->first<<' '<<iter->second<<endl;  
			}
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
		        
		        if(strcmp(allwords[i],">")==0){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=1;
		        }
		        if(strcmp(allwords[i],">=")==0){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=2;
		        }
		        if(strcmp(allwords[i],"<")==0){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=3;
		        }
		        if(strcmp(allwords[i],"<=")==0){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=4;
		        }
		        if(strcmp(allwords[i],"==")==0){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=5;
		        }
		        if(strcmp(allwords[i],"=")==0){
		        	statmode=SETVALUE;
		        	
		        }		        
		        		       
		        if(!IsDigit(allwords[i][0])){
					continue;
				}
		        if(c=='+'){
		            u+=Str2Int(allwords[i]) ;
		        }else if(c=='-'){
		            u-=Str2Int(allwords[i]) ;
		        }
		    }
		    if(statmode==ISEQUAL){
		    	if(eqmode==1){
			        if(leftvalue>u)
			            return 1 ;
			        return -1 ;	    		
				}
		    	if(eqmode==2){
			        if(leftvalue>=u)
			            return 1 ;
			        return -1 ;	    		
				}
				if(eqmode==3){
			        if(leftvalue<u)
			            return 1 ;
			        return -1 ;	    		
				}
				if(eqmode==4){
			        if(leftvalue<=u)
			            return 1 ;
			        return -1 ;    		
				}
				if(eqmode==5){
			        if(u==leftvalue)
			            return 1 ;
					return -1;		    		
				}		    
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
