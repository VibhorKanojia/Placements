#include <iostream>
#include <cstring>
using namespace std;
#define M 1000001
#define ll long long    

int main(){
        int T;
        cin >> T;
        ll * A;
        A = new ll[M];
        A[1] = 1;
        A[2] = 5;
        for (int i = 3 ; i < M ; i++){
                A[i]=2*A[i-1] - A[i-2] + i + i/2;
        }
        while(T--){
                int N;
                cin >> N;
                cout<<A[N]<<endl;
        }
        return 0;
}