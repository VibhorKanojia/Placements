#include <bits/stdc++.h>

using namespace std;

int dynamicFunction(char * array, int ** memo, int closeCount, int curIndex){
  int val = 0;
  if (closeCount < 0) return 0;
  if (curIndex < 0 && closeCount == 0) return 1;
  if (curIndex < 0 && closeCount != 0) return 0;
  if (memo[curIndex][closeCount] != -1) return memo[curIndex][closeCount];
    
  if (array[curIndex] == '['){
    val =  dynamicFunction(array,  memo, closeCount - 1, curIndex-1);
    memo[curIndex][closeCount] = val;
    return val;
  }

  if ( closeCount == 0){
    val = dynamicFunction(array,memo,closeCount+1, curIndex-1);
    memo[curIndex][closeCount] = val;
    return val;
  }
  else{
    val = dynamicFunction(array,memo,closeCount-1, curIndex-1) + dynamicFunction(array,memo,closeCount+1,curIndex-1);
    memo[curIndex][closeCount] = val;
    return val;
  }
}


int main(){
  ios::sync_with_stdio(false);
  int testcases;
  cin >> testcases;

  while(testcases--){
    int n, k;
    cin >> n >> k;
    int size = 2*n;
    char array[size];
    
    for (int i = 0 ; i < size ; i++){
      array[i] = '*';
    }

    for (int i = 0 ; i < k ;i++){
      int pos;
      cin >> pos;
      array[pos-1] = '[';
    }

    int ** memo = new int*[size];
    for (int i = 0 ; i < size ; i++){
      memo[i] = new int[size+1];
    }


    for (int i = 0 ; i < size; i++){
      for (int j = 0 ; j <= size ; j++){
        memo[i][j] = -1;
      }
    }

    int closeCount = 0;
    int curIndex = size -1;
    int val = dynamicFunction(array, memo, closeCount, curIndex);
    cout<<val<<endl;
  }
  
  return 0;
}