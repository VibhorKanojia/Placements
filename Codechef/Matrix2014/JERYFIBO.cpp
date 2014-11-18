#include <iostream>
#include <cmath>
using namespace std;

bool checkSquare(long long N){
	double sn = sqrt(N);
	long long snint = (long long)sn;
	if (snint == sn){
		return true;
	}
	else {
		return false;
	}
}
int main(){
	int testcases;
	cin >> testcases;
	while (testcases--){
		long long N;
		cin >> N;
		long long sqrN1 = 5*N*N + 4;
		if (checkSquare(sqrN1) || checkSquare(sqrN1-8)) {
			cout<<"is fibo"<<endl;
		}
		else{
			cout<<"not fibo"<<endl;
		}
	}
	return 0;
}