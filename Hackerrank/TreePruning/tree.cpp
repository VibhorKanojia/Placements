#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct Node{
	Node * parent;
	list<Node *> children;
	int index;
	long long value;
};

list<struct Node *> allNodes;
list<struct Node *>::iterator it;


void addtoTree(int u, int v){
	list<struct Node *>::iterator it1;
	list<struct Node *>::iterator it2;

	for (it = allNodes.begin() ; it!=allNodes.end() ; it++){
		if ((*it)->index == u){
		//	cout<<"found "<<u<<endl;
			it1 = it;
		}
		else if ((*it)->index == v){
		//	cout<<"found "<<v<<endl;
			it2 = it;
		}
	}
	//cout<<"indexes "<<(*it1)->index<<" "<<(*it2)->index<<endl;
	(*it1)->children.push_back(*it2);
	(*it2)->parent = *it1;	
}

void constructTree(int N){
	for (int i = 0 ; i < N ; i++){
		struct Node * mynode = new Node;
		mynode->index = i+1;
		mynode->parent = NULL;
		cin>>mynode->value;
		//cout<<"val is "<<mynode->value<<endl;
		allNodes.push_back(mynode);
	}
	
	for (int i = 1 ; i < N ; i++){
		int u,v;
		cin >> u;
		cin >> v;
		//cout<<"u is "<<u<<" v is "<<v<<endl;
		addtoTree(min(u,v), max(u,v));
	}
	
}

void printTree(){
	for (it = allNodes.begin() ; it!=allNodes.end() ; it++){
		cout<<"index "<<(*it)->index<<endl;
		cout<<"value "<<(*it)->value<<endl;
		if ((*it)->parent != NULL){
			cout<<"parent "<<(*it)->parent->index<<endl;;
		}
	}
}

long long fillWeights(long long * sub_weights, Node * cur_root){
	int arr_index = cur_root->index -1;
	long val = cur_root->value;

	if ((cur_root->children.size()) != 0 ){	
		list<Node *>::iterator newit;
		for(newit = cur_root->children.begin() ; newit != cur_root->children.end() ; newit++){
			val = val + fillWeights(sub_weights, (*newit));
		}
	}

	sub_weights[arr_index] = val;
	return val;
}

void printWeights(long long * array, int N){
	for (int i = 0 ; i < N ; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int findMin(long long * sub_weights, int N){
	int mymin = 0;
	for (int i = 0 ; i< N ; i++){
		if (sub_weights[mymin] >= sub_weights[i]){
			mymin = i;
		}
	}
	return mymin;
}

void deleteNode(long long * sub_weights,int N, int K){
	for (int i = 0 ; i < K ; i++){
		//cout<<"entered"<<endl;
		int nodeindex = findMin(sub_weights, N);
		if (nodeindex == 0){
			cout<<0<<endl;
			return;
		}
		//cout<<"node index is "<<nodeindex<<endl;
		list<Node *>:: iterator itt;
		list<Node *>:: iterator itt2;
		itt=allNodes.begin() ;
		advance(itt,nodeindex);
		//cout<<"itt index "<<(*itt)->index<<endl;
		Node * myparent = (*itt)->parent;
		while (myparent != NULL){
			sub_weights[myparent->index -1] -= sub_weights[nodeindex];
			myparent = myparent->parent;
		}
		sub_weights[nodeindex] = 10000000000;
		//printTree();
		
		for (itt2 = allNodes.begin() ; itt2 != allNodes.end() ; itt2 ++){
		//	cout<<(*itt2)->value<<endl;
			
			if ((*itt2)->parent != NULL){
			//	cout<<"parent is "<<(*itt2)->parent->index<<endl; 
				if ((*itt2)->parent == (*itt)){
					sub_weights[(*itt2)->index -1] = 10000000000;
					allNodes.erase(itt2);
					itt2--;
				}
			}
			else{
			//	cout<<"parent Null"<<endl;
			}	
		}
		
		allNodes.erase(itt);
		//printTree();
	}
}

int main() {
	int N;
	int K;
	cin >> N;
	cin >> K;
	constructTree(N);
	//printTree();
    long long sub_weights[N];
    fillWeights(sub_weights,*allNodes.begin());
    //printWeights(sub_weights, N);
    deleteNode(sub_weights, N, K);
    //printWeights(sub_weights, N);
    cout<<sub_weights[0]<<endl;
   // cout<<"Size left "<<allNodes.size()<<endl;
    return 0;
}
