#include <bits/stdc++.h>

using namespace std;
struct Edge;

struct Node{
	int dist;
	int state;
	Node * parent;
	Node(){
		dist = 1000000000;
		parent = NULL;
		state = 0;
	}
	list<Edge *> edges;
};

struct Edge{
	float weight;
	Node * v;
};

void applyBFS(vector<Node *> & Graph , int s){
	queue<Node *> temp_queue;
	Graph[s]->state = 1;
	Graph[s]->dist = 0;
	temp_queue.push(Graph[s]);
	while (!temp_queue.empty()){
		Node * cur_node = temp_queue.front();
		list<Edge *>::iterator it;
		for (it = (cur_node->edges).begin() ; it != (cur_node->edges).end() ; it++){
			Node * child = (*it)->v;
			if (child->state == 0){
				child->parent = cur_node;
				child->state = 1;
				child->dist = cur_node->dist +1;
				temp_queue.push(child);
			}
		}
		cur_node->state = 2;
		temp_queue.pop();
	}
}


void printDistance(vector<Node *> & Graph){
	int size = Graph.size();
	for (int i = 0 ; i < size ; i++){
		cout<<i<<" "<<Graph[i]->dist<<endl;
	}
}

int main(){
	int N;
	cin >> N;
	vector<Node *> Graph;
	for (int i = 0 ; i < N ; i++){
		Node * n = new Node;
		Graph.push_back(n);
	}
	

	int E;
	cin >> E;
	for (int i =0 ; i < E ; i++){
		Edge * e1 = new Edge;
		Edge * e2 = new Edge;
		int u;
		int v;
		cin >> u;
		cin >> v;

		e1->v = Graph[v];
		e2->v = Graph[u];
		e1->weight = 1;
		e2->weight = 1;
		(Graph[u]->edges).push_back(e1);
		(Graph[v]->edges).push_back(e2);
	}

	applyBFS(Graph, 0);
	printDistance(Graph);

	return 0;
}