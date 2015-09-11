#include <bits/stdc++.h>

using namespace std;

#define llint long long int

struct island{
  llint l;
  llint r;
  llint index;
};

struct difference{
  llint l;
  llint r;
  llint maxAllowed;
  llint index;
};

struct data{
  llint val;
  llint index;
};

bool compareDiff(struct difference a, struct difference b){
  llint val1 = a.r - a.l;
  llint val2 = b.r - b.l;
  if (val1 < val2) return 1;
  else return 0;
}

bool compareVal(struct data a, struct data b){
  if (a.val < b.val) return 1;
  else return 0;
}


int main(){
  ios::sync_with_stdio(false);
  llint n, m;
  cin >> n >> m;
  struct island islandArray[n];
  llint diffn = n-1;
  struct difference array[diffn];
  struct data bridge[m];
  
 
  for (llint i = 0 ; i < n ; i++){
    cin >> islandArray[i].l;
    cin >> islandArray[i].r;
    islandArray[i].index = i;
  }

  for (llint i = 0 ; i < n -1 ; i++){
    array[i].l = islandArray[i].r;
    array[i].r = islandArray[i+1].l;
    array[i].index = i;
    array[i].maxAllowed = islandArray[i+1].r - islandArray[i].l;
  }

 

  for (llint i = 0 ; i < m ; i++){
    cin >> bridge[i].val;
    bridge[i].index = i+1;
  }

  sort(array, array + diffn, compareDiff);
  sort(bridge, bridge + m, compareVal);

  llint bindex =0;
  llint lindex =0;
  llint answer[diffn];

  while(lindex < diffn){
    if (bindex >= m) {
      cout<<"No"<<endl;
      return 0;
    }
    if ( (bridge[bindex].val >= (array[lindex].r - array[lindex].l)) && (bridge[bindex].val <= array[lindex].maxAllowed)){
      cout<<" bridge: "<<bridge[bindex].val<<endl;
      answer[array[lindex].index] = bridge[bindex].index;
      lindex++;
      bindex++;
      continue;
    }
    else{
      bindex++;
      continue;
    }

    lindex++;
  }
  cout<<"Yes"<<endl;
  for (llint i = 0 ; i < diffn ; i++){
    cout<<answer[i]<<" ";
  }
  cout<<endl;
  return 0;
}

