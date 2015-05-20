#include <iostream>
#include <cmath> 
using namespace std;
int main(){
        ios::sync_with_stdio(false);
        double n,m,a;
        cin >> n>>m>>a;
        cout<<(long long)ceil(n/a)*(long long)ceil(m/a)<<endl;
        return 0;
}