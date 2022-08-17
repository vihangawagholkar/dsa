#include <iostream>
#include <cstring>
using namespace std;
 
class Node{
public:
    char data;
    Node* next;
};
 
class Stack{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(char x);
    char pop();
   
    int isEmpty();
    
   
};
 
Stack::Stack() {
    top = nullptr;
}
 
Stack::~Stack() {
    Node* p = top;
    while (top){
        top = top->next;
        delete p;
        p = top;
    }
}
 
void Stack::push(char x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}
 
char Stack::pop() {
    Node* p;
    char x = -1;
    if (top == nullptr){
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}
 

int Stack::isEmpty() {
    return top ? 0 : 1;
}
 

int isBalanced(char* exp){
    Stack stk;
    char x;
    for (int i=0; exp[i]!='\0'; i++){
        if (exp[i] == '('||exp[i] == '{'||exp[i] == '['){
            stk.push(exp[i]);
        } else if (exp[i] == ')'||exp[i] == '}'||exp[i] == ']'){
            
            if (stk.isEmpty()){
                return false;
            } 

            else{
                x=stk.pop();

                if(exp[i]-x==1)
                    continue;
                
                else
                    return false;
                
            }
        }
    }
    return stk.isEmpty() ? true : false;
}
 
 
int main() {
 	const int size=1000;
    char E[] = "";
    cout<<endl<<"Enter the equation: ";
    cin.getline(E,size);
    if(isBalanced(E))
    	cout<<endl<<"Parentheses Matching";
    else
    	cout<<endl<<"Parenthesis not Matching";
 
    return 0;
 
}