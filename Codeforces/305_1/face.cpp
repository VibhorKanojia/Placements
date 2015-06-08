#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  int m;
  cin >> n >> m;

  char array[n+2][m+2];
  for (int i = 0 ; i <=n+1 ; i++){
    for (int j = 0 ; j <= m+1 ; j++){
      array[i][j] = *;
    }
  }

  for (int i =1; i <=n ; i++){
    for (int j = 1 ; j <= m ; j++){
      cin >> array[i][j];
    }
  }

  
}