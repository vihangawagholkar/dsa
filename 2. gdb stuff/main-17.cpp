/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

// void pair_sum_k(int *a,int l){
//     int sum;
//     cout<<endl<<"Enter the a no. whose sum counterparts are to be found in the given array: ";
//     cin>>sum;
    
    
    
//     cout<<endl<<"The pair of nos. are:- ";
    
//     for(int i=0;i<l-1;i++){
//         for(int j=i;j<l;j++){
//             if(a[i]+a[j]==sum)
//                 cout<<endl<<a[i]<<" + "<<a[j]<<" = "<<sum;
//         }
//     }
// }

int max(int *a,int l){
    int max;
    for(int i=0;i<l;i++)
        if(a[i]>max)
            max=a[i];
    return max;
}
int min(int *a,int l){
    int min;
    for(int i=0;i<l;i++)
        if(a[i]<min)
            min=a[i];
    cout<<endl<<min;
    return min;
}

// H={0};
//6 3 8 10 16 7 5 2 9 14
    // for(int i=L;i<h;i++)
    //     H[a[i]]++;
void pair_sum_k_usinghash(int *a,int l){
    int sum;
    cout<<endl<<"Enter the a no. whose sum counterparts are to be found in the given array: ";
    cin>>sum;
    int h=max(a,l)+1;
    int L=min(a,l);
    
    int *H=new int[h];
    
    for(int i=0;i<h;i++)
        H[i]=0;
        
    
    
    
    cout<<endl<<"The pair of nos. are:- ";
    for(int i=L;i<h;i++){
        if(H[sum-a[i]]!=0&&sum>=a[i]&&H[i]!=-1&&H[sum-a[i]]!=-1){
            cout<<endl<<a[i]<<" + "<<sum-a[i]<<" = "<<sum; 
            H[i]=-1;
            H[sum-a[i]]=-1;
        }
        H[a[i]]++;
        
    }
    
}
//0 1 2 3 4 5 6 7 8 9
int main()
{
    int size,length;
    cout<<"Hello World";
    cout<<endl<<"Enter the size of array: ";
    cin>>size;
    cout<<endl<<"Enter the length of array: ";
    cin>>length;
    cout<<endl<<"Enter the elements of array: ";
    int *A;
    A=new int[size];
    
    for(int i=0;i<length;i++)
        cin>>A[i];
    
    //pair_sum_k(A,length);
    pair_sum_k_usinghash(A,length);
    return 0;
}
