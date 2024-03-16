#include <iostream>

typedef int typeData;
const int maxSize = 5;

class Set{
    private:
        int size;
        typeData* array;
    public:
        Set(){
            size = 0;
            array = new typeData[maxSize];
        }
        ~Set(){
            std::cout << "array deleted\n";
            delete [] array;
        }
        
        int binarySearch(typeData elem){
            int first = 0, last = size-1;
            while(first <= last){
                int mid = (first+last)/2;
                if(array[mid] == elem)      return mid;
                else if(array[mid] > elem)      last = mid-1;
                else                        first = mid+1;
            }
            return -1;
        }
        int binarySearchRecursive(typeData elem, int first, int last){
            if(first <= last){
                int mid = (first+last)/2;
                if(array[mid] == elem)      return mid;
                else if(elem > array[mid])      first = mid+1;
                else                        last = mid-1;
                return binarySearchRecursive(elem, first, last);
            }
            else{
                return -1;
            }
        }

        bool empty(){
            return size == 0;
        }

        bool isFull(){
            return size == maxSize;
        }

        bool contains(typeData elem){
            if(empty())             return false;
            int aux = binarySearch(elem);
            return aux != -1;
        }

        void push(typeData elem){
            if(isFull())        std::cout << "It's not possible, the set is full\n";
            else if(contains(elem))     std::cout << "the set already contains the element\n";
            else if(empty()){
                array[size] = elem;
                size++;
            }
            else{
                int fir = 0, las = size-1;
                while(fir <= las){
                    int mid = (fir+las)/2;
                    if(array[mid] > elem){
                        if(mid == 0 || array[mid-1] < elem){ //elem is the lower || elem has to be in the middle
                            for(int i  = size; i > mid; i--){
                                array[i] = array[i-1];
                            }
                            array[mid] = elem;
                        }
                        else{
                            las = mid-1;
                        }
                    }
                    else{
                        fir = mid+1;
                        if(fir > las){  //elem is the higher
                            array[size] = elem;
                        }
                    }
                }
                size++;
            }
        }

        void pop(typeData elem){
            if(empty())         std::cout << "It's not possible to pop, the set is empty\n";
            else if(!contains(elem))    std::cout << "The set doesn't contain the value\n"; 
            else{
                int pos = binarySearchRecursive(elem, 0, size-1);
                size--;
                for(int i = pos; i < size; i++){
                    array[i] = array[i+1];
                }
            }
        }

        void show(){
            std::cout << "[ ";
            for(int i = 0; i < size; i++){
                std::cout << array[i] << ' ';
            }
            std::cout << "]\n";
        }
};

int main(){
    Set set;
    char oper;
    do{
        std::cout << "Type the operation (Push(P), Pop(O), Show(S), Empty?(E), Full?(F), contains?(C) Terminate Executation(T)) : ";
        std::cin >> oper;
        switch(oper){
            case 'P':
                int aux;
                std::cout << "Type a int to Push: ";
                std::cin >> aux;
                set.push(aux);
                break;
            case 'O':
                int pop;
                std::cout << "Type a int to pop: ";
                std::cin >> pop;
                set.pop(pop);
                break;
            case 'S':
                set.show();
                break;
            case 'E':   
                if(set.empty())       std::cout << "It's empty\n";
                else                std::cout << "It's not empty\n";
                break;
            case 'F':
                if(set.isFull())        std::cout << "It's full\n";
                else                std::cout << "It's not full\n";
                break;
            case 'C':
                int con;
                std::cout << "Type a int to verify: ";
                std::cin >> con;
                if(set.contains(con))       std::cout << "The set contains the value\n";
                else                    std::cout << "The set doesn't contains the value\n";
                break;
            case 'T':
                break;
            default:
                std::cout << "Invalid Operation\n"; 
                break;
        }
    }while(oper != 'T');

    return 0;
}