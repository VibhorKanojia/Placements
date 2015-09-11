#include <bits/stdc++.h>

using namespace std;

struct chain{
  int size;
  vector<int> elements;
};

int main(){
  ios::sync_with_stdio(false);

  int n,k;
  cin >> n; 
  cin >> k;
  
  struct chain array[k];

  for (int i = 0 ; i < k ; i++){
    int tmpsize;
    cin >> tmpsize;
    array[i].size = tmpsize;
    for (int j = 0 ; j < tmpsize ; j++){
      int tmpelem;
      cin >> tmpelem;
      (array[i].elements).push_back(tmpelem);
    }
  }

  //cout<<"initial "<<array[0].elements[1]<<endl;
  int timeTaken = 0;
  int breakCount = 0;
  int minElem = 100000000;
  for (int i = 0 ; i < k ; i++){
    
    int tmpsize = array[i].size;
    int cur_elem = array[i].elements[0];
    int index = 1;
    while (index < tmpsize){

      if (array[i].elements[index] == (cur_elem + 1)){
        cur_elem = array[i].elements[index];
      }

      else{
        minElem = min(cur_elem, minElem);
        break;
      }

      index++;
    }
     minElem = min(minElem, array[i].elements[tmpsize-1]);
  }


  
  
  for (int i = 0 ; i < k ; i++){
    
    int tmpsize = array[i].size;
    int index = 0;
    while (index < tmpsize){
      if (array[i].elements[index] > minElem){
        if (index == 0){
          breakCount = breakCount+tmpsize-index-1;
        }
        else{
           breakCount = breakCount+tmpsize-index;
        }
        break;
      }
      index++;
    }
  }


  timeTaken = breakCount + breakCount + k -1;
  
  cout<<timeTaken<<endl;
  return 0;
}