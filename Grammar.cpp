#include"Grammar.h"

using namespace std;
class Grammar{
	public:
		string Ss[100] ;
		int leftvalue,rightvalue ;
		int global;
		int statmode,eqmode ;
		Variables v;
		string ERROR;



		Grammar(char s[][100],int gl,Variables vv){
			for(int i =0;i<gl;i++){
				Ss[i] = s[i];
				cout << Ss[i] << " StringTrans" << endl;
			}
			leftvalue=rightvalue=0;
			global=gl;
			statmode=0,eqmode=0;
			v = vv;
		}
		// Show words
		void PrintAllWords(){
		    printf("%d Words:\n",global) ;
		    for(int i =0 ;i<global ;i+=1){
				cout << Ss[i] << endl;
		    }
		}
		int ActToAll(){
		    int u=0 ;
		    char c='+' ;

		    for(int i=0 ;i<global ;i++){
				string s = Ss[i];
		        if(s=="+"){
		            c='+' ;
		        }
		        if(s=="-"){
		            c='-' ;
		        }
		        if(s==">"){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=1;
		        }
		        if(s==">="){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=2;
		        }
		        if(s=="<"){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=3;
		        }
		        if(s=="<="){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=4;
		        }
		        if(s=="=="){
		            leftvalue=u ;
		            u=0 ;
		            statmode=ISEQUAL;
		            eqmode=5;
		        }
		        if(s=="="){
		        	statmode=SETVALUE;
		        }
		        		       
		        if(!IsDigit(s[0])){
					if (v.IsExist(s)) {

					}
					continue;
				}
		        if(c=='+'){
		            u+=Str2Int(s) ;
		        }else if(c=='-'){
		            u-=Str2Int(s) ;
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
		    if(statmode==SETVALUE){
				//if()
		    	v.AddVariable(Ss[0],Str2Int(Ss[2]),"",INT);
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
		Vari GetResult(int start, int end) {
			Vari v(0,"",INT);
			for (int i = start; i <= end; i++) {

			}
		}
		void Calc(){
		    printf("result : %d\n",ActToAll()) ;
		    printf("MODE : %d\n",statmode) ;
		}
};
