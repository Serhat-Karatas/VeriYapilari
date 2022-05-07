#include <iostream>

using namespace std;
//int* dizi=NULL;   //bu ve bunun altındaki 2 satırı s yapısını tanımlamadan önce yazmıştım
//int boyut=25;     
//int tepe=0;

int sayaç=1;

struct s {        //birden fazla stack kullanmak isteyebiliriz diye yazdım.
	int boyut;
	int tepe;
	int* dizi;
};

s * intialize() {  
	s* x = (s*)malloc(sizeof(s));
	x->boyut = 25;
	x->tepe = 0;
	x->dizi = NULL;
	return x;
}


int pop(s *x) {
	if (x->dizi == NULL) {
		cout << "Dizi bos" << endl;
		return -1;
	}
    /*if(tepe + 15 <= x->boyut / 2) {   //kullanıcı çok fazla pop ederse geri kalan veriler belleği tüketmesin diye silmek isteyebiliriz diye yazdım. isteğe bağlıdır.
		int* dizi2 = (int*)malloc(sizeof(int) * x->boyut / 2);
		for (int i = 0;i < x->tepe;i++) dizi2[i] = x->dizi[i];
		free(x->dizi);
		x->dizi = dizi2;
		x->boyut /= 2;
	}*/
	x->tepe = x->tepe - 1;
	return x->dizi[x->tepe];

}

void push(int a, s* x) {
	if (x->dizi == NULL) {
		x->dizi = (int*)malloc(sizeof(int) * 25);
	}
	if (x->tepe >= 100) {           //100 eleman sınırımız
		int i;
		for (i = 1;i < 100;i++) {
			x->dizi[i - 1] = x->dizi[i];
		}
		x->dizi[99] = a;
		cout << sayaç++ << ". girilen deger silindi!" << endl;//100sınırımız aşılınca ilk girilen sitemiz diziden silindi.

	}
	else {
		if (x->tepe >= x->boyut) {      //bellek tasarrufu
			int* dizi2 = (int*)malloc(sizeof(int) * x->boyut * 2);
			for (int i = 0;i < x->boyut;i++) dizi2[i] = x->dizi[i];
			free(x->dizi);
			x->dizi = dizi2;
			x->boyut *= 2;
		}
		x->dizi[x->tepe] = a;
		x->tepe = x->tepe + 1;
	}
}

void show(s *x) {           //Belki test etmek istersiniz diye bu fonksiyonu yazdım.
	cout << "BOYUT :" << x->boyut<<endl;
	cout << "TEPE :" << x->tepe<<endl;
	for (int i = 0;i < x->tepe;i++) {
		cout << x->dizi[i] << endl;
	}
}


int main()
{
	s *x1 = intialize();
	s* x2 = intialize();// bunu keyfi olarak x1 den pop ettiklerimizi x2 push etmek için yazdım.
    //while boğunun altında kodu test etmek istersiniz diye bazı işlemler ekledim.
	for (int i = 0;i < 103;i++) {
		push(i, x1);
	}
	int secim;
	int a;
	while (1) {
		cout << "yapmak istedigin islemi sec :\n" << "1) push islemi yapmak icin deger gir\n" << "2) pop islemi yap\n" << "3)yigin bilgilerini goster\n" << "4) yaptigin pop islemlerini goruntule(ilk yapilan pop en son cikar)\n" << "5)programdan cik\n";
		cout << "Secimini yap:";
		cin >> secim;
		if (secim == 1) {
			cout << "push islemi icin deger gir:";
			cin >> a;
			push(a, x1);
		}
		if (secim == 2) {
			push(pop(x1), x2);
		}
		if (secim == 3) {
			show(x1);
		}
		if (secim == 4) {
			show(x2);
		}
		if (secim == 5) {
			cout << "Hoscakal";
			break;
		}
		else cout << "lutfen gecerli deger giriniz!\n";

	}

	//pop();

	/*for (int i = 0;i < 100;i++) {
		push(i,x1);
	}*/
	//show(x1);
	//pop(x1);
	//show(x1);

  /*for (int i = 0;i < 70;i++) {
		pop(x1);
	}
	show(x1);*/

	return 0;
}



