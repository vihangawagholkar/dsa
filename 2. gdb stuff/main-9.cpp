/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
    
int fibo(int n){
    int s;
    if(n>1){
        
        s= fibo(n-2)+fibo(n-1);
        
        cout<<" "<<s; //excessive recursion
        
        return s;
        
        
    }
    else
        return n;
        
    
}
    

int main()
{
    cout<<"Hello World";
    cout<<endl<<"The fibonacci series for 5 terms is : "<<fibo(6);
    
    
    return 0;
}