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
	Node *Delete(Node *p, int key);
	void preorder(Node *p);
	int Height(Node *p);

	Node *Inpre(Node *p);
	Node *Insucc(Node *p);
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

int Tree::Height(Node *p){
	int x,y;
	if(p){
		x=Height(p->lchild);
		y=Height(p->rchild);

		return x>y?x+1:y+1;
	}

	else
		return 0;
}

Node *Tree::Inpre(Node *p){
	while(p && p->rchild!=NULL)
		p=p->rchild;

	return p;
}

Node *Tree::Insucc(Node *p){
	while(p && p->lchild!=NULL)
		p=p->lchild;

	return p;
}

Node* Tree::Delete(Node *p, int key){

	Node *q;

	if(p==NULL)
		return NULL;

	if(p->rchild==NULL&&p->lchild==NULL){
		if(p==root)
			root=NULL;
		free(p);

		return NULL;
	}

	// return p;

	if(key<p->data){
		p->lchild=Delete(p->lchild,key);
	}

	else if(key>p->data)
		p->rchild=Delete(p->rchild,key);

	else{
		if(Height(p->lchild)>Height(p->rchild)){
			q=Inpre(p->lchild);
			p->data=q->data;
			p->lchild=Delete(p->lchild,q->data);

		}
		else{
			q=Insucc(p->rchild);
			p->data=q->data;
			p->rchild=Delete(p->rchild,q->data);
		}
	}

	return p;
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

	// To check valdity of bst
	t.preorder(root);

	cout<<endl<<"Enter the element you want to delete: ";
	cin>>x;
	t.Delete(root,x);

	cout<<endl<<"Inorder traversal of nodes: ";

	// To check valdity of bst
	t.preorder(root);
	return 0;
}