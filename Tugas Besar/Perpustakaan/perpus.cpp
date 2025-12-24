#include "perpus.h"
#include <queue>
#include <algorithm>

/* ==================== BST FUNCTIONS ==================== */

// 1. Membuat node buku baru
Buku* createBuku(string id, string judul, string pengarang, 
                 string kategori, int tahun, int halaman) {
    Buku* baru = new Buku;
    baru->idBuku = id;
    baru->judul = judul;
    baru->pengarang = pengarang;
    baru->kategori = kategori;
    baru->tahunTerbit = tahun;
    baru->jumlahHalaman = halaman;
    baru->firstRiwayat = NULL; // Inisialisasi list anak kosong
    baru->left = baru->right = NULL;
    return baru;
}

// 2. Insert buku ke BST (berdasarkan ID)
void insertBST(Buku* &root, Buku* bukuBaru) {
    if (root == NULL) {
        root = bukuBaru;
    } else if (bukuBaru->idBuku < root->idBuku) {
        insertBST(root->left, bukuBaru);
    } else if (bukuBaru->idBuku > root->idBuku) {
        insertBST(root->right, bukuBaru);
    }
    // Jika ID sama, tidak disimpan (ID harus unik)
}

// 3. Mencari buku berdasarkan ID
Buku* searchBST(Buku* root, string idBuku) {
    if (root == NULL || root->idBuku == idBuku) {
        return root;
    }
    
    if (idBuku < root->idBuku) {
        return searchBST(root->left, idBuku);
    } else {
        return searchBST(root->right, idBuku);
    }
}

// 4. Update informasi buku
void updateBuku(Buku* node, string judul, string pengarang, 
                string kategori, int tahun, int halaman) {
    if (node != NULL) {
        node->judul = judul;
        node->pengarang = pengarang;
        node->kategori = kategori;
        node->tahunTerbit = tahun;
        node->jumlahHalaman = halaman;
        cout << "Buku berhasil diupdate!" << endl;
    }
}

// 5. Menghapus buku dari BST
Buku* findMin(Buku* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Buku* deleteBST(Buku* &root, string idBuku) {
    if (root == NULL) return root;
    
    if (idBuku < root->idBuku) {
        root->left = deleteBST(root->left, idBuku);
    } else if (idBuku > root->idBuku) {
        root->right = deleteBST(root->right, idBuku);
    } else {
        // Node ditemukan
        // Case 1: No child atau satu child
        if (root->left == NULL) {
            Buku* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Buku* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 2: Dua children
        Buku* temp = findMin(root->right);
        root->idBuku = temp->idBuku;
        root->judul = temp->judul;
        root->pengarang = temp->pengarang;
        root->kategori = temp->kategori;
        root->tahunTerbit = temp->tahunTerbit;
        root->jumlahHalaman = temp->jumlahHalaman;
        root->firstRiwayat = temp->firstRiwayat;
        
        root->right = deleteBST(root->right, temp->idBuku);
    }
    return root;
}

/* ==================== MLL FUNCTIONS ==================== */

// 6. Menambahkan riwayat peminjaman (anak) ke buku (parent)
void insertRiwayat(Buku* buku, string tanggal, string namaPeminjam) {
    if (buku == NULL) {
        cout << "Buku tidak ditemukan!" << endl;
        return;
    }
    
    Riwayat* baru = new Riwayat;
    baru->tanggal = tanggal;
    baru->namaPeminjam = namaPeminjam;
    baru->next = NULL;
    
    // Sisipkan di akhir list
    if (buku->firstRiwayat == NULL) {
        buku->firstRiwayat = baru;
    } else {
        Riwayat* temp = buku->firstRiwayat;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Riwayat peminjaman berhasil ditambahkan!" << endl;
}

// 7. Menghapus riwayat peminjaman berdasarkan tanggal
void deleteRiwayat(Buku* buku, string tanggal) {
    if (buku == NULL || buku->firstRiwayat == NULL) {
        cout << "Tidak ada riwayat peminjaman!" << endl;
        return;
    }
    
    Riwayat* curr = buku->firstRiwayat;
    Riwayat* prev = NULL;
    
    // Cari riwayat dengan tanggal yang sesuai
    while (curr != NULL && curr->tanggal != tanggal) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        cout << "Riwayat dengan tanggal " << tanggal << " tidak ditemukan!" << endl;
        return;
    }
    
    // Hapus node
    if (prev == NULL) {
        buku->firstRiwayat = curr->next;
    } else {
        prev->next = curr->next;
    }
    
    delete curr;
    cout << "Riwayat peminjaman berhasil dihapus!" << endl;
}

// 8. Menampilkan semua riwayat peminjaman sebuah buku
void displayRiwayat(Buku* buku) {
    if (buku == NULL) {
        cout << "Buku tidak ditemukan!" << endl;
        return;
    }
    
    cout << "Riwayat Peminjaman Buku: " << buku->judul << endl;
    cout << "==================================" << endl;
    
    Riwayat* temp = buku->firstRiwayat;
    if (temp == NULL) {
        cout << "Belum ada riwayat peminjaman." << endl;
        return;
    }
    
    int count = 1;
    while (temp != NULL) {
        cout << count << ". Tanggal: " << temp->tanggal 
             << ", Peminjam: " << temp->namaPeminjam << endl;
        temp = temp->next;
        count++;
    }
}

/* ==================== TRAVERSAL FUNCTIONS ==================== */

// 9. Pre-order traversal (Root-Left-Right)
void displayPreOrder(Buku* root) {
    if (root != NULL) {
        cout << "ID: " << root->idBuku 
             << ", Judul: " << root->judul 
             << ", Kategori: " << root->kategori << endl;
        displayPreOrder(root->left);
        displayPreOrder(root->right);
    }
}

// 10. In-order traversal (Left-Root-Right) - menampilkan secara terurut
void displayInOrder(Buku* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        cout << "ID: " << root->idBuku 
             << ", Judul: " << root->judul 
             << ", Pengarang: " << root->pengarang 
             << ", Tahun: " << root->tahunTerbit << endl;
        displayInOrder(root->right);
    }
}

// 11. Post-order traversal (Left-Right-Root)
void displayPostOrder(Buku* root) {
    if (root != NULL) {
        displayPostOrder(root->left);
        displayPostOrder(root->right);
        cout << "ID: " << root->idBuku 
             << ", Judul: " << root->judul 
             << ", Halaman: " << root->jumlahHalaman << endl;
    }
}

// 12. Level-order traversal (Breadth First)
void displayLevelOrder(Buku* root) {
    if (root == NULL) return;
    
    queue<Buku*> q;
    q.push(root);
    
    cout << "Level Order Traversal:" << endl;
    while (!q.empty()) {
        Buku* current = q.front();
        q.pop();
        
        cout << "ID: " << current->idBuku 
             << ", Judul: " << current->judul 
             << ", Kategori: " << current->kategori << endl;
        
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
}

/* ==================== SEARCH FUNCTIONS ==================== */

// 13. Mencari buku berdasarkan kategori
void searchByKategori(Buku* root, string kategori) {
    if (root != NULL) {
        searchByKategori(root->left, kategori);
        if (root->kategori == kategori) {
            cout << "ID: " << root->idBuku 
                 << ", Judul: " << root->judul 
                 << ", Pengarang: " << root->pengarang << endl;
        }
        searchByKategori(root->right, kategori);
    }
}

// 14. Mencari buku berdasarkan pengarang
void searchByPengarang(Buku* root, string pengarang) {
    if (root != NULL) {
        searchByPengarang(root->left, pengarang);
        if (root->pengarang == pengarang) {
            cout << "ID: " << root->idBuku 
                 << ", Judul: " << root->judul 
                 << ", Kategori: " << root->kategori << endl;
        }
        searchByPengarang(root->right, pengarang);
    }
}

// 15. Mencari buku berdasarkan tahun terbit
void searchByTahun(Buku* root, int tahun) {
    if (root != NULL) {
        searchByTahun(root->left, tahun);
        if (root->tahunTerbit == tahun) {
            cout << "ID: " << root->idBuku 
                 << ", Judul: " << root->judul 
                 << ", Pengarang: " << root->pengarang << endl;
        }
        searchByTahun(root->right, tahun);
    }
}

/* ==================== COUNTING FUNCTIONS ==================== */

// 16. Menghitung total buku
int countTotalBuku(Buku* root) {
    if (root == NULL) return 0;
    return 1 + countTotalBuku(root->left) + countTotalBuku(root->right);
}

// 17. Menghitung buku berdasarkan kategori
int countByKategori(Buku* root, string kategori) {
    if (root == NULL) return 0;
    
    int count = 0;
    if (root->kategori == kategori) {
        count = 1;
    }
    
    return count + countByKategori(root->left, kategori) 
                 + countByKategori(root->right, kategori);
}

/* ==================== SPECIAL OPERATIONS ==================== */

// 18. Mencari buku terbaru (tahun terbit terbesar)
Buku* findBukuTerbaru(Buku* root) {
    if (root == NULL) return NULL;
    
    Buku* leftMax = findBukuTerbaru(root->left);
    Buku* rightMax = findBukuTerbaru(root->right);
    
    Buku* maxNode = root;
    
    if (leftMax != NULL && leftMax->tahunTerbit > maxNode->tahunTerbit) {
        maxNode = leftMax;
    }
    if (rightMax != NULL && rightMax->tahunTerbit > maxNode->tahunTerbit) {
        maxNode = rightMax;
    }
    
    return maxNode;
}

// 19. Mencari buku terlama (tahun terbit terkecil)
Buku* findBukuTerlama(Buku* root) {
    if (root == NULL) return NULL;
    
    Buku* leftMin = findBukuTerlama(root->left);
    Buku* rightMin = findBukuTerlama(root->right);
    
    Buku* minNode = root;
    
    if (leftMin != NULL && leftMin->tahunTerbit < minNode->tahunTerbit) {
        minNode = leftMin;
    }
    if (rightMin != NULL && rightMin->tahunTerbit < minNode->tahunTerbit) {
        minNode = rightMin;
    }
    
    return minNode;
}

// 20. Mencari buku dengan halaman terbanyak
Buku* findBukuTebal(Buku* root) {
    if (root == NULL) return NULL;
    
    Buku* leftMax = findBukuTebal(root->left);
    Buku* rightMax = findBukuTebal(root->right);
    
    Buku* maxNode = root;
    
    if (leftMax != NULL && leftMax->jumlahHalaman > maxNode->jumlahHalaman) {
        maxNode = leftMax;
    }
    if (rightMax != NULL && rightMax->jumlahHalaman > maxNode->jumlahHalaman) {
        maxNode = rightMax;
    }
    
    return maxNode;
}

// 21. Mencari buku dengan halaman tersedikit
Buku* findBukuTipis(Buku* root) {
    if (root == NULL) return NULL;
    
    Buku* leftMin = findBukuTipis(root->left);
    Buku* rightMin = findBukuTipis(root->right);
    
    Buku* minNode = root;
    
    if (leftMin != NULL && leftMin->jumlahHalaman < minNode->jumlahHalaman) {
        minNode = leftMin;
    }
    if (rightMin != NULL && rightMin->jumlahHalaman < minNode->jumlahHalaman) {
        minNode = rightMin;
    }
    
    return minNode;
}

// 22. Menampilkan buku beserta riwayatnya
void displayBukuDenganRiwayat(Buku* buku) {
    if (buku == NULL) {
        cout << "Buku tidak ditemukan!" << endl;
        return;
    }
    
    cout << "\n=== DETAIL BUKU ===" << endl;
    cout << "ID Buku: " << buku->idBuku << endl;
    cout << "Judul: " << buku->judul << endl;
    cout << "Pengarang: " << buku->pengarang << endl;
    cout << "Kategori: " << buku->kategori << endl;
    cout << "Tahun Terbit: " << buku->tahunTerbit << endl;
    cout << "Jumlah Halaman: " << buku->jumlahHalaman << endl;
    
    displayRiwayat(buku);
}