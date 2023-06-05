#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

class queue:public Node{
Node *front,*rear;
int n;
public:
	queue(){

		front=new Node;
		cout<<endl<<"Enter the length of queue: ";
		cin>>n;
		rear=front;
		rear->next=NULL;
		cout<<endl<<"Enter the elements in your queue: ";
		if(n>0){
			cin>>front->data;
			int i=1;
			
			Node *p;
			while(i++<n){
				p=new Node;
				cin>>p->data;
				rear->next=p;
				rear=p;

			}
		}
		rear->next=NULL;

	}

	void enqueue(int x){
		Node *t=new Node;
		if(t==NULL){
			cout<<endl<<"Queue is full";
		}

		else{
			t->data=x;
			t->next=NULL;
			if(front==NULL){
				front=rear=t;
			}
			else{
				rear->next=t;
				rear=t;

			}
		}
	}

	int dequeue(){
		int x=-1;

		if(front){
				Node *p=front;
				front=front->next;
				x=p->data;
				delete p;
			}

		else{
			cout<<endl<<"Queue is empty.";
		}

		return x;
	}


	void display(){
		Node *p=front;
		cout<<endl<<"The elements are: ";
		while(p){
			cout<<p->data<<" ";
			p=p->next;
		}
	}
};
int main(){
	//Your code here
	

	char s[]="y";
	int c;
	queue q;
	q.display();
	while(s[0]=='y'||s[0]=='Y'){
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
				
			
			}

		}
			cout<<endl<<"Do you want to continue (y/n)?";
			cin.ignore();
			//gets(s);
			cin.getline(s,20);
	}
	return 0;
}