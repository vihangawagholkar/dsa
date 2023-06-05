/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

float tay(float x,float n){
    
    static float nu=1;
    static float d=1;
    float s;
    if(n>0){
        s=tay(x,n-1);
        d=d*n;
        
        nu=nu*x;
        return s+nu/d;
        
    }
    else
        return 1;
    
}
int main()
{
    cout<<"Hello World"<<endl;
    
    cout<<"The tay series for e^2 with precision till 5 terms is : "<<tay(1.0,5.0);

    return 0;
}