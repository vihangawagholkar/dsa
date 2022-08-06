#include <iostream>
#include <fstream>
using namespace std;
class Test{
public:
	int *p;
	ifstream fis;
	Test(){
		p=new int[10];
		//fis.open();
		cout<<endl<<endl<<"Constructor called!";
	}
	~Test(){
		delete []p;
		//fis.close();
		cout<<endl<<"Destructor called!";
	}
};
class Base{
	public: Base(){
		cout<<endl<<"Base Constructor Called.";
	}
	virtual ~Base(){
		cout<<endl<<"Base Destructor called";
	}
};

class Derived:public Base{
	public: Derived(){
		cout<<endl<<"Derived Destructor called";
	}
	~Derived(){
		cout<<endl<<"Derived Destructor called";
	}

};
int main(){
	//Your code here
	Test *a=new Test();
	Base *p=new Derived();
	delete a;
	delete p;
	return 0;
}