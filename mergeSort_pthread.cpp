#include<bits/stdc++.h>
using namespace std;
#define N 20000

vector<int> A(N,0);
int part = 0;

void Merge(int L,int mid,int R){
    vector<int> temp;
    int i = L,j=mid+1;
    while(i<=mid&&j<=R){
        if(A[i]>=A[j]) temp.push_back(A[j++]);
        else temp.push_back(A[i++]);
    }
    while(i<=mid) temp.push_back(A[i++]);
    while(j<=R) temp.push_back(A[j++]);
    for(int i=L;i<=R;i++) A[i] = temp[i-L];
}


void MergeSort(int L,int R){
    if(L<R){
        int mid = (L+R)/2;
        MergeSort(L,mid);
        MergeSort(mid+1,R);
        Merge(L,mid,R);
    }

}

void* MergeSort(void* arg){
    int thread_part = part++;
    int low = thread_part*(N/4);
    int high = (thread_part+1)*(N/4)-1;
    int mid = low+(high-low)/2;
    if(low<high){
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
    }
}


int main(){
    int n = A.size();
    srand(time(0));
    generate(A.begin(),A.end(),rand);
    pthread_t threads[4];
    for(int i=0;i<4;i++)
        pthread_create(&threads[i],NULL,MergeSort,(void*)NULL);
    for(int i=0;i<4;i++)
        pthread_join(threads[i],NULL);
    Merge(0,(N/2-1)/2,N/2-1);
    Merge(N/2,N/2+(N-1-N/2)/2,N-1);
    Merge(0,(N-1)/2,N-1);
    cout<<"Finished"<<endl;
    return 0;
}

