#include <iostream>
#include <string>
using namespace std;

float mismatch_penalty = 1.0;
float gap_penalty = 1.0;

float applyDP(string str1, string str2, float ** penalty){
	int size1 = str1.size();
	int size2 = str2.size();

	if (penalty[size1][size2] != -1){
		return penalty[size1][size2];
	}

	if (size1 == 0) {
		penalty[size1][size2] = size2*gap_penalty;
		return  penalty[size1][size2];
	}
	else if (size2 == 0){
		penalty[size1][size2] = size1*gap_penalty;
		return penalty[size1][size2];
	}

	else {
		float cur_penalty;
		if (str1[0] == str2[0]) cur_penalty = 0;
		else cur_penalty = mismatch_penalty;

		penalty[size1][size2] = min( 
			min(
				gap_penalty + applyDP(str1.substr(1), str2, penalty),
				gap_penalty + applyDP(str1, str2.substr(1), penalty)
				),
			cur_penalty + applyDP(str1.substr(1), str2.substr(1), penalty)
			);

		return penalty[size1][size2];
	}
}

int main(){
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;

	int size1 = str1.size();
	int size2 = str2.size();

	float **penalty = new float*[size1+1];

	for (int i = 0 ; i < size1+1 ; i++){
		penalty[i] = new float[size2+1];
	}

	for (int i = 0 ; i < size1+1 ; i++){
		for (int j = 0 ; j < size2+1 ; j++){
			penalty[i][j] = -1;
		}
	}

	applyDP(str1,str2,penalty);
	cout<<penalty[size1][size2]<<endl;
	return 0;
}