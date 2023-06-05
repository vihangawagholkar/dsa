#include <iostream>
#include <cstring>
using namespace std;


class queue{
int size,front,rear;
int *Q;

public:
	queue(){
		cout<<endl<<"Enter the size of the queue: ";
		cin>>size;
		Q=new int[size];
		front=rear=-1;
	}

	int isEmpty(){
		return front==rear?1:0;
	}

	int isFull(){
		return rear==size-1?1:0;
	}

	void enqueue(int x){
		if(isFull()){
			cout<<endl<<"Queue is Full";
		}
		else{
			Q[++rear]=x;
		}
	}

	int dequeue(){
		int x=-1;
		if(isEmpty()){
			cout<<"Empty queue, nothing to delete.";
		}
		else{
			x=Q[++front];
			cout<<endl<<"Element is deleted.";
		}
		return x;
	}

	void display(){
		cout<<endl<<"The elements are: ";
		int i=front;
		while(i++!=rear){
			cout<<Q[i]<<" ";
		}
	}
	

};
int main(){
	//Your code here
	char s[]="y";
	int c;
	queue q;
	while(s[0]=='y'||'Y'){
		cout<<endl<<"1. Insert";
		cout<<endl<<"2. Delete";
		cout<<endl<<"3. display";
		cout<<endl<<"Enter your choice: ";
		cin>>c;
		switch(c){
			case 1:{
				int x;
				cout<<endl<<"Enter the element to insert: ";
				cin>>x;
				q.enqueue(x);
				q.display();
			}break;

			case 2:{
				q.dequeue();
				q.display();
			}break;

			case 3:{
				q.display();
			}break;

			default:{
				cout<<endl<<"Invalid choice. Please try again.";
				s[0]='y';
			}

		cout<<endl<<"Do you want to continue (y/n)?";
		}
	}
	return 0;
}