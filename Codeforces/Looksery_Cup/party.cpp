#include <bits/stdc++.h>

using namespace std;


int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  char ** array = new char*[n];
  for (int i = 0 ; i < n ; i++){
    array[i] = new char[n];
  }
  for (int i = 0 ; i < n ; i++){
    for (int j = 0; j < n ; j++){
      cin >> array[i][j];
    }
  }
/*
  for (int i = 0 ; i < n ; i++){
    for (int j = 0; j < n ; j++){
      cout << array[i][j]<<" ";
    }
    cout<<endl;
  }
*/
  int val[n];
  for (int i = 0 ; i < n ; i++){
    cin >> val[i];
  }

  for (int j = 0 ; j < n ; j++){
    int sum = 0;
    for (int i = 0 ; i < n ; i++){
      sum = sum + (array[i][j] - '0');
    }

    if (val[j] != 0){
      cout<<0<<endl;
      cout<<endl;
      return 0;
    }

    else if ( sum == 0 && val[j] == 0){
      cout<<-1<<endl;
      return 0;
    }

    else if ()
    
  } 
  cout<<-1<<endl;

  return 0;
}








