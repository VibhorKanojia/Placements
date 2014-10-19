#include <iostream>
using namespace std;

#define MOD 1000000007
int main(){
	int N;
	cin >> N;
	long long numbers[N];
	for (int i = 0 ; i < N ; i++){
		cin >> numbers[i];
	}
	for (int i = 0 ; i < N ; i++){
		if (i == N-1){
			break;
		}
		numbers[i+1] = numbers[i]*numbers[i+1] + numbers[i] + numbers[i+1];
	}
	cout<<numbers[N-1]%MOD<<endl;
	return 0;
}
