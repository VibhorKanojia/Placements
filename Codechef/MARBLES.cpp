#include <bits/stdc++.h>

using namespace std;

long long Combination(long long n, long long k){
	long long ans = 1;
	for (int i = 1 ; i <= k ; i++){
		ans = ans*(n-i+1)/i;
	}
	return ans;
}

int main(){
	int testcases;
	cin >> testcases;
	while (testcases--){
		long long N;
		long long K;
		cin >>N;
		cin >>K;
		long long minK = N-K > K-1 ? K -1 : N-K;
		cout<< Combination(N-1, minK)<<endl;
	}
	return 0;
}