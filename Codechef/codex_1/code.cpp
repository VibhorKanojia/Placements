#include <bits/stdc++.h>

using namespace std;


int dpFunction(string D,string S,int dIndex, int sIndex, int ** memo, int addition){
  if (addition < 0) return 100000000;
  if (dIndex >= D.size() || sIndex >= S.size()){
    return 0;
  }

  if (memo[dIndex][sIndex] != -1) return memo[dIndex][sIndex];

  if (D[dIndex] == S[sIndex]) {
    memo[dIndex][sIndex] = dpFunction(D,S,dIndex+1,sIndex+1,memo, addition);
    return memo[dIndex][sIndex];
  }
  else{
    int val = min ( dpFunction(D,S,dIndex,sIndex+1, memo, addition-1) , 1+dpFunction(D,S,dIndex+1,sIndex+1,memo, addition));
    memo[dIndex][sIndex] = val;
    return val;
  }
}


int main(){
  ios::sync_with_stdio(false);

  int testcases;
  cin >> testcases;

  while(testcases--){
    string D;
    cin >> D;

    string S;
    cin >> S;

    int dSize = D.size();
    int sSize = S.size();

    int **  memo = new int*[dSize];
    for (int i = 0 ; i < dSize ; i++){
      memo[i] = new int[sSize];
    }

    for (int i = 0 ; i <dSize ; i++){
      for (int j = 0 ; j <sSize ; j++){
        memo[i][j] = -1;
      }
    }

    int dIndex = 0;
    int sIndex = 0;
    int ans = dpFunction(D,S,dIndex,sIndex,memo,sSize-dSize);
    cout<<ans<<endl;
  }



  return 0;
}