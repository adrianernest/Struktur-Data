#include "hotel.h"

int main() {
    // 1. SEMUA VARIABEL DI TARUH DI SINI (Supaya tidak error "jump to case label")
    adrNode root = NULL; 
    int pilihan, noKamar;
    string tipe, fasilitas;
    double harga;
    
    // Variabel untuk fitur Min/Max
    adrNode pMin = NULL;
    adrNode pMax = NULL;

    // Data Dummy (Biar pas run ga kosong banget)
    root = insertKamar(root, 102, "Deluxe", 500000);
    root = insertKamar(root, 101, "Standard", 300000);
    root = insertKamar(root, 201, "Suite", 1000000);

    do {
        cout << "\n=== HOTEL MANAGEMENT SYSTEM (BST + MLL) ===" << endl;
        cout << "1. Tambah Kamar Baru" << endl;
        cout << "2. Lihat Semua Kamar (Urut)" << endl;
        cout << "3. Tambah Fasilitas (Insert ke MLL)" << endl;
        cout << "4. Hapus Fasilitas (Delete dari MLL)" << endl;
        cout << "5. Hapus Kamar (Delete Node BST)" << endl;
        cout << "6. Laporan Harga (Min/Max)" << endl;
        cout << "7. Counting Fasilitas per Kamar" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: "; cin >> pilihan;

        switch(pilihan) {
        case 1: {
            cout << "Masukkan No Kamar: "; cin >> noKamar;
            cout << "Masukkan Tipe: "; cin >> tipe;
            cout << "Masukkan Harga: "; cin >> harga;
            root = insertKamar(root, noKamar, tipe, harga);
            break;
        }
            
        case 2: {
            showAllRoom(root);
            break;
        }
            
        case 3: {
            cout << "No Kamar yang mau ditambah fasilitas: "; cin >> noKamar;
            cout << "Nama Fasilitas (cth: Wifi): "; cin >> fasilitas;
            adrNode kamarAdd = searchKamar(root, noKamar);
            insertFasilitas(kamarAdd, fasilitas);
            break;
        }

        case 4: { // Hapus Fasilitas
            cout << "No Kamar yang mau dihapus fasilitas: "; cin >> noKamar;
            cout << "Nama Fasilitas yang akan dihapus: "; cin >> fasilitas;
            adrNode kamarDel = searchKamar(root, noKamar);
            deleteFasilitas(kamarDel, fasilitas);
            break;
        }

        case 5: { // Hapus Kamar
            cout << "Masukkan No Kamar yang akan dihapus (Renovasi): "; 
            cin >> noKamar;
            root = deleteKamar(root, noKamar); 
            cout << "Proses delete selesai." << endl;
            break;
        }

        case 6: { // Laporan Harga
            // Reset pointer biar bersih setiap kali menu dipilih
            pMin = NULL;
            pMax = NULL;
            
            if (root == NULL) {
                cout << "Data Kosong!" << endl;
            } else {
                cariHargaEkstrem(root, pMin, pMax);
                
                cout << "\n=== LAPORAN HARGA KAMAR ===" << endl;
                // Pengecekan safety, takutnya tree kosong
                if (pMin != NULL && pMax != NULL) {
                    cout << "Kamar Termurah: No " << pMin->info.nomorKamar 
                         << " (" << pMin->info.tipe << ") - Rp " << pMin->info.harga << endl;
                         
                    cout << "Kamar Termahal: No " << pMax->info.nomorKamar 
                         << " (" << pMax->info.tipe << ") - Rp " << pMax->info.harga << endl;
                }
            }
            break;
        }

        case 7: { // Counting Fasilitas
            cout << "No Kamar yang ingin dihitung fasilitasnya: "; cin >> noKamar;
            adrNode kamarCount = searchKamar(root, noKamar);
            if (kamarCount != NULL) {
                int jumlah = countFasilitas(kamarCount);
                cout << "Jumlah fasilitas di kamar " << noKamar << ": " << jumlah << endl;
            } else {
                cout << "Kamar tidak ditemukan." << endl;
            }
            break;
        }
            
        case 0: {
            cout << "Keluar dari program..." << endl;
            break;
        }
            
        default: {
            cout << "Pilihan tidak valid!" << endl;
        }
        }
    } while (pilihan != 0);

    return 0;
}