#include <bits/stdc++.h>

using namespace std;
void printArray(int ** dp, int n){
  for (int i = 0 ; i < n ; i++){
    for (int j = 0 ; j < 8 ; j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  return;
}

int main(){

  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int n = s.size();

  bool dp[n][8]; 

  int prev[n][8];

  for (int i = 0 ; i < n ; i++){
    for (int j = 0 ; j < 8 ; j++){
      dp[i][j] = 0;
      prev[i][j] = -1;
    }
  }

  for (int i = 0 ; i < n ; i++){
    int a = s[i] - 48;
    dp[i][a%8] = 1;
  }

  prev[0][(s[0] - 48) % 8] = 9;

  for (int i = 1; i < n ; i++){
    for (int j = 0 ; j < 8 ; j++){
      int a = s[i] - 48;
      dp[i][ (j*10 + a) % 8] = max(dp[i][(j*10 + a) % 8], dp[i-1][j]);

      dp[i][j] = max(dp[i][j], dp[i-1][j]);
      //cout<<" j is "<<j<<endl;
      if ( dp[i][ (j*10 + a) % 8] == 1 && prev[i][(j*10 + a) % 8] == -1 && (dp[i-1][j] == 1 || j == 0) ) prev[i][(j*10 + a) % 8] = j;
      //if (dp[i][j] == 1 && prev[i][(j*10 + a) % 8] == -1) prev[i][j]= j;
    }
  }
  
  string ans = "";
  int lastIndex = -1;
  for (int i = 0 ; i < n ; i++){
    if (dp[i][0]  == 1) {
      lastIndex = i;
      break;
    }
  }

  if (lastIndex == -1){
    cout<<"NO"<<endl;
    return 0;
  }

  int j = prev[lastIndex][0];
  ans = s[lastIndex] + ans;
  while(lastIndex > 0){
    lastIndex--;
    if (j != prev[lastIndex][j] && prev[lastIndex][j] != -1){
      ans = s[lastIndex] + ans;
      j = prev[lastIndex][j];
    }
  }
  cout<<"YES"<<endl;
  cout<<ans<<endl;
  
  return 0;
}







