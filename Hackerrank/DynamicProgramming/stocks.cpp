#include <iostream>
#include <cmath>
#include <vector>
using namespace std;



int applyDP(int cost,int index, int num_shares, vector<int> array, vector<int> memo){
	int N = array.size();
	if (index > N-1){
		return -1*cost;
	}
	int earning1 = applyDP(cost-array[index]*num_shares,index+1,0,array,memo);
	int earning2 = applyDP(cost+array[index], index+1, num_shares+1, array,memo);
	int earning3 = applyDP(cost, index+1, num_shares, array,memo);
	return max(earning1, max(earning2, earning3));
}

int main(){
	int testcases;
	cin >> testcases;
	
	while(testcases--){
		int N;
		cin >> N;
		vector<int> array;
		vector<int> memo(N,0);
		for (int i = 0 ; i < N ; i++){
			int a;
			cin >> a;
			array.push_back(a);
		}
		int ans = applyDP(0,0,0,array,memo);
		cout<<ans<<endl;	
	}
}
