#include <iostream>
#include <string>

using namespace std;

int main(){
        int n ;
        cin >> n;
        int val = 0;
        for (int i = 0 ; i < n ; i++){
                string str;
                cin >> str;
                if (str[1] == '+') val++;
                else if (str[1] == '-') val--;
        }
        cout<<val<<endl;
        return 0;
}