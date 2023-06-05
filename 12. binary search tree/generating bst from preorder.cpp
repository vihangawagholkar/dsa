#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Node{
public:

	int data;
	Node *lchild;
	Node *rchild;

	// Node(){};

	// Node(int data){
	// 	this->data=data;
	// 	lchild=rchild=NULL;
	// }

}*root;

// Node *root=new Node;

class BST{
private:
    Node* root;
public:
    BST(){ root = nullptr; }
    Node* getRoot(){ return root; }
    void iInsert(int key);
    void Inorder(Node* p);
    Node* iSearch(int key);
    Node* rInsert(Node* p, int key);
    Node* rSearch(Node* p, int key);
    Node* Delete(Node* p, int key);
    int Height(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
    void createFromPreorder(int pre[], int n);
};


void generate_bst_pre(int *pre,int n){
	stack<Node*> stk;
	Node *t;
	Node *p;
	int i=0;
	
	root=new Node;
	root->data=pre[i++];
	root->lchild=root->rchild=NULL;
	p=root;
	// stk.push(p);

	while(i<n){	
		if(p->data>pre[i]){
			t=new Node;
			t->data=pre[i++];
			t->rchild=t->lchild=NULL;
			p->lchild=t;
			stk.push(p);
			p=t;
		}
		else{
			if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data){
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                p = t;
            } else {
                p = stk.top();
                stk.pop();
            }
		}

	}
}

void inorder(Node *p){
	if(p){
		inorder(p->lchild);
		cout<<p->data<<", ";
		inorder(p->rchild);
		}
}

// void BST::Inorder(Node* p) {
//     if (p){
//         Inorder(p->lchild);
//         cout << p->data << ", " << flush;
//         Inorder(p->rchild);
//     }
// }

// void BST::createFromPreorder(int *pre, int n) {
 
//     // Create root node
//     int i = 0;
//     root = new Node;
//     root->data = pre[i++];
//     root->lchild = nullptr;
//     root->rchild = nullptr;
 
//     // Iterative steps
//     Node* t;
//     Node* p = root;
//     stack<Node*> stk;
 
//     while (i < n){
//         // Left child case
//         if (pre[i] < p->data){
//             t = new Node;
//             t->data = pre[i++];
//             t->lchild = nullptr;
//             t->rchild = nullptr;
//             p->lchild = t;
//             stk.push(p);
//             p = t;
//         } else {
//             // Right child cases
//             if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data){
//                 t = new Node;
//                 t->data = pre[i++];
//                 t->lchild = nullptr;
//                 t->rchild = nullptr;
//                 p->rchild = t;
//                 p = t;
//             } else {
//                 p = stk.top();
//                 stk.pop();
//             }
//         }
//     }
// }
 

int main(){

	// BST bt;
	//Your code here
	// vector <int> pre = {4, 7, 9, 6, 3, 2, 5, 8, 1};
	// cout<<endl<<"Enter the "

	// generate_bst_pre(pre,pre.size());

	int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
	int n = sizeof(pre)/sizeof(pre[0]);


	generate_bst_pre(pre,n);
	cout<<endl<<"The inorder for given bst and its given preorder is: ";

	inorder(root);

	// cout << "BST from Preorder: " << flush;
    // int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    // int n = sizeof(pre)/sizeof(pre[0]);
 
    // BST b;
    // b.createFromPreorder(pre, n);
    // b.Inorder(b.getRoot());
    // cout << endl;

	return 0;
}