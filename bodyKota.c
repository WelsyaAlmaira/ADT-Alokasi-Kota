#include "headerkota.h"
#include <malloc.h>

/* BODY MODUL */

void printKota(ElmtList dataKt[]) {
/* IS : Daftar kota tidak mungkin kosong karena array kota sudah diinisialisasi sebelumnya
 * FS : Menampilkan daftar nama-nama kota */
 
	int i;
	
	printf("Daftar Kota : \n");
	for (i=0; i<5; i++) {
		if(dataKt[i].nama != Nil) {
			printf("%d. %s\n", i+1, dataKt[i].nama);
		}
	}
}

void printWarga(ElmtList dataKt[]) {
/* IS : List warga mungkin kosong, daftar kota sudah ada
 * FS : Jika list tidak kosong maka nama warga akan ditampilkan sesuai dengan kota nya. 
    Jika list warga kosong maka daftar kota tetap tampil namun menampilkan "Daftar warga masih kosong" */
    
	int  i = 0;
    int pilih;
    address kota;
	
	while(i >= 0 && i < 5) {
	    printf("\n%d. Warga di Kota %s : \n", i+1, dataKt[i].nama);
	        if(dataKt[i].next != Nil){
	            kota = dataKt[i].next;
	
	            while(kota != Nil){
	                printf("   - %s\n",kota->nama);
	                kota = kota->next;
	            }
	        } else {
	        	printf("   Yah, data masih kosong\n");
			}
		i++;	
	}  
}

void insertWarga(ElmtList dataKt[]) {
/* IS : Linked list warga mungkin kosong
 * FS : Melakukan alokasi sebuah node warga. Jika linked list warga sudah ada sebelumnya, maka node akan ditempatkan di akhir
    (elemen terakhir adalah yang baru) */
    
	address nodeNama;
	int pilihKota;
	infotype nama;
	
	printf("Nomor kota yang akan dimasukkan warga : ");
	scanf("%d", &pilihKota);
	
	nama = (infotype) malloc (NAMA);
	printf("Insert nama warga : ");
	scanf("%s", nama);
	
	nodeNama = (address) malloc (sizeof (ElmtList));
	if (nodeNama != Nil) { // Alokasi berhasil, lakukan pengisian data dan penambahan node ke dalam list
		nodeNama->nama = nama;
		nodeNama->next = Nil;
		
		if(pilihKota >= 1 && pilihKota <= 5) {
			if (dataKt[pilihKota-1].next == Nil) { // Jika node kota belum menunjuk ke linked list warganya
		    dataKt[pilihKota-1].next = nodeNama;
		} else {  // Jika node kota sudah menunjuk ke linked list warganya
			Last = dataKt[pilihKota-1].next;
			while (next(Last) != Nil) {
				Last = next(Last);
			}
			next(Last) = nodeNama;
		}
		printf("Data berhasil dimasukkan!\n");
		} else {
			printf("Masukkan nomor yang valid!\n");
		}
		
	} else { // Alokasi gagal, berikan pesan error
	    printf("Gagal melakukan alokasi memori!\n");
	}

}

void deleteWarga(ElmtList dataKt[]) {
/* IS : Linked list warga sudah ada
 * FS : Melakukan tranversal linked list sesuai dengan kota yang dipilih, jika ada info linked list yang sesuai dengan namaWarga yang akan dihapus 
    maka curr dihapus */
    
    int pilihKota;
    infotype namaWarga;
    address prev, curr;	// prev menunjuk ke node sebelumnya, curr menunjuk ke node yang dicari
    bool found = false;
    
    printf("Nomor kota yang warganya akan dihapus : ");
    scanf("%d", &pilihKota);
    
    if(pilihKota >= 1 && pilihKota <= 5) {
	    printf("Nama warga yang ingin dihapus : ");
	    scanf("%s", namaWarga);

	    prev = Nil;
	    curr = dataKt[pilihKota-1].next;
    	while ((curr != Nil) && (!found)) {
	    	if (strcmp(curr->nama, namaWarga) == 0) {
	    		found = true;
			} else {
	            prev = curr;
	            curr = curr->next;
	        }	
		}
		
		if (found) {
			printf("Warga %s berhasil dihapus!\n", curr->nama);
			if (prev == Nil && curr->next == Nil)	{	// Jika elemen list hanya 1
				dataKt[pilihKota-1].next = Nil;
			} else if (prev == Nil) {	// Jika ketemu di elemen list ke-1
				dataKt[pilihKota-1].next = curr->next;
			} else {	// Jika elemen list ketemu di tengah / akhir
				prev->next = curr->next;
			}
			
			curr->next = Nil;
			free(curr);
		} else {
			printf("Warga %s tidak ditemukan!\n", curr->nama);
		}
	} else {
		printf("Masukkan nomor yang valid!\n");
	}
}
