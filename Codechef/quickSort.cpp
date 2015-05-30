#include <bits/stdc++.h>

using namespace std;


void swapPos(int * array, int x, int y){
  int temp = array[x];
  array[x] = array[y];
  array[y] = temp;
}


void printArray(int * array, int N){
  for (int i = 0 ; i <= N ; i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
}
/*

10 9 8 1 2 3 5 
=> 1 2 3 10 9 8 => 1 2 3 5 10 9  8
on 10 9 8
=> 8 10 9
on 10 9
=> 9 10
*/

int partition(int * array, int start, int end){

  int pivot = array[end];
  int index = start;            
  for (int i = start ; i < end ; i++){
    if (array[i] <= pivot){       //if number is smaller than pivot swap it with the index to make it go in the beginning
      swapPos(array, i, index);
      index++;
    }
  }
  // now value of index is 1 more than number of elements smaller than pivot. So swap pivot with that element.
  swapPos(array,index,end);  
  // pivot comes at its correct position.
  return index;

}


void quickSort(int * array, int start, int end){
  if (start >= end) return;
  int p = partition(array, start, end);
  //return;
  quickSort(array, start, p-1);
  quickSort(array, p+1, end);
}


int main(){
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int array[N];

  for (int i = 0 ; i < N ; i++){
    cin >> array[i];   
  }

  quickSort(array, 0, N-1);
  printArray(array,N-1);
  return 0;
}