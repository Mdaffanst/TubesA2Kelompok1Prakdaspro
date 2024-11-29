/*TUGAS BESAR PRAKTIKUM PEMOGRAMAN DASAR
//1. Muhammad Faiz Pasaribu
//2. Gilbert Sitinjak
//3. Muhammad Daffa Adrian
//4. Timoty Teguh Siregar
//5. Agnes Sri Rahayu
//6. Ade Novita Simatupang */

#include <stdio.h>
#include <stdlib.h>

// Struct Mahasiswa
struct Mahasiswa {
    int id;
    int umur;
    char nim[15];
    char nama[50];
    char jurusan[50];
    char cita_cita[50];
};

// Fungsi untuk menambahkan data ke file
void TmbhData() {
    FILE *file = fopen("Data Mahasiswa Kom A2.txt", "a");  // Membuka file untuk append

    struct Mahasiswa mhs;
    printf("Masukkan ID: ");
    scanf("%d", &mhs.id);

    printf("Masukkan Nama: ");
    scanf("%s[^\n]", mhs.nama);  

    printf("Masukkan NIM: ");
    scanf("%s[^\n]", mhs.nim);

    printf("Masukkan Jurusan: ");
    scanf("%s[^\n]", mhs.jurusan);

    printf("Masukkan Cita-cita: ");
    scanf("%s[^\n]", mhs.cita_cita);

    printf("Masukkan Umur: ");
    scanf("%d", &mhs.umur);

    // Menyimpan data ke file
    fprintf(file, "%d|%s|%s|%s|%s|%d\n", mhs.id, mhs.nama, mhs.nim, mhs.jurusan, mhs.cita_cita, mhs.umur);
    fclose(file);

    printf("Data anda berhasil ditambahkan xixi!\n");
}

// Fungsi untuk menampilkan data dari file
void TmplkanData() {
    FILE *file = fopen("Data Mahasiswa Kom A2.txt", "r");  // Membuka file untuk dibaca

    struct Mahasiswa mhs;
    char line[256]; // Buffer untuk menyimpan satu baris data

    // Menampilkan header tabel dengan format yang rapi
    printf("ID   Nama              NIM          Jurusan            Cita-cita           Umur\n");
    printf("-------------------------------------------------------------------------------\n");

    // Membaca file baris demi baris
    while (fgets(line, sizeof(line), file)) {
      
        if (sscanf(line, "%d|%49[^|]|%14[^|]|%49[^|]|%49[^|]|%d", 
                   &mhs.id, mhs.nama, mhs.nim, mhs.jurusan, mhs.cita_cita, &mhs.umur) == 6) {
            
            printf("%-4d %-18s %-12s %-18s %-20s %-4d\n", 
                   mhs.id, mhs.nama, mhs.nim, mhs.jurusan, mhs.cita_cita, mhs.umur);
        } else {
            printf("Format baris salah atau data rusak!\n");
        }
    }

    fclose(file);
}

// Fungsi utama
int main() {
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Tampilkan Data\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                TmbhData();
                break;
            case 2:
                TmplkanData();
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 3);

    return 0;
}