#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define long long long

void fillBricks(vector<int> & bricks, int N){

	for (int i = 0 ; i < N ; i++){
		int num;
		cin >> num;
		bricks.push_back(num);
	}
}

long returnMin(long a1,long a2,long a3){
	long temp_max = a1 <= a2 && a1 <= a3 ? a1 : a2 <= a3 ? a2 : a3;
	return temp_max;
}

long applyDP(vector<int> & bricks,int N, vector<long> & array){
	long sum = 0;
	for (int i = N-1 ; i >= 0 ; i--){
		sum = sum + bricks[i];
		array[i] = sum - returnMin(array[i+1], array[i+2], array[i+3]);
	}
	
	return array[0];
}


int main(){
	int testcases;
	cin >> testcases;
	while (testcases--){
		int N;
		cin >> N;
		vector<int> bricks;
		vector<long> array = *new vector<long>(N+3,0);
		fillBricks(bricks,N);
		long score = applyDP(bricks,N, array);
		cout<<score<<endl;
		
	}
}
