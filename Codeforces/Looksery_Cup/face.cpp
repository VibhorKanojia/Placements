#include <bits/stdc++.h>

using namespace std;

bool compareFunction(char a, char b){
  if (a < b) return 1;
  else return 0;
}

void checkElem(char ** array, int i , int j , int & count){
  char arr[4];
  arr[0] = array[i-1][j-1];
  arr[1] = array[i][j-1];
  arr[2] = array[i-1][j];
  arr[3] = array[i][j];

  sort (arr, arr+4, compareFunction);
  string s = "";
  for (int index = 0 ; index < 4 ; index++){
    s = s + arr[index];
  }
  if (s =="acef") count++;
  

  
  arr[0] = array[i][j];
  arr[1] = array[i][j+1];
  arr[2] = array[i-1][j];
  arr[3] = array[i-1][j+1];
  sort (arr,arr+4, compareFunction);
  s = "";
  for (int index = 0 ; index < 4 ; index++){
    s = s + arr[index];
  }
  if (s =="acef") count++;
  
  arr[0] = array[i][j];
  arr[1] = array[i][j+1];
  arr[2] = array[i+1][j];
  arr[3] = array[i+1][j+1];
  sort (arr,arr+4, compareFunction);
  s = "";
  for (int index = 0 ; index < 4 ; index++){
    s = s + arr[index];
  }
  if (s =="acef") count++;
  
  arr[0] = array[i][j];
  arr[1] = array[i][j-1];
  arr[2] = array[i+1][j];
  arr[3] = array[i+1][j-1];
  sort (arr,arr+4, compareFunction);
  s = "";
  for (int index = 0 ; index < 4 ; index++){
    s = s + arr[index];
  }
  if (s =="acef") count++;

  return;
}

int main(){
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  char ** array = new char*[n+2];
  for (int i = 0 ; i < n+2 ; i++){
    array[i] = new char[m+2];
  }


  for (int i = 0 ; i <= n+1 ; i++){
    for (int j = 0; j <= m+1 ; j++){
      array[i][j] = 'x';
    }
  }

  for (int i = 1 ; i < n+1 ; i++){
    for (int j = 1; j < m+1 ; j++){
      cin >> array[i][j];
    }
  }

  int count = 0;
  for (int i = 1 ; i < n+1 ; i++){
    for (int j = 1 ; j < m +1 ; j++){
      if (array[i][j] != 'x'){
        checkElem(array, i, j, count);
      }
    }
  }
  cout<<count/4<<endl;
  return 0;
}