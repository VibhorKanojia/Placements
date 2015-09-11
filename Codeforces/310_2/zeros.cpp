#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;
  cin >> n;
  
  int oneCount = 0;
  int zeroCount = 0;

  
  for (int i = 0 ; i < n ; i++){
    char b;
    cin >> b;
    
    if (b == '1') oneCount++;
    else if (b == '0') zeroCount++;
  }
  cout<<max(oneCount,zeroCount) - min(oneCount,zeroCount)<<endl;
  
  return 0;
}