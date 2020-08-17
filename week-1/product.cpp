#include<iostream>
int main(){
	long long n,a[1000000],temp;
	std::cin>>n;
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	for(int i=0;i<2;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}	
	}
	temp=a[0]*a[1];
	std::cout<<temp;
	return 0;
}
