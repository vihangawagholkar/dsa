#include <iostream>
#include <stack>
using namespace std;


class Node{
public:
	Node *lchild;
	int data;
	Node *rchild;

	Node(){};

	Node(int data){
		lchild=NULL;
		this->data=data;
		rchild=NULL;
	}
};

// void createTree(){
// 	Node *p=new Node;

// }



int search_inorder(int arr[],int start, int end, int data){
	for(int i=start;i<=end;i++){
		if(arr[i]==data){
			return i;
		}
	}
}

Node* generate_tree(int *inorder, int *preorder, int start, int end){
	static int index=0;

	if(start>end)
		return NULL;

	Node* node=new Node(preorder[index++]);

	if(start==end)
		return node;

	else{
		int split=search_inorder(inorder,start,end,node->data);
		node->lchild=generate_tree(inorder,preorder,start,split-1);
		node->rchild=generate_tree(inorder,preorder,split+1,end);

	}
	return node;
}

void Preorder(Node *p){
		if(p){
			cout<<p->data<<" , "<<flush;
			Preorder(p->lchild);
			Preorder(p->rchild);
		}
	}
int main(){
	//Your code here
	Node *root=new Node;
	int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
	root=generate_tree(inorder,preorder,0,sizeof(inorder)/sizeof(inorder[0])-1);

	

	Preorder(root);
	return 0;
}