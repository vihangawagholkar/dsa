/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int fun(int n){
    static int s;
    if(n>0){
        
        s=fun(n-1)+n;
        return s;
    }
    else
        return 0;
}
int main()
{
    printf("Hello World");
    printf("\nThe sum of n natural nos. is : %d",fun(5));
    return 0;
}
