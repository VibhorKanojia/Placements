#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <list>
using namespace std;


struct Node{
	char value;
	list<Node *> children;
};

Node * root;
list<Node *>::iterator it;



void insert(string l, Node * cur_root){
	//cout<<"value is "<<cur_root->value<<endl;
	if (l==""){
		return;
	}
	char first = l[0];
	//cout<<"first is "<<first<<endl;
	for (it=(cur_root->children).begin() ; it != (cur_root->children).end() ; it++){
		//cout<<"should not enter"<<endl;
		if ((*it)->value == l[0]){
			insert(l.substr(1),(*it));
			return;
		}
	}
	//cout<<"should"<<endl;	
	Node * newnode = new Node;
	newnode->value = l[0];
	(cur_root->children).push_back(newnode);
	insert(l.substr(1),newnode);
}

void constructTree(int D){
	while (D--){
		string l;
		cin>>l;
		insert(l,root);
	}
}


vector<string> parseString(string s){
	cout<<"string is "<<s<<endl;
	vector<string> temp;
	if (s.size() == 0){
		return temp;
	}	
	if (s[0]=='('){
		cout<<"entered bracket"<<endl;
		int i = 1;
		while (s[i] !=')'){
			i++;
		}
		cout<<i<<endl;
		vector<string> prev = parseString(s.substr(i+1));
		if (prev.size() != 0){
			for (int j = 1 ; j < i ; j++){
				for (int k = 0 ; k < prev.size() ; k++){
					string combo = s[j]+prev[k];
					temp.push_back(combo);
				}
			}
		}
		else {
			cout<<"size 0"<<endl;
			for (int j = 1 ; j < i ; j++){
				string combo(1,s[j]);
				temp.push_back(combo);
			}
		}
	}
	
	else{
		cout<<"entered "<<s<<endl;
		string mandatory="";
		int flag = 0;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] != '('){
				mandatory = mandatory + s[i];
				cout<<"mand "<<mandatory<<" "<<s[i]<<endl;
			}
			else{
				flag = 1;
				vector<string> prev = parseString(s.substr(i));
				for (int k = 0 ; k < prev.size() ; k++){
					string combo = mandatory + prev[k];
					temp.push_back(combo);
				}
				break;	
			}
		}
		cout<<"flag is "<<flag<<endl;
		if (flag ==0){
			temp.push_back(mandatory);
		}
	}
	
	return temp;
	
}

void generateCombinations(vector<string> & vec,string s){
	vec = parseString(s);
	cout<<vec.size()<<endl;
	for (int i = 0 ; i < vec.size() ; i++){
		cout<<vec[i]<<endl;
	}
}


int findCombination(string s, Node * cur_root){
	cout<<"s is"<<s<<endl;
	if (s==""){
		return 1;
	} 
	else {
		for (it = (cur_root->children).begin() ; it != (cur_root->children).end() ; it++){
			cout<<(*it)->value<<" "<<s[0]<<endl;
			if ((*it)->value == s[0]){
				cout<<"here"<<endl;
				return findCombination(s.substr(1),(*it));
			}
		}
	}
	return 0;
}

int findCount(vector<string> & vec){
	int count = 0;
	cout<<vec.size()<<endl;
	for (int i = 0 ; i < vec.size() ; i++){
		int found = findCombination(vec[i],root);
		cout<<"found is"<<found<<endl;
		if (found == 1){
			count++;
		}
	}
	return count;
}






int main(){
	root = new Node;
	int L,D,N;
	cin >> L;																											
	cin >> D;
	cin >> N;
	constructTree(D);
	//cout<<root->children(*(root->children).begin())<<endl;
	int case_num = 1;
	while(N--){
		string mystring;
		vector<string> combinations;
		cin>>mystring;
		generateCombinations(combinations,mystring);
		int ans = findCount(combinations);
		cout<<"Case #"<<case_num<<": "<<ans<<endl;
		case_num++;
		combinations.clear();
	}
	
	
return 0;
}
