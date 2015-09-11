#include <bits/stdc++.h>

using namespace std;

bool compareFunction(int a, int b){
  if (a<b) return 1;
  else return 0;
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int array[n];

  for (int i = 0 ; i < n ; i++){
    cin >> array[i];
  }

  sort(array, array+n, compareFunction);
  bool divCheck = true;
  for (int i = 1 ; i < n ; i++){
    if ( array[i] == array[0] || (array[i]/array[0])%2 ==0) continue;
    else{
      divCheck = false;
      break;
    }
  }

  if (divCheck == true){
    
  } 

  return 0;

}