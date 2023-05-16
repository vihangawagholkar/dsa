#include <iostream>


using namespace std;


class Node{
public:
	Node *lchild;
	Node *rchild;
	int data;

public:
	Node(){}

};

Node *root=NULL;

class Tree{
public:
	Node *insert(Node *p,int key);
	void preorder(Node *p);
};

Node *Tree:: insert(Node *p,int key){
	Node *t;

	if(!p){
		t=new Node;
		t->data=key;
		t->lchild=t->rchild=NULL;
		return t;

	}

	if(key<p->data)
		p->lchild=insert(p->lchild,key);

	else if(key>p->data)
		p->rchild=insert(p->rchild,key);

	return p;
}

void Tree::preorder(Node *p){
	if(p){
		preorder(p->lchild);
		cout<<p->data<<", ";
		preorder(p->rchild);
	}
}

int main(){
	//Your code here
	int n,x;
	cout<<endl<<"Enter the no. of nodes in bst: ";
	cin>>n;

	Tree t;

	int i=0;
	while(i++<n){
		cout<<endl<<"Enter the data of node "<<i<<": ";
		cin>>x;
		root=t.insert(root,x);
	}
	// root=insert(root,30);
	// root=insert(root,25);
	// root=insert(root,25);

	cout<<endl<<"Inorder traversal of nodes: ";
	t.preorder(root);
	return 0;
}