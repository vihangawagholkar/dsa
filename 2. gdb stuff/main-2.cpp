/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};
void changeLength(struct Rectangle *r1){
    r1->length++;
    r1->breadth++;
}
int main()
{
    cout<<"Hello World"<<endl;
    
    struct Rectangle r={10,5};
    
    changeLength(&r);
    printf("%d %d",r.length,r.breadth);
    return 0;
}