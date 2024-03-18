#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n, interval = 0;
    cout << "type the size of the list: ";
    cin >> n;
    int array[n];
    cout << "type the numbers: ";
    for(int i = 0; i < n; i++){ //O(n)
        cin >> array[i];
        interval = max(interval, array[i]);
    }
    int size = interval+1, period[size];
    memset(period, 0, sizeof(int)*(size));
    for(int i = 0; i < n; i++){ //O(n)
        period[array[i]] += 1;
    }
    cout << "--------------------Sorted array-------------------\n";
    for(int i = 0; i < size; i++){ //O(k+n)
        for(int j = 0; j < period[i]; j++){
            cout << i << ' ';
        }
    }

    return 0;
}