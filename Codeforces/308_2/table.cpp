#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int count = 0;
  while (n--){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    count += (x2-x1 +1)*(y2-y1+1);
  }
  cout<<count<<endl;

  return 0;
}
