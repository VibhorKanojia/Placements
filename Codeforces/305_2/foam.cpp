#include <bits/stdc++.h>
#define MAXN 100

using namespace std;


int gcd(int a, int b){
  if (max(a,b) % min(a,b) == 0) return min(a,b);
  if (a == 1 || b == 1) return 1;
  if (b > a){
    return gcd(a, b-(b/a)*a);
  }
  else{
    return gcd(b, a-(a/b)*b);
  }
}


void fillGCD(int ** gcdArray, vector<int> & foamVal){
  int size = foamVal.size();
  for (int i = 0 ; i < size ; i++){
    for (int j = i+1 ; j < size ; j++){
      gcdArray[foamVal[i]][foamVal[j]] = gcd(foamVal[i],foamVal[j]);
      gcdArray[foamVal[j]][foamVal[i]] = gcdArray[foamVal[i]][foamVal[j]];
    }
  }
}

int main(){
  ios::sync_with_stdio(false);


  int n;
  int q;
  cin >> n;
  cin >> q;

  bool availArray[MAXN];
  vector<int> foamVal;
  for (int i = 0 ; i < n ; i++){
    int temp;
    cin >> temp;
    foamVal.push_back(temp);
  }

  int ** gcdArray = new int*[MAXN];
  for (int i = 0 ; i < MAXN ; i++){
    gcdArray[i] = new int[MAXN];
  }

  for (int i = 0 ; i < MAXN ; i++){
    for (int j = 0 ; j < MAXN ; j++){
      gcdArray[i][j] = 0;
    }
    availArray[i] = 0;
  }

  fillGCD(gcdArray,foamVal);

  int score = 0;
  while(q--){
    int val;
    cin >> val;
    val = foamVal[val-1];
    availArray[val] = availArray[val] ? 0 : 1;
    for (int i = 1 ; i < MAXN  ; i++){
      if (availArray[i] && (gcdArray[i][val] == 1)) {
        if (availArray[val]){
          score++;
        }
        else{
          score--;
        }
      }
    }

    cout<<score<<endl;
  }


  return 0;
}


