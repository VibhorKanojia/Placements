#include <iostream>
#include <string>
#include <cstdio>
#define gc getchar_unlocked
#define MAX_N 1000000000
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


int main(){
        int testcases;
        scanint(testcases);
        bool primes[MAX_N];
        memset(primes, 0, sizeof(primes));
        int i = 2;
        while( i < MAX_N){

        }       

        return 0;

}








