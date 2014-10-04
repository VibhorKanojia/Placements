#include <iostream>
#include <string>
using namespace std;

int main(){
	int testcases;
	cin >> testcases;
	
	while (testcases--){
		string s;
		cin >>s;
		long long out = 1;
		for (int i=1 ; i<=s.length();i++){
			if (s[i-1] == 'l'){
				if (i%2 == 1){
					out = (out*2)%1000000007;
				}
				else if (i%2 == 0){
					out = (out*2-1)%1000000007;
				}
			}
			else if (s[i-1] == 'r'){
				if (i%2 == 1){
					out = (out*2+2)%1000000007;
				}
				else if (i%2 == 0){
					out = (out*2+1)%1000000007;
				}
			}
		}
		cout<<out<<endl;
	}
}
