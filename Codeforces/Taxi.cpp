#include <iostream>
#include <cmath>
using namespace std;

int main(){
        int array[5]={0,0,0,0,0};
        int n;
        cin >>n;
        int numtaxi = 0;
        for (int i =0; i < n ; i++){
                int temp;
                cin >> temp;
                array[temp]++;
        }

        if (array[2] % 2 == 0){
                numtaxi = numtaxi + array[2]/2;
                numtaxi = numtaxi+ array[4];
                if (array[3] <= array[1]){
                        numtaxi = numtaxi + array[3];
                        array[1] = array[1]-array[3];
                        numtaxi = numtaxi + ceil(((double)array[1])/4);
                }
                else{
                        numtaxi = numtaxi + max(array[3], array[1]);
                }

        }
        else {
                numtaxi = numtaxi + array[2]/2;
                numtaxi = numtaxi+ array[4];
                if (array[3] <= array[1]){
                        numtaxi = numtaxi + array[3];
                        array[1] = array[1]-array[3];
                        array[1] = array[1]-2;
                        numtaxi++;
                        numtaxi = numtaxi + ceil(((double)array[1])/4);
                }
                else{
                        numtaxi = numtaxi + max(array[3], array[1]) + 1;
                }

        }
        cout<<numtaxi<<endl;
        return 0;

}