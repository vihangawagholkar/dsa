#include <iostream>

using namespace std; 
class shape{
	public: virtual void draw()=0;

};

class rectangle:public shape{
public:
	void draw(){
		cout<<endl<<"Rectangle is drawn. ";
	}
};

class circle:public shape{
public:
	void draw(){
		cout<<endl<<"Circle is drawn.";
	}
};


int main(){
	//Your code here
	
	shape *p=new rectangle();

	p->draw();

	p=new circle();

	p->draw();

	return 0;
}