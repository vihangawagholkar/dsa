#include <iostream>

using namespace std;

template <class T>
class Array{
	private: T *A;
	int size;
	int length;

	public: Array (){
		length=0;
		size=0;
	}

		Array(T s,T l){

	    size=s;
	    length=l;
	    A=new T[s];
	    cout<<endl<<"Enter the elements : ";
	    for(int i=0;i<length;i++)
	    	cin>>A[i];
	}
	T max();
	~Array(){
		delete[] A;
	}
	//T initialize();

};

template <class T>

// T Array <T> ::  max(){
// 	T max=A[0];
// 	for(int i=0;i<length;i++)
// 		if(A[i]>max)
// 			max=A[i];
// 	return max;

// }
T Array<T>::max(){
		T max=A[0];
		for(int i=0;i<length;i++)
			if(A[i]>max)
				max=A[i];
		return max;
	}
int main(){

	int s,l;
	//Array <int> a(s,l);
	cout<<endl<<"Enter the size: ";
	cin>>s;

	//cin>>a.size;
	//a.A=new int[a.size];
	cout<<endl<<"Enter the length: ";
	cin>>l;

	Array <int> a(s,l);

	//cin>>a.length;
	
	//cout<<endl<<"Enter the elements: ";
	//for(int i=0;i<a.length;i++)
	//	cin>>a.A[i];

	cout<<"The max in the given array is: "<<a.max();
}