#include <iostream>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

struct Node{
        int id;
        list<Node *> children;
};

// I WILL GET BACK TO YOU BITCH
int main(){
        ios::sync_with_stdio(false);
        int N;
        cin >> N;

        vector<vector <int> > path;
        for (int i = 0 ; i < N ; i++){
                vector<int> temp;
                path.push_back(temp);
        }

        struct Node * array[N];
        for (int i = 0 ; i < N ; i++){
                struct Node * t = new Node;
                t->id = i+1;
                array[i] = t;
        }

        for (int i = 1 ; i < N ; i++){
                int temp;
                cin >>temp;
                (array[temp-1]->children).push_back(array[i]); 
        }


        recursiveFunction(path, array, N, 0);

        return 0;

}