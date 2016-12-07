#include <stdio.h>
#include <stdlib.h>
//Bubble Sort
int main(){
 
    int sinir, gecici;
    int dizi[100];
    printf("Girilecek sayi adeti: ");
    scanf("%d", &sinir);  // Kaç adet sayý girileceði kullanýcýdan öðrenilir
 
    
    for(int i=0; i<sinir; i++){  //Kullanýcýdan sayýlar alýnýr
        printf("%d)Sayi giriniz: ", i+1);
        scanf("%d", &dizi[i]);
    }
    
    //Alýnan sayýlar ekrana yazdýrýlýr
    for(int i=0; i<sinir; i++)
        printf("%d ", dizi[i]);
    printf("\n\n"); // sayýlar yazdýrýldýktan sonra 2 satýr aþaðý iner
    
    //Bubble sort algoritmasý (Küçükten büyüðe sýralama yapar)
    for(int i=0; i<sinir; i++){
        for(int j=0; j<sinir-1-i; j++){//örneðin dizimiz 6 elemanlý olsun i deðeri 2. indisken j deðeri de 6-2=4 yani 3.indis olamlý j deðeri.
            if(dizi[j] > dizi[j+1])//eðer 3. indis 4.indisten büyükse gecici deðerle indislerin yerini deðiþtir.
                gecici = dizi[j];//geçici deðer oluþturmazsak bir sonraki deðeri kaybetmiþ olacaðýz.
                dizi[j] = dizi[j+1];
                dizi[j+1] = gecici;
            }
        }
    }
    //Dizinin sýralanmýþ halini ekrana yazdýrýr
    for(int i=0; i<sinir; i++)
        printf("%d ", dizi[i]);
    
    printf("\n");
    system("pause");
    return 0;
}