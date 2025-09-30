#include <iostream>
using namespace std;

int main(){
    int arr[5];
    for (int i = 0; i < 5; i++){
        cout << "Masukkan nilai indeks ke-" << i << ": ";
        cin >> arr[i];
    }
    int j = 0;
    while (j < 5){
        cout << "Value indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}