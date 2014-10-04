#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

string reverse_function(string s){
	string reverse="";
	for (int i=0 ; i < s.length() ; i++){
		reverse = s[i] + reverse;
	}
	return reverse;
}

int main(){
	int testcases;
	cin >> testcases;
	
	while (testcases > 0){
		string number;
		cin>>number;
		int length = number.length();
		if (length % 2 == 0){
			int half = length/2;
			string first=number.substr(0,half);
			string left=number.substr(half);
			string reverse=reverse_function(first);
			long half_num= (long) atoi(reverse.c_str());
			long left_num= (long) atoi(left.c_str());
			if (half_num > left_num) cout<<first<<half_num<<endl;
			else {
				long first_num= (long) atoi(first.c_str());
				first_num++;
				stringstream ss;
				ss << first_num;
				first = ss.str();
				cout<<first<<reverse_function(first)<<endl;
			}
		}
		else {
			int half =(int)length/2;
			string first=number.substr(0,half);
			string left=number.substr(half+1);
			string reverse=reverse_function(first);
			long half_num= (long) atoi(reverse.c_str());
			long left_num= (long) atoi(left.c_str());
			if (half_num > left_num) cout<<first<<number[half]<<half_num<<endl;
			else {
				int mid_num= number[half] - '0';
				mid_num++;
				cout<<first<<mid_num<<reverse_function(first)<<endl;
			}	
		}
		
		testcases--;
	}
	
	return 0;
}
