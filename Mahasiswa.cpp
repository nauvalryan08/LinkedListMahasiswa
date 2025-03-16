#include "Mahasiswa.h"

// Constructor : Membuat List Kosong
void createList(List* L) {
	L->head = NULL;
}

// Destructor : Menghapus Semua Elemen dalam List
void destroyList(List* L) {
	Mahasiswa* current = L->head;
	Mahasiswa* temp;
	while (current != NULL) {
		temp = current; // Simpan pointer ke node saat ini
		current = current->next; // Pindah ke node berikutnya
		free(temp); // Hapus node saat ini dari memori
	}
	L->head = NULL; // Set head menjadi NULL setelah penghapusan
}

// Validator : Mengecek Apakah List Kosong
int isEmpty(List* L) {
	return L->head == NULL; // Mengembalikan true jika head NULL
}

// Setter dan Getter : Mengubah dan Mengambil Data Nama dan Nilai Mahasiswa
int getNilaiUTS(Mahasiswa* m) {
	return m->nilai_UTS; // Mengambil nilai UTS mahasiswa
}

char* getNama(Mahasiswa* m) {
	return m->nama; // Mengambil nama mahasiswa
}

void setNilaiUTS(Mahasiswa* m, int nilai) {
	m->nilai_UTS = nilai; // Mengubah nilai UTS mahasiswa
}

void setNama(Mahasiswa* m, char* nama) {
	strcpy(m->nama, nama); // Mengubah nama mahasiswa
}

// Print Object : Mencetak Data Mahasiswa
void printMahasiswa(Mahasiswa* m) {
	printf("%s - %d\n", m->nama, m->nilai_UTS);
}

// Insert element kedalam list dengan terurut berdasarkan nama
void insertSorted(List* L, const char* nama, int nilai) {
	Mahasiswa* newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa)); // Alokasi memori baru untuk node baru
	strcpy(newNode->nama, nama); // Menyalin nama ke node baru
	newNode->nilai_UTS = nilai; // Menyimpan nilai UTS
	newNode->next = NULL; // Set pointer to NULL karena ini pointer baru
	
	// Jika list kosong atau nama lebih kecil dari elemen pertama, masukkan di awal
	if (L->head == NULL || strcmp(L->head->nama, nama) > 0) {
		newNode->next = L->head; // Hubungkan newNode dengan elemen pertama (jika ada)
		L->head = newNode; // Jadikan newNode sebagai elemen pertama (head)
		return;
	}
	
	// Memasukkan node baru ke posisi yang benar
	Mahasiswa* current = L->head; // Pointer untuk transversal dalam List L1
	while (current->next != NULL && strcmp(current->next->nama, nama) < 0) {
		current = current->next; // Pindah ke elemen berikutnya dalam list
	}
	newNode->next = current->next;
	current->next = newNode;
}

// Menampilkan list secara Ascending berdasarkan Nama
void printListAscending(List* L) {
	Mahasiswa* current = L->head;
	while (current != NULL) {
		printMahasiswa(current); // Cetak elemen dengan Print Object
		current = current->next; // Pindah ke elemen berikutnya
	}
}

// Menampilkan List secara Descending berdasarkan nilai
void printListDescending(List* L) {
	List tempList;
	createList(&tempList); // Membuat List sementara
	Mahasiswa* current = L->head;
	
	// Salin elemen dengan sorting berdasarkan nilai (descending)
	while (current != NULL) {
		Mahasiswa* newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa));
		strcpy(newNode->nama, current->nama); // Menyalin nama mahasiswa untuk newNode
		newNode->nilai_UTS = current->nilai_UTS; // Mengambil nilai mahasiswa untuk newNode
		newNode->next = NULL; // Set pointer to NULL karena ini pointer baru
		
		// Insert ke dalam list sementara (descending order berdasarkan nilai)
		if (tempList.head == NULL || newNode->nilai_UTS > tempList.head->nilai_UTS) {
			newNode->next = tempList.head; // Set next dari node baru menunjuk ke head lama
			tempList.head = newNode; // Set node baru sebagai head
		} else {
			Mahasiswa* tempCurrent = tempList.head;
			while (tempCurrent->next != NULL && tempCurrent->next->nilai_UTS > newNode->nilai_UTS) {
				tempCurrent = tempCurrent->next; // Geser ke elemen berikutnya dalam tempList
			}
			newNode->next = tempCurrent->next; // Hubungkan newNode dengan elemen berikutnya
			tempCurrent->next = newNode; // Masukkan newNode setelah tempCurrent
		}
		current = current->next; // Lanjut ke elemen berikutnya dalam List L1
	}
	
	// Cetak kembali elemen
	printListAscending(&tempList);
	destroyList(&tempList);
}

// Menghitung Jumlah Elemen dalam List
int countElements(List* L) {
	int count = 0; // Inisialisasi nilai count
	Mahasiswa* current = L->head; 
	while (current != NULL) {
		count++; // Tambah jumlah elemen
		current = current->next; // Pindah ke elemen berikutnya
	}
	return count;
}

// Menyalin Elemen dengan nilai > threshold (batas) ke List lain
void copyIfGreaterThan(List* L1, List* L2, int threshold) {
	Mahasiswa* current = L1->head; 
	while (current != NULL) { 
		if (current->nilai_UTS > threshold) { // Jika nilai UTS lebih besar daripada ambang batas nilai (70)
			insertSorted(L2, current->nama, current->nilai_UTS); // Tambahkan ke List L2
		}
		current = current->next; // Pindah ke elemen berikutnya dalam List L1
	}
}

// Menghapus Elemen yang Memiliki Duplikasi Nama 
void removeDuplicate(List *L) {
    Mahasiswa* current = L->head;
    while (current != NULL && current->next != NULL) {
        Mahasiswa* prev = current; // Pointer prev untuk menyimpan elemen sebelumnya
        Mahasiswa* temp = current->next; // Pointer temp untuk mengecek elemen berikutnya

        while (temp != NULL) {
            if (strcmp(current->nama, temp->nama) == 0) { // Jika ditemukan duplikat nama
                prev->next = temp->next; // Lewati elemen duplikat
                free(temp); // Hapus elemen duplikat dari memori
                temp = prev->next; // Lanjutkan ke elemen berikutnya
            } else {
                prev = temp; // Update prev ke temp
                temp = temp->next; // Pindah ke elemen berikutnya
            }
        }
        current = current->next; // Pindah ke elemen berikutnya dalam List L1
    }
}

