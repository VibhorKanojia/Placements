#include <bits/stdc++.h>

using namespace std;

bool compareFunction(int a, int b){
  if (a<b) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);

  int n, w;
  cin >> n >> w;
  int count = 2*n;
  int array[count];

  for (int i = 0 ; i < count ; i++){
    cin >> array[i];
  }
  sort(array, array+count, compareFunction);
  double ans;
  if ((double)(array[n])/2 > array[0]){
    ans = 3*(double)n*(double)array[0]; 
  }  
  else{
    ans = 3*n*(double)(array[n])/2 ;
  }
  
  if (w < ans){
    cout<<w<<endl;
  }
  else cout<<ans<<endl;

  return 0;
}