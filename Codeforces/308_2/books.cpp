#include <bits/stdc++.h>

using namespace std;
#define llint long long int

llint findDigits(llint n){
  int val = 1;
  int count = 0;
  while (val <= n){
    val *=10;
    count++;
  }
  return count;
}

int main(){
  ios::sync_with_stdio(false);
  llint n;
  cin >> n;
  if (n < 10) {
    cout<<n<<endl;
    return 0;
  }
  llint array[] = {0,10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
  llint power[] = {0,9,90,900,9000,90000,900000,9000000,90000000,900000000};

  llint num_digits = findDigits(n);
 
  llint count = 0;
  llint reminder = n - array[num_digits-1];
//  cout<<"reminder is "<<reminder<<endl;
  count = count + num_digits*(reminder + 1);
 // cout<<"hello "<<count<<endl;
  for (llint i = num_digits-1 ; i > 0 ; i--){
    count += i*power[i];
  //  cout<<"count is "<<count<<endl;
  } 
  cout<<count<<endl;
  return 0;
}