#include<stdio.h>
#include <iostream>
using namespace std;
//Bunun güzel yanı belleğe yüklenmeden pop ve push işlemlerini O(1) karmasıklığında yapabiliyoruz ancak burada sadece tek yığın üzerinde çalışabiliriz.
/*71. satırdan sonraki(yorum satırına alınan kısım) kısımda ise fonksiyonları, yapıları, tip tanımlamalarını, global degiskenleri bir header dosyasına koyup istediğimiz yerde istedigimiz kadar stack üzerinde çalışabiliriz.
O kısımdaki kodların da push ve pop işlemlerinin karmaşıklığı O(1)  dir ancak göründüğü üzere bellek açısından pek tasarruflu değildir. Çeşitli karmaşıklıklarda ve bellek kulanımlarında versiyonları yazılabilir.*/

struct node {
    int data;
    struct node* next;
};
struct node* bas;

void pushStack(int data) {
    
    if (bas == NULL)//if Stack is Empty
    {
        bas = (struct node*)malloc(sizeof(struct node));
        bas->data = data;
        bas->next = NULL;
    }
    else
    {
        struct node* temp = bas;
        struct node* temp2 = (struct node*)malloc(sizeof(struct node));
        temp2->data = data;
        bas = temp2;
        temp2->next = temp;
    }
}

int popStack() {             
   
    if (bas == NULL)//if Stack is Empty
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else
    {
        struct node* temp = bas;
        int a = bas->data;
        bas = temp->next;
        free(temp);
        return a;
    }


}   
void yazdir() {      

    struct node* temp = bas;
    while (temp != NULL)                   //Karmaşıklık O(n)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }


}
int main()
{
    pushStack(10);
    pushStack(20);
    pushStack(30);
    popStack();
    yazdir();
}                              


/* #include <iostream>
#include<stdio.h>
using namespace std;
struct n
{
    n* prev;
    int x;
    n* next;
};
typedef n node;

node* push(node* r, int x) {
    if (r == NULL) {
        r = (node*)malloc(sizeof(node));
        r->x = x;
        r->next = NULL;
        r->prev = r;
        return r;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->x = x;
    r->prev->next = temp;
    temp->prev = r->prev;
    temp->next = NULL;
    r->prev = temp;
    return r;
}

int pop(node* r) {
    if (r == NULL) {
        cout << "yigin bos" << endl;
        return -1;
    }
    node* sil;
    sil = r->prev;
    r->prev = r->prev->prev;
    int x = sil->x;
    free(sil);
    return x;

}

void show(node* r) {
    if (r == NULL)cout << "Yigin bos" << endl;
    while (r != NULL) {
        cout << r->x << endl;
        r = r->next;
    }
}

int main()
{
    node* x1 = NULL;
    node* x2 = NULL;
    int secim;
    int a;
    while (1) {
        cout << "yapmak istedigin islemi sec :\n" << "1) push islemi yapmak icin deger gir\n" << "2) pop islemi yap\n" << "3)yigin bilgilerini goster\n " << "4) yaptigin pop islemlerini goruntule(ilk yapilan pop en son cikar)\n" << "5)programdan cik\n";
        cout << "Secimini yap:";
        cin >> secim;
        if (secim == 1) {
            cout << "push islemi icin deger gir:";
            cin >> a;
            x1 = push(x1, a);
        }
        if (secim == 2) {
            x2 = push(x2, pop(x1));      //4. seçenek için bu şekilde pop ettim.
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
        if (secim < 1 && secim>5) cout << "geceli deger gir" << endl;

    }
}  */










