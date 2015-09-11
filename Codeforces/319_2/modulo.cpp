#include <bits/stdc++.h>
#define MAXM 1001
using namespace std;

bool dpFunction(int * array, int curIndex, int curSum, int M, int N, int ** memo){
  if (curSum == 0){
    memo[curIndex][curSum] = 1;
    return true;
  }

  if (curIndex >= N)  return false;

   

  if (memo[curIndex][curSum] != -1) {
    if (memo[curIndex][curSum] == 1) return true;
    else return false;
  }

  bool val1 = dpFunction(array, curIndex+1,curSum, M, N, memo);
  bool val2 = dpFunction(array, curIndex+1, (curSum+array[curIndex])%M, M, N, memo);
  if (val1 || val2) {
    memo[curIndex][curSum] = 1;
    return true;
  }
  else{
    memo[curIndex][curSum] = 0;
    return false;
  }
}

int main(){
  ios::sync_with_stdio(false);
 
  int n , m;
  cin >> n >> m;
  int array[n];

  for (int i = 0 ; i < n ; i++){
    cin >> array[i];
  }

  if (n > m){
    cout<<"YES"<<endl;
    return 0; 
  }

  int ** memo = new int*[MAXM];
  for (int i = 0 ; i < MAXM ; i++){
    memo[i] = new int[MAXM];
  }

  for (int i = 0 ; i < MAXM ; i++){
    for (int j = 0 ; j < MAXM ; j++){
      memo[i][j] = -1;
    }
  }

  
  bool ans = dpFunction(array, 0,m, m, n, memo);
   
  if (ans) {
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }

  return 0;
}