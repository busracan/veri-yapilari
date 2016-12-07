#include <stdio.h>
#include <stdlib.h>
struct n{//d���m yap�s�n� olu�turduk.
	int x;
	n * next;
};
typedef n node;//tekrar tekrar tan�mlama yapmamak i�in struct� typdefle sabitledik.

void bastir(node * r){
	node *iter = r;//iteri ba�lang�� d���m�yle e�itledik.
	printf("%d ",iter->x);//BU �K� KISIM �u i�e yar�yor:�stte iterle rootu birbirine e�itledik.o y�zden alt sat�rda yapt���m�z while d�ng�s�ne hi� girilmezdi.ancak biz ilk eleman� yaz�dr�p bir ilerletirsek art�k iter roota e�it olmayaca��ndan while d�ng�s� kontrol� de sa�lanm�� olur.
	iter= iter->next;//BU �K� SATIR...
	while(iter != r){//iter roota e�it oluncaya dek yazd�r.yani iter ba�tan ba�a d�n�nceye kadar yazd�r demek istedik asl�nda.
		printf("%d ",iter->x);//ilk elemana mahsus elle yazd�rd�k sonhraki eleamnlar� while d�ng�s�ne sokarak d�ng� ile yazdr�d�k.
		iter= iter->next;
	}
	printf("\n");
	
}


void ekle(node *r, int x){
	node * iter =r;
	while(iter->next!=r){
		iter = iter -> next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = r;//do�rusal listelerde NULL de�erini koyuyorken burada root de�erini koyuyoruz��nk� ko�ulumuz nulla ula�mak de�il roota ula�mak art�k.
}


node * ekleSirali(node * r,int x){
	if(r==NULL){ // linklist bossa//yeni bir d���m olu�turuyoruz ve d���m�n nextini yine kendisine e�itliyoruz.
		r=(node *)malloc(sizeof(node));
		r->next = r;
		r->x = x;
		return r;
	}
	if(r->x > x){ // ilk elemandan kucuk durumu//bu durumda ilk d���m de�i�ecek k���kten b�y��e s�ralama yap�yoruz ��nk� e�er yeni d��m roottan k���kse de�i�iyor ilk eleman.
			// root degisiyor
			node * temp = (node*)malloc(sizeof(node));
			temp -> x = x;
			temp -> next =r;
			node *iter = r;
			while (iter->next!= r)
				iter = iter ->next;	
			iter->next = temp;
			return temp;
	}
	node * iter = r;
	while(iter->next != r && iter->next->x < x){
		iter= iter->next;
	}
	node * temp = (node*)malloc(sizeof(node));
	temp->next = iter -> next;
	iter -> next = temp;
	temp -> x = x;
	return r;
}
node * sil(node *r,int x){
	node *temp;
	node *iter = r;
	if(r->x == x){
		while(iter->next != r){
			iter = iter -> next;
		}
		iter -> next = r->next;//rootun nexti yani:ikinci d���m, art�k iterin nexti:(yani sondaki d���m�n nexti olsun.bu �ekilde rootu silmi� ol.)
		free(r);//Sildi�imiz d���m� RAMden kald�rmak i�in.free yapt�k.
		return iter->next;
	}
	while (iter->next != r && iter->next->x != x){//iterin nexti roottan farkl�yken(sona ula�mam��ken) ve iterin nextinin de�eri arad���m�z de�erden farkl�yken d�n.
		iter = iter ->next;
	}
	if(iter->next == r){
		printf("sayi bulunamadi");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;//d���m aras�ndaki ba�lar� k�rma i�lemini yapt�k.
	free (temp);
	return r;
}
int main(){
	node * root;
	root = NULL;
	root = ekleSirali(root,400);
	root = ekleSirali(root,40);
	root = ekleSirali(root,4);
	root = ekleSirali(root,450);
	root = ekleSirali(root,50);
	bastir(root);
	root = sil(root,50);
	bastir(root);
	root = sil(root,999);
	bastir(root);
	root = sil(root,4);
	bastir(root);
	root = sil(root,450);
	bastir(root);
}









