#include <bits/stdc++.h>

using namespace std;

struct info{
  int nr[2];
  int index;
};

bool compareFunction(struct info a, struct info b){
  if (a.nr[0] < b.nr[0]) return 1;
  else if (a.nr[0] == b.nr[0] && a.nr[1] < b.nr[1] ) return 1;
  else return 0;
}

int main(){
  ios::sync_with_stdio(false);
  string s;
  cin >> s; 
  int n = s.size();
  int steps = log(n)/log(2) + 1;
  int suffixArray[n];
  int lcpArray[n];

  int ** inverseSuffix = new int*[steps+1];
  for (int i = 0 ; i <= steps ; i++){
    inverseSuffix[i] = new int[n];
  }

  for (int i = 0 ; i < n ; i++){
    inverseSuffix[0][i] = s[i] - 'a';
  }

  struct info rankArray[n];

  int step = 1;
  int count = 1;

  for (count = 1; count < n; count *=2){
    for (int i = 0 ; i < n ; i++){
      rankArray[i].nr[0] = inverseSuffix[step-1][i];
      rankArray[i].nr[1] = (i+count) < n ? inverseSuffix[step-1][i+count] : -1;
      rankArray[i].index = i;
     }
     sort(rankArray, rankArray + n, compareFunction);

    for (int i = 0 ; i < n ; i++){
      inverseSuffix[step][rankArray[i].index] = i > 0 && rankArray[i].nr[0] == rankArray[i-1].nr[0] && rankArray[i].nr[1] == rankArray[i-1].nr[1] ? i-1 :i;
     }

     step++;
  }

  for (int i = 0 ; i < n ; i++){
    suffixArray[inverseSuffix[step-1][i]] = i;
  }


  cout<<"SUFFIX ARRAY FOR "<<s<<endl;
  for (int i = 0 ; i < n ; i++){
    cout<<suffixArray[i]<<endl;
  }
  cout<<"-------------------------------------------"<<endl;
  
  int l = 0;
  for (int i = 0 ; i < n ; i++){
    int k = inverseSuffix[step-1][i]; // i=0 => rank of mississippi;
    if (k != 0){
      int j = suffixArray[k-1]; //index of whatever suffix comes before mississippi in ordering
      while (s[i+l] == s[j+l]) l++; // i+l checks character of mississippi and j+l checks characters of suffix before mississippi
      lcpArray[k] = l;      //common prefix between mississippi and it's previous suffix = l;
      if (l > 0 ) l--; // most important line here. Explanation below
    }
    else{
      lcpArray[k] = -1;
    }
  }

  cout<<"PREFIX ARRAY FOR "<<s<<endl;
  for (int i = 0 ; i < n ; i++){
    cout<<lcpArray[i]<<endl;
  }
  cout<<"----------------------------------------------"<<endl;
  return 0;

}


/* 
consider suffix 'ississippi'. The suffix that is lexicographically before it is issippi. 
Therefore, L = 4 for ississippi. When we consider the next suffix, i.e., by removing 'i', we get 'ssissippi'. This next suffix will definitely have
 'ssippi' before it ( That we get by removing 'i' from issippi) . And therefore, l >= 3 by default so we don't have to start l from the beginning.
 keep l = 3 (as 'ssi' is common )and check further characters.
 Therefore the while loop is not run fully and this algorithm is O(n). */





