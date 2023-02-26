#include "headerkota.h"
#include <stdio.h>
#include <stdlib.h>


/* PROGRAM UTAMA */
int main () {
	ElmtList Kota[5];	// Membuat array kota yang menggunakan tipe data ElmtList, yang nantinya memiliki nama dan next
	bool ulang = true; 
	int pilih;
	
	/* Inisialisasi Data Kota */
	Kota[0].nama = "Cimahi";
	Kota[0].next = Nil;
	First = Kota[0].next;
	
	Kota[1].nama = "Bandung";
	Kota[1].next = Nil;
	
	Kota[2].nama = "Jakarta";
	Kota[2].next = Nil;
	
	Kota[3].nama = "Surabaya";
	Kota[3].next = Nil;
	
	Kota[4].nama = "Malang";
	Kota[4].next = Nil;
	
	while (ulang) {
		printf("\n================================\n");
		printf("          Program Kota          \n");
		printf("================================\n");
		
		printf("1. Daftar Kota\n");
		printf("2. Insert Nama Warga\n");
		printf("3. Hapus Warga\n");
		printf("4. Tampil Info Warga\n");
		printf("5. Keluar\n");
		printf("Pilih menu : ");
		scanf("%d", &pilih);
		printf("\n");
		
		switch (pilih) {
			case 1 :	printKota(Kota);
						break;
			case 2 :	insertWarga(Kota);
						break;
			case 3 :	deleteWarga(Kota);
						break;		
			case 4 :	printf("Berikut nama kota beserta warga yang ada di dalamnya");
						printWarga(Kota);
						break;
			case 5 :	ulang = false;
						printf("\nTerima kasih telah menggunakan program ini!");
						break;
			default :	printf("Pilihan tidak valid, coba lagi");
						break;
		}
	}	
}

