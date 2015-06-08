#include <bits/stdc++.h>

using namespace std;


bool checkPalindrome(string s, int start, int size){
  int end = start + size;
  int j = end -1;
  for (int i= start; i < (start+end)/2 ; i++){
    if (s[i] == s[j]){
      j--;
    }
    else{
      return false;
    }
  }
  return true;
}


int main(){
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  
  int k;
  cin >> k;

  if (s.size()%k != 0) {
    cout<<"NO"<<endl;
    return 0;
  }

  int size = s.size()/k;

  for (int i = 0 ; i < k ; i++){
    //cout<<s<<" "<<size*i<<" "<<size<<endl;
    if(!checkPalindrome(s,size*i,size)){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}