#include <bits/stdc++.h>

using namespace std;
#define llint long long int
 
int main(){
  ios::sync_with_stdio(false);

  int m;
  cin >> m;
  llint h1,a1;
  cin >> h1 >> a1;
  llint x1, y1;
  cin >> x1 >> y1;
  llint h2, a2;
  cin >> h2 >> a2;
  llint x2, y2;
  cin >> x2 >> y2;

  bool flagArray1[m];
  bool flagArray2[m];
  for (int i = 0 ; i < m ; i++){
    flagArray1[i] = 0;
    flagArray2[i] = 0;
  }

  llint myTime = 0;
  llint frogFlag = -1;
  llint flowerFlag = -1;
  llint repeat1 = -1;
  llint repeat2 = -1;
  flagArray1[h1] = 1;
  flagArray2[h2] = 1;
  if (h1 == a1 && h2 == a2) {
    cout<<0<<endl;
    return 0;
  }
  cout<<endl;
  while (repeat1 == -1 || repeat2 == -1){
    myTime++;
    h1 = (x1*h1+y1) % m;
    h2 = (x2*h2+y2) % m;
    cout<<h1<<" "<<h2<<endl;
    if (flagArray1[h1] && repeat1 == -1){
      repeat1 = myTime;
    }
    
    if (flagArray2[h2] && repeat2 == -1){
      repeat2 = myTime;
    }

    flagArray1[h1] = 1;
    flagArray2[h2] = 1;
    if (h1 == a1 && frogFlag == -1) frogFlag = myTime;
    if (h2 == a2 && flowerFlag == -1) flowerFlag = myTime;
  }
  cout<<frogFlag<<" "<<flowerFlag<<" "<<repeat1<<" "<<repeat2<<endl;

  if (frogFlag == -1 || flowerFlag == -1) {
    cout<<-1<<endl;
    return 0;
  }

  if (repeat1 == repeat2 && frogFlag != flowerFlag){
    cout<<-1<<endl;
    return 0;
  }

  else{
    llint x1 = 0;
    llint x2 = 0;
    llint a = frogFlag + repeat1*x1;
    llint b = flowerFlag + repeat2*x2;
    while (a != b){
      if (a < b) x1++;
      else x2++;
      a = frogFlag + repeat1*x1;
      b = flowerFlag + repeat2*x2;
    } 
    cout<<a<<endl; 
  }
  return 0;
}