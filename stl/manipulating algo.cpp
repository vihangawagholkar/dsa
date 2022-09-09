#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printarray(vector <int> v,int n){
	cout<<endl<<"The elements are: ";
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
}

int main(){
	//Your code here
	int n;
	cout<<endl<<"Enter the length of list: ";
	cin>>n;
	cout<<endl<<"Enter the elements: ";
	vector <int> v(n);
	for(int i=0;i<n;i++)	
		cin>>v[i];

	cout<<endl<<"Enter the position to delete: ";
	int x;
	cin>>x;
	v.erase(next(v.begin()+x));
	printarray(v,n);

	cout<<endl<<"Enter a duplicate element from list: ";
	v.erase(unique(v.begin(),v.end()),v.end());

	next_permutation(v.begin(),v.end());
	printarray(v,n);

	prev_permutation(v.begin(),v.end());
	printarray(v,n);

	cout<<endl<<"Distance between first and max element: ";
	cout<<distance(v.begin(),max_element(v.begin(),v.end()));

	return 0;
}