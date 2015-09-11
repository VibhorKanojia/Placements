#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000001

struct data{
  int count;
  int start;
  int end;
};
  
int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  map<int, struct data> mymap;
  map<int, struct data>::iterator it;
  int index = 0;
  for (int i = 0 ; i <  n ; i++){
    index++;
    int val;
    cin >>val;
    it = mymap.find(val);
    if (it == mymap.end()){
      struct data d;
      d.count = 1;
      d.start = index;
      d.end = 0;
      mymap.insert(pair<int,struct data>(val,d));
    }

    else {
      (it->second).count++;
      (it->second).end = index;
    }
  }

  int maxOcc = 0;
  int curdiff = 100000000;
  int l = 0;
  int r = 0;

  for (it = mymap.begin() ; it != mymap.end(); it++){
    
    if ((it->second).count == maxOcc){
      if ((it->second).end - (it->second).start < curdiff){
        l = (it->second).start;
        r = (it->second).end;
        curdiff = r-l;
      }  
    }

    else if ((it->second).count > maxOcc){
      maxOcc = (it->second).count;
      l = (it->second).start;
      r = (it->second).end;
      curdiff = r - l;
    }
  }
  if (l > r) {
    l = 1;
    r = 1;
  }
  cout<<l<<" "<<r<<endl;
  return 0;
}