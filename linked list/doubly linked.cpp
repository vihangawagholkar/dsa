#include <iostream>

using namespace std;


class Node{
public:
	int data;
	Node *next,*prev;
};

class DoublyLinked:public Node{
	int length;
	Node *head,*last;
public:
	DoublyLinked(){
		head=new Node;
		last=head;
		last->prev=head->next=NULL;
		cout<<endl<<"Enter the length of list: ";
		cin>>length;
		if(length>0){
				cout<<endl<<"Enter the elements: ";
				cin>>head->data;
				Node *p;
				last->next=p;
				int i=1;
				while(i++<length){
					p=new Node;
					cin>>p->data;
					last->next=p;
					p->prev=last;
					last=p;
					last->next=NULL;}
		}
		
		
	}
	void countNodes(){
		Node *p=head;
		int i=0;
		while(p){
			p=p->next;
			i++;
		}
		if(last->next){
					last=last->next;}
		
		
		length=i;
		
		}
	int getLength(){
		countNodes();
		return length;
	}
	void display(){
		cout<<endl<<"The elements are: ";
		Node *p=head;

		while(p){
			cout<<p->data<<" ";
			p=p->next;
		}

	}
	

	void insert(){
		int pos,x;
		cout<<endl<<"Enter the position and element you want to insert: ";
		cin>>pos>>x;
		
		if(pos<=0){
			Node *t=new Node;
			t->data=x;
			t->prev=NULL;
			t->next=head;
			head->prev=t;
			head=t;
			length++;
		}
		else{
			
			Node *t=new Node;
			t->data=x;
			int i=1;
			
			Node *p=head;
			while(i++<pos-1&&p->next){
				p=p->next;
				
			}
			
			t->next=p->next;
			t->prev=p;
			if(p->next)
			{
				p->next->prev=t;
			
			}
			
			p->next=t;
			length++;

		}

	}

	void Delete(){
		int pos,x;
		cout<<endl<<"Enter the position of node to be deleted: ";
		cin>>pos;
		Node *p=head;
		if(pos<=1){
			x=head->data;
			

			head=head->next;
			delete p;
			if(head)
				head->prev=NULL;
			length--;
		}
		else{
			int i=0;
			while(i++<pos-1&&p->next){
				p=p->next;
			}
			x=p->data;
			p->prev->next=p->next;
			if(p->next){
				p->next->prev=p->prev;

			}
			
			delete p;
			length--;
		}
	}

	void reverse(){
		cout<<endl<<"List reversed.";
		Node *p=head;
		Node *temp;
		while(p){
			temp=p->next;
			p->next=p->prev;
			p->prev=temp;
			p=p->prev;
			if(p!=NULL&&p->next==NULL)
				head=p;
		}
	}
};
int main(){
	//Your code here
	DoublyLinked d1;
	d1.display();
	//d1.insert();
	//d1.Delete();
	//d1.revdisplay();
	// d1.reverse();
	// d1.display();
	d1.reverse();
	d1.display();
	cout<<endl<<"The number of nodes are: "<<d1.getLength();
	return 0;
}