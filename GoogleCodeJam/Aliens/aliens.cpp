#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
using namespace std;


struct Node{
	char value;
	list<Node *> children;
};

Node * root;
list<Node *>::iterator it;



void insert(string l, Node * cur_root){
	if (l==""){
		return;
	}
	char first = l[0];
	for (it=(cur_root->children).begin() ; it != (cur_root->children).end() ; it++){
		if ((*it)->value == l[0]){
			insert(l.substr(1),(*it));
			return;
		}
	}
		
	Node * newnode = new Node;
	newnode->value = l[0];
	(cur_root->children).push_back(newnode);
}

void constructTree(int D){
	while (D--){
		string l;
		cin>>l;
		insert(l,root);
	}
}


void findString(string s){
}



int main(){
	root = new Node;
	int L,D,N;
	cin >> L;
	cin >> D;
	cin >> N;
	constructTree(D);
	while(N--){
	}
	
	
return 0;
}
