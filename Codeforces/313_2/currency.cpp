#include <bits/stdc++.h>
using namespace std;

bool compareFunction(int a, int b){
  if (a < b) return true;
  else return false;
}

int main(){
  int n;
  cin >> n;

  int array[n];
  for (int i = 0 ; i < n ; i++){
    cin >> array[i];
  }

  sort(array, array+n, compareFunction);
  if (array[0] != 1) cout<<1<<endl;
  else cout<<-1<<endl; 
  return 0;

}