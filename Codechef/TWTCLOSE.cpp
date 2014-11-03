#include <bits/stdc++.h>

using namespace std;

int main(){
	int N,K;
	cin >> N;
	cin >> K;
	int opencount = 0;
	map<int,int> mymap;
	map<int,int> emptymap;
	map<int,int>::iterator it;
	while (K--){
		string s;
		cin >>s;
		if (s == "CLOSEALL"){
			mymap = emptymap;
			opencount = 0;
		}
		else {
			int num;
			cin >> num;
			it = mymap.find(num);
			if (it != mymap.end()){
				mymap.erase(it);
				opencount--;
			}
			else{
				mymap.insert(std::pair<int,int>(num,1));
				opencount++;
			}

		}
		cout<<opencount<<endl;
	}

	return 0;
}