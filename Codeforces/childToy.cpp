#include <bits/stdc++.h>

using namespace std;

struct Node{
  int id;
  int weight;
  vector<Node *> * neighbours;        //very important, store the pointer of vector/list.
};



bool compareFunction(struct Node * a, struct Node * b){
    if (a->weight <= b->weight) return 0;           //VERY VERY IMPORTANT. CompareFunction must have a strict weak ordering 
    else return 1;                                  //i.e return 1 only if X > Y . if you write (X >= Y) return 1, it could give segmentation fault.
  
}

int main(){

  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  vector<Node *> nodeVector;            //stores pointers of size 4 bytes. 
  for (int i = 0 ; i < n ; i++){
    struct Node * temp = new Node;      //initialize the struct
    temp->id = i+1;
    cin >> temp->weight;
    temp->neighbours = new vector<Node *>();        //initialize the vector inside a struct.
    nodeVector.push_back(temp);
  }
  for (int i = 0 ; i < m ; i++){
    int n1, n2;
    cin >> n1 >> n2;
    (nodeVector[n1-1]->neighbours)->push_back(nodeVector[n2-1]);
    (nodeVector[n2-1]->neighbours)->push_back(nodeVector[n1-1]);
  }


  sort(nodeVector.begin(),nodeVector.end(), compareFunction);
  
  int energyConsumed = 0;
  for (int i = 0 ; i < n ; i++){
    vector<Node *>::iterator it;
    for (it = (nodeVector[i]->neighbours)->begin() ; it != (nodeVector[i]->neighbours)->end() ; it++){
      energyConsumed += (*it)->weight;
    }
    nodeVector[i]->weight = 0;
  }

  cout<<energyConsumed<<endl;

  return 0;
}






