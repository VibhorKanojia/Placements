#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
        map<char,int> genderList;
        string name;

        cin >> name;
        int size = name.size();
        for (int i = 0 ; i < size ; i++){
                if (genderList.find(name[i]) == genderList.end()){
                        genderList.insert(pair<char,int>(name[i],1));
                }
        }
        if (genderList.size() % 2 == 0) cout<<"CHAT WITH HER!"<<endl;
        else cout<<"IGNORE HIM!"<<endl;

        return 0;
}