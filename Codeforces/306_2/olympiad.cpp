#include <bits/stdc++.h>

using namespace std;

bool cmpfunction(int a,int b){
  if (a < b) return 1;
  else return 0;
}

int n,l,r,x;
int recursiveFunction(int * difficulty, int minPick, int maxPick, int index, int sum){
  /*
  cout<<"MAXPICK "<<maxPick<<endl;
  cout<<"MINPICK "<<minPick<<endl;
  cout<<"INDEX "<<index<<endl;
  cout<<"SUM "<<sum<<endl;
  cout<<endl<<endl;
  */
  if (index == n){
    if (sum <= r && sum >=l && (maxPick - minPick) >= x) {
      return 1;
    }
    else{
      return 0;
    }
  }

  else{
    
    int newMin = min(minPick,difficulty[index]);
    int newMax = max(maxPick,difficulty[index]);
    int val = recursiveFunction(difficulty,newMin,newMax,index+1,sum+difficulty[index]) + recursiveFunction(difficulty,minPick,maxPick,index+1,sum);
    return val; 
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin >> n >> l >> r >> x;
  int difficulty[n];
  for (int i = 0 ; i < n ; i++){
    cin >> difficulty[i];
  }

  int minPick = 1000001;
  int maxPick = -1;
  int sum = 0;
  int index = 0;
  int ans = recursiveFunction(difficulty,minPick,maxPick,index,sum);
  cout<<ans<<endl;

}