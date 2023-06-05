#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node *next;
};

class Stack:public Node{
	Node *top;
	int size,length;
public:
	Stack(){
		top=NULL;
		cout<<endl<<"Enter the size of stack: ";
		cin>>size;
		length=0;
	}

	void push(int x){
		Node *t=new Node;
		if(length==size)
			cout<<endl<<"Stack Overflow";
		else{
			if(top){
				t->data=x;
				t->next=top;
				top=t;
				length++;
			}
			else{
				top=new Node;
				top->data=x;
				length++;
			}
		}

	}

	int pop(){
		Node *p;
		int x=-1;
		if(top==NULL)
			cout<<endl<<"Stack Underflow";

		else{
			p=top;
			top=top->next;
			x=p->data;
			length--;
			delete p;
		}
		return x;
	}

	int peek(int pos){
		
		Node *p=top;
		for(int i=0;i<pos-1&&p;i++)
			p=p->next;
		
		if(p)
			return p->data;

		else
			return -1;
	}

	int stackTop(){
		if(top)
			return top->data;
		return -1;
	}

	int isEmpty(){
		return top?0:1;
	}

	int isFull(){
		return length==size?1:0;
	}

	void display(){
		Node *p=top;
		cout<<endl<<"The elements are: ";
		while(p){
			cout<<p->data<<" ";
			p=p->next;
		}

	}
};
int main(){
	//Your code here
	Stack s1;

	char s[]="y";
	while(s[0]=='y'||s[0]=='Y'){
		cout<<endl<<"1. Push";
		cout<<endl<<"2. Pop";
		cout<<endl<<"3. Peek";
		cout<<endl<<"4. Check if empty.";
		cout<<endl<<"5. Check if full";
		cout<<endl<<"6. Stack top";
		cout<<endl<<"7. display";
		cout<<endl<<"Enter your choice: ";
		int c;
		cin>>c;
		switch(c){
			case 1:{
				cout<<endl<<"Enter the element to push: ";
				int x;
				cin>>x;
				s1.push(x);
				s1.display();
			}
			break;
	
			case 2:{
				int c=s1.pop();
				if(c!=-1){
					
				
					cout<<endl<<"Element is popped! ";
					cout<<endl<<"Element popped is: "<<c;
				}
				s1.display();
			}
			break;
	
			case 3:{
				cout<<endl<<"Enter the index to peek at: ";
				int pos;
				cin>>pos;
				if(s1.peek(pos)==-1)
					cout<<endl<<"Nothing to peek in your stack: ";
				else
					cout<<endl<<"The element at given position is: "<<s1.peek(pos);
				s1.display();
			}
			break;
	
			case 4:{
				if(s1.isEmpty()){
					cout<<endl<<"The stack is empty.";
				}
				else
					cout<<endl<<"The stack is not empty.";
				s1.display();
			}
			break;
	
			case 5:{
				if(s1.isFull())
					cout<<endl<<"The stack is Full.";
				else
					cout<<endl<<"The stack is not full.";
				s1.display();
			}
			break;
	
			case 6:{
				if(s1.stackTop()==-1)
					cout<<endl<<"The stack is empty.";
				else
					cout<<endl<<"The top element is: "<<s1.stackTop();
				s1.display();
			}
			break;
		
			case 7:{
				s1.display();
			}break;
			default:{
				cout<<endl<<"Invalid choice! Please try again...";
			}
		}
		cout<<endl<<"Do you want to continue (y/n)?: ";
		cin.getline(s,100);
		gets(s);
	}
	cout<<endl<<"Thank you for using my stack.";
	return 0;
}