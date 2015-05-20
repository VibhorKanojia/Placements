#include <iostream>
#include <string>

using namespace std;

int main(){
        string str;
        cin >> str;
        int size = str.size();
        if (size == 1){
                if (str[0] > 92) str[0] = str[0] -32;
                else str[0] = str[0]  + 32;
                cout<<str<<endl;
                return 0;
        }
        else{
                bool flag = false;
                string str_org = str;
                for (int i = 1 ; i < size ; i++){
                        if (str[i] > 92) {
                                flag = true;
                                break;
                        }
                        else{
                                str[i]= str[i]+32;
                        }
                }
                if (!flag){
                        if (str[0] > 92) str[0] = str[0]-32;
                        else str[0] = str[0] + 32;
                        cout<<str<<endl;
                        return 0;
                }
                else{
                        cout<<str_org<<endl;
                        return 0;
                }
        }


        return 0;
}