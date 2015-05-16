#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10000001

void markMultiples(int i, bool * array){
        int index = 2;
        while (i*index < MAX_N){
                array[i*index] = 1;
                index++;
        }
        return;
}

int main(){
        bool * array;
        array = new bool[MAX_N];

        memset(array, 0, sizeof(array));

        for (int i = 2 ; i < MAX_N ; i++){
                if (array[i] == 0){
                        cout<<i<<", ";
                        markMultiples(i, array);
                }
        }
}