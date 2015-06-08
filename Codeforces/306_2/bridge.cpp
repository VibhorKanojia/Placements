#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int k;
  cin >> k;
  if (k % 2 == 0) {
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  int n = 4*k -2;
  int m = n*k/2;

  cout<<n<<" "<<m<<endl;
  for (int i = 2 ; i <= k ; i++){
    cout<<1<<" "<<i<<endl;
  }
  for (int i =2; i <=k ; i++){
    for (int j=k+1; j<=2*k-1 ; j++){
      cout<<i<<" "<<j<<endl;
    }
  }

  for (int i =k+1; i < 2*k -1 ; i=i+2){
    cout<<i<<" "<<i+1<<endl;
  }

  cout<<1<<" "<<2*k<<endl;

  for (int i = 1+2*k ; i <= 3*k -1 ; i++){
    cout<<2*k<<" "<<i<<endl;
  }
  for (int i = 1+2*k ; i <=3*k -1 ; i++){
    for (int j=3*k; j< 4*k-1 ; j++){
      cout<<i<<" "<<j<<endl;
    }
  }

  for (int i =3*k; i < 4*k -1 ; i=i+2){
    cout<<i<<" "<<i+1<<endl;
  }

  return 0;
}