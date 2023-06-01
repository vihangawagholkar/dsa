#include <iostream>
#include <vector>

using namespace std;

void Insert(int (&arr)[],int n){
	int temp,i=n;
	temp=arr[n];

	while(i>1 && temp>arr[i/2]){
		arr[i]=arr[i/2];
		i=i/2;
	}

	arr[i]=temp;
}

void vInsert(vector <int> &arr,int key){
	int i = arr.size();
    arr.emplace_back(key);
 
    // Rearrange elements: O(log n)
    while (i > 0 && key > arr[i % 2 == 0 ? (i/2)-1 : i/2]){
        arr[i] = arr[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    arr[i] = key;
}


void createHeap(int (&arr)[]){
	

	for(int i=2;i<8;i++){
		Insert(arr,i);
	}

	cout<<endl<<"The new array heap is: ";

	for(int i=0;i<8;i++){
		cout<<arr[i]<<", ";
	}

}

void vcreateHeap(){
	int A[]={20,54,1,342,6,324,2,54,768,32};
	vector <int> arr;

	for (int i=0; i<10; i++){
        vInsert(arr, A[i]);
    }

    cout<<endl<<"The new vector heap is: ";

    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<", ";
    }
}

void swap(int &x,int &y){
	int temp=x;
	x=y;
	y=temp;
}


void Delete(int (&A)[],int n){
	int x,i,j,val;
	x=A[n];
	val=A[1];
	// A[n]=NULL;
	A[1]=A[n];
	A[n]=val;
	i=1,j=2*i;

	while(j<n-1){
		if(A[j+1]>A[j] && A[j+1]>A[j])
			j=j+1;

		if(A[i]<A[j]){
			swap(A[i],A[j]);
			i=j;
			j=2*j;
		}

		else
			break;

	}

	
}

void display(int arr[]){
	cout<<endl<<"Your array is: ";
	for(int i=0;i<8;i++){
		cout<<arr[i]<<", ";
	}

}
int main(){
	//Your code here
	int arr[]={0,14,15,5,20,30,8,40};
	createHeap(arr);

	for(int i=7;i>1;i--)
		Delete(arr,i);

	display(arr);
	// vcreateHeap();
	return 0;
}