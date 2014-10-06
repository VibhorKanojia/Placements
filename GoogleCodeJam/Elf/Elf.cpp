#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void parseFraction(double & p, double & q, string fraction){
	int found = fraction.find('/'); 
	p = atoi(fraction.substr(0,found).c_str());
	q = atoi(fraction.substr(found+1).c_str());		//atoi works... remember this!! include stdlib.h and convert to char*
}


bool checkPQ(double & P, double & Q){
	double val = Q/2;
	while(val != 1){
		val = val/2;
		if (val < 1){
			if (P != 1){
				Q = Q/P;
				P =1;
				return checkPQ(P,Q);
			}
			else{
				return false;
			}
		}	
	}
	return true;
}


int countAncestors(double & P, double & Q, int & count){
	if (P == 1){
		count = count + (log(Q)/log(2));
	}
	else if (P == Q){
		return count;
	}
	else if (P > Q){
		count++;
		P = P-Q;
		countAncestors(P,Q,count);
	}
	
	else if (P < Q){
		for (int i = P ; i !=1 ; i--){
			
		}
		
	}
}

int main (){
	int testcases;
	cin >> testcases;
	
	while (testcases--){
		string fraction;
		cin>> fraction;
		double P, Q;
		parseFraction(P,Q,fraction);
		bool a = checkPQ(P,Q);
		if (!a){
			cout<<"Impossible"<<endl;
		}
		else{
			int count = 0;
			countAncestors(P,Q,count);
		}
	}
}
