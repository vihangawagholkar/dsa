#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class toyota{
public: 
	string name;
	int price;
	int quantity;

	toyota(string n="",int p=0,int q=0){
		cout<<endl<<"Enter the model : ";
		getline(cin,name);
		cout<<endl<<"ENter the price of car: ";
		cin>>price;
		cout<<endl<<"Enter the quantity of cars you want to buy: ";
		cin>>quantity;
	}
	friend ofstream & operator <<(ofstream & ofs,toyota &t);
	friend ifstream & operator >>(ifstream & ifs,toyota &t);
	~toyota(){

	}

	void display(){
		cout<<endl<<"Model: "<<name;
		cout<<endl<<"Price: "<<price;
		cout<<endl<<"quantity: "<<quantity;
	}
};

ofstream& operator <<(ofstream & ofs,toyota &t){
	ofs<<t.name<<endl;
	ofs<<t.price<<endl;
	ofs<<t.quantity<<endl;
	return ofs;
}

ifstream& operator >>(ifstream & ifs,toyota &t){
	ifs>>t.name>>t.price>>t.quantity;
	return ifs;
}
int main(){
	//Your code here
	toyota t;
	ofstream ofs("Car.txt",ios::app);

	ofs<<t;
	ifstream ifs("Car.txt");
	
	while(!ifs.eof()){
		ifs>>t;
		t.display();
	}


	
	return 0;
}