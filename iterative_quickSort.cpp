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
    int Stack[R-L+1];
    int top = -1;
    Stack[++top] = L;
    Stack[++top] = R;
    while (top >= 0) {
        R = Stack[top--];
        L = Stack[top--];
        int p = Partition(A, L, R);
        if (p - 1 > L) {
            Stack[++top] = L;
            Stack[++top] = p - 1;
        }
        if (p + 1 < R) {
            Stack[++top] = p + 1;
            Stack[++top] = R;
        }
    }
}

int main(){
    vector<int> A(N,0);
    int n = A.size();
	srand(time(0));
	generate(A.begin(),A.end(),rand);
    QuickSort(A,0,n-1);
    cout << "Finished" <<endl ;
    return 0;
}
