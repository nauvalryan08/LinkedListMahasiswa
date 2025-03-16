// 1) Membuat ADT Linked List Mahasiswa
#include "Mahasiswa.h"

int main() {
	// 2) Buat List L1 dan L2 untuk menampung daftar mahasiswa
	List L1, L2;
    createList(&L1);
    createList(&L2);
    
    // 3) Isikan sejumlah elemen ke pada List L1 (harus terurut Ascending berdasarkan nama)
    insertSorted(&L1, "Adit", 80);
    insertSorted(&L1, "Denis", 90);
    insertSorted(&L1, "Jarwo", 85);
    insertSorted(&L1, "Sopo", 65);
    insertSorted(&L1, "Udin", 70);
    insertSorted(&L1, "Adit", 95);
    insertSorted(&L1, "Jarwo", 75);
    
    // 4) Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut ascending berdasarkan nama
    printf("List L1 (Ascending berdasarkan nama) : \n");
    printListAscending(&L1);
    printf("\n");
    
    // 5) Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut desending berdasarkan nilai
    printf("List L1 (Descending berdasarkan nilai) : \n");
    printListDescending(&L1);
    printf("\n");
    
    // 6) Hitung Jumlah elemen (jumlah mahasiswa pada list), kemudian tampilkan
    printf("Jumlah Mahasiswa dalam List L1 : %d\n\n", countElements(&L1));
    
    // 7) Copy seluruh elemen pada list L1 yang Nilainya > 70 ke List L2
    copyIfGreaterThan(&L1, &L2, 70);
    
    // 8) Tampilkan Isi elemen List L2
    printf("Isi List L2 (sebelum menghapus duplikat) : \n");
    printListAscending(&L2);
    printf("\n");
    
    // 9) Hapus elemen yang memiliki nama duplikat di L2
    removeDuplicate(&L2);
    
    // 10) Tampilkan isi elemen List L2 yang baru
    printf("Isi List L2 (setelah menghapus duplikat) : \n");
    printListAscending(&L2);
    printf("\n");
    
    // 11) Hapus List L1 dan L2
    destroyList(&L1);
    destroyList(&L2);
    
    return 0;
}
