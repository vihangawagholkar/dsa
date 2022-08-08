#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node *next;
};

class CircularLinkedList:public Node{
private:
	int n;
	int *a;
	Node *head,*last;
public:

	CircularLinkedList(int n=0){
		head=new Node;
		last=head;
		cout<<endl<<"Enter the length of list: ";
		cin>>n;

		a=new int[n];
		cout<<"Enter the elements: ";
		Node *p;
		last=head;
		cin>>head->data;
		int i=1;
		while(i++<n){
			p=new Node;
			a[i]=i;
			cin>>p->data;
			last->next=p;
			last=p;
		}
		last->next=head;
		//display(head->next);

	}
	void display(){
		Node *p=head;
		cout<<endl<<"The elements are: ";
		do{

			cout<<p->data<<" ";
			p=p->next;
		}
		while(p!=head);
	}
	// void display(Node *p){
	// 	static int flag=0;
		
	// 	if(p!=head->next||flag==0){
	// 		flag=1;
	// 		cout<<p->data<<" ";
	// 		display(p->next);

	// 	}
	// 	flag=0;
	// }
	
	void insert(){
		int pos,x;

		cin>>x>>pos;
		
			if(pos==0){
				Node *t=head;
				Node *p=new Node;
				p->data=x;
				p->next=head;
				while(t->next!=head){
					t=t->next;
				}
				t->next=p;
				head=p;
			}
			else if(pos>0){
				Node *p=head;
				int i=0;
				do{
					
					p=p->next;
				}
				while(i++<pos);

				Node *t=new Node;
				t->data=x;
				t->next=p->next;
				p->next=t;
			}
			else
				cout<<endl<<"Invalid position!";
		
	}
	~CircularLinkedList(){
		
	}
};


int main(){
	//Your code here
	CircularLinkedList l1;
	l1.display();

	cout<<endl<<"Enter the element and position you want to insert: ";
	l1.insert();
	l1.display();
	return 0;
}