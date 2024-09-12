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
        int n; //quantidade de elementos
        int m; //tamanho da tabela
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
};

int main(){
    Hash h;

    h.Add(2, 45.5);
    h.Add(45, 23.5);
    h.Add(35, 2);

    h.PrintHash();

    return 0;
}