#include <iostream>
#include <vector>
using namespace std;

int main(){
	long int n,m,max;
	cin>>n;
	std::vector<long int> v(n);
	for(long int i=0;i<n;i++){
		cin>>v.at(i);
	}
	cin>>m;
	for(long int i=0;(i+m)<=v.size();i++){
		max=v.at(i);
		for(long int j=i;j<i+m;j++){
			if(v.at(j)>max)
				max=v.at(j);
		}
		cout<<max<<" ";
	}
	return 0;
}