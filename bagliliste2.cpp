//BA�LI L�STELERDE ARAYA ELEMAN EKLEME VE SIRALAMA
#include <stdio.h>
#include <stdlib.h>
struct n{
	int x;
	n * next;
};
typedef n node;

void bastir(node * r){
	while(r!=NULL){//liklist bo� de�ilse
		printf("%d ",r->x);//g�sterdi�i de�eri ekrana yazd�r.
		r= r->next;//bir ad�m ilerle
	}
}
void ekle(node *r, int x){
	while(r->next!=NULL){//BURADA EN SON D���ME ER���M SA�LAMI� OLURUZ.null� g�steren d���m yani.en son d���me gitmeliyiz ki oraya eleman ekleyebilelim.
			     //ama s�rekli ba�a d�n�p tekrar null u g�r�nce sona d���m ekleyip tekrar ba�a sarma olay� uzun i�lem gerektirir.
 	r = r->next;  //bu da demektir ki r nin nexti NULL� g�terdi�i zaman bi ad�m ilerle
 	
	}
}
node * ekleSirali(node * r,int x){//iki parametre var.biri linklist biri de linklist e hangi de�er eklenece�i.
	if(r==NULL){ 	// #####linklist bossa//yeni d���m olu�tur ve eleman ekle
		r=(node *)malloc(sizeof(node));//yeni bir kutu a�t�k ve eklemek istedi�imz degeri bu mkutuya ekleme i�lemini ger�ekle�tirdik.
		r->next = NULL;//bi tane kutu var anlam�na gelmektedir.r->null olsayd� cunku hic bir�ey i�arte etmiyo olurdu.
		r->x = x;//r �n i�aret etti�i de�er eklemek istedi�imiz yerdeki(kutudaki) de�eren k���kse:...
		return r;
	}
	if(r->x > x){ 	//####ilk elemandan kucuk durumu
			// #####root degisiyor
			node * temp = (node*)malloc(sizeof(node));//daha k���k olan eleman� ba�a almak i�in ge�ici bir de�er olu�turduk.
			//temp->next=NULL;//bunu yapmak al��kanl�k olmal� son d���m� belirtmeke ad�na ama burada yapmam�za gerek yok ��nk� iki alt sat�rda tempin nextini root(r) yapacag�z.
			temp -> x = x;
			temp -> next =r;
			return temp;
	}
	node * iter = r;//listenin ilk eleman� sabit kals�n biz ilerlerken iteri kullanal�m.
	while(iter->next != NULL && iter->next->x < x){//listenin sonuna gelemediysem hen�z ve listede kontrol etti�im de�er benim eklemeye �al��t���m de�erden k���kse...
		iter= iter->next;//bir sonrakine git
	}
	//BURADAK� �K� S�SL� PARANTEZ ARASINDAK� T�M KOD KUTU EKLEME KODUDUR.
	node * temp = (node*)malloc(sizeof(node));//yeni bir kutu olu�turduk ve bu kutuyu tutmak i�in temp ad�nda bir pointer tan�mlad�k.bellekten yer ay�rd�k.
	temp->next = iter -> next;//yeni olu�an kutunun nexti ile iterin nextini ayn� yeri i�aret edecek �ekilde ayarlad�k.
	iter -> next = temp;//kutuyu burada asl�nda itere ba�lam�� olduk(iterin nexti art�k yeni olu�turdu�umuz tempi i�aret ediyor.
	temp -> x = x;//tempe veri koyduk.
	return r;
	
}
int main(){
	node * root;
	root = NULL;
	root = ekleSirali(root,400);//sadece metottu yazmad�k roota da aktard�k ��nk� r de�eri ve root ayn� yeri g�steriyodu en ba�ta.eger bizz root eklemeseydik ba�a r de�i�kenine farkl� de�erler atad���m�zda ve root bundan etkilenmezdi
	root = ekleSirali(root,40);
	root = ekleSirali(root,4);
	root = ekleSirali(root,450);
	root = ekleSirali(root,50);
	bastir(root);
}









