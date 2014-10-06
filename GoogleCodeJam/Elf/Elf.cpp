#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

void parseFraction(long long & p, long long & q, string fraction){
	int found = fraction.find('/'); 
	p = atoll(fraction.substr(0,found).c_str());
	q = atoll(fraction.substr(found+1).c_str());		//atoi works... remember this!! include stdlib.h and convert to char*
}


long long findHCF(long long a, long long b){
	if (a%b == 0){
		return b;
	}
	else{ 
		long long quot = a/b;
		return findHCF(b,a-(quot*b));
	}
	
}

void dividebyHCF(long long & P, long long & Q){
	long long a =	P>=Q?P:Q;
	long long b = 	P>=Q?Q:P;
	
	long long h = findHCF(a,b);
	P = P/h;
	Q = Q/h; 
}


bool checkPQ(long long & P, long long & Q){
	long long m = Q;
	while(m%2 == 0){
		m = m/2;
		if (m == 1){
			return true;
		}	
	}
	return false;
}


void countAncestors(long long & P, long long & Q, int & count){
	if (P == 1){
		count = count + (log(Q)/log(2));
	}
	else if (P == Q){
		return;
	}
	Q = Q/2;
	
	if (P > Q){
		count++;
		return;
	}
	
	else if (P < Q){
		for (int i = P ; i !=1 ; i--){
			if ( Q % i == 0){
				count++;
				Q = Q/i;
				P=1;
				countAncestors(P,Q,count);
				return;
			}
		}
	}
}

int main (){
	int testcases;
	cin >> testcases;
	int case_num =1;
	while (testcases--){
		string fraction;
		cin>> fraction;
		long long P, Q;
		parseFraction(P,Q,fraction);
		dividebyHCF(P,Q);
		bool a = checkPQ(P,Q);
		if (!a){
			cout<<"Case #"<<case_num<<": impossible"<<endl;
		}
		else{
			
			int count = 0;
			countAncestors(P,Q,count);
			cout<<"Case #"<<case_num<<": "<<count<<endl;
		
		}
		case_num++;
	}
}
