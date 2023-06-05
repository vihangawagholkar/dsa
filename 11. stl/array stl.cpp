#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
	//Your code here
	int a[6]={1,2,3,4,5,-1};
	int x;
	all_of(a,a+6,[](int x){ return x>0; })?
	cout<<endl<<"All are positive elements":
	cout<<endl<<"All are not positive elements";

	any_of(a,a+6, [](int x){ return x<0;})?
	cout<<endl<<"There exists a negative element":
	cout<<endl<<"All are positive elements";

	none_of(a, a+6, [](int x){ return x<0; })?
    cout <<endl<< "No negative elements" :
    cout <<endl<< "There are negative elements";

    int a1[6];

    copy_n(a,6,a1);
    cout<<endl;
    for(int i=0;i<6;i++)
    	cout<<a1[i]<<" ";

    iota(a1,a1+6,20);
    for(int i=0;i<6;i++)
    	cout<<a1[i]<<" ";


	return 0;
}