// ARR POINTER 

// call by reference tidak perlua alamat, tapi bisa langsunh akses ke fungsinya
// call by pointer perlu alamat, lalu di derefer
# include <iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; i++){
        cout << "Elemen array ke-" << i+1 << " menggunakan pointer: " << *(ptr+i) <<endl; 
    }

    // mengakses elemem array meneggunakan indeks
    for(int i = 0; i < 5; i++){
        cout << "Elemen array ke-" << i+1 << " menggunakan indeks: " << arr[i] << endl;
    }
    return 0;
}