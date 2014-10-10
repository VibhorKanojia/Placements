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

struct data{
	long long cum_weight;
	int index;
};

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

long long fillWeights(vector<struct data> & sub_weights, Node * cur_root){

	if (allNodes.size() == 0){
		return -1;
	}
	long val = cur_root->value;

	if ((cur_root->children.size()) != 0 ){	
		list<Node *>::iterator newit;
		for(newit = cur_root->children.begin() ; newit != cur_root->children.end() ; newit++){
			val = val + fillWeights(sub_weights, (*newit));
		}
	}
	struct data mydata = *new data;
	mydata.cum_weight = val;
	mydata.index = cur_root->index;
	sub_weights.push_back(mydata);
	return val;
}

void printWeights(vector<data> & array){
	cout<<"size is " <<array.size()<<endl;
	for (int i = 0 ; i < array.size() ; i++){
		cout<<array[i].cum_weight<<" ";
	}
	cout<<endl;
}

int findMin(vector<data> & sub_weights){
	int mymin = 0;
 
	for (int i = 0 ; i< sub_weights.size() ; i++){
		if (sub_weights[mymin].cum_weight >= sub_weights[i].cum_weight && sub_weights[i].index != 1){
			mymin = i;
		}
	}
	
	return sub_weights[mymin].index;
}

void deleteNode(list<Node *>::iterator mynode){
	list<Node *>:: iterator itt;
	for (itt= allNodes.begin() ; itt !=allNodes.end() ; itt++){
		if ((*itt)->parent == *mynode){
			deleteNode(itt);
			itt--;
		}
	}
	if ((*mynode)->parent != NULL){
		list<Node *>::iterator itt2;
		for (itt2 = (*mynode)->parent->children.begin() ; itt2 != (*mynode)->parent->children.end() ; itt2++){
			if ((*itt2)->index == (*mynode)->index){
				(*mynode)->parent->children.erase(itt2);
				break;
			}
		}
	}	
			
	allNodes.erase(mynode);
}


void deleteFunction(vector<data> & sub_weights, int K){
	long long init_ans = sub_weights[sub_weights.size()-1].cum_weight;
	long long final_ans = 0 > init_ans ? 0 : init_ans;
	for (int i = 0 ; i < K ; i++){
		int nodeindex = findMin(sub_weights);
		cout<<"Node index is "<<nodeindex<<endl;
		list<Node *>:: iterator itt;
		list<Node *>:: iterator itt2;
		itt=allNodes.begin();
		while((*itt)->index != nodeindex){
			itt++;
		}
		//cout<<(*itt)->index<<endl;
		deleteNode(itt);
		//cout<<"here"<<endl;
		sub_weights.clear();
		//cout<<"here2"<<endl;
		//cout<<"New size "<<allNodes.size()<<endl;
		fillWeights(sub_weights,*allNodes.begin());
		if (allNodes.size() == 0){
			final_ans= 0 >final_ans ? 0 : final_ans ;
			cout<<final_ans<<endl;
			return;
		}
		else{
			long long we = sub_weights[sub_weights.size()-1].cum_weight;
			final_ans = final_ans > we ? final_ans : we;
		}
	} 
	cout<<final_ans<<endl;
}

int main() {
	int N;
	int K;
	cin >> N;
	cin >> K;
	constructTree(N);
	//printTree();
    vector<struct data> sub_weights;
    fillWeights(sub_weights,*allNodes.begin());
    printWeights(sub_weights);
    deleteFunction(sub_weights, K);
    //printWeights(sub_weights, N);
    //cout<<sub_weights[0]<<endl;
   // cout<<"Size left "<<allNodes.size()<<endl;
    return 0;
}
