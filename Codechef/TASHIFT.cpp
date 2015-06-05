#include <bits/stdc++.h>

using namespace std;


void constructTable(int * failTable, string A){
  int m = A.size();

  failTable[0] = 0;
  int i = 1;
  int len = 0;

  while ( i < m){
    if (A[i] == A[len]){
      len++;
      failTable[i] = len;
      i++;
    }
    else{
      if (!len){
        failTable[i] = 0;
        i++;
      }
      else{
        len = failTable[len - 1];
      }
    }
  }

}

int kmp(string pattern, string text, int index, int * failTable){
  int i = 0;
  int j = 0;
  int maxj = 0;
  int maxjindex = -1;
  int n = text.size();
  while (i < n){
    if (text[i] == pattern[j]){
      i++;
      j++;
      if (j == index){
        return (i-index);
      }
    }
    else{
      if (j > maxj) {
        maxj = j;
        maxjindex = i - maxj;
      }
      if (!j) i++;
      else j=failTable[j-1];
    }
  }
  return maxjindex;
}


int main(){

  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string A;
  string B;

  cin >> A>> B;

  int failTable[n];

  constructTable(failTable, A);

  string txt = B + B;
  
  int val = kmp(A,txt,n,failTable);
  cout<<val<<endl;
  return 0;
}


/*
EG A = CCADD
   B = BDDCC
   make failTable for A and text = B + B = BDDCCBDDCC
   modified kmp will search for A in B, and if not found, returns the index of maximum length of A that matched; 
*/








