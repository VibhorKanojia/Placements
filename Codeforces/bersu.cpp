#include <bits/stdc++.h>


using namespace std;


int optimizeMatch(int * men, int n, int * women, int m, int index1, int index2, int ** memo){
  if (index1 >= n) return 0;
  if (index2 >= m) return 0;


  if (memo[index1][index2] != -1) return memo[index1][index2];
  if (men[index1] - women[index2] > 1 || men[index1] - women[index2] < -1) {
    int val = max(optimizeMatch(men,n,women,m, index1+1, index2,memo),
                  optimizeMatch(men,n,women,m,index1,index2+1,memo));
    memo[index1][index2] = val;
    return val;
  }
  
  else{
    int val = max( optimizeMatch(men, n, women, m, index1+1, index2,memo),
                1 + optimizeMatch(men, n, women, m, index1+1, index2+1,memo));

    memo[index1][index2] = val;
    return val;
  }
}

void printArray(int * array, int size){
  for (int i = 0 ; i < size ; i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int men[n];
  for (int i = 0 ; i < n ; i++){
    cin >> men[i];
  }
  int m;
  cin >> m;
  int women[m];
  for (int i = 0 ; i < m ; i++){
    cin  >> women[i];
  }

  int ** memo = new int*[n];
  for (int i =0 ; i < n ; i++){
    memo[i] = new int[m];
  }

  for (int i = 0 ; i < n ; i++){
    for (int j = 0 ; j < m ; j++){
      memo[i][j] = -1;
    }
  }

  sort(men, men+n);
  sort(women, women+m);

  cout<<optimizeMatch(men,n,women,m,0,0,memo)<<endl;
  return 0;
}