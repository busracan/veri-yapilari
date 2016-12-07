//BAÐLI LÝSTELERDE ARAYA ELEMAN EKLEME VE SIRALAMA
#include <stdio.h>
#include <stdlib.h>
struct n{
	int x;
	n * next;
};
typedef n node;

void bastir(node * r){
	while(r!=NULL){//liklist boþ deðilse
		printf("%d ",r->x);//gösterdiði deðeri ekrana yazdýr.
		r= r->next;//bir adým ilerle
	}
}
void ekle(node *r, int x){
	while(r->next!=NULL){//BURADA EN SON DÜÐÜME ERÝÞÝM SAÐLAMIÞ OLURUZ.nullý gösteren düðüm yani.en son düðüme gitmeliyiz ki oraya eleman ekleyebilelim.
			     //ama sürekli baþa dönüp tekrar null u görünce sona düðüm ekleyip tekrar baþa sarma olayý uzun iþlem gerektirir.
 	r = r->next;  //bu da demektir ki r nin nexti NULLý göterdiði zaman bi adým ilerle
 	
	}
}
node * ekleSirali(node * r,int x){//iki parametre var.biri linklist biri de linklist e hangi deðer ekleneceði.
	if(r==NULL){ 	// #####linklist bossa//yeni düðüm oluþtur ve eleman ekle
		r=(node *)malloc(sizeof(node));//yeni bir kutu açtýk ve eklemek istediðimz degeri bu mkutuya ekleme iþlemini gerçekleþtirdik.
		r->next = NULL;//bi tane kutu var anlamýna gelmektedir.r->null olsaydý cunku hic birþey iþarte etmiyo olurdu.
		r->x = x;//r ýn iþaret ettiði deðer eklemek istediðimiz yerdeki(kutudaki) deðeren küçükse:...
		return r;
	}
	if(r->x > x){ 	//####ilk elemandan kucuk durumu
			// #####root degisiyor
			node * temp = (node*)malloc(sizeof(node));//daha küçük olan elemaný baþa almak için geçici bir deðer oluþturduk.
			//temp->next=NULL;//bunu yapmak alýþkanlýk olmalý son düðümü belirtmeke adýna ama burada yapmamýza gerek yok çünkü iki alt satýrda tempin nextini root(r) yapacagýz.
			temp -> x = x;
			temp -> next =r;
			return temp;
	}
	node * iter = r;//listenin ilk elemaný sabit kalsýn biz ilerlerken iteri kullanalým.
	while(iter->next != NULL && iter->next->x < x){//listenin sonuna gelemediysem henüz ve listede kontrol ettiðim deðer benim eklemeye çalýþtýðým deðerden küçükse...
		iter= iter->next;//bir sonrakine git
	}
	//BURADAKÝ ÝKÝ SÜSLÜ PARANTEZ ARASINDAKÝ TÜM KOD KUTU EKLEME KODUDUR.
	node * temp = (node*)malloc(sizeof(node));//yeni bir kutu oluþturduk ve bu kutuyu tutmak için temp adýnda bir pointer tanýmladýk.bellekten yer ayýrdýk.
	temp->next = iter -> next;//yeni oluþan kutunun nexti ile iterin nextini ayný yeri iþaret edecek þekilde ayarladýk.
	iter -> next = temp;//kutuyu burada aslýnda itere baðlamýþ olduk(iterin nexti artýk yeni oluþturduðumuz tempi iþaret ediyor.
	temp -> x = x;//tempe veri koyduk.
	return r;
	
}
int main(){
	node * root;
	root = NULL;
	root = ekleSirali(root,400);//sadece metottu yazmadýk roota da aktardýk çünkü r deðeri ve root ayný yeri gösteriyodu en baþta.eger bizz root eklemeseydik baþa r deðiþkenine farklý deðerler atadýðýmýzda ve root bundan etkilenmezdi
	root = ekleSirali(root,40);
	root = ekleSirali(root,4);
	root = ekleSirali(root,450);
	root = ekleSirali(root,50);
	bastir(root);
}









