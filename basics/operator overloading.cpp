#include <iostream>

using namespace std;

class complex{
private:
	int real;
	int img;

public:
	complex(int r=0,int i=0){
		real=r;
		img=i;
	}

	complex operator+(complex c){
		complex t;
		t.real=real+c.real;
		t.img=img+c.img;
		return t;
	}

	friend ostream& operator<<(ostream &x,complex c);
};

ostream& operator<<(ostream &x,complex c){
	cout<<"Output:- ";
	x<<endl<<c.real<<" + "<<c.img<<"i";
	return x;
}

int main(){
	complex c1(3,4);
	complex c2(5,6);
	complex c3=c1+c2;

	cout<<c3;
	return 0;
}