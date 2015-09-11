#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  map<string,int> mymap;
  map<string,int>::iterator it;
  for (int i = 0 ; i < n ; i++){
    string s;
    cin >>s;
    it = mymap.find(s);
    if (it == mymap.end()){
      mymap.insert(pair<string,int>(s,1));
    }
    else{
      it->second++;
    }
  }

  int curmax = 0;
  for (it = mymap.begin() ; it!= mymap.end() ; it++){
    curmax = max(curmax, it->second);
  } 
  cout<<curmax<<endl;

  return 0;
}