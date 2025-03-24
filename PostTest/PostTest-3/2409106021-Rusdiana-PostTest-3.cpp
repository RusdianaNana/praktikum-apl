#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Pemain {
    string nama;
    string posisi;
    int nomorPunggung;
};

struct User {
    string username;
    string password;
    int isAdmin; // 1 = admin, 0 = user biasa
};

// Deklarasi variabel untuk menyimpan data pemain
Pemain dataPemain[100];
int jumlahPemain = 0;

int main() {
    User users[100];
    int jumlahUser  = 0;
    int userLogin = -1;
    int percobaanLogin = 0;
    const int MAX_PERCobaan = 3;

    // Buat admin default
    users[jumlahUser ].username = "Rusdiana";
    users[jumlahUser ].password = "2409106021";
    users[jumlahUser ].isAdmin = 1;
    jumlahUser ++;

    while (true) {
        if (userLogin == -1) {
            // Menu utama
            cout << "\n============================================\n";
            cout << "|       SISTEM MANAJEMEN PEMAIN BOLA      |\n";
            cout << "============================================\n";
            cout << "| 1. Login                                 |\n";
            cout << "| 2. Register                              |\n";
            cout << "| 3. Keluar                                |\n";
            cout << "============================================\n";
            cout << "Pilihan: ";
            
            int pilihan;
            cin >> pilihan;
            cin.ignore();

            if (pilihan == 1) {
                // Login
                while (percobaanLogin < MAX_PERCobaan) {
                    cout << "\n============= LOGIN =============\n";
                    string username, password;
                    cout << "Username: ";
                    getline(cin, username);
                    cout << "Password: ";
                    getline(cin, password);

                    int loginSukses = 0;
                    for (int i = 0; i < jumlahUser ; i++) {
                        if (username == users[i].username && password == users[i].password) {
                            userLogin = i;
                            loginSukses = 1;
                            percobaanLogin = 0;
                            cout << "\nLogin berhasil!\n";
                            break;
                        }
                    }

                    if (loginSukses == 0) {
                        percobaanLogin++;
                        cout << "\nUsername atau password salah!\n";
                        cout << "Percobaan tersisa: " << MAX_PERCobaan - percobaanLogin << endl;
                        
                        if (percobaanLogin >= MAX_PERCobaan) {
                            cout << "\nAnda telah 3x salah login. Program berhenti.\n";
                            return 0;
                        }
                    } else {
                        break;
                    }
                }
            } 
            else if (pilihan == 2) {
                // Register
                if (jumlahUser  < 100) {
                    cout << "\n=========== REGISTER ===========\n";
                    User baru;
                    cout << "Username: ";
                    getline(cin, baru.username);
                    cout << "Password: ";
                    getline(cin, baru.password);
                    baru.isAdmin = 0;
                    users[jumlahUser ] = baru;
                    jumlahUser ++;
                    cout << "\nRegistrasi berhasil!\n";
                } else {
                    cout << "\nKapasitas user penuh!\n";
                }
            }
            else if (pilihan == 3) {
                cout << "\nTerima kasih telah menggunakan program ini!\n";
                return 0;
            }
            else {
                cout << "\nPilihan tidak valid!\n";
            }
        }
        else {
            // Menu setelah login
            if (users[userLogin].isAdmin == 1) {
                // Menu Admin
                cout << "\n============ MENU ADMIN ============\n";
                cout << "1. Tampilkan Data Pemain\n";
                cout << "2. Tambah Pemain\n";
                cout << "3. Edit Pemain\n";
                cout << "4. Hapus Pemain\n";
                cout << "5. Logout\n";
                cout << "==================================\n";
                cout << "Pilihan: ";
                
                int pilihan;
                cin >> pilihan;
                cin.ignore();

                if (pilihan == 1) {
                    // Tampilkan data
                    if (jumlahPemain == 0) {
                        cout << "\nBelum ada data pemain!\n";
                    } else {
                        cout << "\n========= DATA PEMAIN =========\n";
                        cout << left << setw(5) << "No" << setw(20) << "Nama" 
                             << setw(15) << "Posisi" << setw(10) << "Nomor" << endl;
                        cout << "------------------------------------------\n";
                        for (int i = 0; i < jumlahPemain; i++) {
                            cout << left << setw(5) << i+1 
                                 << setw(20) << dataPemain[i].nama
                                 << setw(15) << dataPemain[i].posisi
                                 << setw(10) << dataPemain[i].nomorPunggung << endl;
                        }
                    }
                }
                else if (pilihan == 2) {
                    // Tambah pemain
                    if (jumlahPemain < 100) {
                        Pemain baru;
                        cout << "\n========= TAMBAH PEMAIN =========\n";
                        cout << "Nama: ";
                        getline(cin, baru.nama);
                        cout << "Posisi: ";
                        getline(cin, baru.posisi);
                        cout << "Nomor Punggung: ";
                        cin >> baru.nomorPunggung;
                        cin.ignore();
                        
                        dataPemain[jumlahPemain] = baru;
                        jumlahPemain++;
                        cout << "\nData pemain berhasil ditambahkan!\n";
                    } else {
                        cout << "\nKapasitas data pemain penuh!\n";
                    }
                }
                else if (pilihan == 3) {
                    // Edit pemain
                    if (jumlahPemain > 0) {
                        cout << "\n========= EDIT PEMAIN =========\n";
                        cout << left << setw(5) << "No" << setw(20) << "Nama" 
                             << setw(15) << "Posisi" << setw(10) << "Nomor" << endl;
                        cout << "------------------------------------------\n";
                        for (int i = 0; i < jumlahPemain; i++) {
                            cout << left << setw(5) << i+1 
                                 << setw(20) << dataPemain[i].nama
                                 << setw(15) << dataPemain[i].posisi
                                 << setw(10) << dataPemain[i].nomorPunggung << endl;
                        }
                        
                        int nomor;
                        cout << "\nPilih nomor pemain yang akan diedit: ";
                        cin >> nomor;
                        cin.ignore();
                        
                        if (nomor >= 1 && nomor <= jumlahPemain) {
                            cout << "Nama [" << dataPemain[nomor-1].nama << "]: ";
                            getline(cin, dataPemain[nomor-1].nama);
                            cout << "Posisi [" << dataPemain[nomor-1].posisi << "]: ";
                            getline(cin, dataPemain[nomor-1].posisi);
                            cout << "Nomor Punggung [" << dataPemain[nomor-1].nomorPunggung << "]: ";
                            cin >> dataPemain[nomor-1].nomorPunggung;
                            cin.ignore();
                            cout << "\nData pemain berhasil diupdate!\n";
                        } else {
                            cout << "\nNomor tidak valid!\n";
                        }
                    } else {
                        cout << "\nBelum ada data pemain!\n";
                    }
                }
                else if (pilihan == 4) {
                    // Hapus pemain
                    if (jumlahPemain > 0) {
                        cout << "\n========= HAPUS PEMAIN =========\n";
                        cout << left << setw(5) << "No" << setw(20) << "Nama" 
                             << setw(15) << "Posisi" << setw(10) << "Nomor" << endl;
                        cout << "------------------------------------------\n";
                        for (int i = 0; i < jumlahPemain; i++) {
                            cout << left << setw(5) << i+1 
                                 << setw(20) << dataPemain[i].nama
                                 << setw(15) << dataPemain[i].posisi
                                 << setw(10) << dataPemain[i].nomorPunggung << endl;
                        }
                        
                        int nomor;
                        cout << "\nPilih nomor pemain yang akan dihapus: ";
                        cin >> nomor;
                        cin.ignore();
                        
                        if (nomor >= 1 && nomor <= jumlahPemain) {
                            for (int i = nomor-1; i < jumlahPemain-1; i++) {
                                dataPemain[i] = dataPemain[i+1];
                            }
                            jumlahPemain--;
                            cout << "\nData pemain berhasil dihapus!\n";
                        } else {
                            cout << "\nNomor tidak valid!\n";
                        }
                    } else {
                        cout << "\nBelum ada data pemain!\n";
                    }
                }
                else if (pilihan == 5) {
                    userLogin = -1;
                    cout << "\nLogout berhasil!\n";
                }
                else {
                    cout << "\nPilihan tidak valid!\n";
                }
            }
            else {
                // Menu User Biasa
                cout << "\n=========== MENU USER ===========\n";
                cout << "1. Lihat Data Pemain\n";
                cout << "2. Cari Pemain\n";
                cout << "3. Logout\n";
                cout << "==================================\n";
                cout << "Pilihan: ";
                
                int pilihan;
                cin >> pilihan;
                cin.ignore();

                if (pilihan == 1) {
                    if (jumlahPemain == 0) {
                        cout << "\nBelum ada data pemain!\n";
                    } else {
                        cout << "\n========= DATA PEMAIN =========\n";
                        cout << left << setw(5) << "No" << setw(20) << "Nama" 
                             << setw(15) << "Posisi" << setw(10) << "Nomor" << endl;
                        cout << "------------------------------------------\n";
                        for (int i = 0; i < jumlahPemain; i++) {
                            cout << left << setw(5) << i+1 
                                 << setw(20) << dataPemain[i].nama
                                 << setw(15) << dataPemain[i].posisi
                                 << setw(10) << dataPemain[i].nomorPunggung << endl;
                        }
                    }
                }
                else if (pilihan == 2) {
                    if (jumlahPemain > 0) {
                        string namaCari;
                        cout << "\nMasukkan nama pemain: ";
                        getline(cin, namaCari);
                        
                        int ditemukan = 0;
                        for (int i = 0; i < jumlahPemain; i++) {
                            if (dataPemain[i].nama.find(namaCari) != string::npos) {
                                if (ditemukan == 0) {
                                    cout << "\n====== HASIL PENCARIAN ======\n";
                                    cout << left << setw(5) << "No" << setw(20) << "Nama" 
                                         << setw(15) << "Posisi" << setw(10) << "Nomor" << endl;
                                    cout << "------------------------------------------\n";
                                }
                                cout << left << setw(5) << i+1 
                                     << setw(20) << dataPemain[i].nama
                                     << setw(15) << dataPemain[i].posisi
                                     << setw(10) << dataPemain[i].nomorPunggung << endl;
                                ditemukan = 1;
                            }
                        }
                        
                        if (ditemukan == 0) {
                            cout << "\nPemain tidak ditemukan!\n";
                        }
                    } else {
                        cout << "\nBelum ada data pemain!\n";
                    }
                }
                else if (pilihan == 3) {
                    userLogin = -1;
                    cout << "\nLogout berhasil!\n";
                }
                else {
                    cout << "\nPilihan tidak valid!\n";
                }
            }
        }
    }

    return 0;
}