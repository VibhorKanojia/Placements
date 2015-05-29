#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  if (n == 1) {
    cout<<1<<endl;
    cout<<1<<endl;
    return 0;
  }
  if (n == 2){
    cout<<1<<endl;
    cout<<1<<endl;
    return 0;
  }
  if (n == 3){
    cout<<2<<endl;
    cout<<"1 3"<<endl;
    return 0;
  }
  cout<<n<<endl;
  for (int i = 2 ; i <=n ; i=i+2){
    cout<<i<<" ";
  }
  for (int i = 1 ; i < n-1 ; i=i+2){
    cout<<i<<" ";
  }
  if (n%2 == 0) cout<<n-1<<endl;
  else cout<<n<<endl;
  return 0;
}