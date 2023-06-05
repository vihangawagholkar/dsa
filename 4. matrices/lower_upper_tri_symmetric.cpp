#include <iostream>
#include <cstdlib>
using namespace std;
// Using Row-major Formula
// Upper and Lower triangle both
class Matrix{
public:
	int *A;
	int n;
	virtual void Display(){};
	virtual ~Matrix(){};
};
class Lower_triangle:public Matrix{
public:
	Lower_triangle(int n){
		this->n=n;
		A=new int[n*n];
		cout<<endl<<"Enter the elements of your matrix: ";
		int c=0;
		//int temp[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
										cin>>A[(i*(i+1)/2)+j];
				if(i>=j)
					continue;
					
				else
					A[(i*(i+1)/2)+j]=0;
					

				}
		}
		
	}
	
	
				
	

	~Lower_triangle(){
		delete []A;
	}

	void Display();

};

void Lower_triangle::Display(){
	cout<<endl<<"Your matrix is:-"<<endl;
	for(int i=0;i<n;i++){

		for(int j=0;j<n;j++){
							if(A[(i*(i+1)/2)+j]==0){

																continue;}
			else if(i>=j){
									cout<<A[(i*(i+1)/2)+j]<<" ";
						}
						else
							cout<<"0 ";
		}
		cout<<endl;
	}
	
}

class Symmetric:public Matrix{
public:
	Symmetric(int n){
		this->n=n;
		A=new int[n*n];
		cout<<endl<<"Enter the elements of your matrix: ";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>A[(i*(i+1)/2)+j];
				if(i>=j)
					continue;
				else
					A[(i*(i+1)/2)+j]=A[((i+1)*(n+2)-(i*(i+1))/2)+(j-i)];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<A[(i*(i+1)/2)+j];
			}
			cout<<endl;
		}
	}
	void Display();
};
void Symmetric::Display(){
	cout<<endl<<"Your matrix is:- "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
				cout<<A[(i*(i+1)/2)+j]<<" ";
			


		}
		cout<<endl;
	}
};
class Upper_triangle:public Matrix{
public:
	Upper_triangle(int n){
		this->n=n;
		cout<<endl<<"Enter the elements of your matrix: ";
		A=new int[n*n];
		int c=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				
				cin>>A[((i+1)*(n+2)-(i*(i+1))/2)+(j-i)];
				if(i<=j)
					continue;
					
				else
					A[((i+1)*(n+2)-(i*(i+1))/2)+(j-i)]=0;
					

				
			}
		}
		
	}
	void Display();
};

void Upper_triangle::Display(){
	cout<<endl<<"your matrix is: -"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(A[((i+1)*(n+2)-(i*(i+1))/2)+(j-i)]==0)
							cout<<"0 ";
				
			else if(i<=j)
				cout<<A[((i+1)*(n+2)-(i*(i+1))/2)+(j-i)]<<" ";
							
						
			
		}
		cout<<endl;
	}
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
class tridiagonal:public Matrix{
public:
	tridiagonal(int n){
		this->n=n;
		A=new int[3*n-2];
		int *temp=new int[n*n];
		cout<<endl<<"Enter the elements of your matrix: ";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>temp[(i*(i+1)/2)+j];					
				if(i-j==-1){
									A[2*n+i]=temp[(i*(i+1)/2)+j];
									
									continue;}
				else if(i-j==1){
									A[i]=temp[(i*(i+1)/2)+j];
									
					continue;}
				else if(i-j==0){
									A[n+i]=temp[(i*(i+1)/2)+j];
									
									
						continue;
				}
				
				
			}
		}
		delete []temp;
	}
	void Display();
};

void tridiagonal::Display(){
	cout<<endl<<"Yor matrix is: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i-j==-1){
									cout<<A[2*n+i]<<"  ";
									continue;}
				else if(i-j==1){
									cout<<A[i]<<"  ";
									
					continue;}
				else if(i-j==0){
									cout<<A[n+i]<<"  ";
									
						continue;
				}
				
					
				
			cout<<"0  ";
		}
		cout<<endl;
	}
}
// 1 2 3 4 5 6 7 8 9
class toeplitz:public Matrix{
public:
	toeplitz(int n){
		this->n=n;
		A=new int[2*n-1];
		//int *temp=new int[2*n-1];
		cout<<endl<<"Enter "<<2*n-1<<" elements: ";
		// for(int i=n-1;i>=0;i--){
		// 	for(int j=n-1;j>=0;j--){
		// 		//cin>>A[(i*(i+1)/2)+j];
		// 		if(i<=j){
		// 							cin>>A[j-i];
		// 							continue;}
		// 		else{
		// 							cin>>A[n+i-j-1];
		// 							continue;}
		// 	}
		// }
		for(int i=0;i<2*n;i++){
			
				cin>>A[i];}
		
	}
	void Display(){
		for(int i=n-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				if(i<=j)
					cout<<A[j-i]<<" ";
				else
					cout<<A[n+i-j]<<" ";
			}
			cout<<endl;
		}
	}

};
int main(){
	//Your code here
	int n;
	cout<<endl<<"Enter the dimension of your matrix: ";
	cin>>n;
	// Matrix *m=new Lower_triangle(n);
	// m->Display();
	// delete m;
	// Matrix *p;
	// p=new Upper_triangle(n);
	// p->Display();
	// delete p;
	// Matrix *q=new Symmetric(n);
	// q->Display();
	// Matrix *m=new tridiagonal(n);
	// m->Display();
	Matrix *r=new toeplitz(n);
	r->Display();
	return 0;
}