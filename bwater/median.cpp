#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

void balanceSets(multiset<double> & minset, multiset<double> & maxset, int minsize, int maxsize){
	multiset<double>::iterator it;
	while (minset.size() < minsize){
		it = maxset.begin();
		minset.insert(*it);
		maxset.erase(it);
	}

	while (maxset.size() < maxsize){
		it = minset.end();
		it--;
		maxset.insert(*it);
		minset.erase(it);
	}
}	

int main(){
	int N;
	cin >> N;
	double diff;
	cin >> diff;

	bool isOdd = false;

	if (N%2){
		isOdd = true;
	}


	int maxsize = (int)(N/2);
	int minsize = N - maxsize;
	
 	queue<double> indexqueue;
	multiset<double> minset;
	multiset<double> maxset;

	for (int i = 0 ; i < N ; i++){
		double val;
		if(cin >>val){
			minset.insert(val);
			indexqueue.push(val);	
		}
		else return 0;
	}

	balanceSets(minset,maxset, minsize, maxsize);

	double cur_val;
	multiset<double>::iterator it;

	double median;

	if (isOdd){
		it = minset.end();
		it--;
		median = (*it);
	}

	else{
		it = minset.end();
		it--;
		median = (*it);
		it = maxset.begin();
		median = (median + (*it))/2;
	}
	while (cin >> cur_val){
		indexqueue.push(cur_val);
		double removeElem = indexqueue.front();
		indexqueue.pop();
		if (removeElem > median){
			it = maxset.find(removeElem);
				maxset.erase(it);
		}

		else if (removeElem <= median){
			it = minset.find(removeElem);
				minset.erase(it);
		}


		if (abs(cur_val - median) > diff*median ){
			cout.precision(3);
			cout<<fixed <<cur_val<<endl;
		}


		if (cur_val > median ){
			maxset.insert(cur_val);
		}
		else{
			minset.insert(cur_val);
		}

		balanceSets(minset, maxset, minsize, maxsize);

		if (isOdd){
			it = minset.end();
			it--;
			median = (*it);
		}

		else {
			it = minset.end();
			it--;
			median = (*it);
			it = maxset.begin();
			median = (median + (*it))/2;
		}
	}



	return 0;
}









