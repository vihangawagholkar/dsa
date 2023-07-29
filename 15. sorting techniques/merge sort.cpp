#include <iostream>

using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void Merge(int A[], int l, int mid, int h){
	int i,j,k;
	int B[100];
	i=l,j=mid+1,k=l;

	while(i<=mid && j<=h){
		if(A[i]<A[j]){
			B[k++]=A[i++];
		}

		else
			B[k++]=A[j++];
	}

	while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= h){
        B[k++] = A[j++];
    }

    for (int i=l; i<=h; i++){
        A[i] = B[i];
    }

}

void IMergeSort(int A[], int n){
	int p,i,l,mid,h;

	for(p=2;p<=n;p=p*2){
		for(i=0;i+p-1<n;i=i+p){
			l=i;
			h=i+p-1;
			mid=(l+h)/2;

			Merge(A,l,mid,h);
		}
		if(n-i>p/2)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A, l, mid, n-1);
        }
	}
	if(p/2<n)
		Merge(A,0,p/2-1,n-1);
}
		

void RmergeSort(int A[], int l, int h){
	int mid=0;
	if(l<h){
		mid=(l+h)/2;
		RmergeSort(A, l, mid);
		RmergeSort(A, mid+1, h);
		Merge(A,l,mid,h);
	}
}

int main(){
	//Your code here
	
	int A[]={8,3,7,4,9,2,6,5,1};
	int n = sizeof(A)/sizeof(A[0]);

	// cout<<n<<endl;
	Print(A, n, "\t\tA");

	// IMergeSort(A,n);
	
	RmergeSort(A,0,n-1);
    
    Print(A, n, "\t\tA");

	return 0;
}