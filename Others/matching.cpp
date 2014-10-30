#include <bits/stdc++.h>
using namespace std;

bool matchFound(int N, int ** array, int Jobdata[], int Seen[], int u){

	for (int i = 0 ; i < N ; i++){							//searching every job for this person u
		if (array[u][i] == 1 && !Seen[i]){
			Seen[i] = 1;					// seen this job . If not allotted to anyone else , allot this job to the guy.

			if (Jobdata[i] == -1 || matchFound(N, array, Jobdata, Seen, Jobdata[i])){				// Match found is called with the person currently allocated this job. 
				Jobdata[i]= u;														// Therefore if we can allot that person another job then we are done.
				return true;			
			}
		}
	}
	return false;
}


int findMatching(int N , int **array){
	int Jobdata[N];						// N is no. of Jobs
	for (int i = 0 ; i < N ; i++){
		Jobdata[i] =-1;
	}

	int result = 0;
	for (int i = 0 ; i < N ; i++){
		int Seen[N];					// N is no. of Jobs. Seen[j]= 1 if the i has seen job j;

		for (int j = 0 ; j < N ; j++){
			Seen[j] =0;
		}

		if (matchFound( N, array, Jobdata, Seen , i)){
			result++;
		}

	}
	cout<<result<<endl;
	return result;
} 


int main(){
	int N;
	cin >> N;
	int ** array = new int*[N];
	for (int i = 0 ; i < N ; i++){
		array[i] = new int[N];
	} 

	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < N ; j++){
			cin >> array[i][j];
		}
	}

	int ans = findMatching(N, array);

	return 0;
}