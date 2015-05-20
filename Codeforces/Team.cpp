#include <iostream>
using namespace std;

int main(){
        int n;
        cin >> n;
        bool ** array = new bool*[n];
        for (int i = 0 ; i < n ; i++){
                array[i] = new bool[3];
        }

        for (int i = 0 ; i < n ; i++){
                for (int j = 0 ; j < 3 ; j++){
                        cin >> array[i][j];
                }
        }

        int ans = 0;
        for (int i = 0 ; i < n ; i++){
                int sum = 0;
                for (int j =0 ; j < 3 ; j++){
                        sum = sum + array[i][j];
                }
                if (sum >=2) ans++;
        }

        cout<<ans<<endl;
        return 0;
}