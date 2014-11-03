#include <bits/stdc++.h>

using namespace std;

#define MYMAX  33000


void sieve(vector <int> & yourvector, vector<int> & myvector){
	for (int i =2 ; i < MYMAX ; i++){
		if (!yourvector[i]) continue;
		else{
			for (int j = 2*i ; j< MYMAX ; j=j+i){
				yourvector[j] = 0;
			}
		}
	}
	for (int i=2 ; i < MYMAX ; i++){
		if (yourvector[i])
			myvector.push_back(i);
	}
}



int main(){
	vector<int> yourvector;
	vector<int> myvector;
	for (long long i = 0 ; i < MYMAX ; i++){
		if (i == 0 || i == 1)
			yourvector.push_back(0);
		else 
			yourvector.push_back(1);
	}
	sieve(yourvector, myvector);
	int testcases;
	cin >>testcases;
	while (testcases--){
		long long M,N;
		cin >>M;
		cin >>N;
		long long j;
		bool myflag;
		long long mysqrt;
		for (long long i = M ; i <=N ; i++){
			if (i == 1) continue;
			
			j =0;
			myflag = 0;
			mysqrt = sqrt(i)+1;
			while (myvector[j] < mysqrt){
				if (i%myvector[j] == 0){
					myflag = 1;
					break;
				}
				j++;
			}
			if (myflag == 0){
				printf("%lld\n",i);
			}
		}
	}

	return 0;
}




