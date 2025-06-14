#include <iostream>
using namespace std;

int total_saldo = 0;
long int password;
string username;
int total_harga_keseluruhan = 0;
string alamat;

void login(){	
	cout << "===== LOGIN =====" << endl;
	cout << "Masukkan Username : ";
	cin >> username;
	cout << "Masukkan Password : ";
	cin >> password;
}

void home(){
	system("cls");
	cout << endl;
	cout << "=========================" << endl;
	cout << "Selamat Datang " << username << endl;
	cout << "Saldo = Rp. " << total_saldo << endl;
	cout << "=========================" << endl;
}

void list_barang(){
	system("cls");
	int pilihan;
	char ya_tidak;
	cout << "=============================" << endl;
	cout << "1. Kaos : Rp. 75.000" << endl;
	cout << "2. Kemeja : Rp. 175.000" << endl;
	cout << "3. Celana : Rp. 70.000" << endl;
	cout << "4. Jaket : Rp. 200.000" << endl;
	cout << "5. Sepatu : Rp. 150.000" << endl;
	cout << "-----------------------------" << endl;
	cout << "6. Selesai" << endl;
	cout << "=============================" << endl;

	while (pilihan != 6) {
		cout << "Masukkan pilihan : ";
		cin >> pilihan;
			
		switch (pilihan){
			case 1:
				total_harga_keseluruhan += 75000;
				break;
			case 2:
				total_harga_keseluruhan += 175000;
				break;
			case 3:
				total_harga_keseluruhan += 70000;
				break;
			case 4:
				total_harga_keseluruhan += 200000;
				break;
			case 5:
				total_harga_keseluruhan += 150000;
				break;
		}
	}
}

void input_alamat(){
	system("cls");
	cout << "Masukkan alamat : ";
	cin >> alamat;
}

void tambah_saldo(){
	system("cls");
	int isi_saldo;
	cout << "Masukkan jumlah saldo : ";
	cin >> isi_saldo;
	total_saldo += isi_saldo;
	home();
}

void pilih_ekspedisi(){
	int pilihan;
	cout << endl;
	cout << "1. JNE : Rp. 14.000" << endl;
	cout << "2. JNT : Rp. 15.000" << endl;
	cout << "3. SiCepat : Rp. 13.000" << endl;
	cout << "Pilih Ekspedisi : ";
	cin >> pilihan;
	
	switch (pilihan){
		case 1:
			total_harga_keseluruhan += 14000;
			break;
		case 2:
			total_harga_keseluruhan += 15000;
			break;
		case 3:
			total_harga_keseluruhan += 13000;
			break;
	}
}

void pilih_menu_home(){
	int pilihan;
	cout << endl;
	cout << "1. Belanja" << endl;
	cout << "2. Isi Saldo" << endl;
	cout << "3. Keluar" << endl;
	cout << "Pilih Menu : ";
	cin >> pilihan;
	
	switch (pilihan){
		case 1:
			list_barang();
			input_alamat();
			if (total_harga_keseluruhan >= 200000){
				total_harga_keseluruhan - 50000;
			}
			pilih_ekspedisi();
			break;
		case 2:
			tambah_saldo();
			pilih_menu_home();
			break;	
	}
}

void invoice(){
	cout << "Jumlah yang harus dibayar : " << total_harga_keseluruhan << endl;
}

int main(){
	login();
	home();
	pilih_menu_home();
	invoice();
}
