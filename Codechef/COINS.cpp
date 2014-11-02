#include <bits/stdc++.h>

using namespace std;



long long mymax(vector<long long> & tempvector){
	long long size = tempvector.size();
	long long max_val = tempvector[0];

	for (int i = 0 ; i < size ; i++){
		if (tempvector[i] > max_val){
			max_val = tempvector[i];
		}
	}

	return max_val;
}

long long applyDP(long long N, map<long long, long long> & memo){
	map<long long, long long>:: iterator it;
	if (N <= 5){
		it = memo.find(N);
		if (it != memo.end()){
			return it->second;
		}
		else{
			memo.insert(std::pair<long long, long long>(N, N));
		}
		return N;
	}

	it = memo.find(N);
	if (it != memo.end()){
		return it->second;
	}


	long long a = N/2;
	long long b = N/3;
	long long c = N/4;
	vector<long long> tempvector;
	if (N < 25){
		tempvector.push_back(N);
	}
	tempvector.push_back(applyDP(a, memo)+ applyDP(b, memo)+applyDP(c, memo));
	tempvector.push_back(applyDP(a, memo)+applyDP(b, memo) + c);
	tempvector.push_back(applyDP(a, memo)+applyDP(c, memo) + b);
	tempvector.push_back(applyDP(b, memo)+applyDP(c, memo) + a);
	tempvector.push_back(applyDP(a, memo) + b + c);
	tempvector.push_back(applyDP(b, memo) + c + a);
	tempvector.push_back(applyDP(c, memo) + b + a);
	tempvector.push_back(a+b+c);
	long long ans = mymax(tempvector);
	memo.insert(std::pair<long long, long long>(N, ans));
	return ans;

}

int main(){
	long long N;
	while(cin>>N){
		map<long long, long long> memo;
		
		long long ans = applyDP(N, memo);
		cout<<ans<<endl;
	}

	return 0;	
}