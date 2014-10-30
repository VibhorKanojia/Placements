#include <bits/stdc++.h>

using namespace std;

int findZero(int cumm[], int N){
	int count = 0;
	for (int i = 0 ; i < N ; i++){
		if (cumm[i] == 0){
			count++;
		}
	}
	return count;
}

int combination(int n , int r){
	if (r > n) return 0;
	int numerator = 1;
	int denominator = 1;
	for (int i = 1 ; i <=r ; i++){
		numerator = numerator*(n-i+1);
		denominator = denominator*i;
	}
	return (numerator/denominator);
}

void printArray(int array[], int N){
	for (int i = 0 ; i < N ; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int N;
	cin >>N;
	int array[N];
	int cumm[N];
	int countarray[2*N+1];
	for (int i = 0 ; i < N ; i++){
		cin>>array[i];
		if (array[i] == 0){
			array[i] = -1;
		}
	}

	cumm[0]= array[0];

	for (int i = 1 ; i < N ; i++){
		cumm[i] = cumm[i-1] + array[i];
	}


	int ans = findZero(cumm,N);

	for (int i = 0 ; i <= 2*N ; i++){
		countarray[i]= 0; 
	}
	for (int i = 0 ; i < N ; i++){
		countarray[cumm[i] + N] = countarray[cumm[i] + N] + 1 ;
	}

	//printArray(array, N);
	//printArray(cumm, N);
	//printArray(countarray, 2*N+1);

	for (int i =0 ; i < 2*N +1 ; i++){
		ans = ans + combination(countarray[i],2); 
	}
	cout<<ans<<endl;

	return 0;
}





