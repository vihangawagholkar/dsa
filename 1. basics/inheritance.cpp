#include <iostream>

using namespace std;

class Rectangle{
public:
	int length;
	int breadth;

	Rectangle(){
		length=0;
		breadth=0;
		cout<<endl<<"parent default constructor";
	}
	Rectangle(int length,int breadth){
		this->length=length;
		this->breadth=breadth;
		cout<<endl<<"Parent parameterized Constructor";
	}
	Rectangle(Rectangle &r){
		length=r.length;
		breadth=r.breadth;
	}
	int getLength(){
		return length;
	}

	int getBreadth(){
		return breadth;
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

class Cuboid:public Rectangle{
	private: 
		int height;

	public:
		Cuboid(){
			setLength(0);
			setBreadth(0);
			height=0;
			cout<<endl<<"child default constructor";
		}
		// Cuboid(int l,int b,int h){
		// setLength(l);
		// setBreadth(b);
		// height=h;
		// cout<<endl<<"child parameterized Constructor";
		// }

		Cuboid(int l,int b,int h):Rectangle(l,b){
			height=h;
			cout<<endl<<"child parameterized Constructor";
		}
		void Volume(){
			cout<<endl<<getLength()*getBreadth()*height;
		}
		~Cuboid(){

		}
};
int main(){
	//Your code here
	Cuboid c1;
	Cuboid c2(10,8,5);
	cout<<endl<<c2.area();
	c2.Volume();
	return 0;
}