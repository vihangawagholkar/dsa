#include <iostream>
#include <string.h>
using namespace std;

class stack{
	int size;
	int top;
	int *A;

public: 
	stack(){
		cout<<endl<<"Enter the size of stack: ";
		cin>>size;
		A=new int[size];
		top=-1;
		

	}

	void display(){
		int i=0;
		cout<<endl<<"The elements are: ";
		while(i<=top){
			cout<<A[i++]<<" ";
		}
	}

	void push(int x){

		if(top==size-1)
			cout<<endl<<"Stack Overflow";

		else{
			top=top+1;
			A[top]=x;
		}
	}

	int pop(){
		int x=-1;
		
		if(top<=-1)
			cout<<endl<<"Stack Underflow";

		else{
			x=A[top];
			
			top--;
		}
		return x;

	}

	int peek(int pos){
		int x=-1;
		if(top-pos+1<0){
					cout<<endl<<"Invalid pointer";}
		else{
					x=A[top-pos+1];}

		return x;
	}

	int stackTop(){
		if(top==-1)
			return -1;

		else
			return A[top];
	}

	int isEmpty(){
		if(top==-1)
			return 1;

		else
			return 0;
	}

	int isFull(){
		if(top==size-1)
			return 1;
		else
			return 0;
	} 
};


int main(){
	//Your code here
	stack s1;
	
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