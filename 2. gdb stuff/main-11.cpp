/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

int comb(int n,int r){
    
    if(n==r||r==0)
        return 1;
    else
        return comb(n-1,r-1)+comb(n-1,r);
}

using namespace std;

int main()
{
    cout<<"Hello World"<<endl;
    
    cout<<"The combination of 3C2 is : "<<comb(4,2);

    return 0;
}