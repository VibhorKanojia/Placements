#include <iostream>
#include <vector>
#include <list>

using namespace std;


struct Node{
        int id;
        struct Node * leftchild;
        struct Node * rightchild;
};

void insertItem(Node * node, Node * &root){

        if (root == NULL) {
                root = new Node;
                root->id = node->id;
                root->leftchild = NULL;
                root->rightchild = NULL;
        }
        else if (node->id <= (root->id) ){
                insertItem(node, root->leftchild);
        }
        else {
                insertItem(node, root->rightchild);
        }
}

void printInOrder(struct Node * &root){
        if (root == NULL){
                return;
        }

        printInOrder(root->leftchild);
        cout<<(root->id)<<" ";
        printInOrder(root->rightchild);
        return;        
}

void printPostOrder(struct Node * &root){
        if (root == NULL){
                return;
        }

        printInOrder(root->leftchild);
        printInOrder(root->rightchild);        
        cout<<(root->id)<<" ";
        return;
}

void printPreOrder(struct Node * &root){
        if (root == NULL){
                return;
        }

        cout<<(root->id)<<" ";
        printInOrder(root->leftchild);
        printInOrder(root->rightchild);        
        return;
}

void findSum(struct Node * root, int num, vector<int> &path){
        
        if (num == 0){
                int size = path.size();
                for (int i= 0 ; i < size ; i++){
                        cout<<path[i]<<" ";
                }
                cout<<endl;
                path.clear();
                return;
        }
        
        if (root == NULL){
                path.clear();
                return;        
        }
        path.push_back(root->id);
        findSum(root->leftchild, num - (root->id),path);
        path.push_back(root->id);
        findSum(root->rightchild, num - (root->id), path);
        return; 
}

void printSpiralTraversal(struct Node * root, int & flag, list<struct Node *> & container){
        if (root == NULL) return;
        container.push_back(root);
        cout<<root->id<<" ";
        struct Node * temp;
        while (!container.empty()){
            if (flag == 0){
                int size = container.size();
                int index = 0;
                while (index < size){
                    list<struct Node *>::iterator it = container.begin();
                    temp = *it;
                    container.erase(it);
                    if (temp->leftchild != NULL){
                        cout<<(temp->leftchild)->id<<" ";
                        container.push_back(temp->leftchild);
                    }
                    if (temp->rightchild != NULL){
                        cout<<(temp->rightchild)->id<<" ";
                        container.push_back(temp->rightchild);
                    }
                    index++;
                }
                flag = 1;
            }
            else if (flag == 1){
                int size = container.size();
                int index = 0;
                while (index < size){
                    list<struct Node *>::iterator it = container.end();
                    it--;
                    temp = *it;
                    container.erase(it);
                    if (temp->rightchild != NULL){
                        cout<<(temp->rightchild)->id<<" ";
                        container.push_front(temp->rightchild);
                    }
                    if (temp->leftchild != NULL){
                        cout<<(temp->leftchild)->id<<" ";
                        container.push_front(temp->leftchild);
                    }
                    index++;
                }
                flag = 0;   
            }

        }
        
        return;
}

int main(){

        ios::sync_with_stdio(false);
        int N;
        cin >> N;
        struct Node * root = NULL;
        struct Node * node = new Node;
        for (int i = 0 ; i < N ; i++){
                cin >> node->id;
                insertItem(node , root);
        }
            // FIND ALL PATHS FROM ROOT WITH SUM OF ELEMENTS = num
        /*
        int num;
        cin >> num;
        vector<int> path;
        findSum(root, num, path);
        */



            //PRINT TREE IN ZIG ZAG PATTERN
            /*
                            100

                50                          150

        25              75              125             200

    16      33                      110     133             250

            OUTPUT - 100 50 150 200 125 75 25 16 33 110 133 250
            */



        /*
        list<struct Node *> container;
        int flag = 0;
        printSpiralTraversal(root, flag, container); //ZIG-ZAG PATTERN
        */


        // IN ORDER BST traversal gives sorted list. 

        return 0;
}





