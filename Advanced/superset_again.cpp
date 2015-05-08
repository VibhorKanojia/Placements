#include <iostream>
#include <vector>

using namespace std;

int finalsum = 0;
int findLCM(vector<int> & choices){
    int num1 = choices[0];
    int size = choices.size();
    for (int i = 0 ; i < size  ; i++){
        int num2 = choices[i];
        int c = num1*num2;
        while (num1 != num2){
            if (num1 > num2){
                num1 = num1-num2;
            }
            else {
                num2 = num2 - num1;
            }
        }
        num1 = c/num1;
    }
    cout<<"LCM is "<< num1<<endl;
    return num1;
}

void printChoices(vector<int> & v){
    int size = v.size();

    for (int i = 0 ; i < size ; i++){
        cout<< v[i]<<" ";
    }
    cout<<endl;
}

void fillSum (int i, vector<int> & bag, int N){
    cout<<"************** "<<i<<":"<<endl;
    int num = i;
    int count = 0;
    vector<int> choices;
    while (num >= 1){
        int bit = num & 1;
        if (bit == 1){
            choices.push_back(bag[count]);
        }
        count++;
        num = (int)(num/2);   
    }
    int lcm = findLCM(choices);
    if (choices.size() % 2 == 0){
        finalsum = finalsum - (int)(N/lcm);
    }
    else{
        finalsum = finalsum + (int)(N/lcm);
    }
    cout<<endl;   
    return;
}

int main(){
    int N;
    cin >> N;

    int B;
    cin >> B;

    vector<int> bag;

    for (int i = 0 ; i < B ; i++){
        int val;
        cin >> val;
        bag.push_back(val);
    }

    int super = 1;
    super = (super << B);
    cout<<"Super is "<<super<<endl;
    for (int i = 1 ; i < super ; i++){
        fillSum(i, bag, N);
    }

    cout<< " ANS is "<<finalsum<<endl;
    return 0;
}