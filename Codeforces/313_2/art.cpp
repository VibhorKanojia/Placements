#include <bits/stdc++.h>

using namespace std;

int main(){


  int a1,b1,a2,b2,a3,b3;
  cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

  if (max(a2,max(b2,max(a3,b3))) > max(a1,b1)){
    cout<<"NO"<<endl;
    return 0;
  }


  if (min(a2,b2) + min(a3,b3) <= min(a1,b1)){
    if (max(a2,max(b2,max(a3,b3))) <= max(a1,b1)){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}