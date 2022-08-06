/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Array{
    private:
    int *A;
    int length;
    int size;
    
    public:
    
    Array(int sz){
        size=sz;
        length=0;
        A=new int[size];
        
    }
    
    ~Array(){
        delete []A;
    }
    void initialize();
    //Array* missing_el_sorted(Array *a);
    Array* missing_el_unsorted(Array *a);
    void display();
    int max(Array *a);
    int min(Array *a);
};

void Array::initialize(){
    cout<<endl<<"Enter the size of array: ";
    cin>>size;
    cout<<endl<<"Enter the length of array: ";
    cin>>length;
    A=new int[size];
    cout<<endl<<"Enter the elements of array: ";
    for(int i=0;i<length;i++)
        cin>>A[i];
    
}
void Array:: display(){
    for(int i=0;i<length;i++)
        cout<<" "<< A[i];
}
// Array* Array:: missing_el_sorted(Array *a){
//     cout<<endl<<"Missing elements are: ";
//     Array *c=new Array(a->length);
    
//     int diff=A[0]-0;
//     for(int i=0;i<length;i++){
//         if(A[i]-i!=diff){
//         while(diff<A[i]-i){
//             c->A[c->length++]=diff+i;
//             diff++;
//         }
//     }}
//     return c;
// }

int Array:: max(Array *a){
    int max=a->A[0];
    for(int i=0;i<a->length;i++){
        if(a->A[i]>max){
            max=a->A[i];
        }
    }
    //cout<<max<<endl;
    return max;
}
int Array:: min(Array *a){
    int min=a->A[0];
    for(int i=0;i<a->length;i++){
        if(a->A[i]<min){
            min=a->A[i];
        }
    }
    //cout<<min<<endl;
    return min;
}
Array* Array:: missing_el_unsorted(Array* a){
    cout<<endl<<"The missing elements are:- ";
    
    int h=max(a);
    int l=min(a);
    Array *c=new Array(h);
    int H[h]={0};
    // for(int i=0;i<h;i++){
    //     H[i]={0};
    // }
    for(int i=0;i<length-1;i++){
        H[A[i]]++;
    }
    for(int i=l;i<=h;i++){
        if(H[i]==0){
            c->A[c->length]=i;
            c->length++;
        }
    }
    return c;
}
int main()
{
    Array *arr1,*arr2;
    cout<<"Hello World";
    arr1->initialize();
    // int min=arr1->min(arr1);
    // cout<<min;
    arr1->display();
    
    //arr2=arr1->missing_el_sorted(arr1);
    arr2=arr1->missing_el_unsorted(arr1);
    
    arr2->display();
    
    return 0;
}

