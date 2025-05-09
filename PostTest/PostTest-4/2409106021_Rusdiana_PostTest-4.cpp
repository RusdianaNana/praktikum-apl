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
    int isAdmin; 
};

Pemain dataPemain[100];
int jumlahPemain = 0;
User users[100];
int jumlahUser = 0;

void tampilkanMenuUtama(int &userLogin, int &percobaanLogin);
void login(int &userLogin, int &percobaanLogin);
void registerUser();
void tampilkanMenuAdmin(int &userLogin);
void tampilkanMenuUser(int &userLogin);
void tampilkanDataPemain();
void tambahPemain();
void editPemain();
void hapusPemain();
void cariPemain();
void tampilkanPemain(const Pemain &p);
void tampilkanPemain(const Pemain &p, bool showHeader);

int main() {
    int userLogin = -1;
    int percobaanLogin = 0;

    users[jumlahUser].username = "Rusdiana";
    users[jumlahUser].password = "2409106021";
    users[jumlahUser].isAdmin = 1;
    jumlahUser++;

    while (true) {
        if (userLogin == -1) {
            tampilkanMenuUtama(userLogin, percobaanLogin);
        } else {
            if (users[userLogin].isAdmin == 1) {
                tampilkanMenuAdmin(userLogin);
            } else {
                tampilkanMenuUser(userLogin);
            }
        }
    }

    return 0;
}


void tampilkanMenuUtama(int &userLogin, int &percobaanLogin) {
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

    switch (pilihan) {
        case 1:
            login(userLogin, percobaanLogin);
            break;
        case 2:
            registerUser();
            break;
        case 3:
            cout << "\nTerima kasih telah menggunakan program ini!\n";
            exit(0);
        default:
            cout << "\nPilihan tidak valid!\n";
    }
}

void login(int &userLogin, int &percobaanLogin) {
    const int MAX_PERCobaan = 3;
    
    while (percobaanLogin < MAX_PERCobaan) {
        cout << "\n============= LOGIN =============\n";
        string username, password;
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);

        bool loginSukses = false;
        for (int i = 0; i < jumlahUser; i++) {
            if (username == users[i].username && password == users[i].password) {
                userLogin = i;
                loginSukses = true;
                percobaanLogin = 0;
                cout << "\nLogin berhasil!\n";
                break;
            }
        }

        if (!loginSukses) {
            percobaanLogin++;
            cout << "\nUsername atau password salah!\n";
            cout << "Percobaan tersisa: " << MAX_PERCobaan - percobaanLogin << endl;
            
            if (percobaanLogin >= MAX_PERCobaan) {
                cout << "\nAnda telah 3x salah login. Program berhenti.\n";
                exit(0);
            }
        } else {
            break;
        }
    }
}

void registerUser() {
    if (jumlahUser < 100) {
        cout << "\n=========== REGISTER ===========\n";
        User baru;
        cout << "Username: ";
        getline(cin, baru.username);
        cout << "Password: ";
        getline(cin, baru.password);
        baru.isAdmin = 0;
        users[jumlahUser] = baru;
        jumlahUser++;
        cout << "\nRegistrasi berhasil!\n";
    } else {
        cout << "\nKapasitas user penuh!\n";
    }
}

void tampilkanMenuAdmin(int &userLogin) {
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

    switch (pilihan) {
        case 1:
            tampilkanDataPemain();
            break;
        case 2:
            tambahPemain();
            break;
        case 3:
            editPemain();
            break;
        case 4:
            hapusPemain();
            break;
        case 5:
            userLogin = -1;
            cout << "\nLogout berhasil!\n";
            break;
        default:
            cout << "\nPilihan tidak valid!\n";
    }
}

void tampilkanMenuUser(int &userLogin) {
    cout << "\n=========== MENU USER ===========\n";
    cout << "1. Lihat Data Pemain\n";
    cout << "2. Cari Pemain\n";
    cout << "3. Logout\n";
    cout << "==================================\n";
    cout << "Pilihan: ";
    
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
        case 1:
            tampilkanDataPemain();
            break;
        case 2:
            cariPemain();
            break;
        case 3:
            userLogin = -1;
            cout << "\nLogout berhasil!\n";
            break;
        default:
            cout << "\nPilihan tidak valid!\n";
    }
}

void tampilkanDataPemain() {
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

void tambahPemain() {
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
        
        cout << "\nDetail pemain yang ditambahkan:\n";
        tampilkanPemain(baru);
    } else {
        cout << "\nKapasitas data pemain penuh!\n";
    }
}

void editPemain() {
    if (jumlahPemain > 0) {
        tampilkanDataPemain();
        
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
            
            cout << "\nData pemain setelah edit:\n";
            tampilkanPemain(dataPemain[nomor-1], true);
        } else {
            cout << "\nNomor tidak valid!\n";
        }
    } else {
        cout << "\nBelum ada data pemain!\n";
    }
}

void hapusPemain() {
    if (jumlahPemain > 0) {
        tampilkanDataPemain();
        
        int nomor;
        cout << "\nPilih nomor pemain yang akan dihapus: ";
        cin >> nomor;
        cin.ignore();
        
        if (nomor >= 1 && nomor <= jumlahPemain) {
            cout << "\nData pemain yang akan dihapus:\n";
            tampilkanPemain(dataPemain[nomor-1]);
            
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

void cariPemain() {
    if (jumlahPemain > 0) {
        string namaCari;
        cout << "\nMasukkan nama pemain: ";
        getline(cin, namaCari);
        
        bool ditemukan = false;
        for (int i = 0; i < jumlahPemain; i++) {
            if (dataPemain[i].nama.find(namaCari) != string::npos) {
                if (!ditemukan) {
                    cout << "\n====== HASIL PENCARIAN ======\n";
                    cout << left << setw(5) << "No" << setw(20) << "Nama" 
                         << setw(15) << "Posisi" << setw(10) << "Nomor" << endl;
                    cout << "------------------------------------------\n";
                }
                cout << left << setw(5) << i+1 
                     << setw(20) << dataPemain[i].nama
                     << setw(15) << dataPemain[i].posisi
                     << setw(10) << dataPemain[i].nomorPunggung << endl;
                ditemukan = true;
            }
        }
        
        if (!ditemukan) {
            cout << "\nPemain tidak ditemukan!\n";
        }
    } else {
        cout << "\nBelum ada data pemain!\n";
    }
}

void tampilkanPemain(const Pemain &p) {
    cout << "Nama: " << p.nama << endl;
    cout << "Posisi: " << p.posisi << endl;
    cout << "Nomor Punggung: " << p.nomorPunggung << endl;
}

void tampilkanPemain(const Pemain &p, bool showHeader) {
    if (showHeader) {
        cout << "\n=== DETAIL PEMAIN ===\n";
    }
    tampilkanPemain(p);
}