#include <bits/stdc++.h>

#define MAXN 
using namespace std;

int main(){
  ios::sync_with_stdio(false);


  int n;
  cin >> n;
  int array[n+1];
  for (int i = 0 ; i <=n ; i++){
    array[i] = 0;
  }

  for (int i = 0 ; i < n ; i++){
    int temp;
    cin >> temp;
    array[temp] = array[temp] + 1;
  }

  int count = 0;
  for (int i = 1 ; i < n ; i++){
    if (array[i] > 1){
      array[i+1] += array[i] -1;
      count += array[i] - 1;
      array[i] = 1;
    }
  }
  if (array[n] > 1){
    count = count + (array[n]-1)*(array[n])/2;
  }
  cout<<count<<endl;

  return 0;
}