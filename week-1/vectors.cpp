#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,temp;
	vector <int> num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		num.push_back(temp);
	}
	cout<<"CONTENTS OF THE VECTOR : ";
	for( auto i=num.begin();i!=num.end();i++){
		cout<<*i<<"	"<<endl;
	}
	return 0;
}
