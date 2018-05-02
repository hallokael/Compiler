#include"stdio.h"
#include"utils.h"
#include"string.h"

class Parser{
	public:

		char s[500]; //origin statement
		char allwords[100][100] ; //words after split 
		int splitmode; //mode of last char
		int global; //quantity of words
		
		Parser(char *ss){
			global=0;
			splitmode=-1;
			strcpy_s(s,ss);
		}
		
		void Split(){
		    int FirstFlag=-1 ;   // start position of word
			int Deep = 0;        // deep of bracket
		    for(int i=0 ;s[i]!='\0' ;i+=1){
		    	if(s[i]=='\"'){  //special for string
		    		if(splitmode!=4){
						//split the last when enter string mode
						if (FirstFlag != -1) {
							SplitToAll(s, FirstFlag, i-1);
						}
						//string mode
		    			splitmode=4;
		    			FirstFlag=i;
					}else{
						SplitToAll(s,FirstFlag,i);
						splitmode=-1;
						FirstFlag=-1;
						continue;
					}
				}
				if (s[i] == '(') { //special for bracket
					if (splitmode != 5) {
						//split the last when enter bracket mode
						if (FirstFlag != -1) {
							SplitToAll(s, FirstFlag, i - 1);
						}
						//bracket mode
						splitmode = 5;
						FirstFlag = i;
						Deep = 1;
					}
					else {
						Deep++;
					}
				}
				if (s[i] == ')') { //special for bracket
					if (splitmode != 5) {
						cout << "ERROR \')\'" << endl;
					}
					else {
						Deep--;
						if (Deep == 0) {
							SplitToAll(s, FirstFlag, i);
							splitmode = -1;
							FirstFlag = -1;
						}
					}
				}
				if(splitmode==4 || splitmode==5){
					continue;
				}
		        if(!IsAllowedWords(s[i],splitmode)){   //  enter if c==' ' or char's mode is different from the last one
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
