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

        int printHeights(Noh* n){
            if(n == nullptr)        return 0;
            int leftH = printHeights(n->left);
            int rightH = printHeights(n->right);
            int bh = (leftH > rightH) ? leftH + 1 : rightH + 1;
            cout << n->value << " height: " << bh << endl;
            return bh;
        }

    public:
        Tree(){
            root = nullptr;
        }

        void isEmpty(){
            if(empty())       cout << "it's Empty" << endl;
            else              cout << "It's not empty" << endl;
        }

        void contains(int number){
            Noh* a = root;
            while(a != nullptr){
                if(number > a->value)           a = a->right;
                else if(number < a->value)      a = a->left;
                else{
                    cout << "Yes, the number " << number << " belongs" << endl;
                    return;
                }
            }
            cout << "No, the number " << number << " does not belong to the tree" << endl;
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

        void printAllTree(){
            cout << "Tree: ";
            printTree(root);
            cout << endl;
        }
        
        void printAllHeights(){
            cout << "======Heights=======" << endl;
            printHeights(root);
        }

        void removeValue(int value){
            Noh *n = root;
            Noh **cima = &root;

            while(n != nullptr){
                if(value > n->value){
                    cima = &n->right;
                    n = n->right;
                }
                else if(value < n->value){
                    cima = &n->left;
                    n = n->left;
                }       
                else    break; //n is the value
            }

            if(n == nullptr)        return; //not belongs

            if(n->right == nullptr)         cima = &n->left;
            else if(n->left == nullptr)     cima = &n->right;
            else{ //n has right and left node
                Noh* e = n->right;
                Noh **cima_e = &n->right;

                while(e->left != nullptr){
                    cima_e = &e->left;
                    e = e->left;
                }

                *cima_e = e->right; //remove the e
                //put the e
                *cima = e;
                e->right = n->right;
                e->left = n->left;
            }
            delete n;
        }

        ~Tree(){
            deleteNoh(root);
        }
};

int main(){
    Tree t;
    t.isEmpty();
    t.contains(34);
    t.addValue(20);
    t.isEmpty();
    t.addValue(10);
    t.addValue(5);
    t.addValue(6);
    t.contains(34);
    t.addValue(34);
    t.addValue(30);
    t.addValue(34);
    t.addValue(34);
    t.contains(34);
    t.printAllTree();
    t.printAllHeights();

    return 0;
}