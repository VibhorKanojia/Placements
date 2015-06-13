#include <bits/stdc++.h>

#define MAXN 100001
using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int testcases;
  cin >> testcases;


  while (testcases--){
    int cur_array[MAXN];
    int new_array[MAXN];
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
      int temp;
      cin >> temp;
      cur_array[temp] = i;
    }

    for (int i = 0 ; i < n ; i++){
      int temp;
      cin >> temp;
      new_array[temp] = i;
    }

        

  }


  return 0;
}