#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
        int n;
        cin >> n;
        int sum = 0;
        vector<int> myvector;
        for (int i =0 ; i < n ; i++){
                int temp;
                cin >> temp;
                sum = sum + temp;
                myvector.push_back(temp);
        }

        sort(myvector.begin(), myvector.end());
        int tempsum = 0;
        int index = n-1;
        int count = 0;
        while (tempsum <=(sum/2)){
                count++;
                tempsum = tempsum + myvector[index];
                index--;
        }

        cout<<count<<endl;
        return 0;

}
