#include <iostream>
#include <string>

using namespace std;


int main(){
        string str;
        cin >> str;

        int array[3]={0,0,0};

        int size = str.size();

        for (int i = 0 ; i < size ; i= i+2){
                if (str[i]== '1')array[0]++;
                else if (str[i]== '2')array[1]++;
                else if (str[i]== '3')array[2]++;
        }

        string ans = "";
        for (int i = 0; i < array[0];i++){
                ans=ans+"1+";
        }
        for (int i = 0; i < array[1];i++){
                ans=ans+"2+";
        }
        for (int i = 0; i < array[2];i++){
                ans=ans+"3+";
        }


        cout<<ans.substr(0, size)<<endl;
        return 0;
}