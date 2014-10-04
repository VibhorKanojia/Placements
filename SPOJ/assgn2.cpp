#include <iostream>
#include <cmath>
using namespace std;


int main(){
	int testcases;
	cin >> testcases;
	while (testcases > 0){
		//cout<<"hello"<<endl;
		long low;
		long high;
		long i;
		cin >> low >> high;
		if (low%2 == 0){
			i = low+1;
		}
		else {
			i = low;
		}
		while (i<= high){
			long val = (long) pow(2,i);
			if ((val-2) % i == 0){
				cout<<i<<endl;
			}
			i= i+2;
		}
		
		testcases--;
	}
}
	
