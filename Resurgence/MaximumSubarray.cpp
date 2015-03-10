#include <iostream>
#include <queue>
using namespace std;

int main(){
	int testcases;
	cin >> testcases;

	while (testcases--){
		int N;
		cin >> N;
		int array[N];
		int subarray[N];
		queue<int> myqueue;
		int cursum = 0;
		for (int i = 0 ; i < N ; i++){
			cin >> array[i];
		}

		for (int i = 0 ; i < N ; i++){
			myqueue.push(array[i]);
			cursum = cursum + array[i];
			if (cursum < array[i]){
				while (cursum < array[i]){
					int front = myqueue.front();
					myqueue.pop();
					cursum = cursum - front;
				}
				subarray[i] = cursum;
			}
			else {
				subarray[i] = cursum;
			}
		}
		int maxcont = -100000000;
		int maxval = -100000000;
		int maxnoncont = 0;
		int negflag = 0;
		for (int i = 0 ; i < N ; i++){

			if (maxcont < subarray[i]){
				maxcont = subarray[i];
			}
			if (maxval < array[i]){
				maxval = array[i];
			}
			if (array[i] > 0){
				negflag =1;
				maxnoncont = maxnoncont + array[i];
			}
		}
		if (negflag == 0) maxnoncont = maxval;


		cout<<maxcont<<" "<<maxnoncont<<endl;	
		
	}

	return 0;
}








