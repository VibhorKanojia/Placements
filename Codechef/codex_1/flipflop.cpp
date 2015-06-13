#include <bits/stdc++.h>

using namespace std;


int main(){
  ios::sync_with_stdio(false);

  int testcases;
  cin >> testcases;
  while (testcases--){
    string s;
    cin >> s;
    int size = s.size();
    int count = 0;
    char cur_char;
    char prev_char = 'Z';
    for (int i = 0 ; i < size ; i++){
      cur_char = s[i];
      if (cur_char == prev_char) {
        count++;
      }
      else{
        prev_char = cur_char;
      }
    }

    cout<<count<<endl;

  }


  return 0;
}