#include <iostream>

using namespace std;


class queue{
public:
	int size,front,rear;
	int *Q;
	queue(){
		cout<<endl<<"Enter the size of queue: ";
		cin>>size;
		
		front=rear=0;
		Q=new int[size];
	}

	void enqueue(int x){
		if((rear+1)%size==front)
			cout<<endl<<"Queue is Full";

		else{
			rear=(rear+1)%size;
			Q[rear]=x;
		}
	}

	int dequeue(){
		int x=-1;
		if(front==rear)
			cout<<endl<<"Queue is Empty";
		else{
			front=(front+1)%size;
			x=Q[front];
		}
		return x;

	}

	void display(){
		cout<<endl<<"The elements are: ";
		int i=front+1;
		if(front!=rear){
				do
				{
					cout<<Q[i]<<" ";
					i=(i+1)%size;
				}
				while(i!=(rear+1)%size);}
				
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
				cout<<endl<<"Element deleted: "<<q.dequeue();
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