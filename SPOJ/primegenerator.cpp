#include <iostream>
#include <cstring>
#include <cstdio>       
using namespace std;


// PRIMALITY TEST

int main(){
        
        int testcases;
        cin >> testcases;
        while(testcases--){
                int L,R;
                cin >> L;
                cin >> R;

                for (int i=L; i<=R ; i++){
                        if (i == 1){
                                continue;
                        }
                        if (i <= 3){
                                cout<<i<<endl;
                        }
                        else if (i%2 == 0 || i%3 == 0){
                                continue;
                        }
                        else {
                                int num = 5;
                                int flag = 0;
                                while (num*num <= i){
                                        if (i% num == 0 || i% (num+2) == 0){
                                                flag = 1;
                                                break;
                                        }
                                        num = num + 6;
                                }
                                if (flag ==0){
                                        cout<<i<<endl;
                                }
                        }

                }
                cout<<endl;
        }

        return 0;

}








