#include <iostream>
#include "Stack.h"

int main(){
    Stack stack;
    char oper;
    while(oper != 'Z'){
        std::cout << "Type the operation (Push(P), Pop(O), Show(S), Empty?(E), Full?(F), Terminate Executation(Z)) : ";
        std::cin >> oper;
        switch(oper){
            case 'P':
                char aux;
                std::cout << "Type a char to Push: ";
                std::cin >> aux;
                stack.push(aux);
                break;
            case 'O':
                stack.pop();
                break;
            case 'S':
                stack.back();
                break;
            case 'E':   
                if(stack.empty())       std::cout << "It's empty\n";
                else                std::cout << "It's not empty\n";
                break;
            case 'F':
                if(stack.isFull())        std::cout << "It's full\n";
                else                std::cout << "It's not full\n";
                break;
            case 'Z':
                break;
            default:
                std::cout << "Invalid Operation\n"; 
                break;
        }
    }

    return 0;
}