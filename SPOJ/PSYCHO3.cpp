#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
void factorize(int &temp, int & evencount, int & oddcount, int & index){
        if (temp == 1) return;
        if (temp % primes[index] != 0){
                index = index + 1;
                factorize(temp, evencount, oddcount, index);
                return;
        }
        int val = 0;
        while(temp % primes[index] == 0){
                val++;
                temp = temp/primes[index];
        }
        if (val % 2 == 0) evencount++;
        else oddcount++;
        index = index+1;
        factorize(temp, evencount, oddcount, index);
        return;
}

bool checkPsycho(int temp, vector<int> & isPsycho){
        if (isPsycho[temp] == 1) return true;
        if (isPsycho[temp] == 0) return false;
        int evencount = 0;
        int oddcount = 0;
        int index = 0;
        int curtemp = temp;
        factorize(curtemp, evencount, oddcount, index);
        if (evencount > oddcount){
                isPsycho[temp] = 1;
                return true;
        }
        else{
                isPsycho[temp] = 0;
                return false;
        }
}

bool dynamicFunction(vector<int> & psychoVector, int K , int & flag, int index){
        if (flag == 1) return true;
        if (K == 0) {
                flag = 1;
                return true;
        }
        if (psychoVector.size() <= index) return false;

        dynamicFunction(psychoVector, K-psychoVector[index], flag , index+1);
        if (flag == 1) return true;
        dynamicFunction(psychoVector, K, flag , index+1);
        if (flag == 1) return true;

        return false;
}

int main(){
        int testcases;
        cin >> testcases;

        vector<int> isPsycho(1101, -1);
        isPsycho[0] = 0;
        isPsycho[1] = 0;
        while (testcases--){
                int N, K;
                cin >> N;
                cin >> K;
                vector<int> psychoVector;
                for (int i =0 ; i < N ; i++){
                        int temp;
                        cin >> temp;

                        if (checkPsycho(temp, isPsycho)){
                                psychoVector.push_back(temp);
                        }       
                }
                int flag = 0;
                int index = 0;
                bool ans = dynamicFunction(psychoVector, K, flag, index);
                if (ans) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
        }
        return 0;
}






