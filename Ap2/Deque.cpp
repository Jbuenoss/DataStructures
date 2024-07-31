#include <iostream>

using namespace std;

class Deque{
    private:
        struct Noh{
            Noh *prev;
            int elem;
            Noh *next;
        };
        //First is the leftmost and right is the rightmost
        Noh *first, *last;
        
    public:
        Deque(){
            first = last = nullptr;
        }

        bool isEmpty(){
            return (first == nullptr && last == nullptr);
        }

        void pushLeft(int value){
            Noh *newNoh = new Noh {nullptr, value, first};
            if(isEmpty()){
                first = last = newNoh;
            } else {
                first->prev = newNoh;
                first = newNoh;
            }
        }

        void pushRight(int value){
            Noh *newNoh = new Noh {last, value, nullptr};
            if(isEmpty()){
                first = last = newNoh;
            } else {
                last->next = newNoh;
                last = newNoh;
            }
        }

        int top(){ //precondition: non-empty stack.
            return last->elem;
        }

        int bottom(){ //precondition: non-empty stack.
            return first->elem;
        }

        void popLeft(){
            if(isEmpty())       return;
            
            Noh *aux = first;
            if(first == last)   last = first = nullptr;
            else{ //the deque had at least 2
                first = first->next;
                first->prev = nullptr;
            }

            delete aux;
        }

        void popRight(){
            if(isEmpty())       return;
            
            Noh *aux = last;
            if(first == last)   last = first = nullptr;
            else{ //the deque had at least 2
                last = last->prev;
                last->next = nullptr;
            }
            delete aux;
        }

        void printDeque(){
            cout << "[ ";
            Noh* aux = first;
            if(!isEmpty()){
                while(aux->next != nullptr){
                    cout << aux->elem << " ";
                    aux = aux->next;
                }
                cout << aux->elem << " ";
            }
            cout << "]\n";
        }

        ~Deque(){
            while(!isEmpty()){
                popRight();
            }
        }
};


int main(){
    Deque deque;
    char oper;
    while(oper != 'Z'){
        cout << "Type the operation (Print(I), Push Rigth(R), Push Left(L), Pop Right(P), Pop Left(O), Show Rigth(S), Show Left(D), Empty?(E), Terminate Executation(Z)): ";
        cin >> oper;
        switch(oper){
            case 'I':
                deque.printDeque();
                break;
            case 'R':
                int aux;
                cout << "Type a integer to Push: ";
                cin >> aux;
                deque.pushRight(aux);
                break;
            case 'L':
                int elem;
                cout << "Type a integer to Push: ";
                cin >> elem;
                deque.pushLeft(elem);
                break;
            case 'P':
                deque.popRight();
                break;
            case 'O':
                deque.popLeft();
                break;
            case 'S':
                if(!deque.isEmpty())        cout << "Rigth: " << deque.top() << "\n";
                else                        cout << "the stack is empty\n";
                break;
            case 'D':
                if(!deque.isEmpty())        cout << "Left: " << deque.bottom() << "\n";
                else                        cout << "the stack is empty\n";
                break;
            case 'E':   
                if(deque.isEmpty())       cout << "It's empty\n";
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