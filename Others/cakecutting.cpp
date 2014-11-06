#include <bits/stdc++.h>

using namespace std;

int main(){
	int testcases;
	cin >> testcases;
	vector<long long> myvector(1000000,-1);
	myvector[0] = 1;
	int mycount = 0;
	while (testcases-- ){
		long long N;
		cin >> N;
		long long val = myvector[mycount];
		//cout<<val<<" "<<mycount<<endl;
		if (val == N) {
			cout<<mycount<<endl;
		}
		else if (val > N){
			for (int i = 0 ; i <= mycount ; i++){
				if (myvector[i] >= N ){
					cout<<i<<endl;
					break;
				}
			}
		}
		else {
			for (int i = mycount + 1 ; val < N ; i++){
				myvector[i] = (i*i + i + 2)/2;
				mycount++;
				val = myvector[i];
			}
			cout<<mycount<<endl;
		}	
	}
	/*
	for (int i = 0 ; i <= mycount ; i++){
		cout<<myvector[i]<<" ";
	}
	*/
	
	return 0;
}