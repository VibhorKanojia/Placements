#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int array[N];
	for (int i = 0 ; i  < N ; i++){
		cin >> array[i];
	}

	int j = N -1;
	for (int i = 0 ; i < j ; i++){
		while (array[j] == 0){
			j--;
		}

		while(array[i] != 0){
			i++;
		}
		if ( i > j) break;
		int temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}

	for (int i = 0 ; i < N ; i++){
		cout<<array[i]<<" ";
	}
	return 0;
}