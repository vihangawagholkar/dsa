/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int F[10];

//excessive recursion is reduced using array F 

int fibo(int n){
    if(n>1){
        if(F[n-2]==-1)
            F[n-2]=fibo(n-2);
        if(F[n-1]==-1){
            F[n-1]=fibo(n-1);
        }
        return F[n-2]+F[n-1];
    }
    else
        F[n]=n;
        return n;
}
int main()
{
    cout<<"Hello World"<<endl;
    
    
    
    for(int i=0;i<10;i++){
        F[i]=-1;
    }
    int x=fibo(10);
    for(int i=0;i<10;i++){
        cout<<" "<<F[i];
    }

    return 0;
}