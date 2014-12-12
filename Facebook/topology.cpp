#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
using namespace std;

int main(){

	int N;
	cin >> N;

	string Words[N];
	vector < list<char> > graph;

	for (int i = 0 ; i < 26 ; i++){
		list<char> l = *new list<char>();
		graph.push_back(l);
	}

	for (int i = 0 ; i < N ; i++){
		cin >> Words[i];
	}

	for (int i = 0 ; i < N -1 ; i++){
		int size = min(Words[i].size() , Words[i+1].size());

		for (int j = 0 ; j < size ; j++){
			if (Words[i][j] == Words[i+1][j]) continue;
			else {

				graph[Words[i][j] - 'a'].push_back(Words[i+1][j]);
				break;
			}
		}
	}

		
		stack<char> dfsstack;
		dfsstack.push(Words[0][0]);
	
		vector<char> finalvector;
		while(!dfsstack.empty()){
			char c = dfsstack.top();
			dfsstack.pop();
			int startindex = c - 97;
			finalvector.push_back(c);
			list<char>::iterator it;
			for (it = (graph[startindex]).begin(); it != (graph[startindex]).end() ; it++){
				dfsstack.push(*it);			
			}
		}
	
		for(int i = 0 ; i < finalvector.size() ; i++){
			cout<<finalvector[i]<<" ";
		}

	return 0;
}