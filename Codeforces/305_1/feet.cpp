#include <bits/stdc++.h>

using namespace std;


void fillmaxArray(int * array, int * maxArray, int n , int index){
  if (index == n - 1) {
    maxArray[index] = 1;
    return;
  }
  else{
    
  }

}


int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int array[n];
  int maxArray[n];
  for (int i = 0 ; i < n ; i++){
    cin >> array[i];
    maxArray = -1;
  }

  int index = 0;
  void fillmaxArray(array,maxArray,n,index);
}