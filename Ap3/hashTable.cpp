#include <iostream>

using namespace std;

//map implemeted using hash table
class Hash{
    private:
        struct Noh {
            int key;
            double value;
            Noh *next;
        };
        Noh sent;
        int n; // number of elements
        int m; // table size
        Noh **T;

        int hashFunction(int c){
            return c%m;
        }

        void resizeTable(int newSize){
            Noh **U = new Noh*[newSize];

            int pastSize = m;
            m = newSize;

            for(int i = 0; i < newSize; i++)    U[i] = &sent;

            for(int i = 0; i < pastSize; i++){
                Noh* a = T[i];
                while(a != &sent){
                    int uKey = hashFunction(a->key);
                    Noh* next = a->next;
                    a->next = U[uKey];
                    U[uKey] = a;
                    a = next;
                }
            }

            delete[] T;
            T = U;
        }

    public:
        Hash(){
            n = 0;
            m = 1;
            T = new Noh*[m];
            T[0] = &sent;
        }

        // pre-condition: key was not already part of the hash table
        void Add(int key, double value){
            if(n == m)      resizeTable(2*m);

            int position = hashFunction(key);
            T[position] = new Noh{key, value, T[position]};
            n++;
        }

        void PrintHash(){
            for(int i = 0; i < m; i++){
                Noh* a = T[i];
                cout << "Key " << i << endl;
                while(a != &sent){
                    cout << "   Key: " << a->key << " value: " << a->value << endl;
                    a = a->next;
                }
            }
        }

        void getValue(int key){
            int pos = hashFunction(key);
            sent.key = key;
            Noh* a = T[pos];
            while(a->key != key){
                a = a->next;
            }
            if(a == &sent)      cout << "The key " << key << " not belong to the list" << endl;
            else                cout << "value: " << a->value << endl;
        }

        void removeValue(int key){
            int pos = hashFunction(key);

            Noh* *cima = &T[pos];
            Noh* s = T[pos];

            sent.key = key;
            while(s->key != key){
                cima = &s->next;
                s = s->next;
            }
            if(s == &sent){
                cout << "the key don't belong" << endl;
                return;
            }
            *cima = s->next;
            delete s;
        }

        ~Hash(){
            for(int i = 0; i < m; i++){
                Noh* p = T[i];
                while(p != &sent){
                    Noh* next = p->next;
                    delete p;
                    p = next;
                }
                //T[i] is not an array, but a pointer to a linked list of nodes.
                //delete[] T[i];
            }
            delete[] T;
        }
};

int main(){
    Hash h;

    h.Add(2, 45.5);
    h.Add(45, 23.5);
    h.Add(35, 2.2323);
    h.Add(3, 25.3);
    h.Add(40, 42.34);

    h.removeValue(2);
    h.removeValue(45);
    h.removeValue(40);
    h.removeValue(1);

    h.PrintHash();
    h.getValue(2);
    h.getValue(4);

    return 0;
}