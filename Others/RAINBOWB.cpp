#include <iostream>
using namespace std;

#define MAX 1000000007
#define MAXFACT 641102369
#define INVERSE 397802501
int factorial[1000001];
int inverse[1000001];

void fact_mod(){
	factorial[0]=1;
	for (int i=1 ; i < 1000001; i++){
		factorial[i]=((long long)factorial[i-1]*i)%MAX; 
	}
}

void fill_inverse(){
	inverse[1000000] = INVERSE;
	for (int i = 1000000-1 ; i >= 0 ; i--){
		inverse[i] = ((long long)inverse[i+1]*(i+1))%MAX;
	}
}

long long combination(int n, int r){
	return (((long long)(factorial[n]%MAX)*(long long)(inverse[r]%MAX)%MAX) *(long long)(inverse[n-r]% MAX)) % MAX;
}

int main(){
	fact_mod();
	fill_inverse();
	int n;
	cin >> n;
	if (n< 13){
		cout<<0<<endl; return 0;
	}
	else if (n%2 == 0){
		n = n-1;
	}
	int v = (n - 13)/2;
	long long sum = 0;
	for (int i = 0 ; i <= v ; i++){
		sum = sum + combination(i+5, 5);
	}
	cout<<sum%1000000007<<endl;
		
return 0;	
}
