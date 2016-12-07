#include <stdio.h>
#include <stdlib.h>
struct n{//düðüm yapýsýný oluþturduk.
	int x;
	n * next;
};
typedef n node;//tekrar tekrar tanýmlama yapmamak için structý typdefle sabitledik.

void bastir(node * r){
	node *iter = r;//iteri baþlangýç düðümüyle eþitledik.
	printf("%d ",iter->x);//BU ÝKÝ KISIM þu iþe yarýyor:üstte iterle rootu birbirine eþitledik.o yüzden alt satýrda yaptýðýmýz while döngüsüne hiç girilmezdi.ancak biz ilk elemaný yazýdrýp bir ilerletirsek artýk iter roota eþit olmayacaðýndan while döngüsü kontrolü de saðlanmýþ olur.
	iter= iter->next;//BU ÝKÝ SATIR...
	while(iter != r){//iter roota eþit oluncaya dek yazdýr.yani iter baþtan baþa dönünceye kadar yazdýr demek istedik aslýnda.
		printf("%d ",iter->x);//ilk elemana mahsus elle yazdýrdýk sonhraki eleamnlarý while döngüsüne sokarak döngü ile yazdrýdýk.
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
	iter->next->next = r;//doðrusal listelerde NULL deðerini koyuyorken burada root deðerini koyuyoruzçünkü koþulumuz nulla ulaþmak deðil roota ulaþmak artýk.
}


node * ekleSirali(node * r,int x){
	if(r==NULL){ // linklist bossa//yeni bir düðüm oluþturuyoruz ve düðümün nextini yine kendisine eþitliyoruz.
		r=(node *)malloc(sizeof(node));
		r->next = r;
		r->x = x;
		return r;
	}
	if(r->x > x){ // ilk elemandan kucuk durumu//bu durumda ilk düðüm deðiþecek küçükten büyüðe sýralama yapýyoruz çünkü eðer yeni düðm roottan küçükse deðiþiyor ilk eleman.
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
		iter -> next = r->next;//rootun nexti yani:ikinci düðüm, artýk iterin nexti:(yani sondaki düðümün nexti olsun.bu þekilde rootu silmiþ ol.)
		free(r);//Sildiðimiz düðümü RAMden kaldýrmak için.free yaptýk.
		return iter->next;
	}
	while (iter->next != r && iter->next->x != x){//iterin nexti roottan farklýyken(sona ulaþmamýþken) ve iterin nextinin deðeri aradýðýmýz deðerden farklýyken dön.
		iter = iter ->next;
	}
	if(iter->next == r){
		printf("sayi bulunamadi");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;//düðüm arasýndaki baðlarý kýrma iþlemini yaptýk.
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









