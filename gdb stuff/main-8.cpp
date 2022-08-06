/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

float tay_h(float x,float n){
    static float s;
    if(n>0){
        s=1+x*s/n;
        return tay_h(x,n-1);
    }
    else
        return s;
}
int main()
{
    cout<<"Hello World"<<endl;
    
    cout<<"Taylor Series using hornet's rule : "<<tay_h(1.0,10.0);

    return 0;
}