#include <iostream>

using namespace std;

class Stack{
    private:
        struct Noh{
            int value;
            Noh *before;
        };
        Noh *last;
    public:

        Stack(){
            last = nullptr;
        }

        bool isEmpty(){
            return last == nullptr;
        }

        void push(int elem){
            last = new Noh {elem, last};
        }

        void pop(){
            if(isEmpty())       return;

            Noh *aux = last;
            last = last->before;
            delete aux;
        }

        int top(){ //precondition: non-empty stack.
            return last->value;
        }

        ~Stack(){
            while(last != nullptr){
                Noh *aux = last;
                last = last->before;
                delete aux;
            }
        }
};


int main(){
    Stack stack;
    char oper;
    while(oper != 'Z'){
        cout << "Type the operation (Push(P), Pop(O), Show(S), Empty?(E), Terminate Executation(Z)) : ";
        cin >> oper;
        switch(oper){
            case 'P':
                int aux;
                cout << "Type a integer to Push: ";
                cin >> aux;
                stack.push(aux);
                break;
            case 'O':
                stack.pop();
                break;
            case 'S':
                if(!stack.isEmpty())        cout << "top: " << stack.top() << "\n";
                else                        cout << "the stack is empty\n";
                break;
            case 'E':   
                if(stack.isEmpty())       cout << "It's empty\n";
                else                cout << "It's not empty\n";
                break;
            case 'Z':
                break;
            default:
                cout << "Invalid Operation\n"; 
                break;
        }
    }

    return 0;
}