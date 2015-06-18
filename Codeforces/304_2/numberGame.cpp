#include <bits/stdc++.h>

using namespace std;
#define MAXN 5000001
#define llint long long int;


};
void fillVal(int index, int * factorVal){
  int i = 0;
  int count = 0;
  int init_index = index;
  while (index != 1){
    while (index % primes[i] == 0){
      index = index/primes[i];
      count++;
      if (factorVal[index] != 0){
        count = count + factorVal[index];
        factorVal[init_index] = count;
        return;
      }
    }
    i++;
  }
  factorVal[init_index] = count;
  return;
}


int main(){
  ios::sync_with_stdio(false);


  int testcases;
  cin >> testcases;
  int *factorVal =  new int[MAXN];


  while (testcases--){
    int a;
    int b;
    cin >> a >> b;
    int count = 0;
    for (int i = b+1; i <=a ; i++){
      if (factorVal[i] == 0){
        fillVal(i, factorVal);
      }   
      count = count + factorVal[i];
    }
    cout<<count<<endl;
  }

  return 0;
}