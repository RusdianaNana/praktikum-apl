#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Inisialisasi variabel array satu dimensi
    string nama_pemain[100];
    string posisi_pemain[100];
    int nomor_punggung[100];
    int jumlah_data = 0;

        const string username = "Rusdiana";
        const string password = "2409106021";
        const int max_kesempatan = 3;
        int kesempatan = 0;
    
        while (kesempatan < max_kesempatan) {
            string input_username, input_password;
            cout << "Username: ";
            getline(cin, input_username);
            cout << "Password: ";
            getline(cin, input_password);
    
            if (input_username == username && input_password == password) {
                cout << "Login berhasil!\n" << endl;
                break;
            } else {
                kesempatan++;
                cout << "Login gagal. Sisa percobaan: " << max_kesempatan - kesempatan << "\n" << endl;
            }
        }
    
        if (kesempatan == max_kesempatan) {
            cout << "Anda telah mencoba login " << max_kesempatan << " kali. Program berhenti." << endl;
            return 0;
        }
    
    // Main program
    while (true) {
        cout << "\n==== Manajemen Data Pemain Bola =====" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        int pilihan;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Tampilkan Data
            cout << "\n========================= Data Pemain Bola =========================" << endl;
            cout << setw(5) << "No" << setw(20) << "Nama Pemain" << setw(20) << "Posisi" << setw(20) << "Nomor Punggung" << endl;
            cout << string(66, '-') << endl;
            for (int i = 0; i < jumlah_data; i++) {
                cout << setw(5) << i + 1 << setw(20) << nama_pemain[i] << setw(20) << posisi_pemain[i] << setw(15) << nomor_punggung[i] << endl;
            }
            cout << endl;
        } else if (pilihan == 2) {
            // Tambah Data
            if (jumlah_data < 100) {
                cout << "Masukkan Nama Pemain: ";
                cin.ignore();
                getline(cin, nama_pemain[jumlah_data]);
                cout << "Masukkan Posisi Pemain: ";
                getline(cin, posisi_pemain[jumlah_data]);
                cout << "Masukkan Nomor Punggung: ";
                cin >> nomor_punggung[jumlah_data];
                jumlah_data++;
                cout << "Data berhasil ditambahkan!\n";
            } else {
                cout << "Kapasitas data penuh!\n";
            }
        } else if (pilihan == 3) {
            // Update Data
            if (jumlah_data > 0) {
                cout << "\n===== Data Pemain Bola =====" << endl;
                cout << setw(5) << "No" << setw(20) << "Nama Pemain" << setw(20) << "Posisi" << setw(15) << "Nomor Punggung" << endl;
                cout << string(60, '-') << endl;
                for (int i = 0; i < jumlah_data; i++) {
                    cout << setw(5) << i + 1 << setw(20) << nama_pemain[i] << setw(20) << posisi_pemain[i] << setw(15) << nomor_punggung[i] << endl;
                }
                cout << endl;

                int index;
                cout << "Masukkan nomor pemain yang ingin diupdate: ";
                cin >> index;
                if (index >= 1 && index <= jumlah_data) {
                    cout << "Masukkan Nama Pemain Baru: ";
                    cin >> nama_pemain[index - 1];
                    cout << "Masukkan Posisi Pemain Baru: ";
                    cin >> posisi_pemain[index - 1];
                    cout << "Masukkan Nomor Punggung Baru: ";
                    cin >> nomor_punggung[index - 1];
                    cout << "Data berhasil diupdate!\n";
                } else {
                    cout << "Nomor pemain tidak valid!\n";
                }
            } else {
                cout << "Tidak ada data untuk diupdate!\n";
            }
        } else if (pilihan == 4) {
            // Hapus Data
            if (jumlah_data > 0) {
                cout << "\n=== Data Pemain Bola ===" << endl;
                cout << setw(5) << "No" << setw(20) << "Nama Pemain" << setw(20) << "Posisi" << setw(15) << "Nomor Punggung" << endl;
                cout << string(60, '-') << endl;
                for (int i = 0; i < jumlah_data; i++) {
                    cout << setw(5) << i + 1 << setw(20) << nama_pemain[i] << setw(20) << posisi_pemain[i] << setw(15) << nomor_punggung[i] << endl;
                }
                cout << endl;

                int index;
                cout << "Masukkan nomor pemain yang ingin dihapus: ";
                cin >> index;
                if (index >= 1 && index <= jumlah_data) {
                    for (int i = index - 1; i < jumlah_data - 1; i++) {
                        nama_pemain[i] = nama_pemain[i + 1];
                        posisi_pemain[i] = posisi_pemain[i + 1];
                        nomor_punggung[i] = nomor_punggung[i + 1];
                    }
                    jumlah_data--;
                    cout << "Data berhasil dihapus!\n";
                } else {
                    cout << "Nomor pemain tidak valid!\n";
                }
            } else {
                cout << "Tidak ada data untuk dihapus!\n";
            }
        } else if (pilihan == 5) {
            // Keluar
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    }

    return 0;
}