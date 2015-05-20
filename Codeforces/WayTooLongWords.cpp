#include <iostream>
#include <string>
using namespace std;


int main(){
        int n;
        cin >> n;

        for (int i = 0 ; i < n ; i++){
                string s;
                cin >> s;
                int size = s.size();
                if (size > 10){
                        cout<<s[0];
                        cout<<size-2;
                        cout<<s[size-1];
                        cout<<endl;
                }
                else{
                        cout<<s<<endl;
                }
        }
        return 0;
}