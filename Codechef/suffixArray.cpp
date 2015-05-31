#include <bits/stdc++.h>

using namespace std;


struct tpl{
    int ranks[2];
    int index;
};

bool compareFuction(struct tpl a, struct tpl b){
    if (a.ranks[0] < b.ranks[0]) return 1;
    if (a.ranks[0] == b.ranks[0] && a.ranks[1] < b.ranks[1] ) return 1;
    return 0; 
}

int main(){
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int size = s.size();
    int suffixArray[size];
    int totalCounts = (log(size)/log(2)) + 1;
    int ** p = new int*[totalCounts+1];
    for (int i= 0 ; i < totalCounts+1 ; i++){
        p[i] = new int[size];
    }

    for (int i = 0 ; i < size ; i++){
        p[0][i] = s[i] - 'a';
    }

    int step = 1;
    int count = 1;
    tpl tupleArray[size];
    for (count = 1 ; count < size ; count *=2){
        for (int i= 0 ; i < size ; i++){
            tupleArray[i].ranks[0] = p[step-1][i];
            tupleArray[i].ranks[1] = (i + count) < size ? p[step-1][i+count] : -1;
            tupleArray[i].index = i;
        }
        sort(tupleArray, tupleArray+ size, compareFuction);
        for (int i = 0 ; i < size ; i++){
            if (i == 0) p[step][tupleArray[i].index] =  i;
            else{
                if (tupleArray[i].ranks[0] == tupleArray[i-1].ranks[0] && tupleArray[i].ranks[1]== tupleArray[i-1].ranks[1]){
                    p[step][tupleArray[i].index] = p[step][tupleArray[i-1].index];
                }
                else{
                    p[step][tupleArray[i].index] = i;
                }
            }    
        }

        step++;
    }
    for (int i = 0 ; i < size ; i++){
        suffixArray[p[step-1][i]] = i;
    }
    for (int i = 0 ; i < size ; i++){
        cout<<suffixArray[i]<<endl;
    } 
    return 0;
}



