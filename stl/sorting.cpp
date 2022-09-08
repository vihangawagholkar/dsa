#include <iostream>
#include <algorithm>

using namespace std;

void printarray(int *a,int n){
	cout<<endl<<"The elements are: ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	//Your code here
	int n;
	cout<<endl<<"Enter the length of array: ";
	cin>>n;
	cout<<endl<<"Enter the elements: ";
	int *A=new int[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	printarray(A,n);
	sort(&A[0],&A[n]);
	printarray(A,n);
	return 0;
}