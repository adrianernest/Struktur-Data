#include "perpus.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "\n=== SISTEM PERPUSTAKAAN DIGITAL ===" << endl;
    cout << "1. Tambah Buku Baru" << endl;
    cout << "2. Cari Buku (berdasarkan ID)" << endl;
    cout << "3. Update Informasi Buku" << endl;
    cout << "4. Hapus Buku" << endl;
    cout << "5. Tambah Riwayat Peminjaman" << endl;
    cout << "6. Hapus Riwayat Peminjaman" << endl;
    cout << "7. Tampilkan Semua Buku (In-Order)" << endl;
    cout << "8. Tampilkan Pre-Order" << endl;
    cout << "9. Tampilkan Post-Order" << endl;
    cout << "10. Tampilkan Level-Order" << endl;
    cout << "11. Cari Buku Berdasarkan Kategori" << endl;
    cout << "12. Cari Buku Berdasarkan Pengarang" << endl;
    cout << "13. Cari Buku Berdasarkan Tahun" << endl;
    cout << "14. Hitung Total Buku" << endl;
    cout << "15. Hitung Buku per Kategori" << endl;
    cout << "16. Tampilkan Buku Terbaru" << endl;
    cout << "17. Tampilkan Buku Terlama" << endl;
    cout << "18. Tampilkan Buku Tertebal" << endl;
    cout << "19. Tampilkan Buku Tertipis" << endl;
    cout << "20. Tampilkan Buku dengan Riwayat" << endl;
    cout << "21. Tampilkan Riwayat Buku Tertentu" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
}

int main() {
    Buku* root = NULL; // Root dari BST
    int pilihan;
    string id, judul, pengarang, kategori, tanggal, namaPeminjam;
    int tahun, halaman;
    
    // Data contoh untuk testing
    // Uncomment untuk testing awal
    /*
    Buku* buku1 = createBuku("B001", "Algoritma dan Pemrograman", "Budi", "Teknik", 2020, 300);
    Buku* buku2 = createBuku("B002", "Struktur Data", "Ani", "Teknik", 2021, 350);
    Buku* buku3 = createBuku("B003", "Sejarah Indonesia", "Cici", "Sejarah", 2019, 250);
    insertBST(root, buku1);
    insertBST(root, buku2);
    insertBST(root, buku3);
    insertRiwayat(buku1, "2024-01-10", "Andi");
    insertRiwayat(buku1, "2024-02-15", "Budi");
    */
    
    do {
        displayMenu();
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer
        
        switch (pilihan) {
            case 1: { // Tambah Buku Baru
                cout << "Masukkan ID Buku: ";
                getline(cin, id);
                
                // Cek apakah ID sudah ada
                if (searchBST(root, id) != NULL) {
                    cout << "ID buku sudah terdaftar!" << endl;
                    break;
                }
                
                cout << "Masukkan Judul: ";
                getline(cin, judul);
                cout << "Masukkan Pengarang: ";
                getline(cin, pengarang);
                cout << "Masukkan Kategori: ";
                getline(cin, kategori);
                cout << "Masukkan Tahun Terbit: ";
                cin >> tahun;
                cout << "Masukkan Jumlah Halaman: ";
                cin >> halaman;
                cin.ignore();
                
                Buku* baru = createBuku(id, judul, pengarang, kategori, tahun, halaman);
                insertBST(root, baru);
                cout << "Buku berhasil ditambahkan!" << endl;
                break;
            }
            
            case 2: { // Cari Buku berdasarkan ID
                cout << "Masukkan ID Buku yang dicari: ";
                getline(cin, id);
                Buku* hasil = searchBST(root, id);
                
                if (hasil != NULL) {
                    cout << "\nBuku ditemukan!" << endl;
                    cout << "Judul: " << hasil->judul << endl;
                    cout << "Pengarang: " << hasil->pengarang << endl;
                    cout << "Kategori: " << hasil->kategori << endl;
                    cout << "Tahun: " << hasil->tahunTerbit << endl;
                    cout << "Halaman: " << hasil->jumlahHalaman << endl;
                } else {
                    cout << "Buku tidak ditemukan!" << endl;
                }
                break;
            }
            
            case 3: { // Update Informasi Buku
                cout << "Masukkan ID Buku yang akan diupdate: ";
                getline(cin, id);
                Buku* buku = searchBST(root, id);
                
                if (buku != NULL) {
                    cout << "Masukkan Judul baru: ";
                    getline(cin, judul);
                    cout << "Masukkan Pengarang baru: ";
                    getline(cin, pengarang);
                    cout << "Masukkan Kategori baru: ";
                    getline(cin, kategori);
                    cout << "Masukkan Tahun Terbit baru: ";
                    cin >> tahun;
                    cout << "Masukkan Jumlah Halaman baru: ";
                    cin >> halaman;
                    cin.ignore();
                    
                    updateBuku(buku, judul, pengarang, kategori, tahun, halaman);
                } else {
                    cout << "Buku tidak ditemukan!" << endl;
                }
                break;
            }
            
            case 4: { // Hapus Buku
                cout << "Masukkan ID Buku yang akan dihapus: ";
                getline(cin, id);
                
                if (searchBST(root, id) != NULL) {
                    root = deleteBST(root, id);
                    cout << "Buku berhasil dihapus!" << endl;
                } else {
                    cout << "Buku tidak ditemukan!" << endl;
                }
                break;
            }
            
            case 5: { // Tambah Riwayat Peminjaman
                cout << "Masukkan ID Buku: ";
                getline(cin, id);
                Buku* buku = searchBST(root, id);
                
                if (buku != NULL) {
                    cout << "Masukkan Tanggal Peminjaman (YYYY-MM-DD): ";
                    getline(cin, tanggal);
                    cout << "Masukkan Nama Peminjam: ";
                    getline(cin, namaPeminjam);
                    
                    insertRiwayat(buku, tanggal, namaPeminjam);
                } else {
                    cout << "Buku tidak ditemukan!" << endl;
                }
                break;
            }
            
            case 6: { // Hapus Riwayat Peminjaman
                cout << "Masukkan ID Buku: ";
                getline(cin, id);
                Buku* buku = searchBST(root, id);
                
                if (buku != NULL) {
                    cout << "Masukkan Tanggal Riwayat yang akan dihapus: ";
                    getline(cin, tanggal);
                    deleteRiwayat(buku, tanggal);
                } else {
                    cout << "Buku tidak ditemukan!" << endl;
                }
                break;
            }
            
            case 7: { // Tampilkan In-Order
                cout << "\n=== DAFTAR BUKU (In-Order) ===" << endl;
                displayInOrder(root);
                break;
            }
            
            case 8: { // Tampilkan Pre-Order
                cout << "\n=== DAFTAR BUKU (Pre-Order) ===" << endl;
                displayPreOrder(root);
                break;
            }
            
            case 9: { // Tampilkan Post-Order
                cout << "\n=== DAFTAR BUKU (Post-Order) ===" << endl;
                displayPostOrder(root);
                break;
            }
            
            case 10: { // Tampilkan Level-Order
                displayLevelOrder(root);
                break;
            }
            
            case 11: { // Cari berdasarkan Kategori
                cout << "Masukkan Kategori: ";
                getline(cin, kategori);
                cout << "\nBuku dengan kategori " << kategori << ":" << endl;
                searchByKategori(root, kategori);
                break;
            }
            
            case 12: { // Cari berdasarkan Pengarang
                cout << "Masukkan Nama Pengarang: ";
                getline(cin, pengarang);
                cout << "\nBuku karya " << pengarang << ":" << endl;
                searchByPengarang(root, pengarang);
                break;
            }
            
            case 13: { // Cari berdasarkan Tahun
                cout << "Masukkan Tahun Terbit: ";
                cin >> tahun;
                cin.ignore();
                cout << "\nBuku terbit tahun " << tahun << ":" << endl;
                searchByTahun(root, tahun);
                break;
            }
            
            case 14: { // Hitung Total Buku
                int total = countTotalBuku(root);
                cout << "Total Buku dalam Sistem: " << total << endl;
                break;
            }
            
            case 15: { // Hitung per Kategori
                cout << "Masukkan Kategori: ";
                getline(cin, kategori);
                int count = countByKategori(root, kategori);
                cout << "Jumlah Buku dengan kategori " << kategori << ": " << count << endl;
                break;
            }
            
            case 16: { // Buku Terbaru
                Buku* terbaru = findBukuTerbaru(root);
                if (terbaru != NULL) {
                    cout << "\nBuku Terbaru:" << endl;
                    cout << "Judul: " << terbaru->judul << endl;
                    cout << "Pengarang: " << terbaru->pengarang << endl;
                    cout << "Tahun: " << terbaru->tahunTerbit << endl;
                } else {
                    cout << "Tidak ada buku dalam sistem!" << endl;
                }
                break;
            }
            
            case 17: { // Buku Terlama
                Buku* terlama = findBukuTerlama(root);
                if (terlama != NULL) {
                    cout << "\nBuku Terlama:" << endl;
                    cout << "Judul: " << terlama->judul << endl;
                    cout << "Pengarang: " << terlama->pengarang << endl;
                    cout << "Tahun: " << terlama->tahunTerbit << endl;
                } else {
                    cout << "Tidak ada buku dalam sistem!" << endl;
                }
                break;
            }
            
            case 18: { // Buku Tertebal
                Buku* tebal = findBukuTebal(root);
                if (tebal != NULL) {
                    cout << "\nBuku Tertebal:" << endl;
                    cout << "Judul: " << tebal->judul << endl;
                    cout << "Pengarang: " << tebal->pengarang << endl;
                    cout << "Halaman: " << tebal->jumlahHalaman << endl;
                } else {
                    cout << "Tidak ada buku dalam sistem!" << endl;
                }
                break;
            }
            
            case 19: { // Buku Tertipis
                Buku* tipis = findBukuTipis(root);
                if (tipis != NULL) {
                    cout << "\nBuku Tertipis:" << endl;
                    cout << "Judul: " << tipis->judul << endl;
                    cout << "Pengarang: " << tipis->pengarang << endl;
                    cout << "Halaman: " << tipis->jumlahHalaman << endl;
                } else {
                    cout << "Tidak ada buku dalam sistem!" << endl;
                }
                break;
            }
            
            case 20: { // Tampilkan buku dengan riwayat
                cout << "Masukkan ID Buku: ";
                getline(cin, id);
                Buku* buku = searchBST(root, id);
                displayBukuDenganRiwayat(buku);
                break;
            }
            
            case 21: { // Tampilkan riwayat buku tertentu
                cout << "Masukkan ID Buku: ";
                getline(cin, id);
                Buku* buku = searchBST(root, id);
                displayRiwayat(buku);
                break;
            }
            
            case 0: {
                cout << "Terima kasih telah menggunakan sistem!" << endl;
                break;
            }
            
            default: {
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        }
        
    } while (pilihan != 0);
    
    return 0;
}