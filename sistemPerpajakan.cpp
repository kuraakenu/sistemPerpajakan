#include <iostream>

using namespace std;
string usnTemp, passTemp;
string usn = "a";
string pass = "b";

void welcome();
bool login(bool success);
bool regist(bool success);

struct dataKendaraan{
    string brandKendaraan;
    int noPol;
    int harga;
};


int main(){
    welcome();
    cout << "ASEK";
    return 0;
}

void welcome(){
    char choice;
    bool success = false;

    do{
        system("cls");
        cout << "===| Selamat Datang! |===\n";
        cout << "Sudah memiliki akun? (y/n): ";
        cin >> choice;

        switch(choice){
            case 'y': case 'Y':
            success = login(success);
            break;
            case 'n': case 'N': 
            regist(success);
            break;
            default:
            cout << "Input Salah!\n";
            system("pause");
            break;
        }
    }while(!success);
}

bool login(bool success){
    system("cls");
    int coba = 3;
    while(coba > 0 && !success){
        system("cls");
        cout << "===| Silakan Login |===\n";
        cout << "Username: ";
        cin >> usnTemp;
        cout << "Password: ";
        cin >> passTemp;
        if(usnTemp == usn && passTemp == pass){
            system("cls");
            cout << "===| Login Berasil! |===\n";
            cout << "Anda akan diarahkan ke halaman utama!\n";
            system("pause");
            return success = true;
        }else{
            system("cls");
            coba -= 1;
            cout << "===| Username atau Password Salah! |===\n";
            cout << "===| Kesempatan Coba Sisa " << coba << "! |===\n";
            system("pause");
        }
    }
    system("cls");
    cout << "Kesempatan Login Habis!\n";
    cout << "Silakan Ulangi!\n";
    system("pause");
}

bool regist(bool success){
    system("cls");
    cout << "Silakan Registrasi Terlebih Dahulu!\n";
    cout << "Masukkan Username: ";
    cin >> usn;
    cout << "Masukkan Password: ";
    cin >> pass;
    system("cls");
    cout << "===| Registrasi Berhasil! |===\n";
    cout << "Anda akan diarahkan ke halaman login!\n";
    system("pause");
    return success = true;
}