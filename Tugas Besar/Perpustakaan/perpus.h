#ifndef PERPUS_H
#define PERPUS_H

#include <iostream>
#include <string>
using namespace std;

/* ====== STRUKTUR DATA MULTIPLE LINKED LIST ====== */
// Struktur untuk anak (riwayat peminjaman)
struct Riwayat {
    string tanggal;      // tipe dasar untuk anak
    string namaPeminjam; // tipe dasar untuk anak
    Riwayat* next;
};

// Struktur untuk parent (data buku)
struct Buku {
    string idBuku;       // unik (key untuk BST)
    string judul;
    string pengarang;
    string kategori;     // Fiksi, Non-Fiksi, Teknik, Sains, dll
    int tahunTerbit;
    int jumlahHalaman;
    Riwayat* firstRiwayat; // pointer ke list anak (riwayat peminjaman)
    Buku* left;           // pointer untuk BST
    Buku* right;          // pointer untuk BST
};

/* ====== DEKLARASI FUNGSI BST ====== */
Buku* createBuku(string id, string judul, string pengarang, 
                 string kategori, int tahun, int halaman);
void insertBST(Buku* &root, Buku* bukuBaru);
Buku* searchBST(Buku* root, string idBuku);
void updateBuku(Buku* node, string judul, string pengarang, 
                string kategori, int tahun, int halaman);
Buku* deleteBST(Buku* &root, string idBuku);

/* ====== DEKLARASI FUNGSI MLL ====== */
void insertRiwayat(Buku* buku, string tanggal, string namaPeminjam);
void deleteRiwayat(Buku* buku, string tanggal);
void displayRiwayat(Buku* buku);

/* ====== DEKLARASI FUNGSI OPERASI ====== */
void displayPreOrder(Buku* root);
void displayInOrder(Buku* root);
void displayPostOrder(Buku* root);
void displayLevelOrder(Buku* root);
void searchByKategori(Buku* root, string kategori);
void searchByPengarang(Buku* root, string pengarang);
void searchByTahun(Buku* root, int tahun);
int countTotalBuku(Buku* root);
int countByKategori(Buku* root, string kategori);
Buku* findBukuTerbaru(Buku* root);
Buku* findBukuTerlama(Buku* root);
Buku* findBukuTebal(Buku* root);
Buku* findBukuTipis(Buku* root);
void displayBukuDenganRiwayat(Buku* buku);

#endif