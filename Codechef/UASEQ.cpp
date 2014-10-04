#include <iostream>
using namespace std;

int main(){
	int N;
	int K;
	cin >> N;
	cin >> K;
	int array[N];
	for (int i =0 ; i < N ; i++){
		cin >> array[i];
	}
	int c1 = 0;
	int max_diff = array[1] - array[0];
	for (int i = 1 ; i < N-1 ; i++){
		if (array[i+1] - array[i] > max_diff){
			max_diff = array[i+1] - array[i];
			c1 = i;
		}
	}
	for (int i = 0 ; i< N ; i++){
		if (i == c1){
			cout<<array[c1]<<" ";
		}
		else {
			cout<<array[c1]-(c1-i)*max_diff<<" ";
		}
	}
	cout<<endl;
	


return 0;	
}
