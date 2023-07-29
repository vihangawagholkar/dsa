#include <iostream>

using namespace std;

class Node{
public:
	int value;
	Node *next;
};

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}


int findMax(int A[], int n){
	int max=-32768;
	for(int i=0;i<n;i++){
		if(A[i]>max)
			max=A[i];
	}
	return max;
}

void Insert(Node** ptrBins, int idx){
    Node* temp = new Node;
    temp->value = idx;
    temp->next = nullptr;
 
    if (ptrBins[idx] == nullptr){ // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void BinSort(int A[], int n){
	int max, i, j;

	Node **Bins;
	max= findMax(A,n);

	Bins= new Node*[max+1];

	for(i=0;i<max+1;i++)
		Bins[i]=NULL;

	for(i=0;i<n;i++)
		Insert(Bins, A[i]);

	i=0, j=0;

	while(i<max+1){
		while(Bins[i]!=NULL){
			A[j++]= Delete(Bins, i);
		}
		i++;
	}

	delete [] Bins;
}
int main(){
	//Your code here
	int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
	int n= sizeof(A)/sizeof(A[0]);

	Print(A,n,"\t\tA");
	BinSort(A,n);
	Print(A,n,"\t Sorted A");
	cout<<endl;

	return 0;
}