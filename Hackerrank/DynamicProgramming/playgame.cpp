#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define long long long

void fillBricks(vector<int> & bricks, int N,long & sum){

	for (int i = 0 ; i < N ; i++){
		int num;
		cin >> num;
		bricks.push_back(num);
		sum = sum + num;
	}
}

long returnMax(long a1,long a2,long a3){
	long temp_max = a1 >= a2 && a1 >= a3 ? a1 : a2 >= a3 ? a2 : a3;
	return temp_max;
}

long applyDP(vector<int> & bricks, int N, int index, long sum,vector<long> & array){
	if (index>N-1){
		return 0;
	}
	
	long score=0;
	if (array[index] != -1){
		return array[index];
	}
	long val1 = applyDP(bricks, N, index+1, sum - bricks[index], array );
	long val2 = applyDP(bricks, N, index+2, sum - bricks[index] - bricks[index+1], array);
	long val3 = applyDP(bricks, N, index+3, sum - bricks[index] - bricks[index+1] - bricks[index+2], array);
	score = returnMax(sum - val1,sum - val2,sum - val3);
	array[index] = score;
	return score;
	
}


int main(){
	int testcases;
	cin >> testcases;
	while (testcases--){
		int N;
		cin >> N;
		vector<int> bricks;
		long sum=0;
		vector<long> array = *new vector<long>(N,-1);
		fillBricks(bricks,N,sum);
		cout<<"hello"<<endl;
		long score = applyDP(bricks,N,0, sum,array);
		cout<<score<<endl;
		
	}
}
