#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> & myvector, int start ,int end){
  for (int i = start ; i < end ; i++){
    cout<<myvector[i]<<" ";
  }
  cout<<endl;
}


vector<int> mergeSort(vector<int> myvector, int start, int end){
  if (end - start  == 1) {
    vector<int> v;
    v.push_back(myvector[start]);
    return v;
  }
  else {
    int mid = (start + end) >> 1;
    vector<int> v1 = mergeSort(myvector, start, mid);
    vector<int> v2 = mergeSort(myvector, mid, end);

    int size1 = v1.size();
    int size2 = v2.size();
    vector<int> finalVector;
    int index1 =0;
    int index2 =0;
    while (index1 < size1 || index2 < size2){
      if (index1 >= size1){
        while (index2 < size2){
          finalVector.push_back(v2[index2]);
          index2++;
        }
      }
      else if (index2 >= size2){
        while (index1 < size1){
          finalVector.push_back(v1[index1]);
          index1++;
        }
      }

      else if (v1[index1] < v2[index2]){
        finalVector.push_back(v1[index1]);
        index1++;
      }
      else{
        finalVector.push_back(v2[index2]);
        index2++;
      }
    }
  return finalVector;
  }
}

int main(){
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  vector<int> myvector;
  for (int i = 0 ; i < N ; i++){
    int temp;
    cin >> temp;
    myvector.push_back(temp);
  }

  vector<int> ans = mergeSort(myvector,0,N);
  printVector(ans,0,N);
}

