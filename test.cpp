#include <iostream>

using namespace std;

int main(){
   //Your code here
   int n,h;
       int *a=new int[n];
       int sum=0;
       cin>>n>>h;
       for(int i=0;i<n;i++){
         cin>>a[i];
         if(a[i]>h){
            sum+=2;
         }
         else
            sum+=1;
       }
       cout<<sum;
      //Your Code
       delete []a;
   return 0;
}