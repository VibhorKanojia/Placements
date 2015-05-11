#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097};
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






