#include <iostream>
#include <string>
using namespace std;
#include <iomanip>


int main() {
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

    // Variabel untuk menu dan konversi
    int choice;
    double value;

    // Loop utama program
    while (true) {
        // Menampilkan menu
        cout << "=============================================\n";
        cout << setw(32) <<"Pilih Menu Konversi:\n";
        cout << "1. Konversi Meter ke (Centimeter, Mile, Foot)\n";
        cout << "2. Konversi Centimeter ke (Meter, Mile, Foot)\n";
        cout << "3. Konversi Mile ke (Meter, Centimeter, Foot)\n";
        cout << "4. Konversi Foot ke (Meter, Centimeter, Mile)\n";
        cout << "5. Keluar\n";
        cout << "=============================================\n";
        cout << "Masukkan pilihan (1-5): ";
        cin >> choice;

        // Proses pilihan menu
        if (choice == 1) {
            cout << "Masukkan nilai dalam meter: ";
            cin >> value;
            cout << value << " meter = " << value * 100 << " cm\n";
            cout << value << " meter = " << value * 0.000621371 << " mile\n";
            cout << value << " meter = " << value * 3.28084 << " foot\n\n";
        } else if (choice == 2) {
            cout << "Masukkan nilai dalam centimeter: ";
            cin >> value;
            cout << value << " cm = " << value / 100 << " meter\n";
            cout << value << " cm = " << value * 0.00000621371 << " mile\n";
            cout << value << " cm = " << value * 0.0328084 << " foot\n\n";
        } else if (choice == 3) {
            cout << "Masukkan nilai dalam mile: ";
            cin >> value;
            cout << value << " mile = " << value * 1609.34 << " meter\n";
            cout << value << " mile = " << value * 160934 << " cm\n";
            cout << value << " mile = " << value * 5280 << " foot\n\n";
        } else if (choice == 4) {
            cout << "Masukkan nilai dalam foot: ";
            cin >> value;
            cout << value << " foot = " << value * 0.3048 << " meter\n";
            cout << value << " foot = " << value * 30.48 << " cm\n";
            cout << value << " foot = " << value * 0.000189394 << " mile\n\n";
        } else if (choice == 5) {
            cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!\n";
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n\n";
        }
    }

    return 0;
}