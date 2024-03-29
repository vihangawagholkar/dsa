#include <iostream>
#include <queue>


using namespace std;

class Node{
public:
	int data;
	Node *lchild;
	Node *rchild;

	Node(){};
	Node(int data);
};

Node::Node(int data){
	this->data=data;
	lchild=NULL;
	rchild=NULL;
}


Node *root;

class Tree{

	public:
		Tree();
		void createTree();
		void preorder(Node *p);
		int count(Node *p);
		int height(Node *p);

};


Tree::Tree(){
	root=NULL;
}
void Tree::  createTree(){
	Node *p;
	Node *t;
	root=new Node;
	queue<Node*> q;
	int x;

	cout<<endl<<"Enter the root value: ";
	cin>>x;
	root->data=x;
	root->lchild=NULL;
	root->rchild=NULL;

	if(x!=-1)
		q.emplace(root);

	while(!q.empty()){
		p=q.front();
		q.pop();

		cout<<endl<<"Enter the value of left child of "<<p->data<<" : ";
		cin>>x;

		if(x!=-1){
			t=new Node;
			t->lchild=NULL;
			t->rchild=NULL;
			p->lchild=t;
			t->data=x;
			q.emplace(t);

		}


		cout<<endl<<"Enter the value of right child of "<<p->data<<" : ";
		cin>>x;

		if(x!=-1){
			t=new Node;
			t->lchild=NULL;
			t->rchild=NULL;
			p->rchild=t;
			t->data=x;
			q.emplace(t);

		}
	}

} 

void Tree:: preorder(Node *p){
	
	if(p){
		cout<<p->data<<", ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

//count fn. is done is postorder form

// NOTE!!
// Mostly postorder is used in binary tree

int Tree:: count(Node *p){
	
	int x,y;
	if(p){
		x=count(p->lchild);
		y=count(p->rchild);

		return x+y+1;

	}

	return 0;
}

int Tree:: height(Node *p){
	int x=0,y=0;
	if(p==0)
		return 0;

	x=height(p->lchild);
	y=height(p->rchild);

	if(x>y)
		return x+1;
	else
		return y+1;

}
int main(){
	//Your code here

	Tree t;
	t.createTree();
	t.preorder(root);
	cout<<endl<<"No. of Nodes in Tree: "<<t.count(root);
	cout<<endl<<"Height of Tree: "<<t.height(root);
	return 0;
}