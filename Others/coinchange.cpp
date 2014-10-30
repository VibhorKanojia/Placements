#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int findOptimal(int denominations[], int memo[], int N, int val){
	if (memo[val] != -1){
		return memo[val];
	}
	if (val <= 0) return 0;
	int mymin = findOptimal(denominations, memo, N , val-denominations[0]);
	for (int i = 1 ; i < N ; i++){
		if (val >= denominations[i]){
			mymin = min(mymin, findOptimal(denominations, memo, N, val - denominations[i])); 
		}
	}

	memo[val] = mymin+1;
	return mymin+1;
}


int main(){
	int N;
	cin >> N;					// number of denominations
	int denominations[N];	
	int memo[MAX];				// memoization

	for (int i = 0 ; i < MAX ; i++){
		memo[i] = -1;
	}

	for (int i = 0 ; i < N ; i++){
		cin >> denominations[i];
	}

	int t;						// testcases
	cin >> t;
	while(t--){
		int val;				// value whose change is to be found.
		cin >> val;
		int ans = findOptimal(denominations, memo, N, val);
		cout << ans<<endl;
	}

	return 0;
}