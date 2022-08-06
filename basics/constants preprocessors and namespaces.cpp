#include <iostream>

using namespace std;
#ifndef pi
	#define pi 3.1425
#endif
#define c cout;
#define MAX(a,b) (a>b?a:b)
#define STR(x) #x



class Demo{
	public : int a=10;
	int b=20;
	void display() const{
		//a++;
		cout<<endl<<a<<" "<<b;
	}
};

namespace first{
	void fun(){
		cout<<endl<<"First";
	}
};

namespace second{
	void fun(){
		cout<<endl<<"Second";
	}
};

using namespace first;
int main(){
	//Your code here
	 int x =10,a,b;
	const int * const p=&x;
	x++;
	//*p++;
	int y=20;
	std::cout<<endl<<"X: "<<x;
	std::cout<<endl<<"X: "<<*p;
	//p=&y;
	//cout<<endl<<"Y: "<<*p;
	Demo d;
	d.display();
	std::cout<<endl<<"Enter 2 nos.: ";
	std::cin>>a>>b;
	std::cout<<endl<<"The max is : "<<MAX(a,b);
	std::cout<<endl<<STR(Hello)<<" "<<pi;
	fun();
	second::fun();
	return 0;
}