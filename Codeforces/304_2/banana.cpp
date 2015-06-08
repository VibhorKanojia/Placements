#include <bits/stdc++.h>

#define llint long long int
using namespace std;

int main(){
  ios::sync_with_stdio(false);

  llint k,n,w;
  cin >> k >> n >> w;
  int answer = w*(w+1)*k/2 - n;
  if (answer < 0){
    cout<<0<<endl;
  }
  else{
    cout<<answer<<endl;
  }
  return 0;
}