#include <iostream>
#include "tree.h"

using namespace std;

// Node *root=NULL;
// void Tcreate(){
// 	Node *p,*t;
// 	int x;
// 	Queue q(100);
	

// 	cout<<"Enter the root value: ";
// 	cin>>x;
// 	Node *root=new Node;
// 	root->data=x;
// 	root->lchild=root->rchild=NULL;
// 	q.enqueue(root);

// 	while(!q.isEmpty()){
// 		p=q.dequeue();
// 		cout<<endl<<"Enter the left child: ";
// 		cin>>x;
// 		if(x!=1){
// 			t=new Node;
// 			t->data=x;
// 			t->lchild=t->rchild=NULL;
// 			p->lchild=t;
// 			q.enqueue(t);
// 		}

// 		cout<<endl<<"Enter the right child: ";
// 		cin>>x;
// 		if(x!=-1){
// 			t=new Node;
// 			t->data=x;
// 			t->lchild=t->rchild=NULL;
// 			p->rchild=t;
// 			q.enqueue(t);
// 		}

// 	}

// }

Node* root = new Node;
 
void createTree(){
    Node* p;
    Node* t;
    int x;
    Queue q(10);
 
    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.dequeue();
 
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
 
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
 
void preorder(Node *p){
	if(p){
		cout<<p->data<<" "<<flush;
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
int main(){
	//Your code here
	createTree();
	preorder(root);
	return 0;
}