#include <iostream>
#include <string>

using namespace std;

const int maxSize = 5;

struct Array{
    string key;
    string content;
};

class Map{
    private:
        int size;
        Array* array;
    public:
        Map(){
            array = new Array[maxSize];
            size = 0;
        }
        ~Map(){
            delete [] array;
        }

        bool isFull(){  return size == maxSize; }
        bool empty(){   return size == 0; }

        void push(string key, string content){
            if(isFull()){
                cout << "Its not possible to push\n";
                return;
            }
            array[size].key = key;
            array[size].content = content;
            size++;
        }

        bool hasKey(string key){
            if(empty())     return false;
            for(int i = 0; i < size; i++){
                if(array[i].key == key){
                    return true;
                }
            }
            return false;
        }

        string accessContent(string key){
            for(int i = 0; i < size; i++){
                if(array[i].key == key){
                    return array[i].content;
                }
            }
            return "erro";
        }

        void pop(string key){
            if(!hasKey(key)){
                cout << "the structure don't have the key\n";
                return;
            }
            for(int i = 0; i < size; i++){
                if(array[i].key == key){
                    if(i != (size-1)){
                        array[i].key = array[size-1].key;
                        array[i].content = array[size-1].key;
                    }
                    size--;
                    break;
                }
            }
        }
};


int main(){
    Map map;
    char oper;
    do{
        cout << "Type the operation (Push(P), Pop(O), Empty?(E), Full?(F), Access content(A), Terminate Executation(T)) : ";
        cin >> oper;
        switch(oper){
            case 'P':{
                string auxK, auxC;
                cout << "Type a string key to Push: ";
                cin >> auxK;
                cout << "Type a string content to Push: ";
                cin >> auxC;
                map.push(auxK, auxC);
                break;
            }
            case 'O':{
                string pop;
                cout << "Type a string key to pop: ";
                cin >> pop;
                map.pop(pop);
                break;
            }
            case 'E':   
                if(map.empty())       cout << "It's empty\n";
                else                cout << "It's not empty\n";
                break;
            case 'F':
                if(map.isFull())        cout << "It's full\n";
                else                cout << "It's not full\n";
                break;
            case 'A':{
                string con;
                cout << "Type a int to verify: ";
                cin >> con;
                if(map.hasKey(con))       cout << "content: " << map.accessContent(con) << '\n';
                else                    cout << "The map doesn't contains the key\n";
                break;
            }
            case 'T':
                break;
            default:{
                cout << "Invalid Operation\n"; 
                break;
            }
        }
    }while(oper != 'T');


    return 0;
}