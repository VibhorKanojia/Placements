#include <bits/stdc++.h>

#define llint long long int
#define MAXN 500001
using namespace std;

llint increment[MAXN];

bool comapreFunction(llint a,llint b){
  if (a < b) return 1;
  else return 0;
}

int main(){
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  llint array[n];
  llint original[n];
  
  memset(increment,0,sizeof(increment));

  for (int i = 0 ; i < n ; i++){
    cin >> array[i]; 
    original[i] = array[i];
  }

  int rootn = sqrt(n);

  for (int i = 0 ; i < rootn-1 ; i++){
    sort(array+i*rootn, array+(i+1)*rootn, comapreFunction);
  }
  sort(array+(rootn-1)*rootn, array+n, comapreFunction);

  for (int i = 0 ; i < n ; i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;

  while(q--){
    char op;
    cin >> op;
    if (op == '1'){
      int l,r;
      cin >> l >> r;
      llint x;
      cin >> x;
      for(int i = l-1 ; i < r ; i++){
        increment[i] +=x;
      }

      int index = 0;
      while (l-1 < index*rootn){
        index++;
      }
      if (l == index)
    }

  }

  return 0;
}