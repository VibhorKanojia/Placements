#include <iostream>
#include <list>
using namespace std;

int main(){
	int N;
	cin >> N;

	list<double> window;
	double mean = 0;
	for (int i = 0 ; i < N ; i++){
		double val;
		if (cin >> val){
			window.push_back(val);
		}
		else{
			return 0;
		}
	}
	double sum = 0;
	list<double>::reverse_iterator rit;
	for (rit=window.rbegin() ; rit != window.rend() ; rit++){
		sum = sum + (*rit);
	}


	mean = sum/N;
	cout.precision(3);
	cout<<fixed<<mean<<endl;

	double cur_val;
	list<double>::iterator it;
	while (cin>>cur_val){
		it = window.begin();
		double removeElem = (*it);
		window.erase(it);
		window.push_back(cur_val);
		sum = 0;
		for (rit=window.rbegin() ; rit != window.rend() ; rit++){
			sum = sum + (*rit);
		}	
		mean  = sum/N;
		cout<<fixed<<mean<<endl;
	}



	return 0;
}