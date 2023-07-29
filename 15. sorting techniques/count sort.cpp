#include <iostream>

using namespace std;

int findMax(int A[], int n){
	int max=-32768;
	for(int i=0;i<n;i++){
		if(A[i]>max)
			max=A[i];
	}
	return max;
}

void countSort(int A[], int n){
	int max,i,j;
	int *C;

	max=findMax(A,n);
	C=new int[max+1];

	for(i=0;i<max+1;i++)
		C[i]=0;


	for(i=0;i<n;i++)
		C[A[i]]++;

	i=0,j=0;
	while(i<max+1){

		if(C[i]>0){
			A[j++]=i;
			C[i]--;
		}

		else
			i++;
	}
	delete [] C;
}
int main(){
	//Your code here
	cout<<endl<<"Enter the size of array: ";
	int n;
	cin>>n;

	int *A=new int[n];

	cout<<endl<<"Enter the elements: ";

	for(int i=0;i<n;i++)
		cin>>A[i];

	cout<<endl<<"Sorted list: ";

	countSort(A,n);
	
	for(int i=0;i<n;i++)
		cout<<A[i]<<", ";
	return 0;
}