#include <bits/stdc++.h>

using namespace std;

int clickCount = 0;

int callRecursion(char ** array, int i , int j){
	if (array[i-1][j] == '*' || array[i+1][j] == '*' || array[i-1][j-1] == '*' || array[i+1][j+1] == '*' || array[i+1][j-1] == '*' || array[i-1][j+1] == '*' || array[i][j-1] == '*' || array[i][j+1] == '*')
	{
		return 0;
	}
	else {
		array[i][j]='-';
		
		if (array[i-1][j] == '.'){
			callRecursion(array , i-1, j);
		}
		if (array[i-1][j-1] == '.'){
			callRecursion(array , i-1, j-1);
		}
		if (array[i-1][j+1] == '.'){
			callRecursion(array , i-1, j+1);
		}
		if (array[i][j-1] == '.'){
			callRecursion(array , i, j-1);
		}
		if (array[i][j+1] == '.'){
			callRecursion(array , i, j+1);
		}
		if (array[i+1][j-1] == '.'){
			callRecursion(array , i+1, j-1);
		}
		if (array[i+1][j] == '.'){
			callRecursion(array , i+1, j);
		}
		if (array[i+1][j+1] == '.'){
			callRecursion(array , i+1, j+1);
		}
		array[i-1][j]='-';
		array[i+1][j]='-';
		array[i][j-1]='-';
		array[i][j+1]='-';
		array[i+1][j+1]='-';
		array[i+1][j-1]='-';
		array[i-1][j+1]='-';
		array[i-1][j-1]='-';
		return 1;
	}
}


int main(){
	int testcases;
	cin >> testcases;
	int case_num = 1;
	while (testcases--){
		clickCount =0;
		int N;
		cin >> N;
		char ** array = new char*[N+2];
		for (int i = 0 ; i < N+2 ; i++){
			array[i] = new char[N+2];
		}

		for (int i = 0 ; i < N+2 ; i++){
			for (int j = 0 ; j < N+2 ; j++){
				array[i][j] = '+';
			}
		}

		for(int i = 0 ; i < N ; i++){
			for (int j = 0 ; j < N ; j++){
				cin>>array[i+1][j+1];
			}	
		}
		
		for (int i = 1 ; i < N+1 ; i++){
			for (int j = 1 ; j< N+1 ; j++){
				if (array[i][j] == '.'){
					int res = callRecursion(array, i , j );
					if (res == 1) {
						clickCount++;
					}
				}
			}
		}

		for (int i = 1 ; i < N+1 ; i++){
			for (int j = 1 ; j< N+1 ; j++){
				if (array[i][j] == '.'){
					clickCount++;
				}
			}
		}

		cout<<"Case #"<<case_num<<": "<<clickCount<<endl;
		case_num++;

	}
}