#include <iostream>

using namespace std;


class Node{
public:
	int data;
	Node *next,*prev;
};

class DoublyCircularLinked:public Node{
	int length;
	Node *head,*last;
public:
	DoublyCircularLinked(){
		head=new Node;
		cout<<endl<<"Enter the length of list: ";
		cin>>length;
		last=head;
		cout<<endl<<"Enter the elements: ";
		cin>>head->data;
		int i=1;
		Node *p;
		while(i++<length){
			p=new Node;
			cin>>p->data;
			p->prev=head;
			last->next=p;

			last=p;

			
		}
		last->next=head;
		head->prev=p;
	}
	void display(){
		cout<<endl<<"The elements are: ";
		Node *p=head;
		
		do{
			cout<<p->data<<" ";
			p=p->next;
		}while(p!=head);
		cout<<endl;
		
		do{
			cout<<p->data<<" ";
			p=p->prev;
		}while(p!=head);
	}
};
int main(){
	//Your code here
	DoublyCircularLinked l1;
	l1.display();
	
	return 0;
}