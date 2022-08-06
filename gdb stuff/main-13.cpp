/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct array{
    int size;
    int length;
    int *A;
};

void initialize(struct array *arr){
    cout<<"Enter the size of array: ";
    cin>>arr->size;
    arr->A=new int[arr->size];
    
    cout<<endl<<"Enter the length of array: ";
    cin>>arr->length;
    
    cout<<endl<<"Enter the elements: ";
    
    for(int i=0;i<arr->length;i++){
        cin>>arr->A[i];
    }
}
void display(struct array arr){
    cout<<endl<<"The elements are :";
    
    for(int i=0;i<arr.length;i++){
        cout<<" "<<arr.A[i];
    }
}

// void append(struct array *arr){
//     int n;
//     cout<<endl<<"Enter the element you want to add to the array: ";
//     cin>>n;
//     if(arr->length<arr->size){
//         arr->A[arr->length++]=n;
//     }
// }
// void insert(struct array *arr){
//     int index,n;
//     cout<<endl<<"Enter the position and element to be inserted: ";
//     cin>>index;
//     index-=1;
//     cin>>n;
//     if(index>=0&&index<arr->length){
//         for(int i=arr->length;i>index;i--)
//             arr->A[i]=arr->A[i-1];
//         arr->A[index]=n;
//         arr->length++;
//     }
// }

// void Delete(struct array *arr){
//     int index;
//     cout<<endl<<"Enter the position you want to delete: ";
//     cin>>index;
//     index-=1;
//     if(index>=0&&index<arr->length){
//         int x=arr->A[index];
//         for(int i=index;i<arr->length-1;i++){
//             arr->A[i]=arr->A[i+1];
//         }
//         arr->length--;
//     }
// }

// void swap(int *x,int *y){
//     int temp;
//     temp=*x;
//     *x=*y;
//     *y=temp;
// }

// int imp_linear_search(struct array *arr){
//     cout<<endl<<"Enter the element you want to search: ";
//     int n;
//     cin>>n;
    
//     for(int i=0;i<arr->length;i++){
//         if(arr->A[i]==n)
//             if(i==0)
//                 return i;
            
//             swap(&arr->A[i],&arr->A[i-1]);
//             return i;
//     }
//     return -1;
// }

// int B_search(struct array arr){
//     int n;
//     cout<<endl<<"Enter the element you want to search ";
//     cin>>n;
//     int l=0,h=arr.length-1,mid;
//     while(l<=h){
//         mid=(l+h)/2;
//         if(n==arr.A[mid])
//             return mid+1;
//         else if(n<arr.A[mid])
//             h=mid-1;
//         else
//             l=mid+1;
//     }
//     return -1;
    
// }
// int index;
// int get(struct array a){
    
//     cout<<endl<<"Enter the position of element you want: ";
//     cin>>n;
//     if(n>=0&&n<a.length)
//         return a.A[n-1];
// }

// void set(struct array *a){
//     int n;
//     cout<<endl<<"Enter the position of element you want to change: ";
//     cin>>index;
//     cout<<endl<<"Enter the element you want to swap: ";
//     cin>>n;
//     if(index>0&&index<=a->length)
//         a->A[index-1]=n;
// }

// void Max(struct array a){
//     int max=a.A[0];
//     for(int i=1;i<a.length;i++)
//         if(max<a.A[i])
//             max=a.A[i];
//     cout<<endl<<"The max element in the array is: "<<max;
// }

// void Min(struct array a){
//     int min=a.A[0];
//     for(int i=1;i<a.length;i++)
//         if(min>a.A[i])
//             min=a.A[i];
//     cout<<endl<<"The min element is :"<<min;
// }

// void reverse1(struct array *a){
//     cout<<endl<<"The reversed array is: ";
//     int *b=new int[a->length];
//     for(int i=a->length-1,j=0;i>=0;i--,j++){
//         b[j]=a->A[i];
//     }
//     for(int i=0;i<a->length;i++){
//         a->A[i]=b[i];
//     }
//     delete []b;
// }

// void reverse2(struct array *a){
//     cout<<endl<<"The reversed array is: ";
//     int temp;
//     for(int i=0,j=a->length-1;i<j;i++,j--){
//         temp=a->A[i];
//         a->A[i]=a->A[j];
//         a->A[j]=temp;
//     }
// }

// void insert_in_sorted(struct array *a){
//     int x;
//     cout<<endl<<"Enter the element you want to insert: ";
//     cin>>x;
//     int i=a->length;
    
//     while(a->A[i-1]>x){
//         a->A[i]=a->A[i-1];
//         i--;
//     }
//     a->length++;
//     a->A[i]=x;
// }

// bool check_sorted(struct array a){
//     int c;
//     if(a.A[0]<a.A[1]){
//     for(int i=0;i<a.length-1;i++){
//         if(a.A[i]>a.A[i+1])
//             return false;
            
//         }
//         return true;
//     }
//     else{
//         for(int i=0;i<a.length-1;i++){
//         if(a.A[i]<a.A[i+1])
//             return false;
//         }
//         return true;
//     }
    
    
    
// }

// void neg_on_left(struct array *a){
//     int i=0,j=a->length-1;
//     while(i<j){
//     while(a->A[i]<0){i++;}
//     while(a->A[j]>=0){j--;}
//     if(i<j){
//     swap(&a->A[i],&a->A[j]);}}
// }

// struct array* merge(struct array *a,struct array *b){
    
//     struct array *c=(struct array *)malloc(sizeof(struct array));
//     c->length=a->length+b->length;
//     c->size=a->size+b->size;
//     c->A=new int[c->size];
    
//     int i=0,j=0,k=0;
    
//     while(i<a->length&&j<b->length){
//         if(a->A[i]<b->A[j])
//             c->A[k++]=a->A[i++];
//         else
//             c->A[k++]=b->A[j++];
//     }
//     for(;i<a->length;i++)
//         c->A[k++]=a->A[i];
//     for(;j<b->length;j++)
//         c->A[k++]=b->A[j];
    
    
//     return c;
// }

// struct array* unsorted_union(struct array a,struct array b){
//     struct array*c=(struct array *)malloc(sizeof(struct array));
//     cout<<endl<<"The union of given arrays is:-";
//     c->size=a.size+b.size;
    
//     c->A=new int[c->size];
//     if(a.length>b.length){
//         for(int i=0;i<a.length;i++){
//             c->A[i]=a.A[i];
//         }
//         c->length=a.length;
//         for(int i=0;i<b.length;i++){
//             int C=0;
//             for(int j=0;j<c->length;j++){
//                 if(c->A[j]==b.A[i]){
//                 C++;
//                 break;}
//             }
//             if(C!=0)
//                 continue;
//             c->A[c->length++]=b.A[i];
//         }
//         return c;
        
//     }
//     for(int i=0;i<b.length;i++){
//             c->A[i]=b.A[i];
//         }
//         c->length=b.length;
//         for(int i=0;i<a.length;i++){
//             int C=0;
//             for(int j=0;j<c->length;j++){
//                 if(c->A[j]==a.A[i]){
//                 C++;
//                 break;}
//             }
//             if(C!=0)
//                 continue;
//             c->A[c->length++]=a.A[i];
//         }
//     return c;
// }

// struct array* sorted_union(struct array a,struct array b){
//     int i,j,k;
//     i=j=k=0;
//     cout<<endl<<"The union of given arrays is:- "; 
//     struct array *c=(struct array *)malloc(sizeof(struct array));
//     c->size=a.size+b.size;
//     c->A=new int[c->size];
    
//     while(i<a.length&&j<b.length){
//         if(a.A[i]<b.A[j]){
//             c->A[k++]=a.A[i++];
            
//         }
//         else if(a.A[i]>b.A[j]){
//             c->A[k++]=b.A[j++];
//         }
//         else{
//             c->A[k++]=a.A[i++];
            
//             j++;
//             }
//         c->length++;
//     }
//     for(;i<a.length;i++)
//         c->A[c->length++]=a.A[i];
//     for(;j<b.length;j++)
//         c->A[c->length++]=b.A[j];
    
//     return c;
// }

// struct array* unsorted_intersection(struct array a,struct array b){
//     cout<<endl<<"The intersection of the given arrays are:- ";
//     struct array *c=(struct array *)malloc(sizeof(struct array));
//     c->size=a.size+b.size;
//     c->A=new int[c->size];
//     for(int i=0;i<a.length;i++){
//         for(int j=0;j<b.length;j++){
//             if(a.A[i]==b.A[j]){
//                 c->A[c->length++]=a.A[i];}
//         }
//     }
//     return c;
// }

// struct array* sorted_intersection(struct array a,struct array b){
//     cout<<endl<<"The intersection of the given array is:- "; 
//     struct array *c=(struct array *)malloc(sizeof(struct array));
//     c->size=a.size+b.size;
//     c->A=new int[c->size];
//     int i,j,k;
//     i=j=k=0;
//     while(i<a.length&&j<b.length){
//         if(a.A[i]<b.A[j]){
//             i++;
//             continue;
//         }
//         else if(a.A[i]>b.A[j]){
//             j++;
//             continue;
//         }
//         else{
//             c->A[c->length++]=a.A[i++];
//             j++;
//             continue;
//         }
//     }
//     return c;
    
// }

struct array* unsorted_difference(struct array a,struct array b){
    
    cout<<endl<<"Difference between given arrays is:- ";
    struct array *c=(struct array*)malloc(sizeof(struct array));
    c->size=a.size+b.size;
    c->A=new int[c->size];
    int i,j;
    i=j=0;
    if(a.length>b.length){
        for(i=0;i<a.length;i++){
            int C=0;
            for(j=0;j<b.length;j++){
                if(a.A[i]==b.A[j]){
                    C++;
                    break;  }
            }
            if(C!=0)
                continue;
            c->A[c->length++]=a.A[i];
            //c->A[c->length++]=b.A[i];
            
        }
        // for(;i<a.length;i++){
        //     c->A[c->length++]=a.A[i];
        // }
        // for(;i<b.length;i++){
        //     c->A[c->length++]=b.A[i];
        // }
        
        return c;
    }
    for(i=0;i<b.length;i++){
            int C=0;
            for(j=0;j<a.length;j++){
                if(b.A[i]==a.A[j]){
                    C++;
                    break;  }
            }
            if(C!=0)
                continue;
            c->A[c->length++]=b.A[i];
            
        
    }
    // for(;i<a.length;i++){
    //         c->A[c->length++]=a.A[i];
    //     }
    //     for(;i<b.length;i++){
    //         c->A[c->length++]=b.A[i];
    //     }
    return c;
}
int main()
{
    cout<<"Hello World"<<endl;
    
    struct array arr;
    struct array arr2;
    struct array *arr3;
    
    
    
    initialize(&arr);
    initialize(&arr2);
    
    display(arr);
    display(arr2);
    
    
    //insert(&arr);
    //append(&arr);
    //Delete(&arr);
    
    // int pos=imp_linear_search(&arr);
    
    
    // cout<<"Array is present at position "<<pos+1;
    
    
    
    
    // int pos=B_search(arr);
    
    // if(pos==-1)
    //     cout<<endl<<"Element not present in list";
        
    // else
    //     cout<<endl<<"Element present at position: "<<pos;
    
    // int g=get(arr);
    
    // cout<<endl<<"The element at position "<<n<<" is "<<g;
    
    //set(&arr);
    
    // Max(arr);
    
    // Min(arr);
    
    //reverse1(&arr);
    
    //reverse2(&arr);
    
    //insert_in_sorted(&arr);
    
    // if(check_sorted(arr)){
    //     cout<<endl<<"Array sorted";
    // }
    // else if(check_sorted){
    //     cout<<endl<<"Array unsorted";
    // }
    // neg_on_left(&arr);
    
    //arr3=merge(&arr,&arr2);
    
    //arr3=unsorted_union(arr,arr2);
    //arr3=sorted_union(arr,arr2);
    
    //arr3=unsorted_intersection(arr,arr2);
    //arr3=sorted_intersection(arr,arr2);
    
    arr3=unsorted_difference(arr,arr2);
    display(*arr3);
    delete []arr.A; 
    delete []arr2.A; 
    //delete []arr3->A; 
    return 0;
}

