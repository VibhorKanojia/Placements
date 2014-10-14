#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void printArray(vector<int> & array){
	int N = array.size();
	
	for (int i =0 ; i < N ; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void fillMax(vector<int> & array, vector<int> & max_array){
		int N = array.size();
		max_array[N-1] = array[N-1];
		for (int i = N-2 ; i >= 0 ; i--){
			if (array[i] >= max_array[i+1]){
				max_array[i] = array[i];
			}
			else{
				max_array[i] = max_array[i+1];
			}
		}
}

void calculateProfit(vector<int> & array, vector<int> & max_array){
	int N = array.size();
	long long profit = 0;
	int num_shares = 0;
	for (int i = 0 ; i < N ; i++){
		if (array[i] < max_array[i]){
			profit = profit - array[i];	
			num_shares++;
		}
		else if (array[i] == max_array[i]){
			profit = profit + (long long)array[i]*num_shares;
			num_shares = 0;
		}
	}
	cout<<profit<<endl;
}

int main(){
	int testcases;
	cin >> testcases;
	
	while(testcases--){
		int N;
		cin >> N;
		vector<int> array;
		vector<int> max_array(N,0);
		for (int i = 0 ; i < N ; i++){
			int a;
			cin >> a;
			array.push_back(a);
		}
		fillMax(array, max_array);
		//printArray(array);
		//printArray(max_array);
		calculateProfit(array,max_array);
		
	}
}
