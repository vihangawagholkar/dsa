#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *lchild,*rchild;
	int height;

}*root=NULL;

int NodeHeight(Node *p){
	int hl,hr;

	hl=p && p->lchild ? p->lchild->height:0;
	hr=p && p->rchild ? p->rchild->height:0;

	return hl>hr ? hl+1:hr+1;
}

int BalanceFactor(Node *p){
	int hl,hr;

	hl=p && p->lchild ? p->lchild->height:0;
	hr=p && p->rchild ? p->rchild->height:0;

	return hl-hr;
}

Node *LLRotation(Node *p){
	Node *pl=p->lchild;
	Node *plr=pl->rchild;

	pl->rchild=p;
	p->lchild=plr;
	p->height=NodeHeight(p);
	pl->height=NodeHeight(pl);

	if(root==p)
		root=pl;

	return pl;
}

Node *RRRotation(Node *p){
	
	Node *pr=p->rchild;
	Node *prl=pr->lchild;

	pr->lchild=p;
	p->rchild=prl;
	p->height=NodeHeight(p);
	pr->height=NodeHeight(pr);

	if(root==p)
		root=pr;

	return pr;
}

Node *LRRotation(Node *p){

	Node *pl=p->lchild;
	Node *pr=p->rchild;
	Node *prl=pr->lchild;
	Node *plr=pl->rchild;

	pl->rchild=plr->rchild;
	pr->lchild=plr->lchild;
	plr->lchild=pl;
	plr->rchild=pr;

	p->height=NodeHeight(p);
	pl->height=NodeHeight(pl);
	plr->height=NodeHeight(plr);

	if(root==p)
		root=prl;

	return plr;


}

Node *RLRotation(Node *p){

	Node *pl=p->lchild;
	Node *pr=p->rchild;
	Node *prl=pr->lchild;
	Node *plr=pl->rchild;

	pl->rchild=prl->rchild;
	pr->lchild=prl->lchild;
	prl->lchild=pl;
	prl->rchild=pr;

	p->height=NodeHeight(p);
	pr->height=NodeHeight(pr);
	prl->height=NodeHeight(prl);

	if(root==p)
		root=prl;

	return prl;


}
Node *RInsert(Node *p, int key){
	Node *t;

	if(!p){
		t=new Node;
		t->data=key;
		t->height=1;
		t->lchild=t->rchild=NULL;
		return t;
	}

	if(key<p->data)
		p->lchild=RInsert(p->lchild,key);

	else if(key>p->data)
		p->rchild=RInsert(p->rchild,key);

	p->height=NodeHeight(p);

	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
		return LLRotation(p);

	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
		return RRRotation(p);

	else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
		return LRRotation(p);

	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
		return RLRotation(p);

	return p;
}

Node* InPre(Node *p){
	while(p && p->rchild)
		p=p->rchild;

	return p;
}


Node* InSucc(Node *p){
	while(p && p->lchild)
		p=p->lchild;

	return p;
}

Node *Delete(Node *p, int key){
	Node *q;

	if(p==NULL)
		return NULL;

	if(p->rchild==NULL && p->lchild==NULL){
		if(p==root)
			root=NULL;

		free(p);

		return NULL;
	}

	if(key<p->data)
		p->lchild=Delete(p->lchild,key);

	else if(key>p->data)
		p->rchild=Delete(p->rchild,key);

	else{
		if(NodeHeight(p->lchild)>NodeHeight(p->rchild)){
			q=InPre(p->lchild);
			p->data=q->data;
			p->lchild=Delete(p->lchild,q->data);
		}
		else{
			q=InSucc(p->rchild);
			p->data=q->data;
			p->rchild=Delete(p->rchild,q->data);
		}
	}

	p->height=NodeHeight(p);

	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
		return LLRotation(p);

	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
		return RRRotation(p);

	else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
		return LRRotation(p);

	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
		return RLRotation(p);

	return p;
}

void Inorder(Node *p){
	if(p){
		Inorder(p->lchild);
		cout<<p->data<<", ";
		Inorder(p->rchild);
	}
}
int main(){
	//Your code here
	
	root=RInsert(root,10);
	RInsert(root,20);
	RInsert(root,30);

	RInsert(root,40);
	Delete(root,40);
	RInsert(root,50);
	RInsert(root,100);
	Delete(root,100);
	Delete(root,20);
	RInsert(root,60);
	RInsert(root,30);

	RInsert(root,40);
	Delete(root,40);
	RInsert(root,120);
	RInsert(root,609);
	// Delete(root,100);
	// Delete(root,20);
	Inorder(root);
	return 0;
}