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
        A=new int[sz];
    }
    ~Array(){
        delete []A;
    }
    Array* sorted_Duplicate(Array *a);
    Array* unsorted_Duplicate(Array *a);
    void initialize();
    void display();
    int max();
    int min();
};

void Array:: initialize(){
    cout<<endl<<"Enter the size: ";
    cin>>size;
    cout<<endl<<"Enter the length: ";
    cin>>length;
    A=new int[size];
    cout<<endl<<"Enter the elements: ";
    for(int i=0;i<length;i++)
        cin>>A[i];
}
// 1 2 3 3 4 5 6 6 6 7
void Array:: display(){
    //int i=0;
    // while(i<length){
    //     cout<<A[i++]<<" ";
    // }
    for(int i=0;i<length;i++)
        cout<<" "<<A[i];
}
//2 8 34 9 2 8 34 34 8 8
int Array:: min(){
    int min;
    for(int i=0;i<length;i++)
        if(min>A[i])
            min=A[i];

    return min;
}
int Array:: max(){
    int max;
    for(int i=0;i<length;i++)
        if(max<A[i])
            max=A[i];

    return max;
}

Array* Array:: unsorted_Duplicate(Array *a){
    
    Array *c=new Array(length);
    int h=a->max();
    int l=a->min();
    int H[h+1]={0};
    //int dup=0;
        // for(int j=i+1;j<length;j++){
        //     if(A[i]==A[j]&&dup!=A[i]){
        //         H[A[i]]++;
        //         dup=A[i];
        //     }
        // }
    for(int i=0;i<length;i++){
        H[A[i]]++;
    }
    cout<<endl<<"No. of times duplicates occur:- ";
    for(int i=l;i<h+1;i++){
        if(H[i]>1){
            c->A[c->length++]=i;
            cout<<" "<<H[i];
        }
    }
    // for(int i=l;i<=h;i++){
    //     if(H[i]>0){
    //         cout<<H[i]<<" ";
    //     }
    // }
    
    return c;
}
// Array* Array:: sorted_Duplicate(Array *a){
//     cout<<endl<<"The duplicates are: ";
//     Array *c=new Array(length);
//     int dup=0;
//     for(int i=0;i<length;i++){
//         if(A[i]==A[i+1]&&dup!=A[i]){
//             c->A[c->length++]=A[i];
//             dup=A[i];
//         }
//     }
//     return c;
// }
int main()
{
    cout<<"Hello World";
    Array *arr1,*arr2;
    arr1->initialize();
    arr1->display();
    //arr2=arr1->sorted_Duplicate(arr1);
    arr2=arr1->unsorted_Duplicate(arr1);
    cout<<endl<<"The duplicates are: ";
    arr2->display();
    
    
    return 0;
}