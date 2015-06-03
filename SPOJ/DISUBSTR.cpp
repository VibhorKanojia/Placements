#include <bits/stdc++.h>

using namespace std;


struct info{
  int nr[2];
  int index;
};


bool compareFunction(struct info a, struct info b){
  if (a.nr[0] < b.nr[0]) return 1;
  if (a.nr[0] == b.nr[0] && a.nr[1] < b.nr[1]) return 1;
  else return 0;
}


int main(){
  int testcases;
  cin >> testcases;

  while (testcases--){
    string s;
    cin >> s;

    int n = s.size();
    int steps = log(n)/log(2) + 1;
    
    int ** inverseSuffix = new int*[steps+1];
    int suffixArray[n];
    int lcpArray[n];
    for (int i = 0 ; i < steps + 1 ; i++){
      inverseSuffix[i] = new int[n];
    }

    for (int i = 0 ; i < n ; i++){
      inverseSuffix[0][i]= s[i];
    }

    struct info rankArray[n];

    int step =1;
    int count = 1;

    for (count = 1 ; count < n ; count *=2){
      for (int i = 0 ; i < n ; i++){
        rankArray[i].nr[0] = inverseSuffix[step-1][i]; 
        rankArray[i].nr[1] = (i + count) < n ? inverseSuffix[step-1][i+count] : -1;
        rankArray[i].index = i;
      }

      sort(rankArray, rankArray + n, compareFunction);


      for (int i = 0 ; i < n ; i++){
        inverseSuffix[step][rankArray[i].index] = i > 0 && rankArray[i].nr[0] == rankArray[i-1].nr[0] && rankArray[i].nr[1] == rankArray[i-1].nr[1] ? inverseSuffix[step][rankArray[i-1].index] : i;
      }
      step++;
    }


    if (n == 1){
      inverseSuffix[0][0] = 0; 
      suffixArray[0] = 0;
    }
    else{
      for (int i = 0 ; i < n ; i++){
       suffixArray[inverseSuffix[step-1][i]] = i;
      }
    }

    int l = 0;
    for (int i = 0 ; i < n ; i++){
      int k = inverseSuffix[step-1][i];
      if (k !=0){
        int j = suffixArray[k-1];
        while (s[i+l] == s[j+l]) l++;
        lcpArray[k] = l;
        if (l > 0) l--;
      }
      else{
        lcpArray[k] = 0;
      }
    }
    int distSub = 0;
    for (int i = 0 ; i < n ; i++){
      distSub = distSub + n - suffixArray[i] - lcpArray[i];
    }
    cout<<distSub<<endl;
  

  }

  return 0;
}


/* FIND DISTINCT SUBSTIRINGS OF A STRING */
/* EPIC WAY by using lcp ARRAY
eg. ABABA
REMEMBER : substring - prefix of suffix
prefix array

A         0
ABA       1
ABABA     3
BA        0
BABA      2 

Consider prefix of each of the suffixes, 
eg. BABA - B, BA, BAB, BABA
    BA   - B, BA

    therefore, number of prefixes of a given suffix = length of that suffix
    But it includes duplicates, and here we will make use of lcp Array
    LCP(ABABA) = 3 it means that 'ABA'BA has 3 letters common with 'ABA', so we don't have to consider those prefixes.
    Therefore we will count only ABAB and ABABA. 
    Therefore the formula becomes 
    distinct prefixes for ABABA = length of ABABA - lcp Value of ABABA
    and length of ABABA can be found using suffixArray. 
    length of a suffix  = length of string - index of suffix.
  
    Therefore, total number of distinct substrings of ABABA = 1 + 2 + 2 + 2 + 2 = 9;

*/







