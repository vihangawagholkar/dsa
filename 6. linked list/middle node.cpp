#include <iostream>

using namespace std;


class Node{
public:
	int data;
	Node *next;
};

class SinglyLinked:public Node{
	Node *head,*last;
	int length;
public:
	SinglyLinked(){
		
				head=new Node;
				cout<<endl<<"Enter the length of list: ";
				cin>>length;
				if(length>0){
				cout<<endl<<"Enter the elements: ";
				cin>>head->data;
				last=head;
				Node *p;
				int i=1;
				while(i++<length){
					p=new Node;
					cin>>p->data;
					last->next=p;
					last=p;
				}
				last->next=NULL;
				
			}
		else
			cout<<endl<<"List cannot be created of NULL size";
	}
	void display(){
		Node *p=head;
		cout<<endl<<"The elements are: ";
		while(p){
			cout<<p->data<<" ";
			p=p->next;
		}
	}

	void naive_middlenode(){
		cout<<endl<<"The middle node is: ";
		int i=0;
		Node *p=head;

		if(length%2==0){

			while(++i<length/2){
				
				p=p->next;
			}
			cout<<p->data<<" "<<p->next->data;

		}
		else{
			while(i++<length/2){
				
				p=p->next;
			}
			cout<<p->data;
		}
	}

	void twoptr_middlenode(){
		cout<<endl<<"The middle node is: ";
		Node *q=head;
		Node *p=head;
		if(length%2==0){
			while(q){
				p=p->next;
				q=q->next->next;
			}
			cout<<p->data<<" "<<p->next->data;
		}
		else{
			while(q){
				q=q->next;
				if(q==NULL)
					break;
				p=p->next;
				q=q->next;
			}
			cout<<p->data;
		}
	}
	int getLength(){
		return length;
	}
};
int main(){
	//Your code here
	SinglyLinked l1;
	l1.display();
	cout<<endl<<"Number of nodes are: "<<l1.getLength();
	//l1.naive_middlenode();
	l1.twoptr_middlenode();
	l1.display();
	return 0;
}