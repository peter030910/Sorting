#include <bits/stdc++.h>
using namespace std;
#define N 10000

vector<int> merge(vector<int> A, int L1, int R1, int L2, int R2) {
	vector<int> temp;
	while (L1 <= R1 && L2 <= R2) {
		if (A[L1] <= A[L2])
			temp.push_back(A[L1++]);
		else
			temp.push_back(A[L2++]);
	}
	while (L1 <= R1) { temp.push_back(A[L1++]); }
	while (L2 <= R2) { temp.push_back(A[L2++]); }
	return temp;
}

int main() {
	vector<int> A(N,0);
	srand(time(0));
	generate(A.begin(),A.end(),rand);
	int n = A.size();
	int len = 1;
	while (len<n) {
		int i = 0;
		while (i < n) {
			int L1 = i;
			int R1 = i + len - 1;
			int L2 = i + len;
			int R2 = i + len*2 - 1;
			if (L2 >= n) break;
			if (R2 >= n) R2 = n - 1;
            vector<int> temp = merge(A, L1, R1, L2, R2);
            for (int j = 0;j <= R2 - L1 ;j++) { A[i + j] = temp[j]; }
            i = i + len * 2;
		}
		len = len * 2;
	}
	cout << "Finished" <<endl ;
    return 0;
}
