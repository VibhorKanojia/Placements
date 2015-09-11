#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int min1,min2,min3,max1,max2,max3;
  cin >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;

  int ans1,ans2,ans3;
  ans1 = max1;
  ans2 = max2;
  ans3 = n - ans1 - ans2;
  while(ans3 < min3){
    ans3++;
    if (ans2>min2){
      ans2--;
    }
    else{
      ans1--;
    }
  }

  cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
  return 0;
}