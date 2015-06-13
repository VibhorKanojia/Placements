#include <bits/stdc++.h>


using namespace std;

bool compareFunction(int a, int b){
  if (a > b) return 1;
  else return 0;
}


int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  int array[n];
  int sort_array[n];
  for (int i = 0 ; i < n ; i++){
    cin >> array[i];
    sort_array[i] = array[i];
  }

  sort(sort_array, sort_array+n, compareFunction);

  int rankArray[2001];
  int rank = 1;
  int val = sort_array[0];
  rankArray[val] = rank;
  for (int i = 1 ; i < n ; i++){
    int cur_val = sort_array[i];
    rank++;
    if (cur_val != val){
      rankArray[cur_val]=rank;
      val = cur_val;
    }
  }

  for (int i = 0 ; i < n ; i++){
    cout<<rankArray[array[i]]<<" ";
  }
  cout<<endl;



  return 0;
}