#include <iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        char nama[5];
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "Masukkan nama siswa: ";
        cin >> siswa[i].nama;
        cout << "Masukkan nilai siswa: ";
        cin >> siswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while(j < MAX){
        cout << "Nama siswa: " << siswa[j].nama << " ,Nilai siswa: " << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}