#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//Rastgele sayı girişi için başlangıç noktası
	srand(time(NULL));
	
	//Durum Değişkenleri (0-100 sınırları arasında)
	int saglik = 100;
	int oksijen = 100;
	int enerji = 100;
	int su = 50;
	int yedekParca = 5;
	int modulHasari = 0;
	
	int gun = 1;
	int tur = 0;
	int kilitMuhurlu = 0; // 0: Mühürlü değil, 1: Mühürlü
	
	char zorluk;
	char komut;
	int firtinaSuresi = 3;
	
	// Zorluk Seviyesi Seçimi (Geçersiz seçimde tekrar isteyecek şekilde do-while)
	do {
		printf("--- MARS KONOLISI YASAM DESTEK SIMULATORU ---\n");
		printf("Zorluk Seviyesi Seciniz (K: Kolay, N: Normal, Z: Zor): ");
		scanf(" %c", &zorluk);
		
		switch (zorluk) {
			case 'k':
			case 'K':
				su = 60;
				yedekParca = 6;
				firtinaSuresi = 3;
				printf("Zorluk: Kolay secildi. Kaynaklar bol.\n\n");
				break;
			case 'n':
			case 'N':
				su = 40;
				yedekParca = 4;
				firtinaSuresi = 5;
				printf("Zorluk: Normal secildi.\n\n");
				break;
			case 'z':
			case 'Z':
				su = 25;
				yedekParca = 2;
				firtinaSuresi = 7;
				printf("Zorluk: Zor secildi. Sartlar agir!\n\n");
				break;
			default:
				printf("Gecersiz zorluk secimi! Tekrar deneyin.\n\n");
				zorluk = 'X'; // Döngünün devam etmesi için
				break;		
			}
		} while (zorluk == 'X');
	
	// Ana Oyun Döngüsü (do-while)
	do {
		printf("\n-------------------------------------------\n");
		printf("GUN: %d | TUR: %d\n", gun, tur);
		printf("Komutlar -> [G]Kesif, [O]Oksijen Uret, [T]Tamir, [D]Durum, [U]Uyu, [K]Kum Firtinasi, [H]Hava Kilidi Sifresi, [Q]Cikis\n");
		printf("Komutunuzu girin: ");
		scanf(" %c", &komut);
		
		int gecerliKomut = 1; //Tur artışı ve zaman akışı için kontrol
		
		switch (komut) {
			case 'g':
			case 'G': {
				if (enerji < 15 || oksijen < 10) {
					printf("Yetersiz kaynak! Kesif icin en az 15 enerji ve 10 oksijen gerekiyor.\n");
					gecerliKomut = 0;
					break;
				}
				
				enerji -= 15;
				oksijen -= 10;
			
				int zar = rand() % 100;
				int esik = 45;
				printf("Zar: %d / Esik: %d -> ", zar, esik);
			
				if (zar < 10 || modulHasari > 70) {
					printf("BASARISIZ! Disarida yaralandiniz.\n");
					saglik -= 15;
				} else if (zar < 50){
					int bulunanSu = 10;
					su += bulunanSu;
					printf("BASARILI! %d birim su buldunuz.\n", bulunanSu);
				} else if (zar < 80) {
					int bulunanParca = 2;
					yedekParca += bulunanParca;
					printf("BASARILI! %d adet yedek parca buldunuz.\n", bulunanParca);
				} else {
					printf("Eli bos dondunuz. \n");
				}
				break;	
			}
	
			case 'o':
			case 'O': {
				if (enerji < 10) {
					printf("Yetersiz enerji! Oksijen uretmek icin en az 10 enerji gerekiyor.\n");
					gecerliKomut = 0;
					break;
				}
				if (su < 2) {
					printf("Yetersiz su! Oksijen uretmek icin en az 2 birim su lazim.\n");
					gecerliKomut = 0;
					break;
				}
		
				int harcananSu;
				printf("Uretim icin harcanacak su miktarini girin (Mevcut Su: %d): ", su);
				scanf("%d", &harcananSu);
		
				if (harcananSu > su || harcananSu <= 0) {
					printf("Gecersiz su miktari!\n");
					gecerliKomut = 0;
				} else {
					enerji -= 10;
					su -= harcananSu;
			
					int uretilenOksijen = (harcananSu / 2) * 3;
					if (harcananSu % 2 != 0){
						su += 1;
						printf("Tek su girdiginiz icin 1 birim su depoda artirilarak geri verildi.\n");
					}
					oksijen += uretilenOksijen;
					printf("Basariyla %d birim oksijen uretildi.\n", uretilenOksijen);
				}
				break;
			}
	
			case 't':
			case 'T':{
				if (yedekParca <= 0){
					printf("Yedek parcaniz kalmadi! Tamir yapilamaz.\n");
					gecerliKomut = 0;
					break;
				}
				if (modulHasari == 0) {
					printf("Modulde tamir edilecek hasar yok.\n");
					gecerliKomut = 0;
					break;
				}
		
				yedekParca--;
				enerji -= 10;
		
				if (modulHasari <= 30) {
					modulHasari -= 15;
					printf("Hafif hasar giderlildi.\n");
				} else if (modulHasari <= 70) {
					modulHasari -= 10;
					printf("Orta seviye hasar onarildi.\n");
				} else {
					modulHasari -= 5;
					printf("Agir hasar kismi olarak onarildi.\n");
				}
				break;
			}
	
			case 'd':
			case 'D': {
				printf("\n--- DURUM RAPORU ---\n");
				printf("Saglik			: %d/100\n", saglik);
				printf("Enerji			: %d/100\n", enerji);
				printf("Oksijen			: %d/100\n", oksijen);
				printf("Su Miktari		: %d birim\n", su);
				printf("Yedek Parca		: %d adet\n", yedekParca);
				printf("Modul Hasari	: %d/100\n", modulHasari);
				printf("Hava Kilidi		: %s\n", kilitMuhurlu ? "Muhurlu" : "Acik");
		
				if (oksijen < 25) { printf("Kritik UYARI: Oksijen tehlikeli seviyede dusuk!\n"); }
				if (saglik < 30) { printf("Kritik UYARI: Saglik durumu kritik!\n"); }
				if (modulHasari > 70) { printf("Kritik UYARI: Modul hasari cok yuksek!\n"); }
		
				if (oksijen >= 25 && saglik >= 30 && modulHasari <= 70){
					printf("TUM SİSTEMLER NORMAL.\n");
				}
				gecerliKomut = 0; 
				break;
			}
	
			case 'u':
			case 'U':{
				enerji += 20;
				saglik += 10;
		
				if (oksijen < 20) {
					saglik -= 10;
					printf("Oksijen cok dusuk oldugu icin dinlenirken sagliginiz kotulesti!\n");
				} else {
					printf("Dinlendiniz. Enerji ve saglik yenilendi.\n");
				}
				break;
			}
	
			case 'k':
			case 'K': {
				printf("Kum firtinasi basladi! (Suresi: %d tur)\n", firtinaSuresi);
				
				int i;
				for (i = 1; i <= firtinaSuresi; i++){
					int zar = rand() % 100;
					int hasarCarpani = 1;
					
					// Çift numaralı turlarda rüzgar şiddetlenir (mod operatörü ile) [cite: 2]
					if (i % 2 == 0) {
						hasarCarpani = 2;
						printf(" Tur %d (Siddetli Ruzgar!): ", i);
					} else {
						printf(" Tur %d: ", i);
					} 
			
					if (kilitMuhurlu == 1) {
						printf("Hava kilidi muhurlu oldugu icin sizinti atlandi. \n");
						continue; //Döngünün o turunu atlar [cite: 2]
					}
			
					if (zar < 30) {
						oksijen -= 5 * hasarCarpani;
						modulHasari += 10 * hasarCarpani;
						printf("Oksijen sizintisi ve modul hasari alindi!\n");
					} else {
						printf("Firtina hafif atlandi, zarar gorulmedi.\n");
					}
				
					if (saglik <= 0 || oksijen <= 0) {
						break; // Döngüyü hemen sonlandırır. [cite: 2]
					}
				}
				break;
			}
	
			case 'h':
			case 'H': {
				char dogruSifre = 'A' + (gun % 26);
				int deneme = 3;
				int basarili = 0;
			
				printf("Hava Kilidi Guvenlik Sifresi Dogrulamasi\n");
				printf("Ipucu: Sifre, alfabede 'A' harfinden bugunun gun sayisi (%d) kadar ilerideki buyuk harftir.\n", gun);
		
				 do {
				 	char girilenHarf;
			 		printf("Kalan hak (%d). Harf girin: ", deneme);
			 		scanf(" %c", &girilenHarf);

			 		if (girilenHarf == dogruSifre || girilenHarf == dogruSifre + 32) {
			 			basarili = 1;
			 			break;
					 } else {
				 		deneme--;
				 		enerji -= 5;
				 		if (girilenHarf < dogruSifre) {
				 			printf("Yanlis! Ileri git (daha ileride bir harf gir). \n");
						} else {
					 		printf("Yanlis! Geri git (daha onceki bir harf gir). \n");
						}
					}
				} while (deneme > 0);
			 
				if (basarili) {
			 		kilitMuhurlu = 1;
			 		printf("Tebrikler! Hava kilidi basariyla muhurlendi.\n");
				} else {
			 		modulHasari += 20;
			 		printf("Tum haklar bitti! Sifre yanlis oldugu icin modul hasar aldi.\n");
				}
				break;
			}
		
			case 'q':
			case 'Q':
				printf("Oyundan cikiliyor...\n");
				goto oyunBitti;
				break;
			
			default:
				printf("Tanimsiz komut girdiniz! Tur harcanmadi.\n");
				gecerliKomut = 0;
				break;
		}
	
		// Sınnırlandırma (0 ile 100 arasında tutma)
		if (saglik > 100) saglik = 100;
		if (saglik < 0) saglik = 0;
		if (enerji > 100) enerji = 100;
		if (enerji < 0) enerji = 0;
		if (oksijen > 100) oksijen = 100;
		if (oksijen < 0) oksijen = 0;
		if (modulHasari > 100) modulHasari = 100;
		if (modulHasari <0) modulHasari = 0;
	
		//Geçerli komut çalıştıysa zaman akışını ilerlet
		if (gecerliKomut) {
			tur ++;
			// Her 3 turda bir yeni gün başlar
			if (tur % 3 == 0) {
				gun ++;
				oksijen -= 8;
				if (modulHasari > 70) {
					saglik -= 5;
					printf("\n[BILGI] Modul hasari 70'in uzerinde oldugu ıcın yeni gunde 5 saglik kaybettiniz! \n");
				}
			}
		}
	
		// Oyun sonu koşulları kontrolü
		if ( saglik <= 0 || oksijen <=0) {
			printf("\n\n=== OYUN BITTI: HAYATTA KALAMADINIZ! ===\n");
			break;
		}
	
		if (gun > 15) {
			printf("\n\n=== TEBRİKLER! 15 GUNU TAMAMLADINIZ, KURTARAN EKİBİ GELDİ! ===\n");
			break;
		}
		
		
	} while (1); // Ana döngünün do-while bitişi
	
	int puan = (gun * 100) + saglik + oksijen - modulHasari;
	
	
oyunBitti:
	printf("\n================ SONUC RAPORU ================\n ");
	printf("Hayatta Kalinan Gun : %d\n", gun);
	printf("Toplam Tur Sayisi 	: %d\n", tur);
	printf("Kalan Saglik 		: %d\n", saglik);
	printf("Kalan Enerji 		: %d\n", enerji);
	printf("Kalana Oksijen 		: %d\n", oksijen);
	printf("Kalan Su 			: %d\n", su);
	printf("Kalan Yedek Parca 	: %d\n", yedekParca);
	printf("Son Modul Hasari 	: %d\n", modulHasari);
	printf("GENEL PUANINIZ 		: %d\n", puan);
	printf("==============================================\n");
	
	
	return 0;
}
