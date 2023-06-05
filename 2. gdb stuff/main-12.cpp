/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

void toh(int n,int A,int B,int C){
    if(n>0){
    toh(n-1,A,C,B);
    cout<<A<<" to "<<C<<endl;
    toh(n-1,B,A,C);}
}


int main()
{
    cout<<"Hello World"<<endl;
    toh(3,1,2,3);
    return 0;
}