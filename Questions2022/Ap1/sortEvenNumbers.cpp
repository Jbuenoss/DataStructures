/*
receive a list of int and sort only the even numbers
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "type how much int the list will have: ";
    cin >> n;
    int array[n];
    cout << "type the numbers: ";
    for(int i = 0; i < n; i++)      cin >> array[i];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((array[i] % 2 != 0) || (array[j] % 2 != 0))      continue;
            if(array[i] > array[j]){
                int aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
    cout << "-----------array sorted------------\n";
    for(int i = 0; i < n; i++)      cout << array[i] << ' ';

    return 0;
}