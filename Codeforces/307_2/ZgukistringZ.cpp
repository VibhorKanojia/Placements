#include <bits/stdc++.h>

using namespace std;

map<char,int>::iterator it;
map<char,int>::iterator it1;
int b1;
int b2;
int b3;
int b4;

int countFunction(map<char,int> amap, map<char,int> bmap, map<char,int> cmap){
  int count1 = 0;
  int minval = 100000000;
  
  for (it = bmap.begin() ; it != bmap.end() ; it++){
    int val2 = it->second;
    it1 = amap.find(it->first);
    if (it1 == amap.end()){
      minval = 0;
      break;
    }

    else{
      int val1 = it1->second;
      int divnum = val1/val2;
      minval = min(divnum,minval);
    }
  }

  count1 = minval;
  b1 = count1;
  if (count1 != 0){  
    for (it = bmap.begin() ; it != bmap.end() ; it++){
      it1 = amap.find(it->first);
      it1->second = it1->second - count1*(it->second) ;
    }
  }
  

  minval = 100000000;
    
    for (it = cmap.begin() ; it != cmap.end() ; it++){
      int val2 = it->second;
      it1 = amap.find(it->first);
      if (it1 == amap.end()){
        minval = 0;
        break;
      }
      else{
        int val1 = it1->second;
        int divnum = val1/val2;
        minval = min(divnum,minval);
      }
    }
    b2 = minval;
    count1 +=minval;
  return count1;
}

int main(){
  ios::sync_with_stdio(false);
  string a;
  string b;
  string c;
  cin >> a >> b >> c;
  map<char,int> amap;
  map<char,int> bmap;
  map<char,int> cmap;
  
  for (int i=0 ; i < a.size() ; i++){
    it = amap.find(a[i]);
    if (it != amap.end()){
      it->second +=1;
    }
    else{
      amap.insert(pair<char,int>(a[i],1));
    }
  }

  for (int i=0 ; i < b.size() ; i++){
    it = bmap.find(b[i]);
    if (it != bmap.end()){
      it->second +=1;
    }
    else{
      bmap.insert(pair<char,int>(b[i],1));
    }
  }

  for (int i=0 ; i < c.size() ; i++){
    it = cmap.find(c[i]);
    if (it != cmap.end()){
      it->second +=1;
    }
    else{
      cmap.insert(pair<char,int>(c[i],1));
    }
  }

  int count1 = countFunction(amap, bmap, cmap);
  b3 = b1;
  b4 = b2;
  int count2 = countFunction(amap, cmap, bmap);
  string s="";
  if (count1 >= count2){  
    while(b3--) s=s+b;
    while(b4--) s=s+c;
  }

  else{
    while(b1--) s=s+c;
    while(b2--) s=s+b;
  }

  for (int i = 0 ; i < s.size() ; i++){
    it1=amap.find(s[i]);
    it1->second = it1->second -1;
  }

  for (it = amap.begin() ; it!= amap.end() ; it++){
    while (it->second != 0){
      s=s+(it->first);
      it->second = it->second -1;
    }
  }
  cout<<s<<endl;




  return 0;
}















