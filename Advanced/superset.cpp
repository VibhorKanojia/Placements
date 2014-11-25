//For all those problems which require you to look at all possible subsets of a given set. That is, considering all the 2^N possibilites.

#include <iostream>
#include <vector>
using namespace std;

int final_sum;

// THIS METHOD IS AN EPIC SHIT !!!!!
// SUPERSET QUESTIONS HERE I COME ---------->
// FIND OUT HOW THE LCM IS CALCULATED !!

int findLCM(vector<int> & choice){
	int num1 = choice[0];
	for (int i = 1 ; i < choice.size() ; i++){
		int num2 = choice[i];
		int c = num1*num2;
		while (num1 != num2){
			if (num1 > num2){
				num1 = num1 - num2;
			}
			else{
				num2 =num2-num1;
			}
		}
		num1 = c/num1;
	}
	return num1;
}

void fillSum(int num, vector<int> & bag, int N){
	vector<int> choice;
	int count = 0;
	int bit = num & 1;
	while (num > 0){
		num = (int)(num/2);
		if (bit == 1){		
			choice.push_back(bag[count]);
		}
		bit = num & 1;
		count++;
	}

	int LCM = findLCM(choice);
	if (choice.size() % 2 == 0){
		final_sum = final_sum - (int)(N/LCM);
	}
	else{
		final_sum = final_sum + (int)(N/LCM);
	}
}


int main(){
	int N;
	cin >> N;

	int B;
	cin >> B;

	vector<int> bag;
	for (int i = 0 ; i < B ; i++){
		int val;
		cin >> val;
		bag.push_back(val);
	}
	int super = 1;
	super =(super << B) - 1;

	for (int i = 1 ; i < super ; i++){
		fillSum(i, bag, N);
	}
	
	cout<<N-final_sum<<endl;

	return 0;
}