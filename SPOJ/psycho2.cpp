#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX_N 10000001

vector<int> primes;

void markMultiples(int i, bool * array){
        int index = 2;
        while (i*index < MAX_N){
                array[i*index] = 1;
                index++;
        }
        return;
}

void factorize(int &temp, int & evencount, int & oddcount, int index){
        if (temp == 1) return;
        if (temp % primes[index] != 0){
                factorize(temp, evencount, oddcount, index + 1);
                return;
        }
        int val = 0;
        while(temp % primes[index] == 0){
                val++;
                temp = temp/primes[index];
        }
        if (val % 2 == 0) evencount++;
        else oddcount++;
        factorize(temp, evencount, oddcount, index+1);
        return;
}

bool checkPsycho(int temp){
        int evencount = 0;
        int oddcount = 0;
        int index = 0;
        factorize(temp, evencount, oddcount, index);
        if (evencount > oddcount){
                return true;
        }
        else{
                return false;
        }
}

int main(){

        bool * array;
        array = new bool[MAX_N];
        memset(array, 0, sizeof(array));
        for (int i = 2 ; i < MAX_N ; i++){
                if (array[i] == 0){
                        primes.push_back(i);
                        markMultiples(i, array);
                }
        }


        int testcases;
        cin >> testcases;
        while (testcases--){
                int N;
                cin >> N;       
                if (N == 0 || N == 1){
                        cout<<"Ordinary Number"<<endl;
                        continue;
                } 
                if(checkPsycho(N)){
                        cout<<"Psycho Number"<<endl;
                }
                else{
                        cout<<"Ordinary Number"<<endl;
                }
                
        }
        return 0;
}






