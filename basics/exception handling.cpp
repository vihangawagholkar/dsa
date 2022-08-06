#include <iostream>
#include <typeinfo>
#include <type_traits>
using namespace std;

class Exception{

};
class Rectangle{
	private: int length,breadth;
	
	public: Rectangle(int l=0,int b=0){
		length=l;
		breadth=b;
	}
	int perimeter() {
		if(length<0||breadth<0){
			throw Exception() ;
		}
		return 2*(length+breadth);
}
	int area() throw (Exception){
		if(length<0||breadth<0){
			throw Exception();
		}
		return length*breadth;
	}
	~Rectangle(){

	}

};


int main(){
	//Your code here
		int ar,p;
		int count=0;
	while(count>=0){
		count=0;

	cout<<endl<<"Enter the length and breadth of rectangle: "<<endl;
	int a,b;
	cin>>a>>b;
	
	Rectangle t(a,b);
	try{
		ar=t.area();
		p=t.perimeter();
		count--;
	}
	catch(Exception t){
		cout<<endl<<"Input cannot be negative please try again: ";
		count++;
	}}

	cout<<endl<<"The area is : "<<ar;
	cout<<endl<<"The perimeter is: "<<p;
	return 0;
}