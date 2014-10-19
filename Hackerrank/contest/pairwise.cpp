#include <iostream>
using namespace std;

int main(){
	int testcases;
	cin >> testcases;
	while (testcases--){
		int N;
		cin >> N;
		int array[N];
		long long sum = 0;
		int num1= 0;
		int num2=0;
		for (int i = 0 ; i < N ; i++){
			cin>>array[i];
			if (array[i] == 1){
				num1++;
			}
			else if (array[i] == 2){
				num2++;
			}
		}
		sum = (long long)num1*(N-1) + (long long)(num2*(num2-1))/2;
		cout<<sum<<endl;
	}
	
	return 0;
}
