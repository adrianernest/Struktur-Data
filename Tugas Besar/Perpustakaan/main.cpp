#include "perpus.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Buku *node = NULL;
    int pilihan, tahun, halaman;
    string id, judul, pengarang, kategori, tanggal, namaPeminjam;

    do
    {
        cout << "\n=== SISTEM PERPUSTAKAAN DIGITAL ===" << endl;
        cout << "1. Tambah Buku Baru" << endl;
        cout << "2. Cari Buku (berdasarkan ID)" << endl;
        cout << "3. Update Informasi Buku" << endl;
        cout << "4. Hapus Buku" << endl;
        cout << "5. Tampilkan Semua Buku (In-Order)" << endl;
        cout << "6. Tampilkan Pre-Order" << endl;
        cout << "7. Tampilkan Post-Order" << endl;
        cout << "8. Tampilkan Level-Order" << endl;
        cout << "9. Cari Buku Berdasarkan Kategori" << endl;
        cout << "10. Cari Buku Berdasarkan Pengarang" << endl;
        cout << "11. Cari Buku Berdasarkan Tahun" << endl;
        cout << "12. Hitung Total Buku" << endl;
        cout << "13. Hitung Buku per Kategori" << endl;
        cout << "14. Tampilkan Buku Terbaru" << endl;
        cout << "15. Tampilkan Buku Terlama" << endl;
        cout << "16. Tampilkan Riwayat Peminjaman" << endl;
        cout << "17. Tambah Riwayat Peminjaman" << endl;
        cout << "18. Hapus Riwayat Peminjaman" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        { 
        }

        case 0:
        {
            cout << "Terima kasih" << endl;
            break;
        }

        default:
        {
            cout << "Inputan tidak valid!" << endl;
            break;
        }
        }

    } while (pilihan != 0);

    return 0;
}