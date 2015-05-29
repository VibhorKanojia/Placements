#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  string s;
  cin >>s;

  int netCount=0;
  int size = s.size();

  for(int i = 0 ; i < size ; i++){
    
    if (s[i] == '(') netCount ++;
    else netCount --;
    if (netCount < 0) {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if (netCount != 0) cout<<"NO"<<endl;
  else{
    cout<<"YES"<<endl;
  }

  return 0;
}