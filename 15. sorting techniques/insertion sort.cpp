#include <iostream>

using namespace std;


// Naturally Adaptive 
// Stable

void insertion_sort(int A[],int n){

	int j,x;

	for(int i=0;i<n;i++){

		j=i-1;
		x=A[i];

		while(j>-1 && x<A[j]){

			A[j+1]=A[j];
			j--;
		}

		A[j+1]=x;
	}
}

int main(){
	//Your code here

	int n;
	cout<<endl<<"Enter the length of array: ";
	cin>>n;

	int *a=new int[n];

	cout<<endl<<"Enter the elements: ";

	for(int i=0;i<n;)
		cin>>a[i++];

	insertion_sort(a,n);

	cout<<endl<<"The sorted list is: ";

	for(int i=0;i<n;)
		cout<<a[i++]<<" ";

	return 0;
}