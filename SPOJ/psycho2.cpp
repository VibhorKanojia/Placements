#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void factorize(int &temp, int & evencount, int & oddcount, int & index){
        if (temp == 1) return;
        if (temp % index != 0){
                index = index + 1;
                factorize(temp, evencount, oddcount, index);
                return;
        }
        int val = 0;
        while(temp % index == 0){
                val++;
                temp = temp/index;
        }
        if (val % 2 == 0) evencount++;
        else oddcount++;
        index = index+1;
        factorize(temp, evencount, oddcount, index);
        return;
}

bool checkPsycho(int temp){
        int evencount = 0;
        int oddcount = 0;
        int index = 2;
        int curtemp = temp;
        factorize(curtemp, evencount, oddcount, index);
        if (evencount > oddcount){
                return true;
        }
        else{
                return false;
        }
}

int main(){
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






