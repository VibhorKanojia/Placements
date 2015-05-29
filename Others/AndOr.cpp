#include <iostream>
#include <string>
#include <vector>
#define MAX 1000000000000000000
using namespace std;

void printBits(int num){
        string s="";
        while (num >= 1){
                int temp = num&1;
                if (temp == 1) s='1'+s;
                else s='0'+s;
                num = num/2;
        }
        cout<<s<<endl;
        return;
}


long long incrementB(long long B){
        long long temp = 1;
        while ( B >=1){
                temp = temp << 1;
                //cout<<temp<<endl;
                B = B/2;
        }
        return temp-1;
}

long long incrementB2(long long B){
        long long temp = 1;
        while ( B >=1){
                temp = temp << 1;
                //cout<<temp<<endl;
                B = B/2;
        }
        return temp-1;
}



int main(){
        cout<<(81|82|83|84)<<endl;
        /*
        vector<long long> powers;
        long long temp = 1;
        while (temp < MAX){
                temp = temp << 1;
                powers.push_back(temp-1);
                //cout<<temp<<endl;
        }
        int testcases;
        cin >> testcases;
        while (testcases--){
                long long A;
                long long B;
                cin >> A >> B;
        
                int size = powers.size();
                int index1 = 0;
                int index2 = 0;
                for (int i = 0 ; i < size ; i++){
                        if (powers[i] > A){
                                index1 = i;
                                break;
                        }
                }
                if (powers[index1] <= B){
                        long long ans = incrementB(B);
                        cout<<ans<<endl;
                }
                else{
                        long long ans = incrementB2(B);
                        cout<<ans<<endl;
                }
        }       
        /*
        int A, B;
        cin >>A >> B;
        printBits(A);
        printBits(B);
        
        int temp = A;
        for (int i = A ; i <= B ; i++){
          //      cout<<"Hello"<<endl;
                temp  = temp | i;
            //    cout<<temp<<endl; 
        }
        cout<<temp<<endl;
        */
        return 0;
}