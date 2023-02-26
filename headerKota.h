/*
Nama : Welsya Almaira Indra
NIM : 221524032
Kelas : 1A - TI4
Tanggal : 14-02-2023
Versi : 1.0
*/

#ifndef headerkota_H
#define headerkota_H
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define Nil NULL
#define nama(P) (P)->nama
#define next(P) (P)->next
#define NAMA 50

/* DATA BENTUKAN */
typedef char * infotype; //mengubah typedata int menjadi (char *) untuk membuat string. char * menunjuk ke character yang mana akan membentuk C-string.
typedef struct tElmtList *address;

typedef struct tElmtList {
	 infotype nama;
	 address  next;
	} ElmtList;

address First, Last;
	
/* DEKLARASI MODUL */
void printKota(ElmtList dataKt[]);
/* IS : Daftar kota tidak mungkin kosong karena array kota sudah diinisialisasi sebelumnya
 * FS : Menampilkan daftar nama-nama kota */
 
void insertWarga(ElmtList dataKt[]);
/* IS : Linked list warga mungkin kosong
 * FS : Melakukan alokasi sebuah node warga. Jika linked list warga sudah ada sebelumnya, maka node akan ditempatkan di akhir
    (elemen terakhir adalah yang baru) */
    
void deleteWarga(ElmtList dataKt[]);
/* IS : Linked list warga sudah ada
 * FS : Melakukan tranversal linked list sesuai dengan kota yang dipilih, jika ada info linked list yang sesuai dengan namaWarga yang akan dihapus 
    maka curr dihapus */
    
void printWarga(ElmtList dataKt[]);
/* IS : List warga mungkin kosong, daftar kota sudah ada
 * FS : Jika list tidak kosong maka nama warga akan ditampilkan sesuai dengan kota nya. 
    Jika list warga kosong maka daftar kota tetap tampil namun menampilkan "Daftar warga masih kosong" */

#endif // headerkota_H
