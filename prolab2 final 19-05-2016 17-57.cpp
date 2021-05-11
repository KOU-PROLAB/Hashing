// prolab2.cpp : Defines the entry point for the console application.
#include <cstdlib>
#include<time.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "graphics.h"
#include <Windows.h>


using namespace std;
int uzaklik, yol, nereden, nereye, nekadar, X_kordinat, Y_kordinat;

void sutun_ciz(float ilkkenar, float baslangic, colors renk, float yontem)
{
	// printf("%d,%f\n",baslangic,yontem);
	int i;
	setcolor(renk);
	for (i = 0; i<20; i++)
	{
		line(ilkkenar - i, baslangic, ilkkenar - i, 397);
	}
	char s1[20];
	sprintf(s1, "%0.f", yontem);
	settextstyle(BOLD_FONT, 0, 13);
	outtextxy(ilkkenar - 20, baslangic - 20, s1);
}



void satir_ciz(float ilkkenar, float baslangic, colors renk, float yontem)
{
	// printf("%d,%f\n",baslangic,yontem);
	int i;
	setcolor(renk);
	//line(10,580,10+(320*atBkSay/dizi[i]),580);
	for (i = 0; i<10; i++)
	{
		line(10, ilkkenar - i, baslangic, ilkkenar - i);
	}



}

///////////////////////////////////////
void AnalizAdimSayisi_2(int lyBkSay, int lyKatSay, int lyKortSay, int atBkSay, int atKatSay, int atKortSay, float lineerSay,int dizi[7])
{
	int driver, mode, errcode = 0;
	driver = DETECT;

	// initgraph(&driver,&mode,"C:\\TC\\BGI");

	int ekran = initwindow(1200, 800);
	//Garafik Ekran Yükleme Hatalarý
	errcode = graphresult();
	if (errcode != 0)
	{
		printf("graph error:%d", errcode);
		exit(1); //hata ile cik
	}


	//DÜZ ÇİZGİ KODU(yatay)
	line(200, 400, 1060, 400);
	line(200, 399, 1060, 399);
	line(200, 398, 1060, 398);
	line(200, 397, 1060, 397);
	line(200, 396, 1060, 396);

	outtextxy(210, 410, " AYRIK TASMA      AYRIK TASMA     AYRIK TASMA    LINEER YOKLAMA    LINEER YOKLAMA    LINEER YOKLAMA    LINEER ARAMA");
	outtextxy(210, 425, " BOLEN KALAN     KARE ORTASI       KATLAMA            BOLEN KALAN          KARE ORTASI               KATLAMA");


	int i;

	float x_kor, y_kor;
	
	
	for (i = 0; i<7; i++)
	{
		if (dizi[i] == atBkSay&&dizi[i] == atKortSay) {

			sutun_ciz(385, 397 - (320 * atKortSay / lineerSay), colors(7), atKortSay);
			satir_ciz(520 + (i * 20), 10 + (320 * atBkSay / atKortSay), colors(7), atKortSay);
			x_kor = 20 + (320 * atBkSay / atKortSay);
			y_kor = 507 + (i * 20);
			outtextxy(x_kor, y_kor, "AYRIK TASMA KARE ORTASI");
		
			i++;
			sutun_ciz(270, 397 - (320 * atBkSay / lineerSay), colors(9), atBkSay);
			satir_ciz(520 + (i * 20), 10 + (320 * atBkSay / atBkSay), colors(9), atBkSay);
			x_kor = 20 + (320 * atBkSay / atBkSay);
			y_kor = 507 + (i * 20);
			outtextxy(x_kor, y_kor, "AYRIK TASMA BOLEN KALAN");

			cout << setw(27) << "Ayrik Tasma BolenKalan: " << dizi[i] << endl;
			cout << setw(27) << "Ayrik Tasma KareOrtasi: " << dizi[i] << endl;  continue;
		}
	
		//int lyBkSay, int lyKatSay, int lyKortSay, int atBkSay, int atKatSay, int atKortSay, float lineerSay, int dizi[MAX])
		else if (dizi[i] == lineerSay)
		{
			sutun_ciz(1010, 397 - (320 * lineerSay / dizi[6]), colors(2), lineerSay);
			satir_ciz(520 + (i * 20), 10 + (320 * dizi[0] / lineerSay), colors(2), lineerSay);

			x_kor = 20 + (320 * dizi[0] / lineerSay);
			y_kor = 507 + (i * 20);;
			outtextxy(x_kor, y_kor, "LINEER ARAMA");

		}

		else if (dizi[i] == lyKatSay)
		{
			sutun_ciz(875, 397 - (320 * lyKatSay / dizi[6]), colors(3), lyKatSay);
			satir_ciz(520 + (i * 20), 10 + (320 * dizi[0] / lyKatSay), colors(3), lyKatSay);
			x_kor = 20 + (320 * dizi[0] / lyKatSay);
			y_kor = 507 + (i * 20);;
			outtextxy(x_kor, y_kor, "LINEER YOKLAMA KATLAMA");
		}

		else if (dizi[i] == lyKortSay)
		{
			sutun_ciz(740, 397 - (320 * lyKortSay / dizi[6]), colors(4), lyKortSay);
			satir_ciz(520 + (i * 20), 10 + (320 * dizi[0] / lyKortSay), colors(4), lyKortSay);
			x_kor = 20 + (320 * dizi[0] / lyKortSay);
			y_kor = 507 + (i * 20);;
			outtextxy(x_kor, y_kor, "LINEER YOKLAMA KARE ORTASI");
		}

		else if (dizi[i] == lyBkSay)
		{

			sutun_ciz(605, 397 - (320 * lyBkSay / dizi[6]), colors(5), lyBkSay);
			satir_ciz(520 + (i * 20), 10 + (320 * dizi[0] / lyBkSay), colors(5), lyBkSay);
			x_kor = 20 + (320 * dizi[0] / lyBkSay);
			y_kor = 507 + (i * 20);;
			outtextxy(x_kor, y_kor, "LINEER YOKLAMA BOLEN KALAN");

		}
		else if (dizi[i] == atKatSay)
		{


			sutun_ciz(485, 397 - (320 * atKatSay / dizi[6]), colors(6), atKatSay);
			satir_ciz(520 + (i * 20), 10 + (320 * dizi[0] / atKatSay), colors(6), atKatSay);
			x_kor = 20 + (320 * dizi[0] / atKatSay);
			y_kor = 507 + (i * 20);
			outtextxy(x_kor, y_kor, "AYRIK TASMA KATLAMA");
		}
		else if (dizi[i] == atKortSay)
		{

			sutun_ciz(385, 397 - (320 * atKortSay / dizi[6]), colors(7), atKortSay);
			satir_ciz(520 + (i * 20), 10 + (320 * dizi[0] / atKortSay), colors(7), atKortSay);
			x_kor = 20 + (320 * dizi[0] / atKortSay);
			y_kor = 507 + (i * 20);
			outtextxy(x_kor, y_kor, "AYRIK TASMA KARE ORTASI");
		}
		else if (dizi[i] == atBkSay)
		{

			sutun_ciz(270, 397 - (320 * atBkSay / dizi[6]), colors(9), atBkSay);
			satir_ciz(520+(i*20), 10 + (320 * dizi[0] / atBkSay), colors(9), atBkSay);
			x_kor = 20 + (320 * dizi[0] / atBkSay);
			y_kor = 507 + (i * 20);
			outtextxy(x_kor, y_kor, "AYRIK TASMA BOLEN KALAN");
		}

	}

	settextstyle(BOLD_FONT, 0, 13);
	setcolor(10);
	outtextxy(275, 20, "KULLANILAN YONTEMLERIN ADIM SAYISINA GORE ANALIZ TABLOSU");
	outtextxy(10, 480, "PERFORMANS TABLOSU");
	line(270, 40, 820, 40);
	line(10, 500, 200, 500);


	getch();
	closegraph(ekran);

}




//////////////////////////////////////////////

void AnalizAdimSayisi(int lyBkSay, int lyKatSay, int lyKortSay, int atBkSay, int atKatSay, int atKortSay, float lineerSay)
{
	printf("lybk:%d \nlykat:%d \nlykort:%d\n atbk:%d \natkat:%d \natkort:%d \nlineersay:%f", lyBkSay, lyKatSay, lyKortSay, atBkSay, atKatSay, atKortSay, lineerSay);
	int driver, mode, errcode = 0;
	driver = DETECT;

	// initgraph(&driver,&mode,"C:\\TC\\BGI");

	int ekran = initwindow(1200, 600);
	//Garafik Ekran Yükleme Hatalarý
	errcode = graphresult();
	if (errcode != 0)
	{
		printf("graph error:%d", errcode);
		exit(1); //hata ile cik
	}
	//DÜZ ÇİZGİ KODU(yatay)
	line(200, 400, 1060, 400);
	line(200, 399, 1060, 399);
	line(200, 398, 1060, 398);
	line(200, 397, 1060, 397);
	line(200, 396, 1060, 396);
	//OK UCU KODU(YATAY)
	line(1060, 388, 1060, 408);
	line(1061, 390, 1061, 406);
	line(1062, 392, 1062, 404);
	line(1063, 394, 1063, 402);
	line(1064, 396, 1064, 400);
	outtextxy(210, 410, " AYRIK TASMA      AYRIK TASMA     AYRIK TASMA    LINEER YOKLAMA    LINEER YOKLAMA    LINEER YOKLAMA    LINEER ARAMA");
	outtextxy(210, 425, " BOLEN KALAN     KARE ORTASI       KATLAMA            BOLEN KALAN          KARE ORTASI               KATLAMA");
	float oran;
	int baslangic;
	colors renk;
	oran = 320 / lineerSay;
	printf("\noran:%f", oran);
	baslangic = 397 - (lineerSay*oran);
	sutun_ciz(1010, baslangic, YELLOW, lineerSay);

	baslangic = 397 - (lyKatSay*oran);

	printf("\noran:%f", oran);
	sutun_ciz(875, baslangic, GREEN, lyKatSay);

	baslangic = 397 - (lyKortSay*oran);
	sutun_ciz(740, baslangic, RED, lyKortSay);

	baslangic = (397 - lyBkSay*oran);
	sutun_ciz(605, baslangic, WHITE, lyBkSay);

	baslangic = (397 - atKatSay*oran);
	sutun_ciz(485, baslangic, BROWN, atKatSay);

	baslangic = (397 - atKortSay*oran);
	sutun_ciz(375, baslangic, LIGHTMAGENTA, atKortSay);

	sutun_ciz(270, baslangic, CYAN, atBkSay);
	printf("\nbaslangic:%d\n", baslangic);


	settextstyle(BOLD_FONT, 0, 13);
	setcolor(8);
	outtextxy(275, 20, "KULLANILAN YONTEMLERIN ADIM SAYISINA GORE ANALIZ TABLOSU");
	line(270, 40, 820, 40);

	getch();
	closegraph(ekran);

}


struct Kayit
{
	char* adSoyad;
	int numara;
	int bagilAdr;

};

static int sayac = 0;//numara �retiminde kullan�l�yor.
int lyBkSay = 0, lyKatSay = 0, lyKortSay = 0, atBkSay = 0, atKatSay = 0, atKortSay = 0, lineerSay = 0;;//7 dosyan�n ad�m say�s� i�in global de�i�kenler tan�mland� 
																									   //hem kay�t i�in hemde arama i�in saya� her ad�mda artt�r�l�r.
enum {
	MAX = 7
};//6 tane ad�m say�c� i�in dizinin boyutunu global olarak tan�ml�yoruz.
void buble(int*);//s�ralarken kullan�lacak fonksiyonun prototipi.

int numara[9] = { 1,1,0,2,0,2,0,0,0 };//Kocaeli �niversitesi Numara Sistemi.

int diziToIntNumara(int byt, int numara[])
{
	int sonuc = 0;
	for (int i = 0; i < byt; i++)
	{
		int num = numara[i];
		if (num != 0)
		{
			while (num > 0)
			{
				sonuc *= 10;
				num /= 10;
			}
			sonuc += numara[i];
		}
		else
		{
			sonuc *= 10;
		}

	}
	return sonuc;

}

int NumaraUret()
{
	/*
	Struct dizisi sayesinde s�ras�yla bu fonksiyon �al��acakt�r.
	Numara sistemi ��yledir:
	ilk �� basamak 110,120,130... giri� y�l�n� temsil eder. 110=2011 gibi...
	sonraki �� basamak bilg. m�hendisli�inin kodudur. 202.
	son �� basamak ise giri� s�ralamas�d�r. (hi� bir ��rencinin numaras� 0 ile bitemez.)
	her sene i�in 100 ki�i ay�rarak 5 senelik kay�t tutulmaktad�r. 110-202-099 den sonra 110-202-101 gelir.
	*/
	sayac++;
	if (sayac<100)
	{
		numara[8] = sayac % 10;
		numara[7] = sayac / 10;
	}
	else if (sayac>99 && sayac<101)
	{
		numara[6] = 1;
		numara[7] = 0;
		numara[8] = sayac % 10 + 1;
	}
	else
	{
		numara[1] ++;
		sayac = 1;
		numara[6] = 0;
		numara[7] = 0;
		numara[8] = 1;
	}
	//dizideki sonucu integer bir de�i�kene at�yoruz
	return diziToIntNumara(9, numara);

}

char *RasgeleIsimUret()
{
	//alt + rand() % (ust - alt + 1) 
	int AdUzunluk = 2 + rand() % 6;//en az 2 harfli en�ok 7 harfli isim
	int SoyadUzunluk = 5 + rand() % 6;//en az 5 harfli en�ok 10 harfli soyisim
	char *isim = new char[9 + 2];// isim soyisim aras�ndaki bo�luk ve c�mle sonu \0 � da ekleriz +2 olur.
								 //Toplam 10 karakterlik isim soyisim istendi�i i�in 9+2 =11 char alan� ay�r�yoruz... (bo�lu�u dahil etmedim)
	char *KuckHarf = "abcdefghijklmnopqrstuvwxyz";
	char *BykHarf = "ABCDEFGHIJKLMOPRSTUVWXYZ";
	for (int i = 0; i < AdUzunluk; i++) {
		if (i == 0)
		{
			isim[0] = BykHarf[rand() % strlen(BykHarf)];
			continue;//ilk harfi atad�ktan sonra di�er harfe ge�mesi i�in d�ng�y� 1 atlat�r�z.
		}
		isim[i] = KuckHarf[rand() % strlen(KuckHarf)];
	}
	isim[AdUzunluk] = ' ';
	for (int i = AdUzunluk + 1; i < 11; i++) {
		if (i == AdUzunluk + 1)
		{
			isim[i] = BykHarf[rand() % strlen(BykHarf)];
			continue;
		}
		isim[i] = KuckHarf[rand() % strlen(KuckHarf)];
	}

	isim[11] = '\0';
	return isim;
}

void anaKayitDosyasi(struct Kayit anaKayit[500])
{
	int numaraHavuzu[800];//800 kapasiteli numara havuzu olu�turup i�inden rasgele 500 tane numaray� kullan�yoruz.Numara �retimi...
	for (int i = 0; i < 800; i++)
	{
		lineerSay++; lineerSay++; lineerSay++;
		numaraHavuzu[i] = NumaraUret();
	}
	lineerSay++;
	int numaraBayrak[800] = {};
	lineerSay++;
	int k = 0, rast;
	do
	{
		lineerSay++;
	basla:
		lineerSay++;
		rast = rand() % 800;
		lineerSay++;
		if (numaraBayrak[rast] == 0) {
			lineerSay++; lineerSay++;

			anaKayit[k].numara = numaraHavuzu[rast];
			lineerSay++;
			numaraBayrak[rast]++;
		}
		else
		{
			lineerSay++;
			goto basla;
		}
		lineerSay++;
		k++;
	} while (k<500);


	for (int i = 0; i < 500; i++)
	{
		lineerSay++; lineerSay++; lineerSay++;
		anaKayit[i].adSoyad = RasgeleIsimUret();//�sim �retimi...

	}
	/*cout << setw(7) << "Numara" << setw(15) << "Ad Soyad" << endl;
	for (int i = 0; i < 500; i++) kontorol ama�l� yazd�rma
	{
	cout << setw(5) << anaKayit[i].numara << setw(15) << anaKayit[i].adSoyad << endl;
	}*/
	ofstream kayit;
	kayit.open("Kayit.txt");
	lineerSay++; lineerSay++;
	kayit << setw(5) << "Numara" << setw(20) << "Ad Soyad" << endl;//setw iomanip k�t�phanesinden gelir bo�luk b�rak�p yaz� yazmay� sa�lar.
	for (int i = 0; i < 500; i++)
	{
		lineerSay++; lineerSay++; lineerSay++;

		kayit << setw(5) << anaKayit[i].numara << setw(20) << anaKayit[i].adSoyad << endl;
	}
	kayit.close();
}

int bolenKalan(int numara, string cakismaTipi)
{

	int bglAdres;
	if (cakismaTipi == "lineerYoklama")
		bglAdres = numara %= 631;
	else if (cakismaTipi == "ayrikTasma")
		bglAdres = numara %= 501;
	return bglAdres;
	//631 olmas�n�n sebebi; B�t�n hash fonksiyonlar�, dosya dolulu�a yakla�t�k�a k�t� i�lemeye ba�larlar. 
	//Genel bir tavsiye olarak y�kleme fakt�r� %70 veya %80 al�n�r. y�kl.fakt�r�=500/625 =%80 ykleme fakt�r�n� verir.
	//maksimum 625 olabiliyorsa, 625 e en yak�n asal say� olarak 631 se�iliyor.

}
int katlama(int numara, string cakismaTipi)
{

	int bglAdres;
	int dizi[9];
	//numaray� diziye cevirelim...
	for (int i = 8; numara != 0; i--)
	{
		dizi[i] = numara % 10;
		numara /= 10;
	}
	//diziyi 3 er 3 er Katl�yoruz..
	int son[3], orta = 202, bas[3];

	
	for (int i = 8; i > 5; i--)
	{
		son[8 - i] = dizi[i];
	}

	for (int i = 2; i >= 0; i--)
	{
		bas[2 - i] = dizi[i];

	}

	bglAdres = diziToIntNumara(3, son) + diziToIntNumara(3, bas) + orta;
	if (bglAdres > 999)//4 basamakl� say�lar elde ediyoruz e�er 5 basamak olursa on binler basama�� silinir
	{
		bglAdres %= 1000;
	}
	if (cakismaTipi == "lineerYoklama")
		return bglAdres % 631;
	else
		return bglAdres % 501;

}
int kareOrtasi(int numara, string cakismaTipi)
{
	unsigned long long kare = numara;
	kare *= kare;

	int kareOrt[3];
	int bglAdres;


	int dizi[17];
	for (int i = 16; kare != 0; i--)
	{
		dizi[i] = kare % 10;
		kare /= 10;
	}

	for (int i = 7; i<10; i++)
	{
		kareOrt[i - 7] = dizi[i];
	}
	bglAdres = diziToIntNumara(3, kareOrt);


	//max kayit sayisina g�re mod al�n�r �yle g�nderilir.
	if (cakismaTipi == "ayrikTasma")
		bglAdres %= 501;
	else if (cakismaTipi == "lineerYoklama")
		bglAdres %= 631;

	return bglAdres;
}


int bayrakLyBk[631] = { 0 };// �ncelikle i�eri�in hepsini 0 yap�yoruz, kay�t edilince 1 e �eviriyoruz (bayrak mant���).
struct Kayit lyBolenKalanKayit[631];//yazd�rd���m�z verileri tutmak i�in kullan�yoruz.

void LineerYoklamaBolenKalan(struct Kayit lineer[500])
{
	int bglAdres;
	int evAdres;
	for (int i = 0; i < 500; i++)
	{
		lyBkSay++;
		bglAdres = bolenKalan(lineer[i].numara, "lineerYoklama");
		lyBkSay++;
		evAdres = bglAdres;
		lyBkSay++;
	basla:
		lyBkSay++;
		if (bayrakLyBk[bglAdres] == 0)
		{
			lyBkSay++;
			bayrakLyBk[bglAdres]++;
			lyBkSay++;
			lyBolenKalanKayit[bglAdres].adSoyad = lineer[i].adSoyad;
			lyBkSay++;
			lyBolenKalanKayit[bglAdres].numara = lineer[i].numara;
			lyBkSay++;
			lyBolenKalanKayit[bglAdres].bagilAdr = bglAdres;
			lyBkSay++;

		}

		else if (bayrakLyBk[bglAdres] == 1)
		{
			lyBkSay++;
			lyBkSay++;
			bglAdres = bglAdres + 1;
			lyBkSay++;

			if (bglAdres > 630)
			{
				lyBkSay++;
				bglAdres = 0;
				lyBkSay++;
			}

			if (bglAdres == evAdres) {
				lyBkSay++;
				cout << "Dosya Doldu!" << endl;
				lyBkSay++;

			}
			lyBkSay++;
			goto basla;
		}

		lyBkSay++;
	}
	//Dosyaya yazd�rma ger�ekle�iyor...
	ofstream lyBolenKalan;
	lyBolenKalan.open("lineerYoklamaBolenKalan.txt");
	lyBkSay++;
	lyBolenKalan << setw(5) << "Bagil Adres" << setw(14) << "Numara" << setw(20) << "Ad Soyad" << endl;//setw iomanip k�t�phanesinden gelir bo�luk b�rak�p yaz� yazmay� sa�lar.
	lyBkSay++;
	for (int i = 0; i < 631; i++)
	{
		lyBkSay++;	lyBkSay++;
		if (bayrakLyBk[i] == 1) {
			lyBkSay++;
			lyBolenKalan << setw(7) << lyBolenKalanKayit[i].bagilAdr << setw(20) << lyBolenKalanKayit[i].numara << setw(20) << lyBolenKalanKayit[i].adSoyad << endl;
			lyBkSay++;
		}
		else {
			lyBkSay++;
			lyBolenKalanKayit[i].bagilAdr = i;
			lyBkSay++;
			lyBolenKalanKayit[i].adSoyad = "";
			lyBkSay++;
			lyBolenKalanKayit[i].numara = NULL;
			lyBkSay++;
			//bo� kay�tlar�da g�stermek i�in kullan�yoruz. Yazd�r�rken Numaray� yazd�rm�yoruz ��nk� null de�er 0 olarak okunuyor.
			lyBolenKalan << setw(7) << lyBolenKalanKayit[i].bagilAdr << setw(20) << " " << setw(20) << lyBolenKalanKayit[i].adSoyad << endl;
			lyBkSay++;
		}
	}


}


int lineerYoklamaBolenKalanAra(struct Kayit lineer[500])
{

	int ogrSay = 0;

	int bglAdres;
	int evAdres;
	for (int i = 0; i < 500; i++)
	{
		lyBkSay++;	lyBkSay++;
		bglAdres = bolenKalan(lineer[i].numara, "lineerYoklama");
		lyBkSay++;
		evAdres = bglAdres;
		lyBkSay++;

	basla:	lyBkSay++;
		if (bayrakLyBk[bglAdres] == 0) {
			lyBkSay++; cout << "Kayit Dosyada Degil!" << endl; lyBkSay++;
		}
		else
		{
			lyBkSay++;
			if (lyBolenKalanKayit[bglAdres].numara == lineer[i].numara)
			{
				lyBkSay++;
				ogrSay++;
				lyBkSay++;
				cout << ogrSay << ". " << lyBolenKalanKayit[bglAdres].numara << " " << lyBolenKalanKayit[bglAdres].adSoyad << endl;
				lyBkSay++;
			}
			else
			{
				lyBkSay++;
				bglAdres++;
				lyBkSay++;
				if (bglAdres > 630)
				{
					lyBkSay++;
					bglAdres = 0;	lyBkSay++;
				}
				if (bglAdres == evAdres) {
					lyBkSay++; cout << "Kayit Dosyada Degil! " << endl;	lyBkSay++;
				}

				else { lyBkSay++; goto basla; }
			}
		}
	}

	return ++lyBkSay;

}
int bayrakLyKatlama[631] = { 0 };
struct Kayit lyKatlamaKayit[631];//yazd�rd���m�z verileri tutmak i�in kullan�yoruz.
void LineerYoklamaKatlama(struct Kayit lineer[500])
{
	int bglAdres;
	int evAdres;
	for (int i = 0; i < 500; i++)
	{
		lyKatSay++;
		bglAdres = katlama(lineer[i].numara, "lineerYoklama");
		lyKatSay++;
		evAdres = bglAdres;
		lyKatSay++;
	basla:
		lyKatSay++;
		if (bayrakLyKatlama[bglAdres] == 0)
		{
			lyKatSay++;
			bayrakLyKatlama[bglAdres]++;
			lyKatSay++;
			lyKatlamaKayit[bglAdres].adSoyad = lineer[i].adSoyad;
			lyKatSay++;
			lyKatlamaKayit[bglAdres].numara = lineer[i].numara;
			lyKatSay++;
			lyKatlamaKayit[bglAdres].bagilAdr = bglAdres;
			lyKatSay++;
		}
		else if (bayrakLyKatlama[bglAdres] == 1)
		{
			lyKatSay++;	lyKatSay++;
			bglAdres = bglAdres + 1;
			lyKatSay++;

			if (bglAdres > 630) {
				lyKatSay++;
				bglAdres = 0;
				lyKatSay++;
			}

			if (bglAdres == evAdres) {
				lyKatSay++;
				cout << "Dosya Doldu!" << endl;
				lyKatSay++;
			}
			lyKatSay++;
			goto basla;
		}

		lyKatSay++;
	}
	//Dosyaya yazd�rma ger�ekle�iyor...
	ofstream lyBolenKatlama;
	lyBolenKatlama.open("lineerYoklamaKatlama.txt");
	lyKatSay++;
	lyBolenKatlama << setw(5) << "Bagil Adres" << setw(14) << "Numara" << setw(20) << "Ad Soyad" << endl;//setw iomanip k�t�phanesinden gelir bo�luk b�rak�p yaz� yazmay� sa�lar.
	lyKatSay++;
	for (int i = 0; i < 631; i++)
	{
		lyKatSay++; lyKatSay++;
		if (bayrakLyKatlama[i] == 1) {
			lyKatSay++; lyKatSay++;
			lyBolenKatlama << setw(7) << lyKatlamaKayit[i].bagilAdr << setw(20) << lyKatlamaKayit[i].numara << setw(20) << lyKatlamaKayit[i].adSoyad << endl;
		}
		else {
			lyKatSay++;
			lyKatlamaKayit[i].bagilAdr = i;
			lyKatSay++;
			lyKatlamaKayit[i].adSoyad = "";
			lyKatSay++;
			lyKatlamaKayit[i].numara = NULL;
			lyKatSay++;
			//bo� kay�tlar�da g�stermek i�in kullan�yoruz. Yazd�r�rken Numaray� yazd�rm�yoruz ��nk� null de�er 0 olarak okunuyor.
			lyBolenKatlama << setw(7) << lyKatlamaKayit[i].bagilAdr << setw(20) << " " << setw(20) << lyKatlamaKayit[i].adSoyad << endl;
			lyKatSay++;
		}
	}


}
int lineerYoklamaKatlamaAra(struct Kayit lineer[500])
{
	int ogrSay = 0;
	int bglAdres;
	int evAdres;
	for (int i = 0; i < 500; i++)
	{
		lyKatSay++; lyKatSay++;
		bglAdres = katlama(lineer[i].numara, "lineerYoklama");
		lyKatSay++;
		evAdres = bglAdres; lyKatSay++;
	basla:lyKatSay++;
		if (bayrakLyKatlama[bglAdres] == 0) {
			lyKatSay++; cout << "Kayit Dosyada Degil!" << endl; lyKatSay++;
		}
		else
		{
			lyKatSay++;
			if (lyKatlamaKayit[bglAdres].numara == lineer[i].numara)
			{
				lyKatSay++;
				ogrSay++;
				lyKatSay++;
				cout << ogrSay << ". " << lyKatlamaKayit[bglAdres].numara << " " << lyKatlamaKayit[bglAdres].adSoyad << endl;
				lyKatSay++;
			}
			else
			{
				lyKatSay++;
				bglAdres++;
				lyKatSay++;
				if (bglAdres > 630) {
					lyKatSay++;
					bglAdres = 0; lyKatSay++;
				}
				if (bglAdres == evAdres) {
					lyKatSay++; cout << "Kayit Dosyada Degil! " << endl; lyKatSay++;
				}

				else { lyKatSay++; goto basla; }
			}
		}
	}

	return ++lyKatSay;

}

int bayrakLyKareOrt[631] = { 0 };
struct Kayit lyKareOrtKayit[631];//yazd�rd���m�z verileri tutmak i�in kullan�yoruz.
void LineerYoklamaKareOrt(struct Kayit lineer[500])
{
	int bglAdres;
	int evAdres;
	for (int i = 0; i < 500; i++)
	{
		lyKortSay++;
		bglAdres = kareOrtasi(lineer[i].numara, "lineerYoklama");
		lyKortSay++;
		evAdres = bglAdres;
		lyKortSay++;
	basla:
		lyKortSay++;
		if (bayrakLyKareOrt[bglAdres] == 0)
		{
			lyKortSay++;
			bayrakLyKareOrt[bglAdres]++; lyKortSay++;
			lyKareOrtKayit[bglAdres].adSoyad = lineer[i].adSoyad; lyKortSay++;
			lyKareOrtKayit[bglAdres].numara = lineer[i].numara; lyKortSay++;
			lyKareOrtKayit[bglAdres].bagilAdr = bglAdres; lyKortSay++;

		}
		else if (bayrakLyKareOrt[bglAdres] == 1)
		{
			lyKortSay++; lyKortSay++;
			bglAdres = bglAdres + 1;
			lyKortSay++;

			if (bglAdres > 630) {
				lyKortSay++; bglAdres = 0; lyKortSay++;
			}

			if (bglAdres == evAdres) {
				lyKortSay++;
				cout << "Dosya Doldu!" << endl;
				lyKortSay++;

			}
			lyKortSay++;
			goto basla;
		}
		lyKortSay++;


	}
	//Dosyaya yazd�rma ger�ekle�iyor...
	ofstream lyKareOrt;
	lyKareOrt.open("lineerYoklamaKareOrtasi.txt"); lyKortSay++;
	lyKareOrt << setw(5) << "Bagil Adres" << setw(14) << "Numara" << setw(20) << "Ad Soyad" << endl;//setw iomanip k�t�phanesinden gelir bo�luk b�rak�p yaz� yazmay� sa�lar.
	lyKortSay++;
	for (int i = 0; i < 631; i++)
	{
		lyKortSay++; lyKortSay++;
		if (bayrakLyKareOrt[i] == 1) {
			lyKortSay++; lyKortSay++;
			lyKareOrt << setw(7) << lyKareOrtKayit[i].bagilAdr << setw(20) << lyKareOrtKayit[i].numara << setw(20) << lyKareOrtKayit[i].adSoyad << endl;
		}
		else {
			lyKortSay++;
			lyKareOrtKayit[i].bagilAdr = i; lyKortSay++;
			lyKareOrtKayit[i].adSoyad = ""; lyKortSay++;
			lyKareOrtKayit[i].numara = NULL; lyKortSay++;
			//bo� kay�tlar�da g�stermek i�in kullan�yoruz. Yazd�r�rken Numaray� yazd�rm�yoruz ��nk� null de�er 0 olarak okunuyor.
			lyKareOrt << setw(7) << lyKareOrtKayit[i].bagilAdr << setw(20) << " " << setw(20) << lyKareOrtKayit[i].adSoyad << endl; lyKortSay++;
		}
	}


}
int lineerYoklamaKareOrtAra(struct Kayit lineer[500])
{

	int ogrSay = 0;
	int bglAdres;
	int evAdres;
	for (int i = 0; i < 500; i++)
	{
		lyKortSay++; lyKortSay++;
		bglAdres = kareOrtasi(lineer[i].numara, "lineerYoklama"); lyKortSay++;
		evAdres = bglAdres; lyKortSay++;
	basla:lyKortSay++;
		if (bayrakLyKareOrt[bglAdres] == 0) {
			lyKortSay++; cout << "Kayit Dosyada Degil!" << endl; lyKortSay++;
		}
		else
		{
			lyKortSay++;
			if (lyKareOrtKayit[bglAdres].numara == lineer[i].numara)
			{
				lyKortSay++;
				ogrSay++;
				lyKortSay++;
				cout << ogrSay << ". " << lyKareOrtKayit[bglAdres].numara << " " << lyKareOrtKayit[bglAdres].adSoyad << endl;
				lyKortSay++;
			}
			else
			{
				lyKortSay++;
				bglAdres++;
				lyKortSay++;
				if (bglAdres > 630) {
					lyKortSay++;
					bglAdres = 0; lyKortSay++;
				}
				if (bglAdres == evAdres) {
					lyKortSay++; cout << "Kayit Dosyada Degil! " << endl; lyKortSay++;
				}

				else { lyKortSay++; goto basla; }
			}
		}
	}

	return ++lyKortSay;

}

int bayrakAtBk[900] = { 0 };// �ncelikle i�eri�in hepsini 0 yap�yoruz, kay�t edilince 1 e �eviriyoruz (bayrak mant���).
struct Kayit atBolenKalanKayit[900];//yazd�rd���m�z verileri tutmak i�in kullan�yoruz.
static int atBkAdimSay = 0;//Kay�t ve Araman�n toplam ad�m sayilar�n� bu �ekilde tutaca��z.

void AyrikTasmaBolenKalan(struct Kayit lineer[500])
{
	int bglAdres;

	int ayriTasma = 501;

	for (int i = 0; i < 500; i++)
	{
		atBkSay++; atBkSay++;
		bglAdres = bolenKalan(lineer[i].numara, "ayrikTasma");
		atBkSay++;

	basla:
		atBkSay++;
		if (bayrakAtBk[bglAdres] == 0)
		{
			atBkSay++;
			bayrakAtBk[bglAdres]++;
			atBkSay++;
			atBolenKalanKayit[bglAdres].adSoyad = lineer[i].adSoyad;
			atBkSay++;
			atBolenKalanKayit[bglAdres].numara = lineer[i].numara;
			atBkSay++;
			atBolenKalanKayit[bglAdres].bagilAdr = bglAdres;
			atBkSay++;

		}
		else
		{
			atBkSay++;
			while (bayrakAtBk[ayriTasma] == 1)
			{
				atBkSay++;
				ayriTasma++;
				atBkSay++;
			}
			bglAdres = ayriTasma;
			atBkSay++;
			goto basla;

		}



	}
	//Dosyaya yazd�rma ger�ekle�iyor...

	ofstream atBolenKalan;
	atBolenKalan.open("ayrikTasmaBolenKalan.txt"); atBkSay++;
	atBolenKalan << setw(5) << "Bagil Adres" << setw(14) << "Numara" << setw(20) << "Ad Soyad" << endl;//setw iomanip k�t�phanesinden gelir bo�luk b�rak�p yaz� yazmay� sa�lar.
	atBkSay++;
	for (int i = 0; i < 900; i++)
	{
		atBkSay++; atBkSay++;
		if (i == 501) {
			atBkSay++;
			atBolenKalan << setw(35) << "AYRIK TASMA ALANI" << endl;
			atBkSay++;
		}
		if (bayrakAtBk[i] == 1) {
			atBkSay++;
			atBolenKalan << setw(7) << atBolenKalanKayit[i].bagilAdr << setw(20) << atBolenKalanKayit[i].numara << setw(20) << atBolenKalanKayit[i].adSoyad << endl;
			atBkSay++;

		}
		else {
			atBkSay++;
			atBolenKalanKayit[i].bagilAdr = i; atBkSay++;
			atBolenKalanKayit[i].adSoyad = ""; atBkSay++;
			atBolenKalanKayit[i].numara = NULL; atBkSay++;
			//bo� kay�tlar�da g�stermek i�in kullan�yoruz. Yazd�r�rken Numaray� yazd�rm�yoruz ��nk� null de�er 0 olarak okunuyor.
			atBolenKalan << setw(7) << atBolenKalanKayit[i].bagilAdr << setw(20) << " " << setw(20) << atBolenKalanKayit[i].adSoyad << endl; atBkSay++;

		}
	}


}
int ayrikTasmaBolenKalanAra(struct Kayit lineer[500])
{


	int tasma = 501;

	int ogrSay = 0;


	for (int i = 0; i < 500; i++)
	{
		atBkSay++; atBkSay++;
		int aranan = lineer[i].numara;
		atBkSay++;
		int bglAdr = bolenKalan(aranan, "ayrikTasma");
		atBkSay++;
		if (bayrakAtBk[bglAdr] == 0)
		{
			atBkSay++; cout << "Ogrenci Bulunamadi" << endl; atBkSay++;

		}

		else
		{
			atBkSay++;
		basla:
			atBkSay++;
			if (atBolenKalanKayit[bglAdr].numara == aranan)
			{
				atBkSay++;
				ogrSay++;
				atBkSay++;

				cout << ogrSay << ". " << atBolenKalanKayit[bglAdr].numara << " " << atBolenKalanKayit[bglAdr].adSoyad << endl;
				atBkSay++;

			}
			else
			{
				atBkSay++;
				bglAdr = tasma;
				atBkSay++;
				tasma++;
				atBkSay++;

				goto basla;

			}
		}

	}
	return ++atBkSay;
}
int bayrakAtKat[900] = { 0 };// �ncelikle i�eri�in hepsini 0 yap�yoruz, kay�t edilince 1 e �eviriyoruz (bayrak mant���).
struct Kayit atKatKayit[900];//yazd�rd���m�z verileri tutmak i�in kullan�yoruz.
							 //static int atBkAdimSay = 0;//Kay�t ve Araman�n toplam ad�m sayilar�n� bu �ekilde tutaca��z.
void AyrikTasmaKatlama(struct Kayit lineer[500])
{
	int bglAdres;
	int evAdres;
	int ayriTasma = 501;

	for (int i = 0; i < 500; i++)
	{
		atKatSay++; atKatSay++;
		bglAdres = katlama(lineer[i].numara, "ayrikTasma");
		atKatSay++;

	basla:
		atKatSay++;
		if (bayrakAtKat[bglAdres] == 0)
		{
			atKatSay++;
			bayrakAtKat[bglAdres]++; atKatSay++;
			atKatKayit[bglAdres].adSoyad = lineer[i].adSoyad; atKatSay++;
			atKatKayit[bglAdres].numara = lineer[i].numara; atKatSay++;
			atKatKayit[bglAdres].bagilAdr = bglAdres; atKatSay++;

		}
		else
		{
			atKatSay++;
			while (bayrakAtKat[ayriTasma] == 1) {
				atKatSay++;
				ayriTasma++;
				atKatSay++;
			}
			atKatSay++;
			bglAdres = ayriTasma;

			goto basla;

		}



	}
	//Dosyaya yazd�rma ger�ekle�iyor...

	ofstream atKatlama;
	atKatlama.open("ayrikTasmaKatlama.txt");
	atKatSay++;
	atKatlama << setw(5) << "Bagil Adres" << setw(14) << "Numara" << setw(20) << "Ad Soyad" << endl;//setw iomanip k�t�phanesinden gelir bo�luk b�rak�p yaz� yazmay� sa�lar.
	atKatSay++;
	for (int i = 0; i < 900; i++)
	{
		atKatSay++; atKatSay++;
		if (i == 501) {
			atKatlama << setw(35) << "AYRIK TASMA ALANI" << endl;
			atKatSay++; atKatSay++;
		}
		if (bayrakAtKat[i] == 1) {
			atKatSay++;
			atKatlama << setw(7) << atKatKayit[i].bagilAdr << setw(20) << atKatKayit[i].numara << setw(20) << atKatKayit[i].adSoyad << endl;
			atKatSay++;

		}
		else {
			atKatSay++;
			atKatKayit[i].bagilAdr = i; atKatSay++;
			atKatKayit[i].adSoyad = ""; atKatSay++;
			atKatKayit[i].numara = NULL; atKatSay++;
			//bo� kay�tlar�da g�stermek i�in kullan�yoruz. Yazd�r�rken Numaray� yazd�rm�yoruz ��nk� null de�er 0 olarak okunuyor.
			atKatlama << setw(7) << atKatKayit[i].bagilAdr << setw(20) << " " << setw(20) << atKatKayit[i].adSoyad << endl;
			atKatSay++;

		}
	}


}



int ayrikTasmaKatlamaAra(struct Kayit lineer[500])
{


	int tasma = 501;

	int ogrSay = 0;
	int aranan, bglAdr;


	for (int i = 0; i < 500; i++)
	{
		atKatSay++; atKatSay++;
		aranan = lineer[i].numara;
		atKatSay++;

		bglAdr = katlama(aranan, "ayrikTasma");
		atKatSay++;

		if (bayrakAtKat[bglAdr] == 0)
		{
			atKatSay++; atKatSay++;
			cout << "Ogrenci Bulunamadi" << endl;

		}

		else
		{
			atKatSay++;
		basla:
			atKatSay++;
			if (atKatKayit[bglAdr].numara == aranan)
			{
				atKatSay++; atKatSay++; atKatSay++;
				ogrSay++;

				cout << ogrSay << ". " << atKatKayit[bglAdr].numara << " " << atKatKayit[bglAdr].adSoyad << endl;

			}
			else
			{
				atKatSay++; atKatSay++; atKatSay++;
				bglAdr = tasma;
				tasma++;

				goto basla;

			}
		}

	}
	return  ++atKatSay;
}

int bayrakAtKareOrt[900] = { 0 };// �ncelikle i�eri�in hepsini 0 yap�yoruz, kay�t edilince 1 e �eviriyoruz (bayrak mant���).
struct Kayit atKareOrtKayit[900];//yazd�rd���m�z verileri tutmak i�in kullan�yoruz.
								 //static int atBkAdimSay = 0;//Kay�t ve Araman�n toplam ad�m sayilar�n� bu �ekilde tutaca��z.
void AyrikTasmaKareOrt(struct Kayit lineer[500])
{
	int bglAdres;
	int ayriTasma = 501;

	for (int i = 0; i < 500; i++)
	{
		atKortSay++; atKortSay++; atKortSay++;
		bglAdres = kareOrtasi(lineer[i].numara, "ayrikTasma");

	basla:
		atKortSay++;
		if (bayrakAtKareOrt[bglAdres] == 0)
		{
			atKortSay++; atKortSay++; atKortSay++; atKortSay++; atKortSay++;
			bayrakAtKareOrt[bglAdres]++;
			atKareOrtKayit[bglAdres].adSoyad = lineer[i].adSoyad;
			atKareOrtKayit[bglAdres].numara = lineer[i].numara;
			atKareOrtKayit[bglAdres].bagilAdr = bglAdres;

		}
		else
		{
			atKortSay++;
			while (bayrakAtKareOrt[ayriTasma] == 1) {
				atKortSay++; atKortSay++;
				ayriTasma++;
			}
			bglAdres = ayriTasma;
			atKortSay++;
			goto basla;

		}



	}
	//Dosyaya yazd�rma ger�ekle�iyor...

	ofstream atKareOrtasi;
	atKareOrtasi.open("ayrikTasmaKareOrtasi.txt");
	atKortSay++;
	atKareOrtasi << setw(5) << "Bagil Adres" << setw(14) << "Numara" << setw(20) << "Ad Soyad" << endl;//setw iomanip k�t�phanesinden gelir bo�luk b�rak�p yaz� yazmay� sa�lar.
	atKortSay++;
	for (int i = 0; i < 900; i++)
	{
		atKortSay++; atKortSay++;
		if (i == 501) {
			atKortSay++; atKortSay++;
			atKareOrtasi << setw(35) << "AYRIK TASMA ALANI" << endl;
		}
		if (bayrakAtKareOrt[i] == 1) {
			atKortSay++; atKortSay++;
			atKareOrtasi << setw(7) << atKareOrtKayit[i].bagilAdr << setw(20) << atKareOrtKayit[i].numara << setw(20) << atKareOrtKayit[i].adSoyad << endl;

		}
		else {
			atKortSay++; atKortSay++; atKortSay++; atKortSay++; atKortSay++;
			atKareOrtKayit[i].bagilAdr = i;
			atKareOrtKayit[i].adSoyad = "";
			atKareOrtKayit[i].numara = NULL;
			//bo� kay�tlar�da g�stermek i�in kullan�yoruz. Yazd�r�rken Numaray� yazd�rm�yoruz ��nk� null de�er 0 olarak okunuyor.
			atKareOrtasi << setw(7) << atKareOrtKayit[i].bagilAdr << setw(20) << " " << setw(20) << atKareOrtKayit[i].adSoyad << endl;

		}
	}


}



int ayrikTasmaKareOrtAra(struct Kayit lineer[500])
{


	int tasma = 501;

	int ogrSay = 0;
	int aranan, bglAdr;


	for (int i = 0; i < 500; i++)
	{
		atKortSay++; atKortSay++; atKortSay++; atKortSay++;
		aranan = lineer[i].numara;

		bglAdr = kareOrtasi(aranan, "ayrikTasma");

		if (bayrakAtKareOrt[bglAdr] == 0)
		{
			atKortSay++; atKortSay++;
			cout << "Ogrenci Bulunamadi" << endl;

		}

		else
		{
			atKortSay++;
		basla:
			atKortSay++;
			if (atKareOrtKayit[bglAdr].numara == aranan)
			{
				atKortSay++; atKortSay++; atKortSay++;
				ogrSay++;

				cout << ogrSay << ". " << atKareOrtKayit[bglAdr].numara << " " << atKareOrtKayit[bglAdr].adSoyad << endl;

			}
			else
			{
				atKortSay++; atKortSay++; atKortSay++;
				bglAdr = tasma;
				tasma++;

				goto basla;

			}
		}

	}
	return ++atKortSay ;
}

int lineerAra(struct Kayit lineer[500])
{
	int aranan, ogrSay = 0;

	for (int i = 0; i < 500; i++)
	{
		lineerSay++;
		aranan = lineer[i].numara;
		lineerSay++;
		for (int j = 499; j >= 0; j--)
		{
			lineerSay++; lineerSay++;
			if (aranan == lineer[j].numara)
			{
				lineerSay++; lineerSay++; lineerSay++;
				ogrSay++;
				cout << ogrSay << ". " << lineer[j].numara << " " << lineer[j].adSoyad << endl;
			}

		}
	}
	return ++lineerSay;
}


int main()
{
	Kayit kisiler[500];//500 ki�ilik bir struct dizisi olu�turuluyor. ��erisinde adSoyad Numara ve Ba��lAdres de�i�kenlerini tutar.

	srand(time(NULL));//rastgele say� �retmek i�in main fonksiyonda zaman �ekirde�ini kullan�yoruz.

	anaKayitDosyasi(kisiler);//Ana Kay�t Dosyas� burada olu�turuluyor.	Numara ve AdSoyad �retiliyor.

	LineerYoklamaBolenKalan(kisiler); //Lineer Yoklama ve Bolen Kalan Kay�t Dosyas� olu�turuluyor.

	cout << setw(5) << lineerYoklamaBolenKalanAra(kisiler) << " Adimda Lineer Yoklama BolenKalan Yontemiyle Bulunmustur." << endl;//Lineer Yoklama ve Bolen Kalan Kay�t edilen dosyadan t�m ki�iler aran�yor ve ekrana numara isim yazd�r�l�yor.
	Sleep(2000);
	system("cls");


	LineerYoklamaKatlama(kisiler);

	cout << setw(5) << lineerYoklamaKatlamaAra(kisiler) << " Adimda Lineer Yoklama Katlama Yontemiyle Bulunmustur." << endl;
	Sleep(2000);
	system("cls");


	LineerYoklamaKareOrt(kisiler);
	cout << setw(5) << lineerYoklamaKareOrtAra(kisiler) << " Adimda Lineer Yoklama KareOrtasi Yontemiyle Bulunmustur." << endl;


	Sleep(2000);
	system("cls");

	AyrikTasmaBolenKalan(kisiler);
	cout << ayrikTasmaBolenKalanAra(kisiler) << " Adimda AyrikTasma BolenKalan Yontemiyle Bulunmustur." << endl;

	Sleep(2000);
	system("cls");

	AyrikTasmaKatlama(kisiler);
	cout << ayrikTasmaKatlamaAra(kisiler) << " Adimda AyrikTasma Katlama Yontemiyle Bulunmustur." << endl;
	Sleep(2000);
	system("cls");

	AyrikTasmaKareOrt(kisiler);
	cout << ayrikTasmaKareOrtAra(kisiler) << " Adimda AyrikTasma KareOrtasi Yontemiyle Bulunmustur." << endl;

	Sleep(2000);
	system("cls");

	cout << lineerAra(kisiler) << " Adimda Lineer Arama Yontemiyle Bulunmustur." << endl;

	Sleep(2000);
	system("cls");
	//SIRALAMA...
	//e�it olursa...

	//atBkSay = 14753;
	//atKortSay =14753;
	//lineerSay = 256000;
	//lyBkSay = 14000;
	//lyKatSay = 15000;
	int dizi[MAX] = { lyBkSay,lyKortSay,lyKatSay,atBkSay,atKortSay,atKatSay ,lineerSay };

	buble(dizi);//S�ralamak i�in dizi bubble sort'a g�nderiliyor. 
	cout << setw(19) << "ARAMA TIPI" << setw(18) << "ADIM SAYISI" << endl;
	cout << "---------------------------------------" << endl;
	for (int i = 0; i<MAX; i++)
	{

		if (dizi[i] == atBkSay&&dizi[i] == atKortSay)
		{
			if (i == 0) {
				cout << setw(27) << "Ayrik Tasma BolenKalan: " << dizi[i] << "\t" << "<-- EN IYI PERFORMANS" << endl;
				cout << setw(27) << "Ayrik Tasma KareOrtasi: " << dizi[i] << "\t" << "<-- EN IYI PERFORMANS" << endl; i++; continue;
			}
			else
			{
				cout << setw(27) << "Ayrik Tasma BolenKalan: " << dizi[i] << endl;
				cout << setw(27) << "Ayrik Tasma KareOrtasi: " << dizi[i] << endl; i++; continue;
			}
		}
		else if (dizi[i] == lyBkSay)
			cout << setw(27) << "Lineer Yoklama BolenKalan: ";
		else if (dizi[i] == lyKortSay)
			cout << setw(27) << "Lineer Yoklama KareOrtasi: ";
		else if (dizi[i] == lyKatSay)
			cout << setw(27) << "Lineer Yoklama Katlama: ";
		else if (dizi[i] == atBkSay)
			cout << setw(27) << "Ayrik Tasma BolenKalan: ";
		else if (dizi[i] == atKortSay)
			cout << setw(27) << "Ayrik Tasma KareOrtasi: ";
		else if (dizi[i] == atKatSay)
			cout << setw(27) << "Ayrik Tasma Katlama: ";
		else if (dizi[i] == lineerSay)
			cout << setw(27) << "Lineer(hash yok) Arama: ";

		cout << dizi[i] << " ";
		if (i == 0)cout << "\t" << "<-- EN IYI PERFORMANS";
		if (i == 6)cout << "\t" << "<-- EN KOTU PERFORMANS";
		if (i<MAX - 1)
			cout << endl;


	}//S�ralanan dizi yazd�r�l�yor.
	cout << endl;
	system("pause");
	AnalizAdimSayisi_2(lyBkSay, lyKatSay, lyKortSay, atBkSay, atKatSay, atKortSay, lineerSay,dizi);
	return 0;




}
void buble(int *ptr)
{
	void sirala(int*, int*);//Birer birer k���k b�y�k kar��la�t�rmas� ya�lacak, fonksiyonun prototipi burada tan�mlan�yor.
	for (int i = 0; i<MAX - 1; i++)
		for (int j = i + 1; j<MAX; j++)
			sirala(ptr + i, ptr + j);
}
void sirala(int*d1, int*d2)
{
	int gecici;
	if (*d2<*d1)
	{
		gecici = *d1;
		*d1 = *d2;
		*d2 = gecici;
	}
}
