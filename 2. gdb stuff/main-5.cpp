/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int pow(int b,int p){
    if(p>1){
        return pow(b,p-1)*b;
    }
    else
        return b;
}

int main()
{
    cout<<"Hello World"<<endl;
    
    cout<<"The power of 2 to 3 is : "<<pow(2,3);
    return 0;
}