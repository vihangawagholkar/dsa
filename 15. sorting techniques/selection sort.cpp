#include <iostream>

using namespace std;

void swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void selection_sort(int A[],int n){
	int i,j,k;

	for(i=0;i<n-1;i++){

		for(j=k=i;j<n;j++){

			if(A[j]<A[k])
				k=j;
		}
		swap(A[i],A[k]);
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

	selection_sort(a,n);

	cout<<endl<<"The sorted list is: ";

	for(int i=0;i<n;)
		cout<<a[i++]<<" ";

	return 0;
}