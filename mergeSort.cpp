#include<bits/stdc++.h>
using namespace std;
#define N 10000


void Merge(vector<int>&A,int L,int mid,int R){
    vector<int> temp;
    int i = L,j=mid+1;
    while(i<=mid&&j<=R){
        if(A[i]>A[j]) temp.push_back(A[j++]);
        else temp.push_back(A[i++]);
    }
    while(i<=mid) temp.push_back(A[i++]);
    while(j<=R) temp.push_back(A[j++]);
    for(int i=L;i<=R;i++) A[i] = temp[i-L];
}


void MergeSort(vector<int>&A,int L,int R){
    if(L<R){
        int mid = (L+R)/2;
        MergeSort(A,L,mid);
        MergeSort(A,mid+1,R);
        Merge(A,L,mid,R);
    }

}


int main(){
     vector<int> A(N,0);
    int n = A.size();
	srand(time(0));
	generate(A.begin(),A.end(),rand);
    MergeSort(A,0,A.size()-1);
    cout<<"Finished"<<endl;
    return 0;
}

