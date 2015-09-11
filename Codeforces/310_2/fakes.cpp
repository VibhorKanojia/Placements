#include <bits/stdc++.h>

using namespace std;

int main(){

  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int array[n];
  for (int i = 0 ; i < n ; i++){
    cin >> array[i];
  }
  
  int addval = n - array[0];

  array[0] = 0;
  for (int i = 1 ; i < n ; i=i+2){
    array[i] = (array[i] - addval + n)%n;

  }

  for (int i = 2 ; i < n ; i=i+2){
    array[i] = (array[i] + addval)%n;
  }

  for (int i = 0 ; i < n ; i++){
    if (array[i] != i){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;

  return 0; 
}