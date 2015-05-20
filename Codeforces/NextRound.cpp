#include <iostream>
using namespace std;

int main(){
         int N, K;
         cin >> N >> K;
         int index = 1;
         int count = 0;
         int kval;
         for (int i = 0 ; i < N ; i++){
                int temp;
                cin >> temp;
                if (index == K) kval = temp;
                if (index <=K){
                        if (temp >0){
                                count++;
                        }
                        else{
                                cout<<count<<endl;
                                return 0;
                        }
                }
                else if (index > K && temp == kval){
                        count++;
                } 
                else if (index > K && temp < kval) {
                        cout<<count<<endl;
                        return 0;
                }
                index++;           
         }
         cout<<count<<endl;
         return 0;
}