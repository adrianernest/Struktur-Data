#include "hotel.h"


// Membuat Node Baru
adrNode createNode(int no, string tipe, double harga) {
    adrNode p = new Node;
    p->info.nomorKamar = no;
    p->info.tipe = tipe;
    p->info.harga = harga;
    p->info.namaTamu = "-";
    p->info.isBooked = false;
    p->info.firstFasilitas = NULL; // Inisialisasi head list fasilitas
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Insert ke BST (Rekursif)
adrNode insertKamar(adrNode root, int no, string tipe, double harga) {
    if (root == NULL) {
        return createNode(no, tipe, harga);
    }
    
    // Logika Kiri (Kecil) & Kanan (Besar)
    if (no < root->info.nomorKamar) {
        root->left = insertKamar(root->left, no, tipe, harga);
    } else if (no > root->info.nomorKamar) {
        root->right = insertKamar(root->right, no, tipe, harga);
    } else {
        cout << "Error: Nomor Kamar " << no << " sudah ada!" << endl;
    }
    return root;
}

// Searching Node (Untuk keperluan update)
adrNode searchKamar(adrNode root, int no) {
    if (root == NULL || root->info.nomorKamar == no) {
        return root;
    }
    if (no < root->info.nomorKamar) {
        return searchKamar(root->left, no);
    }
    return searchKamar(root->right, no);
}

// Fitur Menambah Isi Array (Challenge) - DIHAPUS, diganti dengan MLL
// void tambahFasilitas(adrNode root, int no, string fas) { ... }

// Tampilkan semua kamar (Inorder: Urut dari nomor terkecil)
void showAllRoom(adrNode root) {
    if (root != NULL) {
        showAllRoom(root->left);
        
        cout << "---------------------------------" << endl;
        cout << "No. Kamar : " << root->info.nomorKamar << endl;
        cout << "Tipe      : " << root->info.tipe << endl;
        cout << "Status    : " << (root->info.isBooked ? "Terisi" : "Kosong") << endl;
        // Tampilkan List Fasilitas (MLL)
        cout << "Fasilitas : ";
        showFasilitas(root);
        cout << endl;
        
        showAllRoom(root->right);
    }
}

void cariHargaEkstrem(adrNode root, adrNode &pTermurah, adrNode &pTermahal) {
    if (root == NULL) return; // Basis: jika kosong, stop.

    // 1. Cek Node Saat Ini
    // Inisialisasi awal (jika pTermurah masih NULL) atau jika nemu yang lebih murah
    if (pTermurah == NULL || root->info.harga < pTermurah->info.harga) {
        pTermurah = root;
    }

    // Inisialisasi awal (jika pTermahal masih NULL) atau jika nemu yang lebih mahal
    if (pTermahal == NULL || root->info.harga > pTermahal->info.harga) {
        pTermahal = root;
    }

    // 2. Cek ke Kiri dan Kanan (Traverse All)
    cariHargaEkstrem(root->left, pTermurah, pTermahal);
    cariHargaEkstrem(root->right, pTermurah, pTermahal);
}

// Helper: Mencari node paling kecil (paling kiri) di subtree
// Digunakan untuk mencari pengganti (Successor) saat hapus node punya 2 anak
adrNode findMin(adrNode node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Fungsi DELETE Utama
adrNode deleteKamar(adrNode root, int no) {
    // Basis: Jika tree kosong
    if (root == NULL) return root;

    // 1. Searching dulu nodenya ada di mana
    if (no < root->info.nomorKamar) {
        root->left = deleteKamar(root->left, no);
    } else if (no > root->info.nomorKamar) {
        root->right = deleteKamar(root->right, no);
    } 
    // 2. Jika ketemu (no == root->info.nomorKamar)
    else {
        // KASUS 1 & 2: Node punya 0 atau 1 anak
        if (root->left == NULL) {
            adrNode temp = root->right;
            delete root; // Hapus dari memori
            return temp; // Anak kanan naik menggantikan
        } else if (root->right == NULL) {
            adrNode temp = root->left;
            delete root; // Hapus dari memori
            return temp; // Anak kiri naik menggantikan
        }

        // KASUS 3: Node punya 2 anak
        // Cari pengganti: Node terkecil dari subtree kanan (Successor)
        adrNode temp = findMin(root->right);

        // Salin SEMUA data dari successor ke node ini
        root->info = temp->info;
        
        // Hapus node successor yang asli (karena datanya sudah dipindah ke atas)
        // Kita panggil delete lagi untuk subtree kanan
        root->right = deleteKamar(root->right, temp->info.nomorKamar);
    }
    return root;
}

// === IMPLEMENTASI FUNGSI MLL (Fasilitas) ===

// Membuat Node Fasilitas Baru
adrNodeFasilitas createNodeFasilitas(string nama) {
    adrNodeFasilitas p = new NodeFasilitas;
    p->info.namaFasilitas = nama;
    p->next = NULL;
    return p;
}

// Insert Fasilitas ke List Anak (MLL)
void insertFasilitas(adrNode kamar, string nama) {
    if (kamar == NULL) {
        cout << "Kamar tidak ditemukan." << endl;
        return;
    }
    adrNodeFasilitas newNode = createNodeFasilitas(nama);
    if (kamar->info.firstFasilitas == NULL) {
        kamar->info.firstFasilitas = newNode;
    } else {
        adrNodeFasilitas temp = kamar->info.firstFasilitas;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Fasilitas " << nama << " berhasil ditambahkan." << endl;
}

// Delete Fasilitas dari List Anak (MLL)
void deleteFasilitas(adrNode kamar, string nama) {
    if (kamar == NULL || kamar->info.firstFasilitas == NULL) {
        cout << "Kamar tidak ditemukan atau tidak ada fasilitas." << endl;
        return;
    }
    adrNodeFasilitas temp = kamar->info.firstFasilitas;
    adrNodeFasilitas prev = NULL;
    while (temp != NULL && temp->info.namaFasilitas != nama) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Fasilitas " << nama << " tidak ditemukan." << endl;
        return;
    }
    if (prev == NULL) {
        kamar->info.firstFasilitas = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Fasilitas " << nama << " berhasil dihapus." << endl;
}

// Tampilkan List Fasilitas (Helper untuk showAllRoom)
void showFasilitas(adrNode kamar) {
    if (kamar == NULL || kamar->info.firstFasilitas == NULL) {
        cout << "Standar";
        return;
    }
    adrNodeFasilitas temp = kamar->info.firstFasilitas;
    while (temp != NULL) {
        cout << temp->info.namaFasilitas;
        if (temp->next != NULL) cout << ", ";
        temp = temp->next;
    }
}

// Counting Fasilitas (Pengolahan MLL)
int countFasilitas(adrNode kamar) {
    if (kamar == NULL) return 0;
    int count = 0;
    adrNodeFasilitas temp = kamar->info.firstFasilitas;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}