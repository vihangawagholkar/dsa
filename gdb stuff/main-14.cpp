/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
void initialize(int *p){
    for(int i=0;i<5;i++){
        cin>>p[i];
    }
}
int main()
{
    printf("Hello World\n");
    
    int *p=new int[5];
    
    initialize(p);
    int *q=new int[10];
    
    for(int i=0;i<5;i++){
        q[i]=p[i];
    }
    
    delete []p;
    
    p=q;
    q=NULL;
    
    for(int i=0;i<10;i++){
        cout<<p[i];
    }
    
    cout<<endl<<sizeof(p);
    return 0;
}
