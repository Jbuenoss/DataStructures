#include <iostream>
#include <string>

using namespace std;

//Program to access the even indices of a string using a pointer
int main(){
    string name;
    cout << "Type something: ";
    getline(cin, name);
    char *letter = &name[0];
    for (int i = 0; i < (int)name.size(); i += 2){
        cout << *(letter + i);
    }
    cout << endl;

    return 0;
}