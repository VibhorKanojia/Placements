#include <bits/stdc++.h>

using namespace std;


void fill_l(int * l, int * array, int n){
  stack<int> s;
  for (int i = 0 ; i < n ; i++){
    while ( (!s.empty()) && array[s.top()] >= array[i]) s.pop();
    if (s.empty()) l[i] = -1;
    else {
      l[i] = s.top();
    }
      s.push(i);
  }
}

void fill_r(int * r, int * array, int n){
  stack<int> s;
  for (int i = n-1 ; i >=0 ; i--){
    while ( (!s.empty()) && array[s.top()] > array[i]) s.pop();
    if (s.empty()) r[i] = n;
    else {
      r[i] = s.top();
    }
    s.push(i);
  }
}

void printArray(int * arr, int start, int end){
  for (int i = start ; i < end ; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}


int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int array[n];

  for (int i = 0 ; i < n ; i++){
    cin >> array[i];
  }
  int l[n];
  int r[n];
  int ans[n+1];         // ans[1] => answer for group size = 1;

  memset(ans, 0, sizeof(ans));
  
  fill_l(l, array, n);
  fill_r(r, array, n);

  for (int i = 0 ; i <n ; i++){
    int index = r[i] - l[i] - 1;      // array[i] can be minimum element for at max r[i]-l[i]-1 interval;
    ans[index] = max(ans[index], array[i]);     
  }

  for (int i = n-1 ; i >0 ; i--){
    ans[i] = max(ans[i],ans[i+1]);
  }

  printArray(ans, 1, n+1);
  

  return 0;
}


/*
testcase

10
1 2 3 4 5 4 3 2 1 6

l =  0 0 1 2 3 2 1 0  0  8 
r = 10 8 7 6 5 6 7 8 10 10 
ans before = '_'  => not filled
           = _ 6 _ 4 _ 3 _ 2 _ _ 1

                                 ^ ans for group of size 10 
                               ^  same will be for group of size 9
                           ^ ans for group of size 7
                         ^ same will be for group of size 6
                                  
ans after  = _ 6 4 4 3 3 2 2 1 1 1 
*/
                