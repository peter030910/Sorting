#include<bits/stdc++.h>
using namespace std;
#define N 10000

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(vector<int>& A,int L,int R){
    int pivot = A[R];
    int i = L-1;
    for(int j=L;j<R;j++){
        if(A[j]<pivot){
            i++;
            swap(&A[j],&A[i]);
        }
    }
    i++;
    swap(&A[i],&A[R]);
    return i;
}

void QuickSort(vector<int>& A,int L,int R){
    if(L<R){
        int pivot = Partition(A,L,R);
        # pragma omp parallel
        {
            # pragma omp sections
            {
                # pragma omp section
                QuickSort(A,L,pivot-1);
                # pragma omp section
                QuickSort(A,pivot+1,R);
            }
        }
    }
}


int main(){
    vector<int> A(N,0);
    int n = A.size();
	srand(time(0));
	generate(A.begin(),A.end(),rand);
    QuickSort(A,0,n-1);
    cout<<"Finished"<<endl;
    return 0;
}
