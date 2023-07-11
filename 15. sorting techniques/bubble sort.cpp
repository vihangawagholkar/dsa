#include <iostream>

using namespace std;


void swap(int &a, int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}


void Bubble_Sort(int a[],int n){
	int flag;
	for(int i=0;i<n-1;i++){
		flag=0;
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				flag=1;
			}
		}
		if(flag==0){
			cout<<endl<<"Array is already sorted.";
					break;
				}
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

	Bubble_Sort(a,n);

	cout<<endl<<"The sorted list is: ";

	for(int i=0;i<n;)
		cout<<a[i++]<<" ";

	return 0;
}