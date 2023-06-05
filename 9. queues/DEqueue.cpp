#include <iostream>

using namespace std;


class DEqueue{
	int front, rear,size;
	int *Q;
public:
	DEqueue(){
		front=rear=-1;
		cout<<endl<<"Enter the length of queue: ";
		cin>>size;
		Q=new int[size];
		cout<<endl<<"Enter the elements: ";
		int i=0;
		while(i<size){
			cin>>Q[i++];
			rear++;
			
		}
		

	}

	void enqueuef(int x){
		if(rear==size-1){
			cout<<"Queue is Full. ";

		}

		else{
			Q[front]=x;
			front--;
		}
	}
	void enqueuer(int x){
		if(rear==size-1){
			cout<<"Queue is Full. ";
		}

		else{
			rear++;
			Q[rear]=x;
		}
	}

	int dequeuef(){
		int x=-1;
		if(rear==front)
			cout<<endl<<"Queue is Empty";

		else{
			
			x=Q[front];
			front++;
		}

		return x;
	}
	int dequeuer(){
		int x=-1;
		if(rear==front)
			cout<<endl<<"Queue is Empty";

		else{
			x=Q[rear];
			rear--;
		}

		return x;
	}

	void display(){
		cout<<endl<<"The elements are: ";
		for (int i=front+1; i<=rear; i++) {
        	cout << Q[i] << flush;
       	 	if (i < rear){
            	cout << " <- " << flush;
        	}
   		}
	    cout << endl;
	    
	}

};
int main(){
	//Your code here
	char s[]="y";
	int c;
	DEqueue q;
	while(s[0]=='y'||s[0]=='Y'){
		cout<<endl<<"1. Insert from front";
		cout<<endl<<"2. Delete from front";
		cout<<endl<<"3. Insert from back";
		cout<<endl<<"4. Delete from back";
		cout<<endl<<"5. display";
		cout<<endl<<"Enter your choice: ";
		cin>>c;
		switch(c){
			case 1:{
				int x;
				cout<<endl<<"Enter the element to insert: ";
				cin>>x;
				q.enqueuef(x);
				q.display();
			}break;

			case 2:{
				q.dequeuef();
				q.display();
			}break;

			case 3:{
				int x;
				cout<<endl<<"Enter the element to insert: ";
				cin>>x;
				q.enqueuer(x);
				q.display();
			}break;

			case 4:{
				q.dequeuer();
				q.display();
			}break;


			case 5:{
				q.display();
			}break;

			default:{
				cout<<endl<<"Invalid choice. Please try again.";
				s[0]='y';
			}

		}

		cout<<endl<<"Do you want to continue (y/n)?";
		cin.ignore();
		cin.getline(s,100);
	}
	return 0;
}