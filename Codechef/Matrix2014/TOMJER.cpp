#include <iostream>
using namespace std;

int main(){
	int testcases;
	cin >> testcases;
	while (testcases--){
		int N;
		cin >> N;
		N = N - 1;
		long long ans = 1;
		cout<< (ans << N)%1000 <<endl;
	}
	return 0;
}