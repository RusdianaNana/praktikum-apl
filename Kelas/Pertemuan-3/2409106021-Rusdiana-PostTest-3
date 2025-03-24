#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan struct
struct Mahasiswa {
    string nama;
    int umur;
    float ipk;
};

typedef struct {
    string judul;
    string penulis;
    int tahunTerbit;
    float harga;
} Buku;

typedef struct {
    int nim;
    string nama;
} datamhs;
struct datanilai {
    float nilai_uts;
    float nilai_uas;
    };
typedef struct {
    datamhs mhs;
    struct datanilai nil;
} nilai;

int main() {
    // Membuat variabel bertipe struct Mahasiswa
    Mahasiswa mhs1;
    mhs1.nama = "Andi";
    mhs1.umur = 20;
    mhs1.ipk = 3.75;

    Mahasiswa mhs2;
    mhs2.nama = "Budi";
    mhs2.umur = 21;
    mhs2.ipk = 3.80;

    Buku buku1;
    // Mengisi nilai ke dalam struct
    buku1.judul = "Belajar C++";
    buku1.penulis = "John Doe";
    buku1.tahunTerbit = 2022;
    buku1.harga = 150000.75;

    nilai nilaimhs;
    nilaimhs.mhs.nim = 073;
    nilaimhs.mhs.nama = "Daffa";
    nilaimhs.nil.nilai_uts = 60;
    nilaimhs.nil.nilai_uas = 60;


    // Menampilkan data
    cout << "Nama: " << mhs1.nama << endl;
    cout << "Umur: " << mhs1.umur << endl;
    cout << "IPK: " << mhs1.ipk << endl;

    cout << "Nama: " << mhs2.nama << endl;
    cout << "Umur: " << mhs2.umur << endl;
    cout << "IPK: " << mhs2.ipk << endl;

    cout << "Judul: " << buku1.judul << endl;
    cout << "Penulis: " << buku1.penulis << endl;
    cout << "Tahun Terbit: " << buku1.tahunTerbit << endl;
    cout << "Harga: Rp" << buku1.harga << endl;

    cout << "NIM : " << nilaimhs.mhs.nim << endl;
    cout << "Nama : " << nilaimhs.mhs.nama << endl;
    cout << "Nilai UTS : " << nilaimhs.nil.nilai_uts << endl;
    cout << "Nilai UAS : " << nilaimhs.nil.nilai_uas << endl;

    return 0;
}