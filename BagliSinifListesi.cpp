/*
 Bağlı listeye ekleme(sıralı ekleme), çıkarma ve listeleme işlemlerini kullanabileceğimiz bir proje
*/
#include <iostream>
using namespace std;

struct n {                           
	int no;                                                    
	n* next;                        
};
typedef n node;

node* ekleSirali(node* r, int x) {  //node pointer döndürmemiz gerekebilir.Çünkü başa ekleme işlemi olabilir.

	if (r == NULL) {               //listemizin boş olma durumu Root umuz aynı.
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->no = x;
		return r;
	}

	if (r->no > x) {              //root umuz değişir. Başa ekleme durumu.
		node* temp = (node*)malloc(sizeof(node));
		temp->next = r;
		temp->no = x;
		return temp;
	}

	node* iter = r;
	while (iter->next != NULL && x > iter->next->no) iter = iter->next;  //iterimizin nexti null değilse ve sonraki kutunun verisi x imizden küçük olduğu sürece iteri ilerlet.
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->no = x;
	return r;
	
}


node* sil(node* r, int x) { //Silmek istediğimiz değer ilk değer olabileceği için rootumuzun değişmesi gerekebileceğinden node pointer döndürüyorum.
	node* temp;
	node* iter=r;
	if (r->no == x) {    //ilk elemanı silme durumu root değişir.
		temp = r;        //temp şuan en başı tutuyor yani silinecek elemanı
		r = r->next;     //yeni root
		free(temp);      //sildik.
		return r;
	}

	while (iter->next != NULL && iter->next->no != x) iter = iter->next;
	if (iter->next == NULL) {
		cout << "Listede bu eleman bulunamadi" << endl;
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return r;
}

void göster(node* r) {
	cout << "LISTEM :" << endl;
	while (r != NULL) {                
		cout << r->no << endl;
		r = r->next;
	}

}



int main()
{
	node* root;       //yapımızın tipinde bir pointer oluşturduk.Listemizin en başını tutacak.
	root = NULL;     
	int numara;
	int islem;

	while (1) {
		cout << "Yapmak istediginiz islemi giriniz:\n" << "1)Listeye ekle\n" << "2)Listeden sil\n"<<"3)Listeyi goster\n"<<"4)Programdan cik\n";
		cin >> islem;

		if (islem == 1) {
			cout << "Islem yapmak istediginiz numarayi giriniz :";
			cin >> numara;
			root = ekleSirali(root, numara);
		}

		else if (islem == 2) {
			cout << "Islem yapmak istediginiz numarayi giriniz :";
			cin >> numara;
			if (root != NULL) root = sil(root, numara);
			else cout << "Listen bos!" << endl;
		}

		else if (islem == 3) göster(root);

		else if (islem == 4) break;

		else cout << "Lutfen gecerli bir islem giriniz." << endl;
		
	}

	return 0;
}


