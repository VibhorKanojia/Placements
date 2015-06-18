#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int testcases;
  cin >> testcases;
  while (testcases--){
    int N;
    cin >> N;
    int array[N];
    for (int i = 0 ; i < N ; i++){
      cin >> array[i];
    }
    queue<int> buffer;
    int xorArray[N];
    xorArray[0] = array[0];
    buffer.push(array[0]);
    for (int i = 1 ; i < N ; i++){
      int cur_xor = xorArray[i-1]^array[i];
      buffer.push(array[i]);
      int topelem = buffer.front();
      int temp_xor = cur_xor^topelem;
      while (temp_xor >= cur_xor){
        buffer.pop();
        cur_xor = temp_xor;
        topelem = buffer.front();
        temp_xor = cur_xor^topelem;
      }
      xorArray[i] = cur_xor;
    }


    for (int i = 0 ; i < N ; i++){
      cout<<xorArray[i]<<" ";
    }
    cout<<endl;
  }

  return 0;
}