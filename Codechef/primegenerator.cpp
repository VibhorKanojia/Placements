#include <bits/stdc++.h>

using namespace std;

#define MYMAX  10005
struct data{
	long long val;
	bool flag;
};


void sieve(vector <struct data> & myvector){
	for (int i =2 ; i < MYMAX ; i++){
		if (!myvector[i].flag) continue;
		else{
			for (int j = 2*i ; j< MYMAX ; j=j+i){
				myvector[j].flag = 0;
			}
		}
	}
}



int main(){
	vector<struct data> myvector;
	for (long long i = 0 ; i < MYMAX ; i++){
		struct data d;
		d.val = i;
		if (i == 0 || i == 1)
			d.flag = 0;
		else d.flag = 1;
		myvector.push_back(d);
	}
	sieve(myvector);

	int testcases;
	cin >>testcases;
	while (testcases--){
		long long M,N;
		cin >>M;
		cin >>N;
	
		if (N <= MYMAX){
			for (long long i = M ; i <= N ; i++){
				if (!myvector[i].flag) continue;
				cout<<myvector[i].val<<endl;
			}
			return 0;
		}

		long long j;
		bool myflag;
		long long mysqrt;
		for (long long i = M ; i <=N ; i++){
			if (i%2 == 0 || i%3 == 0) continue;
			j = myvector[0].val;
			myflag = 0;
			mysqrt = sqrt(i)+1;
			//cout<<"calculated "<<i<<" "<<sqrt(i)<<endl;
			while (j < mysqrt){
				if (!myvector[j].flag) {
					j++;
					continue;
				}
				if (i%myvector[j].val == 0){
					myflag = 1;
					break;
				}
				j++;
			}
			if (myflag == 0){
				cout<<i<<endl;
			}
		}
	}

	return 0;
}




