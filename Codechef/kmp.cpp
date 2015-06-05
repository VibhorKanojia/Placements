#include <bits/stdc++.h>

using namespace std;

void constructFailTable(string pattern, int * failTable){
  int m = pattern.size();
  failTable[0] = 0;
  int i = 1;
  int len = 0;

  while (i < m){
    if (pattern[i] == pattern[len]){
      len++;
      failTable[i] = len;
      i++;
    }

    else{
      if (len == 0){
        failTable[i] = 0;
        i++;
      }
      else{
        len=failTable[len-1];    //aabaac  failTable(aabaa) = 2 => set len = 2 => check 'c' with 'b' as 'aa' is already matched ; rough explanation
      }
    }
  }

}

int main(){
  ios::sync_with_stdio(false);

  string text;
  string pattern;
  cin >> text >> pattern;

  int n = text.size();
  int m = pattern.size();
  int failTable[m];

  constructFailTable(pattern, failTable);

  cout<<"FAIL TABLE FOR PATTERN "<<pattern<<endl;
  for (int i = 0 ; i < m ; i++){
    cout<<failTable[i]<<" ";
  }
  cout<<endl;

  int i = 0;
  int j = 0;
  while (i < n){
    if (text[i] == pattern[j]){

      i++;
      j++;
      if (j == m){
        cout<<"pattern found at index "<<i-m<<endl; 
        j = failTable[j-1];
      }

    }

    else{
      if (j!=0){
        j = failTable[j-1];               // eg. text = aaacaaaa ; pattern = aaaa ; matching c with last a; mismatch therefore check failTable for aaa
      }                                   // it gives 2 that means 2nd and 3rd a's of text will match with 1st and 2nd a's of pattern. therefore check
      else{                               // 3rd 'a' of pattern with 'c' of text. therefore, i remains unchanged, j = failTable[j-1]; 
        i++;      //case when 1st letter of pattern doesn't match with the character. Simply do i++;
      }
    }
  }

  return 0;
}






