#include <stdio.h>
#include <stdlib.h>
//Bubble Sort
int main(){
 
    int sinir, gecici;
    int dizi[100];
    printf("Girilecek sayi adeti: ");
    scanf("%d", &sinir);  // Ka� adet say� girilece�i kullan�c�dan ��renilir
 
    
    for(int i=0; i<sinir; i++){  //Kullan�c�dan say�lar al�n�r
        printf("%d)Sayi giriniz: ", i+1);
        scanf("%d", &dizi[i]);
    }
    
    //Al�nan say�lar ekrana yazd�r�l�r
    for(int i=0; i<sinir; i++)
        printf("%d ", dizi[i]);
    printf("\n\n"); // say�lar yazd�r�ld�ktan sonra 2 sat�r a�a�� iner
    
    //Bubble sort algoritmas� (K���kten b�y��e s�ralama yapar)
    for(int i=0; i<sinir; i++){
        for(int j=0; j<sinir-1-i; j++){//�rne�in dizimiz 6 elemanl� olsun i de�eri 2. indisken j de�eri de 6-2=4 yani 3.indis olaml� j de�eri.
            if(dizi[j] > dizi[j+1])//e�er 3. indis 4.indisten b�y�kse gecici de�erle indislerin yerini de�i�tir.
                gecici = dizi[j];//ge�ici de�er olu�turmazsak bir sonraki de�eri kaybetmi� olaca��z.
                dizi[j] = dizi[j+1];
                dizi[j+1] = gecici;
            }
        }
    }
    //Dizinin s�ralanm�� halini ekrana yazd�r�r
    for(int i=0; i<sinir; i++)
        printf("%d ", dizi[i]);
    
    printf("\n");
    system("pause");
    return 0;
}