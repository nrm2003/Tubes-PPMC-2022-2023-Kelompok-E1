/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 8 - Advance Algorithm
 *   Hari dan Tanggal    : Rabu, 5 April 2023
 *   Nama (NIM)          : Nurazizah Rizkiana Marali (18320002)
 *   Nama File           : main.c
 *   Deskripsi           : Menemukan longest path dari sebuah matriks
 */

//sumber referensi : https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
#include <stdio.h>
#include <stdlib.h>
#define N_MAX 100

int maximum(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

//fungsi untuk menemukan longest path dari suatu array
int CariPathTerpanjang(int arr[N_MAX][N_MAX], int i, int j,int m){
    int l=1, r=1, t=1, b=1; //penyimpan panjang path untuk masing-masing arah (kanan, kiri, atas, bawah)
    
    if((j< m)&& (arr[i][j+1] == (arr[i][j]+1))){ //ke arah kiri
            r = 1+ CariPathTerpanjang(arr,i,j+1,m);
        }
    if((j> 0) && (arr[i][j-1] == (arr[i][j] + 1))){ //ke arah kanan
            l = 1+ CariPathTerpanjang(arr, i, j-1,m);
        }
    if((i> 0) && (arr[i-1][j] == (arr[i][j] + 1))){ // ke arah atas
            t = 1+ CariPathTerpanjang(arr, i-1, j,m); 
        }
    if((i < m) && (arr[i+1][j] == (arr[i][j] + 1))){ //ke arah bawah
            b = 1 + CariPathTerpanjang(arr, i+1, j,m);
        }  

    //longest path adalah maksimum besar path di antara path masing-masing arah
    int max1 = maximum(r,l);
    int max2 = maximum(max1,t);
    return maximum(max2,b);

}

int main() {
    // baca input
    int n;
    printf("Input:\n");
    scanf("%d",&n);
    int arr[N_MAX][N_MAX];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Output: ");
    printf("%d",car(arr,0,0,(n-1)));
    // lanjutkan program

}
