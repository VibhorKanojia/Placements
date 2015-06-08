#include <iostream>
#include <cstring>
#include <cstdio>       
#define gc getchar_unlocked
#define MAX_N 6000000
using namespace std;


void scanint(int &x){
        register int c = gc();
        x = 0;
        for (; (c < 48 || c > 57) ; c=gc());
        for (; ( c > 47 && c < 58) ; c=gc()){
                x = (x<<1) + (x<<3) + c-48;
        }
}


void scanword(string &s){
        s = "";
        register char c = gc();
        while (c != ' ' || c!= '\n'){
                s = s + c;
                c = gc();
        }
}


void scanline(string &s){
        s ="";
        register char c = gc();
        while (c!= '\n'){
                s = s + c;
                c = gc();
        }       
}

void markMultiples(bool * primes, int num , int N){
        int i = 2;
        while (num*i < N){
                primes[num*i] = 1;
                i++;
        }
}


int main(){
        bool * primes;
        primes = new bool[MAX_N+1];
        memset(primes, 0, sizeof(primes));
        primes[0] = 1;
        primes[1] = 1;
        for (int i=2 ; i < MAX_N+1 ; i++){
                if (primes[i] == 0){
                        markMultiples(primes, i,MAX_N+1);
                }
        }
        int testcases;
        scanint(testcases);
        while(testcases--){
                int L,R;
                scanint(L);
                scanint(R);

                for (int i=L; i<=R ; i++){
                        if (primes[i] == 0){
                                cout<<i<<", ";
                        }
                }
                cout<<endl;
        }

        return 0;

}








