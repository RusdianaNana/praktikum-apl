#include <iostream>
using namespace std;

void tukarBilangan(int *bil1, int *bil2) {
    int sementara = *bil1;
    *bil1 = *bil2;
    *bil2 = sementara;
}
int main() {
    int a = 1;
    int b = 2;
    
    cout << "\nNilai sebelum ditukar:\n";
    cout << "Bilangan pertama = " << a << endl;
    cout << "Bilangan kedua = " << b << endl;
    tukarBilangan(&a, &b);
    cout << "\nNilai setelah ditukar:\n";
    cout << "Bilangan pertama = " << a << endl;
    cout << "Bilangan kedua = " << b << endl;
    
    return 0;
}