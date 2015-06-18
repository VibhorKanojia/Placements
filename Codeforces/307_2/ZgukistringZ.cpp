#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

void countFunction(int* amap, int* bmap, int* cmap,string a,string b, string c){
  int minval = MAXN;
  
  for (int i = 0 ; i < 26 ; i++){
    if (bmap[i]) minval = min(minval, amap[i]/bmap[i]);
  }

  int bcount = minval;
  int cur_b = -1;
  int cur_c = -1;
  for (int k = 0 ; k <= bcount ; k++){
    minval = MAXN;
    for (int i = 0 ; i < 26 ; i++){
      if (cmap[i]) {
        minval = min(minval, (amap[i] - k*bmap[i])/cmap[i]);
      }
    }

    if (k + minval > cur_b + cur_c){
      cur_b = k;
      cur_c = minval;
    }  
  }

  for (int i = 0 ; i < 26 ; i++){
    amap[i] = amap[i] - cur_b*bmap[i] - cur_c*cmap[i];
  }

  string s = "";
  while (cur_b--) s = s+b;
  while (cur_c--) s = s+c;

  for (int i = 0 ; i < 26 ; i++){
    while (amap[i] != 0){
      s=s+(char)(i+'a');
      amap[i]--;
    }
  }
  cout<<s<<endl;
  return;
}

int main(){
  ios::sync_with_stdio(false);
  string a;
  string b;
  string c;
  cin >> a >> b >> c;

  int amap[26];
  int bmap[26];
  int cmap[26];


  memset(amap, 0, sizeof(amap));
  memset(bmap, 0, sizeof(bmap));
  memset(cmap, 0, sizeof(cmap));

  for (int i=0 ; i < a.size() ; i++){
    amap[a[i]-'a']++;
  }

  for (int i=0 ; i < b.size() ; i++){
   bmap[b[i]-'a']++;
  }

  for (int i=0 ; i < c.size() ; i++){
   cmap[c[i]-'a']++;
  }  

  countFunction(amap, bmap, cmap, a, b, c);  
  return 0;
}















