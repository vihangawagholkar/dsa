#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Rectangle{
private:
	int length;
	int breadth;

public:
	Rectangle(int length=0,int breadth=0){
		this->length=length;
		this->breadth=breadth;
	}
	Rectangle(Rectangle &r){
		length=r.length;
		breadth=r.breadth;
	}
	void setLength(int length){
		this->length=length;
	}

	void setBreadth(int breadth){
		this->breadth=breadth;
	}

	int area();

	inline int perimeter();

	int diagonal();
	~Rectangle(){

	}


};

int Rectangle:: perimeter(){
	return 2*(length+breadth);
}

int Rectangle:: area(){
	return length*breadth;
}

int Rectangle::diagonal(){
	return sqrt((length*length)+(breadth*breadth));
}


int main(){
	Rectangle r1;
	int l,b;
	//Rectangle *p=new Rectangle();
	cout<<endl<<"Enter the length: ";
	cin>>l;
	r1.setLength(l);

	cout<<endl<<"Enter the breadth: ";
	cin>>b;
	r1.setBreadth(b);
	string c="Y";
	while(c=="Y"||c=="y"){
		int choice;
		cout<<endl<<"Enter your choice:- ";
		cout<<endl<<"1. Area";
		cout<<endl<<"2. Perimeter";
		cout<<endl<<"3. diagonal"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
			cout<<endl<<"The area is : "<<r1.area();
			break;

			case 2:
			cout<<endl<<"The perimeter is : "<<r1.perimeter();
			break;

			case 3:
			cout<<endl<<"The diagonal is : "<<r1.diagonal();
			break;

			default:
			cout<<endl<<"Wrong Input!";
		}	
		cout<<endl<<"Do you want to continue (Y/N)?"<<endl;
		cin>>c;
	}
	r1.~Rectangle();
	return 0;
	
}