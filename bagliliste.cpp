//BAÐLI LÝSTELERDE FONKSÝYON VE DÖNGÜ ÝLE ERÝÞÝM
#include <stdio.h>
#include <stdlib.h>
struct n{
	int x;	//düðümdeki data(veri)
	n * next;	//rootun(kök) baþlangýç düðümünün gösterdiði adres
};
typedef n node;//her defasýnda yeni bir node tanýmlamasý yapmamak için en baþta typdef kullanmalýyýz.aksi takdirde her defasýnda struct node tanýmlamasý yapmalýyýz.

void bastir(node * r){
	while(r!=NULL){		//eðer baþlangýç deðeri boþ deðilse sonrakine geç ve teker teker gez düðümleri bitene kadar.
		printf("%d ",r->x);
		r= r->next;
		
	}
}

int main(){
	node * root; //baþlangýç düðümüne root de.
	root = (node *)malloc(sizeof(node));	//düðüm için malloc fonksiyonuyla bellekten yer ayýr.
	root -> x = 10;//rootun gösterdiði deðere(data(veri)) 10 deðerini ata.
	root -> next = (node * ) malloc (sizeof(node));	//rootun nexti için de bellekten malloc fonksiyonuyla yer ayýr.
	root -> next -> x = 20;	//rootun nextinin nextine 20 deðerini ata.
	root -> next -> next = (node *) malloc(sizeof(node)); 	//rootun nextinin nextinin nexti için ayrý bellekten malloc fonksiyonuyla yer ayýr.
	root -> next ->next -> x = 30;	//ayný þekilde atama iþlemi yap.
	root -> next ->next ->next = NULL;//düðümü sonlandýr.NULL ý pointer ederek.
	node * iter;	//iter adýnda gezginci düðüm ata.her elemana ayrý ayrý ulaþabilmek için
	iter = root;//rootun gösteridði deðeri ayný zamanda iter de göstersin.
	printf("%d",iter->x);//iterin þuan göstermiþ olduðu x deðerini ekrana bas.
	iter = iter -> next;//iterden bi sonraki kutuya geçerek oradaki deðeri göster.
	printf("%d",iter->x);//þimdiki iter deðerini ekrana bastýr.
	iter = root;	//rootun gösterdði deðeri itere ata.
	int i =0;
	while (iter->next != NULL){	//iterin nexti NULL olaana kadar dedik çünkü en son deðer iterin nexti olacaktýr.
		i++;
		printf("%dinci eleman : %d \n",i,iter->x);
		iter = iter ->next;
	}
	for(i=0;i<5;i++){
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next;
		iter->x = i*10;
		iter->next =NULL;
	}
	bastir(root);
	
}









