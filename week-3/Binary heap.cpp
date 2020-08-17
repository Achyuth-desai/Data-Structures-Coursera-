#include<iostream>
#include<stdlib.h>
#include<limits>
using namespace std;

class BinaryHeap {

public:
	int maxSize = 15;
	int size = 0;
	int heap[15];

	void output(){
		for(int i=1;i<=size;i++){
			cout<<heap[i]<<" ";
		}
		cout<<endl;
	}

	void Insert(int value){
		if(size==maxSize){
			cout<<"Overflow";
			exit(0);
		}
		heap[++size]=value;
		shiftup(size);
	}

	void shiftup(int pos){
		int i=pos,temp;
		while((i>1)&&(heap[i]>heap[i/2])){
			temp=heap[i];
			heap[i]=heap[i/2];
			heap[i/2]=temp;
			i/=2;
		}
	}

	void shiftdown(int pos){
		int temp,swp=pos,l=2*pos,r=2*pos+1;
		if(l<=size&&r<=size){
			if(heap[pos]<heap[l]||heap[pos]<heap[r])
				if(heap[l]>=heap[r])
					swp=l;
				else
					swp=r;

			if(swp!=pos){
				temp=heap[swp];
				heap[swp]=heap[pos];
				heap[pos]=temp;
				shiftdown(swp);
			}
		}
	}
	int GetMax(){
			return heap[1];
	}
	void ExtractMax(){
		heap[1]=heap[size];
		heap[size]=0;
		size--;
		shiftdown(1);
	}

	void ChangePriority(){
		int pos,oldP,newP;
		cout<<"ENTER THE POSITION : ";
		cin>>pos;
		cout<<"ENTER THE NEW PRIORITY : ";
		cin>>newP;
		oldP = heap[pos];
		heap[pos]=newP;
		if(newP>oldP)
			shiftup(pos);
		if(oldP>newP)
			shiftdown(pos);
	}

	void Remove(){
		int pos;
		cout<<"ENTER THE POSITION OF THE ELEMENT TO BE REMOVED : ";
		cin>>pos;
		heap[pos] = numeric_limits<int>::max();
		shiftup(pos);
		ExtractMax();
	}

};
BinaryHeap B;

int main(){
	int n,value,choice;
	cout<<"ENTER NO OF ENTRIES : ";
	cin>>n;
	cout<<"ENTER THE VALUES OF THE STACK : ";
	for(int i=1;i<=n;i++){
		cin>>value; 	
		B.Insert(value);
	}
	cout<<"HEAP : ";
	B.output();
	cout<<"\nENTER OPERATION : \n";
	cout<<"1.Insert\n2.Get Max\n3.Extract Max\n4.Change Priority\n5.Remove Element"<<endl;
	cin>>choice;
	switch(choice){
		case 1: cout<<"ENTER THE VALUE : ";
				cin>>value;
				B.Insert(value);
				break;
		case 2: cout<<"MAX VALUE : "<<B.GetMax()<<endl;
				break;

		case 3: cout<<"MAX VALUE : "<<B.GetMax()<<endl;
				B.ExtractMax();
				break;
		case 4: B.ChangePriority();
				break;
		case 5: B.Remove();
				break;
		default : 
				cout<<"Invalid choice";
				exit(0);
				break;
	}
	cout<<"HEAP : ";
	B.output();
	return 0;
}