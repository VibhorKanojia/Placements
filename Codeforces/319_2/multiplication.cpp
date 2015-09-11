#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,x;
  cin >> n >> x;

  int rx = sqrt(x);
  int count = 0;
  for (int i = 1 ; i <= rx ; i++){
    if (x%i == 0) {
      if (x/i <= n){
        count = count +2;
      }
    }
  }
  float frx = sqrt(x);

  if (frx == rx && frx <=n) count--;

  cout<<count<<endl;
  return 0;
}