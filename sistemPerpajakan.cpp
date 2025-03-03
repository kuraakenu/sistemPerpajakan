#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;
string usnTemp, passTemp;
string usn = "admin";
string pass = "admin";

void welcome();
bool login(bool success);
bool regist(bool success);
bool isUsnValid();
bool isPassValid();
bool isBlank(string str);

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
            return true;
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

bool regist(bool success){\
    bool valid = false;
    bool blank = true;
    system("cls");
    cin.ignore();
    while(!valid || blank){
        system("cls");
        cout << "Silakan Registrasi Terlebih Dahulu!\n";
        cout << "Masukkan Username: ";
        getline(cin, usn);
        blank = isBlank(usn);
        if(blank){
            cout << "Username tidak boleh kosong!\n";
            system("pause");
        }
        valid = isUsnValid();
        if(!valid){
            cout << "Username tidak boleh ada spasi atau lebih dari 12 char!\n";
            system("pause");
        }
    }
    valid = false;
    blank = true;
    while(!valid || blank){
        system("cls");
        cout << "Silakan Registrasi Terlebih Dahulu!\n";
        cout << "Masukkan Username: " << usn << '\n';
        cout << "Masukkan Password: ";\
        getline(cin, pass);
        blank = isBlank(pass);
        if(blank){
            cout << "Password tidak boleh kosong!\n";
            system("pause");
        }
        valid = isPassValid();
        if(!valid){
            cout << "Password harus terdiri dari Huruf dan Angka tanpa Spasi!\n";
            system("pause");
        }
    }

    system("cls");
    cout << "===| Registrasi Berhasil! |===\n";
    cout << "Anda akan diarahkan ke halaman login!\n";
    system("pause");
    return true;
}

bool isUsnValid(){
    if(usn.length() > 12){
        return false;
    }
    for(char c : usn){
        if(isspace(c)){
            return false;
        }
    }
    return true;
}

bool isPassValid(){
    bool hasDigit = false;
    if(pass.length() > 10){
        return false;
    }
    for(char c : pass){
        if(isspace(c)){
            return false;
        }
        if(isdigit(c)){
            hasDigit = true;
        }
    }
    if(hasDigit){
        return true;
    }else{
        return false;
    }
}

bool isBlank(string str){
    if(str.empty()){
        return true;
    }
    for(char c : str){
        if(!isspace(c)){
            return false;
        }
    }
    return true;
}