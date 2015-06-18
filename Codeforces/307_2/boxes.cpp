#include <bits/stdc++.h>

using namespace std;

#define llint long long int


bool binarySearch(llint mid, vector<llint> pile, llint m){
  llint p = pile.size() - 1;
  for (llint i = 0 ; i < m ; i++){            // repeat for all men
    while (p >= 0 && pile[p] == 0) p--;         // find the last non-empty pile

    llint timeLeft = mid - p - 1;           // time taken to reach that pile
    if (timeLeft <= 0 ) return false;              // if can't even reach the pile, return false
    while (p >=0 && pile[p] <= timeLeft){        // while number of boxes are less than time remaining, remove them! 
      timeLeft -= pile[p];
      p--;
    } 
    if (p >=0) pile[p] = pile[p] - timeLeft;      // if time is left but can't remove all the boxes, remove as many boxes as you can
  }               // So, worker 1 has removed as many as he can in the given time, now worker 2 will have the same time and he has to continue where worker 1 has left.
  if ( p < 0) return true;       // if p < 0 => work can be done in 'mid' time
  else return false;

}


int main(){
  ios::sync_with_stdio(false);
  llint n, m;
  cin >> n >> m;

  vector<llint> pile;
  llint s = 0;;
  for (llint i = 0 ; i < n ; i++){
    llint temp;
    cin >> temp;
    pile.push_back(temp);
    s += pile[i];
  }
  llint start = 0;
  llint end = n + s + 1 ;

  while (start < end){
    llint mid = (start + end) >> 1;     // mid is the time we are checking
    bool val = binarySearch(mid, pile, m);
    if (val) end = mid;
    else start = mid+1;
  }
  cout<<end<<endl;
  return 0;
}