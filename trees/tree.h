#include <iostream>

#ifndef tree_h
#define tree_h

using namespace std;

// class Node{
// public:
// 	Node *lchild;
// 	int data;
// 	Node *rchild;
// };

// class Queue{
// public:
// 	int front;
// 	int size;
// 	int rear;
// 	Node **Q;

// 	Queue(int size){
// 		this->size=size;
// 		front=rear=0;
// 		Q=new Node*[size];
// 	}

// 	void enqueue(Node* x){
// 		if((rear+1)%size==front)
// 			cout<<"Queue is Full";

// 		else{
// 			rear=(rear+1)%size;
// 			Q[rear]=x;
// 		}
// 	}

// 	Node* dequeue(){
// 		Node *x=NULL;
// 		if(front==rear)
// 			cout<<"Queue is Empty";

// 		else{
// 			front=(front+1)%size;
// 			x=Q[front];
// 		}
// 		return x;
// 	}

// 	int isEmpty(){
// 		return front==rear?1:0;
// 	}

// };

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class Queue{
private:
    int size;
    int front;
    int rear;
    Node** Q;  // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node* x);
    Node* dequeue();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}
 
Queue::~Queue() {
    delete [] Q;
}
 
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(Node* x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}


#endif