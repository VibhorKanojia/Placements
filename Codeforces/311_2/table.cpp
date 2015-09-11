#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001

bool compareFunction(int a, int b){
  if (a > b) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >>n;
  int l[n];
  int d[n];

  int used[MAXN];
  memset(used, 0, sizeof(used));

  for (int i = 0 ; i < n ; i++){
    cin >> l[i];
  }


  for (int i = 0 ; i < n ; i++){
    cin >> d[i];
    used[l[i]] += d[i];
  }

  sort(l, l+n, compareFunction);

  int lastchecked = -1;
  int minused = 100000000;

  for (int i = 0 ; i < n ; i++){
    
  }

  return 0;
}