#include <iostream>
using namespace std;

int mymodulus(int num1 , int num2){
	return (num2-num1)%num2;
	
}

int main(){
	
	int n;
	cin >> n;
	int m;
	cin >> m;
	int array[n];
	int pointer = 0;
	for (int i = 0 ; i < n ; i++){
		int val;
		cin >> val;
		array[i] = val;
	}	
	
	for (int i =0 ; i < m ; i++){
		char c;
		int v;
		cin >> c;
		cin >> v;
		if (c == 'C'){
			pointer = (pointer - v)%n;
		}
		else if (c == 'A'){
			pointer = (pointer + v)%n;
		}
		else if (c == 'R'){
			//cout<<"ptr is " <<pointer<< endl;
			int val = mymodulus(pointer,n);
			//cout<<"val is " <<val<< endl;
			cout<<array[(v+val-1)%n]<<endl;
		}
	}
	return 0;	
}
