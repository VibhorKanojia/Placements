#include <iostream>
#include <string>
using namespace std;

int main(){
        string str;
        cin >> str;

        int count=0;
        char flag='0';
        int size = str.size();

        for (int i = 0 ; i < size ; i++){
                if (str[i] == flag) count++;
                else{
                        if (flag == '0') flag = '1';
                        else flag = '0';
                        count = 1;
                }
                if (count == 7) {
                        cout<<"YES"<<endl;
                        return 0;
                }
        }
        cout<<"NO"<<endl;
        return 0;
}