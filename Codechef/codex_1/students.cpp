#include <bits/stdc++.h>

using namespace std;

int min_count;
int sum_reduced = 0;
int findMin(vector<int> my_vector, int n){
  int min = 1000000000;
  min_count = 0;
  for (int i = 0 ; i < n ; i++){
    if (my_vector[i] - sum_reduced <= 0) continue;
    else{
      if (my_vector[i] -sum_reduced < min){
        min = my_vector[i] - sum_reduced;
        min_count = 1;
      }
      else if (my_vector[i] - sum_reduced == min){
        min_count++;
      }
    }
  }
  return min;
}

int main(){
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> my_vector;
  for (int i = 0 ; i < n ; i++){
    int temp;
    cin >> temp;
    my_vector.push_back(temp);
  }
  
  
  int branches_left = n;

  while(branches_left > 0){
    
    int min_val = findMin(my_vector,n);
    //cout<<"total count is "<<min_count<<endl;
    int students_reduced = branches_left*min_val;
    cout<<students_reduced<<endl;
    branches_left = branches_left - min_count;
    sum_reduced = sum_reduced + min_val;
  }


  return 0;
}