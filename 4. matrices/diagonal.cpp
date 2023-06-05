#include <iostream>

using namespace std;

class Diag_Matrix{

	int **A;
	int length;
	public: 
	Diag_Matrix(){
		cout<<"Enter dimension of your matrix: ";
		cin>>length;
		A=new int*[length];
		for(int i=0;i<length;i++){
			A[i]=new int[length];
		}
		cout<<endl<<"Enter the elements in your matrix: ";
		for(int i=0;i<length;i++){
			for(int j=0;j<length;++j){
				
				
									
				set(i,j);
		}
	}}

	void set(int i,int j){
		
			cin>>A[i][j];
		
	}

	int get(int i,int j){
		if(i==j)
			return A[i][j];
		else 
			return 0;
	}

	void Display();
	~Diag_Matrix(){
		delete[]A;
	}
};




void Diag_Matrix ::  Display(){
	cout<<endl;
	for(int i=0;i<length;i++){
		for(int j=0;j<length;j++){
							cout<<get(i,j)<<" ";
			
		}
		cout<<endl;
	}
}
int main(){
	//Your code here
	Diag_Matrix a;
	
	cout<<endl<<"Your matrix is : ";
	a.Display();
	return 0;
}