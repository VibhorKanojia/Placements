#include <iostream>
#include <cmath>

using namespace std;

int main(){
        int m, n;
        cin >> m >> n;
        int t = max(m,n);
        int ans = 0;
        ans = ans + (int)(t/2)*(m+n-t);
        if (t%2){
                ans = ans + (int)((m+n-t)/2);
        }
        cout<<ans<<endl;
        return 0;
}