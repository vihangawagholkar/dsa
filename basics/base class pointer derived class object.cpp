#include <iostream>

using namespace std;

class Rectangle{
private:
	int length;
	int breadth;

public:
	Rectangle(int l=0,int b=0){
		length=l;
		breadth=b;
	}

	int getLength(){
		return length;
	}

	int getBreadth(){
		return breadth;
	}

	void setLength(int l){
		length=l;
	}

	void setBreadth(int b){
		breadth=b;
	}

	int perimeter(){
		return 2*(length+breadth);
	}

	int area(){
		return length*breadth;
	}
	~Rectangle(){}
};



class Cuboid:public Rectangle{
	private: int height;

	public: Cuboid(int l=0,int b=0,int h=0){
		setLength(l);
		setBreadth(b);
		height=h;
	}

	int Volume(){
		return getLength()*getBreadth()*height;
	}

	~Cuboid(){}
};

int main(){
	//Your code here
	
	Rectangle *p;
	p=new Cuboid(10,5,8);

	cout<<"The area is: "<<p->area()<<endl;
	cout<<"The perimeter is: "<<p->perimeter()<<endl;

	return 0;
}