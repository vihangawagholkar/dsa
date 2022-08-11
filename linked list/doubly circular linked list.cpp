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
		
		
	}

	void insert(){
		int pos,x;
		cout<<endl<<"Enter the position and the element you want to insert in: ";
		cin>>pos>>x;
		if(pos==0){
			Node *t=new Node;
			t->data=x;
			t->next=head;
			t->prev=head->prev;
			head->prev=t;
			head=t;
			length++;

		}
		else if(pos>0){
			int i=0;
			Node *p=head;
			Node *t=new Node;
			t->data=x;
			while(i++<pos-1){
				p=p->next;
			}
			t->next=p->next;
			t->prev=p;
			if(p->next==head){
				p->next->prev=t;
			}
			p->next=t;
			length++;
		}
	}
};
int main(){
	//Your code here
	DoublyCircularLinked l1;
	l1.insert();
	l1.display();
	
	return 0;
}