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


void createHeap(){
	int arr[]={20,54,1,342,6,324,2,54,768,32};

	for(int i=2;i<10;i++){
		Insert(arr,i);
	}

	cout<<endl<<"The new array heap is: ";

	for(int i=0;i<10;i++){
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

int main(){
	//Your code here
	createHeap();
	vcreateHeap();
	return 0;
}