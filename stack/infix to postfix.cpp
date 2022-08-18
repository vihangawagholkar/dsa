#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

class stack:public Node{
	Node *top;
public:
	stack(){

		top=NULL;
	}

	void push(char x){

		if(top==NULL){
			top=new Node;
			top->data=x;
			top->next=NULL;
			
		}
		else{
			Node *p=new Node;
			p->data=x;
			p->next=top;
			top=p;
		}
		
	}

	char pop(){
		Node *p=top;
		int x=-1;
		if(top==NULL){
			
		}
		else{
			top=top->next;
			x=p->data;
			delete p;
			
		}
		return x;
	}

	int stackTop(){
		if(top)
			return top->data;
		
			return 0;
	}

	int isEmpty(){
		return top?0:1;
	}
};
int isOperand(char x){
	if(x=='+'||x=='-'||x=='*'||x=='/')
		return 0;
	else
		return 1;

}

int precedence(char x){
	if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
	return 0;
}

//a+b*c-d/e
char * postfix(char exp[]){
	stack s1;
	char *postfix=new char[strlen(exp)+1];
	int i=0,j=0;
	while(exp[i]!='\0'){
		if(isOperand(exp[i])){
			postfix[j++]=exp[i++];
		}
		else{
			if(precedence(exp[i])>precedence(s1.stackTop())){
				s1.push(exp[i++]);
			}
			else{
				postfix[j++]=s1.pop();
				
			}
		}

	}
	while(!s1.isEmpty()){
		postfix[j++]=s1.pop();
	}
	postfix[j]='\0';
	return postfix;
}


int main(){
	//Your code here
	const int size=1000;
	char exp[]="";
	cout<<endl<<"Enter your expression: ";

	cin.getline(exp,size);

	char *res=postfix(exp);
	cout<<endl<<"Your postfix expression is: ";
	int i=0;
	while(res[i]!='\0'){
		cout<<res[i++];
	}
	return 0;
}