#include <iostream>

struct Fila{
    static constexpr int size = 5;

    int i[size];
    int first = -1, last;

    void Enqueue(int var){
        if(Empty()){
            first = last = 0;
            i[last] = var;
        } else if(Full()){
            std::cout << "It's not possible Enqueue, the fila is full!\n";
        } 
        else{
            last = (last+1) % size;
            i[last] = var;
        }
    }

    void Dequeue(){
        if(Empty()){
            std::cout << "The queue is empty, it can't dequeue\n";
        }
        else if(first == last){
            first = -1;
        }
        else{
            first = (first+1) % size;
        }
    }

    void FirstElement(){
        if(Empty())     std::cout << "The queue has not elements\n";
        else            std::cout << "the queue first: " << i[first] << '\n';
        
    }
    bool Empty(){
        return first == -1;
    }

    bool Full(){
        if(Empty())   return false;
        return (first == (last+1) % size); //% tem precedencia sobre soma
    }
}f;

int main(){
    char oper;
    while(oper != 'T'){
        std::cout << "Type the operation (Enqueue(E), Dequeue(D), First(F), Empty?(M), Full?(U), Terminate Executation(T)) : ";
        std::cin >> oper;
        switch(oper){
            case 'E':
                int aux;
                std::cout << "Type a integer to Enqueue: ";
                std::cin >> aux;
                f.Enqueue(aux);
                break;
            case 'D':
                f.Dequeue();
                break;
            case 'F':
                f.FirstElement();
                break;
            case 'M':
                if(f.Empty())       std::cout << "The queue is empty\n";
                else                std::cout << "The queue is not empty\n";
                break;
            case 'U':
                if(f.Full())       std::cout << "The queue is full\n";
                else                std::cout << "The queue is not full\n";
                break;
            case 'T':
                break;
            default:
                std::cout << "Invalid Operation\n"; 
                break;
        }
    }

    return 0;
}