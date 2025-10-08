#include <iostream>
using namespace std;

// fungsi untuk menampilkan isi array
void tampilArray(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// fungsi untuk menukar nilai
void tukarNilai(int *ptrA, int *ptrB){
    int temp = *ptrA;       // Ambil nilai di alamat A
    *ptrA = *ptrB;    // Timpa nilai di alamat A dengan nilai dari B
    *ptrB = temp;         // Timpa nilai di alamat B dengan nilai sementara
}

int main(){
    int arrA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arrB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "--- SEBELUM DITUKAR ---" << endl;
    cout << "Array A :" << endl;
    tampilArray(arrA); // Beri arrA ke fungsi tampil
    cout << "Array B :" << endl;
    tampilArray(arrB); // Beri arrB ke fungsi tampil

    // Lakukan penukaran untuk setiap elemen
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            // Kirim alamat dari setiap elemen untuk ditukar nilainya
            tukarNilai(&arrA[i][j], &arrB[i][j]);
        }
    }

    cout << "--- SETELAH DITUKAR ---" << endl;
    cout << "Array A :" << endl;
    tampilArray(arrA);
    cout << "Array B :" << endl;
    tampilArray(arrB);

    return 0;
}