#include <iostream>

using namespace std;


int panjang = 0;
string buah[100];
//buah[0] = apel

int total_array = sizeof(buah) / sizeof(string);
int pilihan, index;

int main () {
    do {
        // system("clear");
        cout << endl;
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Buah" << endl;
        cout << "2. Tambah Buah" << endl;
        cout << "3. Ubah Buah" << endl;
        cout << "4. Hapus Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
    
        switch (pilihan)
            {
            case 1:
                if (panjang == 0) {
                    cout << "Belom ada buah" << endl;
                } else {
                    for (int i = 0; i < panjang; i++) {
                        cout << i+1 << ". " << buah[i] << endl;
                    }
                }
                break;

            case 2:
                if (panjang < total_array) {
                    cout << "Masukkan Nama Buah: ";
                    cin.ignore();
                    getline (cin, buah[panjang]); // input di buah[0]; 
                    panjang ++;
                    cout << "buah berhasil ditambahkan" << endl;
                } else {
                    cout << "BUah pemuh";
                }
                break;

            case 3:
                if (panjang == 0) {
                    cout << "Belum ada buah untuk diubah." << endl;
                } else {
                    for (int i = 0; i < panjang; i++) {
                    cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
                    }
                    
                    cout << "pilih nomor buah yang mau di ubah : ";
                    cin.ignore();
                    cin >> index;

                    if ( index > 0 && index <= panjang) {
                        cout << "masukkan nama buah baru : ";
                        cin.ignore();
                        getline(cin, buah[index - 1]);
                        cout << "Buah berhasil di ubah" << endl;
                    } else {
                        cout << "nomor tidak valid" << endl;
                    }
                break;

            case 4:
                if (panjang == 0) {
                    cout << "Beloma ada buah";
                } else {
                    for (int i = 0; i < panjang; i++) {
                    cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
                    }

                    cout << "Masukkan nomor buah yang akan dihapus : ";
                    cin >> index;

                    if (index > 0 && index <= panjang) {
                        for(int i = index - 1; i < panjang -1; i++) {
                            buah[i] = buah [i + 1];
                        }
                    panjang--;
                    cout << "BUah berhasil dihapus";
                    } else {
                        cout << "nomor buah tidak valid" << endl;
                    }
                }
                break;
            
            default:
                break;
            }
        }
   } while (pilihan != 5);
}