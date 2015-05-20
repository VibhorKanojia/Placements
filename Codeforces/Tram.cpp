#include <iostream>
using namespace std;

int main(){
        int max = 0;
        int cur = 0;
        int n;
        cin >> n;

        for (int i = 0 ; i < n ; i++){
                int a,b;
                cin >>a>>b;
                cur = cur + b - a;
                if (cur > max){
                        max = cur;
                }
        }

        cout<<max<<endl;

        return 0;
}