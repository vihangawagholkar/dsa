#include <iostream>

using namespace std;

class Node{
public:
	int data;
	int col;
	Node *next;
};

class Matrix:public Node{
int m,n,num;
Node *head,*last;
Node **A;

public:
	Matrix(){
		
		cout<<endl<<"Enter the dimensions of Matrix: ";
		cin>>m>>n;
		A=new Node*[m];
		
		int c;
		
		
		Node *p;
		for(int i=0;i<m;i++){
			A[i]=new Node;
			last=A[i];
			
			cout<<endl<<"Enter the no. of non-zero elements in row "<<i+1<<": ";
			cin>>c;
			for(int j=0;j<c;j++){
				cout<<endl<<"Enter the col no. and value: ";
				p=new Node;
				cin>>p->col;
				cin>>p->data;
				
				last->next=p;
				last=p;
			}
			
			last->next=NULL;

			
		}
		

	}

	void display(){
		cout<<endl<<"Your matrix is: "<<endl;
		Node *p;
		for(int i=0;i<m;i++){
			p=A[i];
			for(int j=0;j<n;j++){
				if(p->next){
					if(j+1==p->next->col){
					
						cout<<p->next->data<<" ";
						p=p->next;
					}
					else
						cout<<"0 ";
				}	
				
			else
				cout<<"0 ";
			}
			cout<<endl;
		}
	}
};
int main(){
	//Your code here
	Matrix m1;
	m1.display();
	return 0;
}