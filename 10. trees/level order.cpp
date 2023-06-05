#include <iostream>
#include "queue.h"
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

void levelorder(Node *p){
	Queue q(1000);
	cout<<p->data<<" "<<flush;
	q.enqueue(p);
	while(!q.isEmpty()){
		p=q.dequeue();
		if(p->lchild){
			cout<<p->lchild->data<<" ";
			q.enqueue(p->lchild);
		}
		if(p->rchild){
			cout<<p->rchild->data<<" ";
			q.enqueue(p->rchild);
		}
	}
}
int main(){
	//Your code here
	createTree();
	levelorder(root);
	return 0;
}