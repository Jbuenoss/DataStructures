#include <iostream>

using namespace std;

class Tree{
    private:
        struct Noh {
            Noh* left;
            int value;
            Noh* right;
        };
        Noh* root;

        //Percurso em ordem
        void printTree(Noh* n){
            if(n != nullptr){
                printTree(n->left);
                cout << n->value << ' ';
                printTree(n->right);
            }
        }

        //Percurso pos-ordem
        void deleteNoh(Noh* n){
            if(n != nullptr){
                deleteNoh(n->left);
                deleteNoh(n->right);
                delete n;
            }
        }

        bool empty(){
            return root == nullptr;
        }

    public:
        Tree(){
            root = nullptr;
        }

        void isEmpty(){
            if(empty())       cout << "it's Empty" << endl;
            else              cout << "It's not empty" << endl;
        }
        
        //pre-condition: none
        void addValue(int number){
            if(empty()){
                root = new Noh {nullptr, number, nullptr};
                return;
            }

            Noh* father = nullptr;
            Noh* a = root;
            while(a != nullptr and a->value != number){
                if(number > a->value){
                    father = a;
                    a = a->right;
                } else if(number < a->value) {
                    father = a;
                    a = a->left;
                } else{
                    return; //the number is already in the tree
                }
            }
            //don't have it
            if(a == nullptr){
                Noh* elem = new Noh {nullptr, number, nullptr};
                if(number > father->value)      father->right = elem;
                else                            father->left = elem;
            }
        }

        // bool contains(int number){
        // }

        void printAllTree(){
            cout << "Tree: ";
            printTree(root);
            cout << endl;
        }

        

        ~Tree(){
            deleteNoh(root);
        }
};


int main(){
    Tree t;
    t.isEmpty();
    t.addValue(20);
    t.isEmpty();
    t.addValue(10);
    t.addValue(5);
    t.addValue(6);
    t.addValue(34);
    t.addValue(30);

    t.printAllTree();
    


    return 0;
}