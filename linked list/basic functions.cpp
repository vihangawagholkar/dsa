#include <iostream>
#include <string>
using namespace std;
int *a;
class Node{
public:
	int data;
	Node *next;

}*head;

void initialize(int n){
	
	cin>>head->data;
	head->next=NULL;
	Node *p;
	Node *last=head;
	int i=1;

	while(i++<n){
		p=new Node;
		cin>>p->data;
		p->next=NULL;
		last->next=p;
		last=p;
	}
}

int display(){
	Node *p=head;
	cout<<endl<<"the elements are: ";
	int i=0;
	while(p){

		cout<<p->data<<" ";
		p=p->next;
		i++;
	}
	return i;
}

int sum(){
	Node *p=head;
	int sum=0;
	while(p){
		sum+=p->data;
		p=p->next;
	}
	return sum;
}

int max(){
	Node *p=head;
	int max=p->data;
	while(p){
		if(max<p->data)
			max=p->data;

		p=p->next;
	}
	return max;
}

int search_basic(){
	Node *p=head;
	cout<<endl<<"Enter the element you want to search: ";
	int key;
	cin>>key;
	int i=0;
	while(p){
		i++;
		if(key==p->data)
			return i;
		p=p->next;

	}

	return 0;
}
int search_transposition(){
	Node *p=head;
	Node *q=NULL;
	cout<<endl<<"Enter the element you want to search: ";
	int key;
	cin>>key;
	int i=0;
	while(p){
		i++;
		if(key==p->data){
			q->next=p->next;
			p->next=head;
			head=p;
			return i;
		}
		q=p;
		p=p->next;
	}
	return 0;
}

void insert(){
	int c=display();
	cout<<endl<<"1. At beginning";
	cout<<endl<<"2. At given position";
	string s="y";
	
	while(s[0]=='y'||s[0]=='Y'){
		cout<<endl<<"Enter your choice: ";
		int n;
		cin>>n;
		switch(n){
			case 1:{
						Node *p=head;
						Node *t=new Node;
						cout<<endl<<"Enter the value to be inserted: ";
						cin>>t->data;
						t->next=head;
						head=t;
						c=display();
					}
						break;
			case 2:{
						Node *p=head;
						int pos,i=1;
						Node *t=new Node;
						cout<<endl<<"Enter the value to be inserted: ";
						cin>>t->data;
						cout<<"Enter the position you want to insert value";
						cin>>pos;
						
						while(i<c){
							if(a[i++]==pos){
								t->next=p->next;
								p->next=t;
								break;
							}
							p=p->next;
						}
					}
						break;

			default:
			cout<<endl<<"Invalid input!";
		}
	cout<<"Do you want to insert again (y/n)?";
	cin>>s;
	}
}

void sorted_insertion(){
	Node *p=head;
	Node *q=NULL;
	int n;
	cout<<endl<<"Enter the element you want to insert: ";
	cin>>n;

	while(p&&p->data<n){
		q=p;
		p=p->next;
	}
	Node *t=new Node;
	if(p==head){
		t->next=head;
		head=t;
	}
	else
	{t->data=n;
		t->next=q->next;
		q->next=t;}

}

int Delete(int c){
	int pos;
	cout<<endl<<"Enter the position of node you want to delete: ";
	cin>>pos;
	Node *p=head;
	Node *q=NULL;
	int i=1;

	if(pos<=c&&pos>=0)
	{
				if(pos==1){
					
					head=head->next;
					delete p;
					return 1;
				}
		while(i++<pos){
				q=p;
				p=p->next;
		}
		q->next=p->next;
		delete p;
		return 1;
	}
	else 
		return 0;
}

int check_sorted(){
	Node *p=head;
	
	Node *q=NULL;
	
	while(p->next!=NULL){
		
		if(p->data>p->next->data){
					return 0;
				}
		q=p;
		p=p->next;
		
		
	}

	return 1;
	
	
}

void remove_duplicate(){
	Node *p=head->next;
	Node *q=head;
	while(p){
		if(p->data==q->data){
			q->next=p->next;
			delete p;
			p=q->next;
		}
		else{
				q=p;
				p=p->next;}
	}
}

void naive_reverse(int c){
	cout<<endl<<"Reverse of given list is: ";
	Node *p=head;
	int *A=new int[c];
	int i=0;
	while(p){
		A[i]=p->data;
		p=p->next;
		i++;
	}
	p=head;
	i=c-1;
	
	while(p){
		p->data=A[i];
		p=p->next;
		i--;
	}


}
int main(){
	//Your code here
	int n;
	head=new Node;
	head->next=NULL;
	// Node *p=head; 
	cout<<endl<<"Enter the no. of elements you want to insert: ";
	cin>>n;
	//int i=0;
	if(n>0){
			cout<<endl<<"Enter the elements: ";
			
			initialize(n);}
	// while(i++<n){
	// 	cout<<endl<<"Enter the "<<i<<" element: ";
	// 	p=initialize(p);
	// 	p->next=0;
	// }
	int c=display();	
	cout<<endl<<"Number of nodes - "<<c;
	// cout<<endl<<"The sum is: "<<sum();

	// cout<<endl<<"The max element is: "<<max();

	
	// if(n>0)
	// {
	// 	int index=search_transposition();
	// 	if(index)
	// 		cout<<endl<<"The element is present at "<<index;
	// 	else
	// 		cout<<endl<<"element no present";
	// }
	// else
	// 	cout<<endl<<"Linear search not applicable.";

	//c=display();
	//insert();

	// sorted_insertion();
	
	// if(Delete(c))
	// 	cout<<endl<<"Element deleted successfully!";

	// else
	// 	cout<<endl<<"Invalid position.";

	
	
	// if(check_sorted())
	// 	cout<<endl<<"Sorted";
	
	// else
	// 	cout<<endl<<"Not sorted";

	//remove_duplicate(c);

	naive_reverse(c);
	int co=display();
	return 0;
}