#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  char array[n];
  for (int i = 0 ; i < n ; i++){
    cin >> array[i];
  }
  if (array[n-1] == '1'){
    cout<<"NO"<<endl;
    return 0;
  }
  else if (array[n-1] == '0' && array[n-2] == '0'){
    int flag = 0;
    for (int i = 0 ; i < n-2 ; i++){
      if (array[i] == '0'){
        flag = 1;
      }
    }
    if (flag == 0){
      cout<<"NO"<<endl;
      return 0;
    }
  }

  if (array[n-1] == '0' && array[n-2] == '1'){
    cout<<"YES"<<endl;
    string s ="";
    for (int i = 0 ; i < n-1 ; i++){
      s=s+array[i]+"->";
    }
    s=s+array[n-1];
    cout<<s<<endl;
    return 0;
  }
  else{
    
  }

  return 0;
}