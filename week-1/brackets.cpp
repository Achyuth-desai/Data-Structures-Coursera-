#include<iostream>
#include<string.h>

using namespace std;

int compare(char S[]);

int main(){
	char S[100000];
	int n;
	cin>>S;
	n=compare(S);
	if(n==-1){
		cout<<"Success"<<endl;
		exit(0);
	}
	cout<<n<<endl;
}

int compare(char S[]){
	char n[100000];
	int i=0,j=0;
	long int l[100000];
	while(S[j]!='\0'){
		if(S[j]=='{'||S[j]=='('||S[j]=='['){
			n[i]=S[j];
			l[i]=j+1;
			i++;
		}
		if(S[j]=='}'||S[j]==')'||S[j]==']'){
			if(S[j]=='}'){
                		if(n[i-1]=='{'){
                    			n[i-1]='\0';
					l[i-1]=0;
                    			i--;
                			}
                		else{
                    			return j+1;
                		}
            		}
            		if(S[j]==']'){
                		if(n[i-1]=='['){
                    			n[i-1]='\0';
					l[i-1]=0;
                    			i--;
                		}
                		else{
                    			return j+1;
                		}
            		}
            		if(S[j]==')'){
                		if(n[i-1]=='('){
                    			n[i-1]='\0';
					l[i-1]=0;
                    			i--;
                		}
                		else{
                    			return j+1;
                		}	
            		}	
		}
		j++;
	}
	if(l[0]!=0){
		return l[0];
	}
	return -1;
}
