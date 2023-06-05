#include <iostream>
#include "queue.h"

#include <stack>


using namespace std;

Node *root=new Node;

void createTree(){
	Node *p;
	Node *t;
	int x;
	Queue q(100);

	cout<<endl<<"Enter root value: ";
	cin>>root->data;
	root->lchild=NULL;
	root->rchild=NULL;
	q.enqueue(root);
	while(!q.isEmpty()){
		p=q.dequeue();

		cout<<endl<<"Enter the value of left child "<<p->data<<": "<<flush;
		cin>>x;
		if(x!=-1){
			t=new Node;
			t->data=x;
			t->lchild=NULL;
			t->lchild=NULL;
			p->lchild=t;
			q.enqueue(t);
		}

		cout<<endl<<"Enter the value of right child: "<<p->data<<": "<<flush;
		cin>>x;
		if(x!=-1){
			t=new Node;
			t->data=x;
			t->rchild=NULL;
			t->rchild=NULL;
			p->rchild=t;
			q.enqueue(t);
		}


	}
}

void inorder(Node *p){
	
	stack<Node *> st;
	

	while(p!=NULL || !st.empty())
	{
		if(p!=NULL)
		{
			st.push(p);
			p=p->lchild;
		}
		else
		{
			p = st.top();
			st.pop();
			cout<<p->data<<", "<<flush;
			p = p->rchild;
		}
		
	}
	cout<<endl;
		
}

void preorder(Node *p){
	stack <Node*> st;
	while(p||!st.empty()){
		if(p){
			cout<<p->data<<", "; 
			st.push(p);
			p=p->lchild;
		}
		else{
			p=st.top();
			st.pop();
			p=p->rchild;
		}
	}
	cout<<endl;
}

void postorder(Node *p){
	
	stack<long int> stk;
    long int temp;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.push((long int)p);
            p = p->lchild;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0){
                stk.push(-temp);
                p = ((Node*)temp)->rchild;
            } else {
                cout << ((Node*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}
int main(){
	//Your code here
	createTree();
	cout<<endl<<"Preorder: ";
	preorder(root);
	cout<<endl<<"Inorder: ";
	inorder(root);
	cout<<endl<<"Postorder: ";
	postorder(root);
	return 0;
}