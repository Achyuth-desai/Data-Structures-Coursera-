#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int pop(long unsigned int stk[],long unsigned int &endof_stack);
int max(long unsigned int stk[],long unsigned int &endof_stack);
int push(long unsigned int value,long unsigned int stk[],long unsigned int &endof_stack);

int main(){
	long unsigned int n,stk[400000],endof_stack=0,value;
	char query[400000][6];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>query[i];
		if(strcmp(query[i],"push")==0){
			cin>>value;
			push(value,stk,endof_stack);
		}
	}
	for(long unsigned int i=0;i<n;i++){
		if(strcmp(query[i],"pop")==0)
			pop(stk,endof_stack);
		if(strcmp(query[i],"max")==0)
			max(stk,endof_stack);
	}
}

int push(long unsigned int value,long unsigned int stk[],long unsigned int &endof_stack){
	stk[endof_stack]=value;
	endof_stack++;
	return 0;
}
int pop(long unsigned int stk[],long unsigned int &endof_stack){
	stk[--endof_stack]=0;
	return 0;
}
int max(long unsigned int stk[],long unsigned int &endof_stack){
	long unsigned int maxx=stk[0];
	for(long unsigned int i=0;i<=endof_stack;i++){
		if(maxx<stk[i])
			maxx=stk[i];
	}
	cout<<maxx<<endl;
	return 0;
}
