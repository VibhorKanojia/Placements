#include <iostream>
#include <list>
#include <limits.h>

using namespace std;

struct Node;
struct Edge;

struct Node{
	int index;
	list<Edge*> edges;
	Node(){
		edges = *new list<Edge*> 
	}
};

struct Edge{
	int weight;
	Node * nextnode;
};

int findDistance(int len, int source, struct Node ** graph, int N, int ** memo){
	

	if (memo[len][source] != INT_MAX){
		return memo[len][source];
	}

	if (len == 0 && source == N - 1){
		memo[len][source] = 0;
		return 0;
	}

	if (len == 0 && source != N - 1 ){
		memo[len][source] = INT_MAX;
	}

	int mindist = findDistance(len-1, source, graph, N , memo);
	list<Edge*>::iterator it;
	for (it = ((graph[source])->edges).begin() ;
		 it != ((graph[source])->edges).end() ;
		 it++)
	{
		mindist = min(mindist, (*it)->weight + findDistance(len-1, ((*it)->nextnode)->index, graph, N, memo)); 

	} 
	memo[len][source] = mindist;
	return memo[len][source];

}

int main(){
	int N;
	int M;
	cin >> N >> M;

	Node * graph[N];

	int ** memo = new int*[N];
	for (int i = 0 ; i < N ; i++){
		memo[i] = new int[M];
	}

	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < M ; j++){
			memo[i][j] = INT_MAX;
		}
	}

	for (int i =  0 ; i < N ; i++){
		graph[i] = new Node;
		graph[i]->edges = *new list<Edge*>();
		graph[i]->index = i;

	}

	cout<<"here"<<endl;
	while(M--){
		int i ;
		int j ;
		int weight;
		cin >> i >> j >> weight;
		struct Edge * e;
		e->weight = weight;
		e->nextnode = graph[j];
		(graph[i]->edges).push_back(e);
	}

	findDistance(N-1, 0,graph,N,memo);
}