#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Data-rata nilai adalah :" << rata2(mhs) << endl;

    system("read -p 'Press Enter to continue...' var");

    return 0;
}