#include <iostream>
#include <string> 

using namespace std;


int main(){
        string s,t;
        cin >>s;
        t="";
        int size = s.size();
        for (int i= 0 ; i < size ; i++){
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' );
                else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' );
                else if (s[i] < 92){
                        char temp = s[i]+32;
                        t=t+'.'+temp;
                }
                else{
                        t=t+'.'+s[i];
                }
        }
        cout<<t<<endl;

        return 0;
}

