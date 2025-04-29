#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Struktur data
struct Pemain {
    string nama;
    string posisi;
    int nomorPunggung;
};

struct User {
    string username;
    string password;
    bool isAdmin;
};

// Variabel global
const int MAX_PEMAIN = 100;
const int MAX_USER = 100;
Pemain dataPemain[MAX_PEMAIN];
User users[MAX_USER];
int jumlahPemain = 0;
int jumlahUser = 0;
int percobaanLogin = 0;

// Deklarasi fungsi
void initSystem();
void tampilkanMenuUtama();
void login();
void registerUser();
void tampilkanMenuAdmin();
void tampilkanMenuUser();
void tampilkanDataPemain();
void tambahPemain();
void editPemain();
void hapusPemain();
void cariPemain();
void sortNamaAscending();
void sortNomorDescending();
void selectionSortPosisi();

int main() {
    initSystem();
    tampilkanMenuUtama();
    return 0;
}

void initSystem() {
    // Buat akun admin default
    users[jumlahUser++] = {"Rusdiana", "2409106021", true};
}

// Implementasi fungsi-fungsi sorting
void sortNamaAscending() {
    for (int i = 0; i < jumlahPemain - 1; i++) {
        for (int j = 0; j < jumlahPemain - i - 1; j++) {
            if (dataPemain[j].nama > dataPemain[j + 1].nama) {
                swap(dataPemain[j], dataPemain[j + 1]);
            }
        }
    }
    cout << "\nData berhasil diurutkan berdasarkan nama (A-Z)!\n";
}

void sortNomorDescending() {
    for (int i = 0; i < jumlahPemain - 1; i++) {
        for (int j = 0; j < jumlahPemain - i - 1; j++) {
            if (dataPemain[j].nomorPunggung < dataPemain[j + 1].nomorPunggung) {
                swap(dataPemain[j], dataPemain[j + 1]);
            }
        }
    }
    cout << "\nData berhasil diurutkan berdasarkan nomor (terbesar ke terkecil)!\n";
}

void selectionSortPosisi() {
    for (int i = 0; i < jumlahPemain - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < jumlahPemain; j++) {
            if (dataPemain[j].posisi < dataPemain[min_idx].posisi) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(dataPemain[i], dataPemain[min_idx]);
        }
    }
    cout << "\nData berhasil diurutkan berdasarkan posisi!\n";
}

// Implementasi fungsi lainnya
void tampilkanMenuUtama() {
    while (true) {
        cout << "\n=== SISTEM MANAJEMEN PEMAIN BOLA ===";
        cout << "\n1. Login";
        cout << "\n2. Register";
        cout << "\n3. Keluar";
        cout << "\nPilihan: ";

        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: login(); break;
            case 2: registerUser(); break;
            case 3: exit(0);
            default: cout << "Pilihan tidak valid!\n";
        }
    }
}

void login() {
    string username, password;
    cout << "\nUsername: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].username == username && users[i].password == password) {
            if (users[i].isAdmin) {
                tampilkanMenuAdmin();
            } else {
                tampilkanMenuUser();
            }
            return;
        }
    }

    percobaanLogin++;
    cout << "\nLogin gagal! Percobaan " << percobaanLogin << "/3\n";
    if (percobaanLogin >= 3) {
        cout << "Anda telah 3x salah login. Program berhenti.\n";
        exit(0);
    }
}

void registerUser() {
    if (jumlahUser >= MAX_USER) {
        cout << "\nKapasitas user penuh!\n";
        return;
    }

    User baru;
    cout << "\nUsername: ";
    getline(cin, baru.username);
    cout << "Password: ";
    getline(cin, baru.password);
    baru.isAdmin = false;

    users[jumlahUser++] = baru;
    cout << "\nRegistrasi berhasil!\n";
}

void tampilkanMenuAdmin() {
    while (true) {
        cout << "\n=== MENU ADMIN ===";
        cout << "\n1. Tampilkan Data Pemain";
        cout << "\n2. Tambah Pemain";
        cout << "\n3. Edit Pemain"; 
        cout << "\n4. Hapus Pemain";
        cout << "\n5. Cari Pemain";
        cout << "\n6. Urutkan Data Pemain";
        cout << "\n7. Logout";
        cout << "\nPilihan: ";

        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: tampilkanDataPemain(); break;
            case 2: tambahPemain(); break;
            case 3: editPemain(); break;
            case 4: hapusPemain(); break;
            case 5: cariPemain(); break;
            case 6: {
                cout << "\n1. Urutkan berdasarkan Nama (A-Z)";
                cout << "\n2. Urutkan berdasarkan Nomor (Descending)";
                cout << "\n3. Urutkan berdasarkan Posisi";
                cout << "\nPilihan: ";
                int sortChoice;
                cin >> sortChoice;
                cin.ignore();
                switch (sortChoice) {
                    case 1: sortNamaAscending(); break;
                    case 2: sortNomorDescending(); break;
                    case 3: selectionSortPosisi(); break;
                    default: cout << "Pilihan tidak valid!\n";
                }
                break;
            }
            case 7: return;
            default: cout << "Pilihan tidak valid!\n";
        }
    }
}

void tampilkanMenuUser() {
    while (true) {
        cout << "\n=== MENU USER ===";
        cout << "\n1. Tampilkan Data Pemain";
        cout << "\n2. Cari Pemain";
        cout << "\n3. Urutkan Data Pemain";
        cout << "\n4. Logout";
        cout << "\nPilihan: ";

        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: tampilkanDataPemain(); break;
            case 2: cariPemain(); break;
            case 3: {
                cout << "\n1. Urutkan berdasarkan Nama (A-Z)";
                cout << "\n2. Urutkan berdasarkan Nomor (Descending)";
                cout << "\n3. Urutkan berdasarkan Posisi";
                cout << "\nPilihan: ";
                int sortChoice;
                cin >> sortChoice;
                cin.ignore();
                switch (sortChoice) {
                    case 1: sortNamaAscending(); break;
                    case 2: sortNomorDescending(); break;
                    case 3: selectionSortPosisi(); break;
                    default: cout << "Pilihan tidak valid!\n";
                }
                break;
            }
            case 4: return;
            default: cout << "Pilihan tidak valid!\n";
        }
    }
}

// Implementasi fungsi-fungsi CRUD pemain
void tampilkanDataPemain() {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain!\n";
        return;
    }

    cout << "\n=== DAFTAR PEMAIN ===\n";
    cout << left << setw(4) << "No" << setw(20) << "Nama" 
         << setw(15) << "Posisi" << setw(10) << "Nomor" << endl;
    cout << "----------------------------------------\n";
    
    for (int i = 0; i < jumlahPemain; i++) {
        cout << left << setw(4) << i+1 
             << setw(20) << dataPemain[i].nama
             << setw(15) << dataPemain[i].posisi
             << setw(10) << dataPemain[i].nomorPunggung << endl;
    }
}

void tambahPemain() {
    if (jumlahPemain >= MAX_PEMAIN) {
        cout << "\nKapasitas pemain penuh!\n";
        return;
    }

    Pemain baru;
    cout << "\nNama: ";
    getline(cin, baru.nama);
    cout << "Posisi: ";
    getline(cin, baru.posisi);
    cout << "Nomor Punggung: ";
    cin >> baru.nomorPunggung;
    cin.ignore();

    dataPemain[jumlahPemain++] = baru;
    cout << "\nData pemain berhasil ditambahkan!\n";
}

void editPemain() {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain!\n";
        return;
    }

    tampilkanDataPemain();
    cout << "\nPilih nomor pemain yang akan diedit: ";
    int nomor;
    cin >> nomor;
    cin.ignore();

    if (nomor < 1 || nomor > jumlahPemain) {
        cout << "\nNomor tidak valid!\n";
        return;
    }

    cout << "Nama [" << dataPemain[nomor-1].nama << "]: ";
    getline(cin, dataPemain[nomor-1].nama);
    cout << "Posisi [" << dataPemain[nomor-1].posisi << "]: ";
    getline(cin, dataPemain[nomor-1].posisi);
    cout << "Nomor Punggung [" << dataPemain[nomor-1].nomorPunggung << "]: ";
    cin >> dataPemain[nomor-1].nomorPunggung;
    cin.ignore();

    cout << "\nData pemain berhasil diupdate!\n";
}

void hapusPemain() {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain!\n";
        return;
    }

    tampilkanDataPemain();
    cout << "\nPilih nomor pemain yang akan dihapus: ";
    int nomor;
    cin >> nomor;
    cin.ignore();

    if (nomor < 1 || nomor > jumlahPemain) {
        cout << "\nNomor tidak valid!\n";
        return;
    }

    for (int i = nomor-1; i < jumlahPemain-1; i++) {
        dataPemain[i] = dataPemain[i+1];
    }
    jumlahPemain--;
    cout << "\nData pemain berhasil dihapus!\n";
}

void cariPemain() {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain!\n";
        return;
    }

    string keyword;
    cout << "\nMasukkan nama pemain: ";
    getline(cin, keyword);

    bool ditemukan = false;
    for (int i = 0; i < jumlahPemain; i++) {
        if (dataPemain[i].nama.find(keyword) != string::npos) {
            if (!ditemukan) {
                cout << "\n=== HASIL PENCARIAN ===\n";
                cout << left << setw(4) << "No" << setw(20) << "Nama" 
                     << setw(15) << "Posisi" << setw(10) << "Nomor" << endl;
                cout << "----------------------------------------\n";
                ditemukan = true;
            }
            cout << left << setw(4) << i+1 
                 << setw(20) << dataPemain[i].nama
                 << setw(15) << dataPemain[i].posisi
                 << setw(10) << dataPemain[i].nomorPunggung << endl;
        }
    }

    if (!ditemukan) {
        cout << "\nPemain tidak ditemukan!\n";
    }
}