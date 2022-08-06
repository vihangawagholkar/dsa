#include <iostream>

using namespace std;

class element{
public:
	int i;
	int j;
	int x;
};

class sparse{
	int m;
	int n;
	int num;
	element *e;
public:
	sparse(){}
	sparse(int m,int n){
		this->m=m;
		this->n=n;
		cout<<endl<<"Enter the number of non-zero elements: ";
		cin>>num;
		e=new element[num];
		for(int i=1;i<=num;i++){
			cout<<endl<<"Enter the row, column and element: ";
			cin>>e[i].i>>e[i].j>>e[i].x;
		}
	}
	void display(){
		cout<<endl<<"Your matrix is:-"<<endl;
	
		int c=1;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(i==e[c].i&&j==e[c].j){
					cout<<e[c].x<<" ";
					c++;
					
				}
				else
				cout<<"0 ";
			}
			cout<<endl;
		}
	}
	void add(sparse s2);
	
};
//1 4 6 2 2 7 3 2 2 3 4 5 5 1 4
//2 2 3 2 5 5 3 3 2 3 6 7 4 4 9 5 1 8
void sparse:: add(sparse s2){
	sparse temp;
	temp.e=new element[num+s2.num];
	if(s2.m==m&&s2.n==n){
		int c=1;
		temp.m=m;
		temp.n=n;
		for(int i=1,j=1;i<=num||j<=s2.num;){
	
			if(e[i].i==s2.e[j].i){
				if(e[i].j==s2.e[j].j){
								temp.e[c].i=e[i].i;
								temp.e[c].j=e[i].j;
								temp.e[c].x=e[i].x+s2.e[j].x;
								i++;
								j++;
								c++;
								continue;}
				else if(e[i].j<s2.e[j].j){
					temp.e[c].i=e[i].i;
					temp.e[c].j=e[i].j;
					temp.e[c].x=e[i].x;
					i++;
					c++;
					continue;
				}
				else{
					temp.e[c].i=s2.e[j].i;
					temp.e[c].j=s2.e[j].j;
					temp.e[c].x=s2.e[j].x;
					j++;
					c++;
					continue;
				}

			}
			else if(e[i].i<s2.e[j].i){
				
					temp.e[c].i=e[i].i;
					temp.e[c].j=e[i].j;
					temp.e[c].x=e[i].x;
					i++;
					c++;
					continue;
				
			}
			else{
				temp.e[c].i=s2.e[j].i;
				temp.e[c].j=s2.e[j].j;
				temp.e[c].x=s2.e[j].x;
				j++;
				c++;
				continue;
			}
		}
		
		
		temp.display();
	}
	else {
			cout<<endl<<"Dimensions aren't same.\n Can't add!";
		}
}

int main(){
	//Your code here
	int m,n;
		cout<<endl<<"Enter the Dimension: ";
		cin>>m>>n;
	sparse s1(m,n);
	s1.display();
		cout<<endl<<"Enter the Dimension: ";
		cin>>m>>n;
	sparse s2(m,n);
	s2.display();
	
	s1.add(s2);
	return 0;
}