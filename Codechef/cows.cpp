//GOOD QUESTION
//http://sahilmutneja.com/blog/2015/02/aggressive-cowsaggrcow-spoj/

#include <bits/stdc++.h>

using namespace std;



bool checkDistance(int mid, int * positions, int N, int C){
  int cowsPlaced = 1;
  int lastPosition = positions[0];
  for (int i = 1 ; i < N ; i++){
    if (positions[i] - lastPosition >= mid){
      cowsPlaced++;
      lastPosition = positions[i];
      if (cowsPlaced == C) return 1;
    }
  }
  return 0;
}


int main(){
  int testcases;
  cin >> testcases;

  while (testcases--){
    int N, C;
     cin >> N >> C;
     int positions[N];
     for (int i = 0 ; i < N ; i++){
      cin >> positions[i];
     }

     sort(positions, positions+N);
     int start = 0;
     int end = positions[N-1] - positions[0] + 1;  // AT max the cow can be N - 1 distance apart. Cows cannot be 'end' distance apart
     // assume end = 9 and start = 0 
     // therefore checking, if C cows can be placed at 4 distance apart on not. If yes check from 4 - 9 , if no check from 0 - 4
     int mid;
     while (end - start > 1){
      mid = (end + start)/2;
      if (checkDistance(mid, positions, N, C)) start = mid;
      else end = mid;
     }
     cout<<start<<endl;

  }
  return 0;
}