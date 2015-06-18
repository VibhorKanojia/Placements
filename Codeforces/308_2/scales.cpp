#include <bits/stdc++.h>

using namespace std;

#define llint long long int

void printArray(llint * sumpowers, int n){
  for (int i = 0 ; i < n ; i++){
    cout<<sumpowers[i]<<" ";
  }
  cout<<endl;
}

int main(){
  llint w;
  llint m;
  cin >> w >> m;

  vector<llint> powers;
  
  llint val = 1;
  int size = 0;
  while (val <= m && size<99){
    powers.push_back(val);
    val *=w;
    size++;
  }

  powers.push_back(val);
  size++;

  llint sumpowers[size];
  sumpowers[0] = powers[0];
  for (int i = 1 ; i < size ; i++){
    sumpowers[i] = sumpowers[i-1] + powers[i];
  }

  val = 


  printArray(sumpowers,size);

return 0;
}