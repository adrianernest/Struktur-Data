#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
using namespace std;

// === SPESIFIKASI STRUKTUR DATA ===
const int MAX_FASILITAS = 5; // Array statis dalam record (untuk BST, tapi sekarang kita gunakan MLL untuk fasilitas)

// Forward declaration untuk MLL
struct NodeFasilitas;
typedef NodeFasilitas* adrNodeFasilitas;

struct Kamar {
    int nomorKamar;          // KEY: 101, 102 (Unik)
    string tipe;             // Standard, Deluxe
    double harga;
    string namaTamu;         // Kosong jika belum check-in
    bool isBooked;           // Status kamar
    
    // Pointer ke head list fasilitas (MLL: anak)
    adrNodeFasilitas firstFasilitas;
};

struct Node {
    Kamar info;
    Node* left;
    Node* right;
};

typedef Node* adrNode;

// === STRUKTUR UNTUK MLL (Fasilitas sebagai anak) ===
struct Fasilitas {
    string namaFasilitas; // Tipe dasar: string
};

struct NodeFasilitas {
    Fasilitas info;
    NodeFasilitas* next;
};

// === PROTOTYPE FUNGSI ===
// 1. Dasar BST
adrNode createNode(int no, string tipe, double harga);
adrNode insertKamar(adrNode root, int no, string tipe, double harga);

// 2. Fungsionalitas Tambahan (Challenge)
adrNode searchKamar(adrNode root, int no); // Cari node by nomor
void checkIn(adrNode root, int no, string nama); // Update Data

// 3. View / Traversal
void showAllRoom(adrNode root); // Inorder Traversal

// 4. Delete kamar
adrNode findMin(adrNode node); // Helper untuk kasus 3
adrNode deleteKamar(adrNode root, int no); // Fungsi Delete utama

// Fitur Mencari Harga Termurah & Termahal
void cariHargaEkstrem(adrNode root, adrNode &pTermurah, adrNode &pTermahal);

// === PROTOTYPE FUNGSI MLL (Fasilitas) ===
// 1. Dasar MLL
adrNodeFasilitas createNodeFasilitas(string nama);
void insertFasilitas(adrNode kamar, string nama); // Insert anak ke parent
void deleteFasilitas(adrNode kamar, string nama); // Delete anak dari parent
void showFasilitas(adrNode kamar); // Tampilkan list fasilitas anak

// 2. Pengolahan MLL
int countFasilitas(adrNode kamar); // Counting anak
#endif