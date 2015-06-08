#include <bits/stdc++.h>

using namespace std;

int main(){

  ios::sync_with_stdio(false);
  string s;
  cin >>s;
  int baCount =0;
  int abCount =0;
  vector<int> baIndex;
  vector<int> abIndex;
  int size = s.size();
  for (int i =0 ; i < size - 1  ; i++){
    if (s[i]== 'B' && s[i+1] == 'A'){
      baIndex.push_back(i);
      baCount++;
      continue;
    }

    if (s[i]== 'A' && s[i+1] == 'B'){
      abCount++;
      abIndex.push_back(i);
      continue;
    }
  }
  
  if (!baCount || !abCount) cout<<"NO"<<endl;
  else{
    for (int i = 0 ; i < baIndex.size() ; i++){
      for (int j = 0; j < abIndex.size(); j++){
        if (baIndex[i] - abIndex[j] != 1 && abIndex[j] - baIndex[i] != 1){
          cout<<"YES"<<endl;
          return 0;
        }
      }
    }
    cout<<"NO"<<endl;
  }

  return 0;
}