typedef char data;
const int maxSize = 5;

//implement of a limited stack
class Stack{
    private:
        data* array;
        int size;
    public:
        Stack();
        ~Stack();
        void push(data elem);
        void pop();
        void back();
        bool isFull();
        bool empty(); 
};