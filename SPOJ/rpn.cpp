#include <iostream>
#include <string>
#include <stack>
using namespace std;


stack<char> operators;

string parse(string exp){
	string postfix="";
	for (int i=0; i< exp.length(); i++){
		if ( 96 < exp[i] && exp[i]< 123){
			postfix = postfix + exp[i];
		}
		else if ( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^'){
			operators.push(exp[i]);
		}
		else if ( exp[i] == ')') {
			char c = operators.top();
			operators.pop();
			postfix = postfix + c;
		}
	}
	return postfix;
}


int main(){
	int testcases;
	cin >> testcases;
	while (testcases > 0){
		string exp;
		cin >> exp;
		string rpn = parse(exp);
		cout<<rpn<<endl;
		testcases --;
	}
	return 0;
}
