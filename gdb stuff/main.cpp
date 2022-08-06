/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std ;
int main()
{
    printf("Hello World");
    
    int a=10;
    int &r=a;
    int b=30;
    cout<<a<<endl;
    cout<<r<<endl;
    r=b;
    cout<<a<<" "<<b<<endl;
    return 0;
}
