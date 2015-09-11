#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int size = s.size();

  int count = 26*(size+1);
  count = count - size;

  cout<<count<<endl;


  return 0;
}