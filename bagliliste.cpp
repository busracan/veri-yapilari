//BA�LI L�STELERDE FONKS�YON VE D�NG� �LE ER���M
#include <stdio.h>
#include <stdlib.h>
struct n{
	int x;	//d���mdeki data(veri)
	n * next;	//rootun(k�k) ba�lang�� d���m�n�n g�sterdi�i adres
};
typedef n node;//her defas�nda yeni bir node tan�mlamas� yapmamak i�in en ba�ta typdef kullanmal�y�z.aksi takdirde her defas�nda struct node tan�mlamas� yapmal�y�z.

void bastir(node * r){
	while(r!=NULL){		//e�er ba�lang�� de�eri bo� de�ilse sonrakine ge� ve teker teker gez d���mleri bitene kadar.
		printf("%d ",r->x);
		r= r->next;
		
	}
}

int main(){
	node * root; //ba�lang�� d���m�ne root de.
	root = (node *)malloc(sizeof(node));	//d���m i�in malloc fonksiyonuyla bellekten yer ay�r.
	root -> x = 10;//rootun g�sterdi�i de�ere(data(veri)) 10 de�erini ata.
	root -> next = (node * ) malloc (sizeof(node));	//rootun nexti i�in de bellekten malloc fonksiyonuyla yer ay�r.
	root -> next -> x = 20;	//rootun nextinin nextine 20 de�erini ata.
	root -> next -> next = (node *) malloc(sizeof(node)); 	//rootun nextinin nextinin nexti i�in ayr� bellekten malloc fonksiyonuyla yer ay�r.
	root -> next ->next -> x = 30;	//ayn� �ekilde atama i�lemi yap.
	root -> next ->next ->next = NULL;//d���m� sonland�r.NULL � pointer ederek.
	node * iter;	//iter ad�nda gezginci d���m ata.her elemana ayr� ayr� ula�abilmek i�in
	iter = root;//rootun g�sterid�i de�eri ayn� zamanda iter de g�stersin.
	printf("%d",iter->x);//iterin �uan g�stermi� oldu�u x de�erini ekrana bas.
	iter = iter -> next;//iterden bi sonraki kutuya ge�erek oradaki de�eri g�ster.
	printf("%d",iter->x);//�imdiki iter de�erini ekrana bast�r.
	iter = root;	//rootun g�sterd�i de�eri itere ata.
	int i =0;
	while (iter->next != NULL){	//iterin nexti NULL olaana kadar dedik ��nk� en son de�er iterin nexti olacakt�r.
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









