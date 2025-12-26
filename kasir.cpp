#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

struct transaksi
{
    string namaBarang;
    int hargaBarang;
    int jumlahBeli;
};

void inputPembelian(int jumlahBarang, transaksi pembelian[]){
    for (size_t i = 0; i < jumlahBarang; i++)
    {
        cout << "masukan nama barang ";
        cin >> pembelian[i].namaBarang;
        cout << "harga barang ";
        cin >> pembelian[i].hargaBarang;
        cout << "jumlah beli ";
        cin >> pembelian[i].jumlahBeli;
    }
    
}

int tampilkanPembelian(int jumlahBarang, transaksi pembelian[]){
    int totalHarga;
    int subtotal[jumlahBarang];
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "nama barang    harga      qty     subtotal" << endl;
    cout << setfill('-') << setw(50) << '-' << endl;
    for (size_t i = 0; i < jumlahBarang; i++)
    {
        cout << pembelian[i].namaBarang << "          ";
        cout << pembelian[i].hargaBarang << "        ";
        cout << pembelian[i].jumlahBeli << "          ";
        subtotal[i] = pembelian[i].hargaBarang * pembelian[i].jumlahBeli;
        cout << subtotal[i] << endl;
    }
     cout << setfill('-') << setw(50) << '-' << endl;

     totalHarga = accumulate(subtotal,subtotal+jumlahBarang,0);
     cout << "total harga" << totalHarga << endl;

    return totalHarga;
}

void pembayaran(int totalHarga){
    cout << "Bayar ";
    int uangTunai;
    cin >>uangTunai;
    if (uangTunai<totalHarga)
    {
       cout << "uang tidak uckup" << endl;
       return;
    }
    cout << "kembalian" << uangTunai - totalHarga << endl;
    cout << "terimaksih telah berbelanaja" << endl;
    
}

void headerStruk(){
    cout << setfill('=') << setw(50) << '=' << endl;
    cout << "PROGRAM KASIR TOKO" << endl;
    cout << setfill('=') << setw(50) << '=' << endl;
}

int main(){
    int jumlahBarang;
    
    
    // blok kode menampilkan header
    headerStruk();    
    
    // blok kode 1
    cout << "Masukkan jumlah barang: ";
    cin >> jumlahBarang;
    transaksi pembelian[jumlahBarang];
    inputPembelian(jumlahBarang, pembelian);
    
    // blok kode 2
    int totalHarga = tampilkanPembelian(jumlahBarang, pembelian);

    // blok kode 3
    pembayaran(totalHarga);

    
    return 0;
}