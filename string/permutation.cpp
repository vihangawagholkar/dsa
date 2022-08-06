#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// void perm(string s,int k){
// 	static int A[10]={0};
	
// 	static string res="";
// 	int i;
// 	if(s[k]=='\0'){
// 			res[k]='\0';
// 			cout<<endl<<res;}
// 	else{
// 		for(i=0;s[i]!='\0';i++){
// 			if(A[i]==0){
// 						res[k]=s[i];
// 						A[i]=1;
// 						perm(s,k++);
// 						A[i]=0;}
// 		}
// 	}
// }

void swap_perm(string s,int l, int h){
	int i;
	if(l==h){
		cout<<endl<<s;
	}
	else{
		for(i=l;i<=h;i++){
			swap(s[l],s[i]);
			swap_perm(s,l+1,h);
			swap(s[l],s[i]);
		}
	}
}
int main(){
	//Your code here
	cout<<endl<<"Enter the string to be permuted: ";
	string s="";
	getline(cin,s);
	cout<<endl<<"The permutations are:-";
	int i=0;
	for(;i!='\0';i++){

	}
	// int l=i;
	//perm(s,0);
	swap_perm(s,0,s.length()-1);

	return 0;
}