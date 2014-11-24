#include <iostream>
#include <queue>
using namespace std;

int main(){
	int N;
	cin >> N;

	queue<double> windows;
	double mean = 0;
	for (int i = 0 ; i < N ; i++){
		double val;
		if (cin >> val){
			mean = mean + val;
			windows.push(val);
		}
		else{
			return 0;
		}
	}

	mean = mean/N;
	cout.precision(3);
	cout<<fixed<<mean<<endl;

	double cur_val;
	while (cin>>cur_val){
		double removeElem = windows.front();
		windows.pop();
		windows.push(cur_val);
		mean  = (mean*N - removeElem + cur_val)/N;
		cout<<fixed<<mean<<endl;
	}



	return 0;
}