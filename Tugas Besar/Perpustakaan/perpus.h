#ifndef PERPUS_H
#define PERPUS_H

#include <iostream>
#include <string>
using namespace std;

struct Buku
{
    string idBuku;
    string judul;
    string pengarang;
    string kategori;
    int tahunTerbit;
    Buku *L;
    Buku *R;
};

struct Riwayat {
    string tanggal;     
    string namaPeminjam;
    Riwayat* next;
};

// Nanda Bagus P
Buku *BuatBuku();
void insertBST();
Buku *searchBST();
void updateBuku();
void lihatRiwayat(); //MLL

// Vincentius Prastica
Buku *HapusBST();
void nampilinPreOrder();
void nampilinInOrder();
void nampilinPostOrder();
void tambahRiwayat(); //MLL

// Adrian Ernest
void nampilinLevelOrder();
void cariByKategori();
void cariByPengarang();
void cariByTahun();
void hapusRiwayat(); //MLL

// M Fathurizal
int hitungTotalBuku();
int hitungByKategori();
Buku *CariTerbaru();
Buku *CariTerlama();

#endif