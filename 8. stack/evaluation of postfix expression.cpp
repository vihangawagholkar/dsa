#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};
//template <class T>
class stack:public Node{
	Node *top;
public:
	stack(){
		top=NULL;
	}

	void push(char x){
		if(top){
			Node *p=new Node;
			p->data=x;
			p->next=top;
			top=p;
		}
		else{
			top=new Node;
			top->data=x;
			top->next=NULL;
		}
	}

	int pop(){
		int x=-1;
		if(top){
			Node *p=top;
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
	if(x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')'||x=='^')
		return 0;
	else
		return 1;
}

// int outstackprecedence(char x){
// 	if(x=='+'||x=='-')
// 		return 1;
// 	else if(x=='*'||x=='/')
// 		return 3;
// 	else if(x=='^')
// 		return 6;
// 	else if(x=='(')
// 		return 7;
// 	else if(x==')')
// 		return 0;
// 	return -1;
// }

// int instackprecedence(char x){
// 	if(x=='+'||x=='-')
// 		return 2;
// 	else if(x=='*'||x=='/')
// 		return 4;
// 	else if(x=='^')
// 		return 5;
// 	else if(x=='(')
// 		return 0;

// 	return -1;
	
// }

// //((a+b)*c)-d^e^f
// char *postfix(char exp[]){
// 	stack s1;
// 	char *res=new char[strlen(exp)+1];
// 	int i=0,j=0;
// 	while(exp[i]!='\0'){
// 		if(isOperand(exp[i]))
// 			res[j++]=exp[i++];
// 		else{
			
// 			if(s1.isEmpty()||outstackprecedence(exp[i])>instackprecedence(s1.stackTop())){
// 				s1.push(exp[i++]);
// 			}
// 			else if(outstackprecedence(exp[i])==instackprecedence(s1.stackTop())){
// 				s1.pop();
// 				i++;
// 			}
// 			else{
// 				res[j++]=s1.pop();

// 			}
// 		}
// 	}
// 	while(!s1.isEmpty()){
// 		res[j++]=s1.pop();
// 	}
// 	res[i]='\0';
// 	return res;
// }
int eval(char postfix[]){
	
	stack s2;
	int x,y,r,result;
	char op;
	int i=0;
	while(postfix[i]!='\0'){
		if(isOperand(postfix[i])){
			s2.push(postfix[i++]-'0');
		}
		else{
			
			y=s2.pop();
			x=s2.pop();
			switch(postfix[i]){
				case '+':{
					r=y+x;
					
					s2.push(r);
				}break;
				case '-':{
					r=x-y;
					
					s2.push(r);
				}break;
				case '*':{
					r=x*y;
					
					s2.push(r);
				}break;
				case '/':{
					r=x/y;
					
					s2.push(r);
				}break;
				

			}
			
			i++;
		}
	}

	result= s2.pop();
	return result;

}
int main(){
	//Your code here
	const int size=1000;
	// char E[]="";
	// cout<<endl<<"Enter your expression: ";
	// cin.getline(E,size);
	// char *res=postfix(E);
	// int i=0;
	// cout<<"Postfix expression: ";
	// while(res[i]!='\0'){
	// 	cout<<res[i++];
	// }

	char res[]="234*+82/-";
	cout<<endl<<"The result is: "<<eval(res);
	
	return 0;
}