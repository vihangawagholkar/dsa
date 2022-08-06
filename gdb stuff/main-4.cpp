/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int fact(int n){
    static int f;
    if(n>1){
        return fact(n-1)*n;
        
    }
    else
        return 1;
}
int main()
{
    cout<<"Hello World"<<endl;
    
    cout<<"The factorial is : "<<fact(5);
    return 0;
}