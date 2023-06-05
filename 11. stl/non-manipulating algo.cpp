#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void printarray(vector <int> v,int n){
	
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
}
int main(){
	//Your code here
	int n;
	cout<<endl<<"Enter the size of list: ";
	cin>>n;
	vector <int> a(n);
	cout<<endl<<"Enter the elements: ";
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<endl<<"The elements are: ";
	printarray(a,n);
	sort(a.begin(),a.end());
	cout<<endl<<"Sorted list is: ";
	printarray(a,n);

	// cout<<endl<<"reverse of list is: ";
	// reverse(a.begin(),a.end());
	// printarray(a,n);

	cout<<endl<<"The min element in list is: "<< *min_element(&a[0],&a[n]);
	

	cout<<endl<<"The max element in list is: "<< *max_element(&a[0],&a[n]);

	cout<<endl<<"Summation of vector element is: "<<accumulate(a.begin(),a.end(),0);

	int x;
	cout<<endl<<"Enter the element you want to count in list: ";
	cin>>x;
	cout<<endl<<"The count is: "<<count(a.begin(),a.end(),x);

	cout<<endl<<"Enter the elements to check in list: ";
	cin>>x;
	find(a.begin(),a.end(),x)!=a.end()?cout<<"Element found":cout<<"Element not found";
	
	cout<<endl<<"Enter the element you want to find lower bound in list: ";
	cin>>x;

	int q=*lower_bound(a.begin(),a.end(),x);
	int p=*upper_bound(a.begin(),a.end(),x);
	cout<<endl<<"The lower bound is at: "<<q;
	
	cout<<endl<<"Enter the element you want to find upper bound in list: ";
	cin>>x;
	cout<<endl<<"The upper bound is at: "<<p;



	return 0;
}