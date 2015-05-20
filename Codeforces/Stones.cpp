#include <iostream>
#include <string>

using namespace std;

int main(){
        int n;
        cin >> n;
        char cur='1';
        int count = 0;
        for (int i = 0 ;  i< n ; i++){
                char c;
                cin >> c;
                if (c ==cur) count++;
                else{
                        cur = c;
                }
        }
        cout<<count<<endl;
        return 0;
}