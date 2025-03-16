#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

// Membuat Struktur Node
typedef struct Mahasiswa {
	char nama[50];
	int nilai_UTS;
	struct Mahasiswa* next;
} Mahasiswa;

// Membuat Struktur Linked List
typedef struct {
	Mahasiswa* head;
} List;

// Membuat Fungsi Utama dalam ADT
void createList(List* L);
void destroyList(List* L);
int isEmpty(List* L);
int getNilaiUTS(Mahasiswa* m);
char* getNama(Mahasiswa* m);
void setNilaiUTS(Mahasiswa* m, int nilai);
void setNama(Mahasiswa* m, char* nama);
void printMahasiswa(Mahasiswa* m);

// Membuat Procedure dan Function yang dibutuhkan
void insertSorted(List* L, const char* nama, int nilai);
void printListAscending(List* L);
void printListDescending(List* L);
int countElements(List* L);
void copyIfGreaterThan(List* L1, List* L2, int threshold);
void removeDuplicate(List* L);

#endif

