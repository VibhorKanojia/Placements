#include <iostream>
#include <cmath>

using namespace std;

int main(){

        int n;
        cin >> n;
        
        int sum = 0 ;
        int index = 1;
        while (sum < n){
                sum = 5*(pow(2,index) -1);
                index++;
        }
        index = index -2;
        int duplicates = pow(2,index);
        int rem = (sum - n)/duplicates;
        if (rem == 4) cout<<"Sheldon"<<endl;
        if (rem == 3) cout<<"Leonard"<<endl;
        if (rem == 2) cout<<"Penny"<<endl;
        if (rem == 1) cout<<"Rajesh"<<endl;
        if (rem == 0) cout<<"Howard"<<endl;
        //cout<<duplicates<<endl;
        return 0;
}