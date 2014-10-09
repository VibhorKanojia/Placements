#include <iostream>
#include <string>
#include <map>
using namespace std;


void printMap(map<char,int> conversion){
	map<char,int>::iterator it;
	for (it=conversion.begin() ; it!=conversion.end() ;it++){
		cout<<(it)->first<<" "<<(it)->second<<endl;
	}

} 

int main(){
	int testcases;
	cin >> testcases;
	int case_num=1;
	while (testcases--){
		map<char,int> conversion;
		map<char,int>::iterator it;
		string s;
		cin >> s;
		int count  = 0;
		long long sum = 0;
		int size = s.size();
		for (int i = 0 ; i < size ; i++){
			if (i == 0){
				conversion.insert(pair<char,int>(s[i],1));
			}
			
			else if (conversion.insert(pair<char,int>(s[i],count)).second){
				count++;
				if (count == 1){
					count++;
				}
			}
		}
		if (count == 0){
			count =2;
		}
		//printMap (conversion);
		//cout<<count<<endl;
		long long base =1;
		for (int i = size -1 ; i >=0 ; i--){
			sum = sum + (conversion.find(s[i])->second)*base;	
			base= base*count;
		}
		
		cout<<"Case #"<<case_num<<": "<<sum<<endl;
		case_num++;
		 
	}
	
	
	
	
	return 0;
}
