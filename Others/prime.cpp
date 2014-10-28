#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000					//pre calculating primes less than MAX


struct data{
	int num;
	int flag;
};

int main(){
	int N;
	cin >>N;
	struct data array[MAX];
	vector<int> primes;

	for (int i = 0 ; i < MAX ; i++){
		struct data d;
		d.num = i+2;
		d.flag = 1;
		array[i]=d;
	}

	for (int i = 0; i < MAX ; i++){
		if (array[i].flag == 0){
			continue;
		}
		else{
			int mynum = array[i].num;
			primes.push_back(mynum);

			for (int j = 2*mynum ; j < MAX ; j= j+mynum){
				array[j-2].flag = 0;
			}
		}
	}

	for (int i =0 ; i < N ; i++){
		cout<<primes[i]<<" ";
	}
	cout<<endl;


	return 0;
}