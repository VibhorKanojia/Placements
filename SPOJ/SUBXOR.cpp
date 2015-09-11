#include <bits/stdc++.h>

using namespace std;

struct trie{
  bool value;
  struct trie * nextElem[2];
  int size;
};

void insertTrie(struct trie* &tmproot, bool val){
  if (tmproot->size == 0){
    
  }
  else{
    for (int i = 0 ; i < 2 ; i++){
      if (tmproot->nextElem)[i]->value == val){

      }
    }
  }
}

bool checkTrie(struct trie * &root, int elem){
  int bitCount = log(15)/log(2) + 1;

  bitset<16> bs((long) elem);
  struct trie * tmproot = root;
  for (int i = 0 ; i < bitCount ; i++){
    
    if (tmproot->size == 0){
      tmproot->nextElem = new struct trie[2];
      (tmproot->nextElem)[0]->value = val;
      (tmproot->size)++;
    }

    else{
      if (tmproot->nextElem)[0]->value == val){
        tmproot=(tmproot->nextElem)[0];
        continue;
      }
      else {
        (tmproot->nextElem)[1]->value = val;
        tmproot=(tmproot->nextElem)[1];
        (tmproot->size)++;
        continue;
      }
    }
  }



  }
  cout<<endl;
  return true;
}

int main(){
  ios::sync_with_stdio(false);

  int testcases;
  cin >> testcases;

  while (testcases--){
    int N, K;
    cin >> N >> K;
    struct trie * root = new struct trie;
    root->value = 0;
    root-> nextElem = NULL;

    int count = 0;
    for (int i = 0 ; i < N ; i++){
      int elem;
      cin >> elem;
      bool val = checksTrie(root , elem);
      if (val) count++;
    }
  }

  return 0;
}