/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"


volatile long czas ;
void zegarek()
{
	czas++;
}
END_OF_FUNCTION(zegarek);

LOCK_VARIABLE(czas);
LOCK_FUNCTION(zegarek); 

int egzamin(int mode, int od_pytania, int do_pytania, char *kategoria, int *liczba_pytan, Odpowiedzi *odpow)
{
	BITMAP *obrazek = NULL;
	char pytanie[300];
	char odpa[300];
	char odpb[300];
	char odpc[300];
	char odpowiedz[4];
	char odpowiedz2[4];
	int zaznaczone[4];
	int wysokosc_belek;
	int x;
	int x_old;
	int aktywny = 1;
	int koniec = 0;
	int poprawnie = 0;
	int licznik = 0;
	int tab_pyt[526];
	int ii;
	int pytania_egz[18];
	
	/* Zmienne dla czasu egzaminu*/
	int polgodziny = 1500;
	int minuty;
	int sekundy;
	czas = 0;

	int numer = od_pytania - 1;
	char plik_txt[30];
	char plik_bmp[30];
	char *str;

	str = (char *)malloc(4 * sizeof(char));

	/* Czyszczenie tablicy pytan ktore juz zostaly wybrane */
	for(ii=0; ii<=526; ii++)
		tab_pyt[ii] = 0;
	tab_pyt[0] = 1;
	
	/* Losowane sa pytania aby mozna bylo sie miedzy nimi przelaczac (lewo, prawo) */
	for(ii=0; ii<18; ii++)
	{
		do
		{
			numer = rand()%((do_pytania-od_pytania)+1) + od_pytania;
			if(numer > *liczba_pytan || numer < 1)
				numer = 0;
		}
		while(tab_pyt[numer] == 1);
		
		pytania_egz[ii] = numer;
	}
	
	/* Resetuje pytania i zmienne na odpowiedzi w strukturach odpowiedzi */
	for(ii=0; ii<18; ii++)
	{
		odpow[ii].numer_pytania = pytania_egz[ii];
		odpow[ii].odpA = ' ';
		odpow[ii].odpB = ' ';
		odpow[ii].odpC = ' ';
	}

	/* instalowanie zegara */
	install_int_ex(zegarek, BPS_TO_TIMER(1));
	
	/* Ustawiamy dostep do plikow. Zalezy kategorii  prawo jazdy */
	if(*kategoria == 'a')
	{
		strcpy(plik_txt, "kategorie/A/pyt/pyt");
		strcpy(plik_bmp, "kategorie/A/rys/pyt");
	}
	else if(*kategoria == 'b')
	{
		strcpy(plik_txt, "kategorie/B/pyt/pyt");
		strcpy(plik_bmp, "kategorie/B/rys/pyt");
	}
	else if(*kategoria == 'c')
	{
		strcpy(plik_txt, "kategorie/C/pyt/pyt");
		strcpy(plik_bmp, "kategorie/C/rys/pyt");
	}
	else if(*kategoria == 'd')
	{
		strcpy(plik_txt, "kategorie/D/pyt/pyt");
		strcpy(plik_bmp, "kategorie/D/rys/pyt");
	}
	else
	{
		strcpy(plik_txt, "kategorie/T/pyt/pyt");
		strcpy(plik_bmp, "kategorie/T/rys/pyt");
	}
		

	/* Glowna petla egzaminu */
	while(TRUE)
	{
		numer = odpow[licznik].numer_pytania;
		/* Resetowane zaznaczenia pytan */
		if(odpow[licznik].odpA == 'a')
			zaznaczone[1] = 1;
		else
			zaznaczone[1] = 0;
		
		if(odpow[licznik].odpB == 'b')
			zaznaczone[2] = 1;
		else
			zaznaczone[2] = 0;
		
		if(odpow[licznik].odpC == 'c')
			zaznaczone[3] = 1;
		else
			zaznaczone[3] = 0;

		/* Resetowanie odanych odpowiedzi */
		odpowiedz2[0] = 0;
		odpowiedz2[1] = 0;
		odpowiedz2[2] = 0;

		/* Jezeli licznik bedzie rowny 18 wychodzimy z funkcji egzamin */
		if(licznik+1 > 18)
			break;

		if(*kategoria == 'a')
		{
			strcpy(plik_txt, "kategorie/A/pyt/pyt");
			strcpy(plik_bmp, "kategorie/A/rys/pyt");
		}
		else if(*kategoria == 'b')
		{
			strcpy(plik_txt, "kategorie/B/pyt/pyt");
			strcpy(plik_bmp, "kategorie/B/rys/pyt");
		}
		else if(*kategoria == 'c')
		{
			strcpy(plik_txt, "kategorie/C/pyt/pyt");
			strcpy(plik_bmp, "kategorie/C/rys/pyt");
		}
		else if(*kategoria == 'd')
		{
			strcpy(plik_txt, "kategorie/D/pyt/pyt");
			strcpy(plik_bmp, "kategorie/D/rys/pyt");
		}
		else
		{
			strcpy(plik_txt, "kategorie/T/pyt/pyt");
			strcpy(plik_bmp, "kategorie/T/rys/pyt");
		}

		sprintf(str, "%d", numer);
		strcat(plik_txt, str);
		strcat(plik_txt, ".txt");

		sprintf(str, "%d", numer);
		strcat(plik_bmp, str);
		strcat(plik_bmp, ".bmp");

		/* Czysci nacisniete klawisze */
		clear_key();
		/* Wskazuje na pytanie aktywane */
		aktywny = 1;
		/* Czysci ekran */
		clear_to_color(bufor_glowny, COLOR_TLA);

		obrazek = NULL;
		obrazek = load_bmp(plik_bmp, default_palette);

		wczytaj_pytanie(plik_txt, pytanie, odpa, odpb, odpc, odpowiedz);

		/* Oblicza jaki obszar ekranu beda zajmowac belki na pytania */
		wysokosc_belek = (liczba_wierszy(pytanie) * FONT_HEIGHT) + (liczba_wierszy(odpa) * FONT_HEIGHT) + \
		(liczba_wierszy(odpb) * FONT_HEIGHT) + (liczba_wierszy(odpc) * FONT_HEIGHT) + (4 * PRZESTRZEN);
		/* Od kad trzeba rysowac belki */
		x = SCREEN_HEIGHT - wysokosc_belek;

		/* Petla sterujaca przyciskami itp. */
		while(TRUE)
		{
			clear_to_color(bufor_glowny, COLOR_TLA);

			/* 
			 * Dopuki nie trzeba nie wychodzimy z petli i do tego 
			 * potrzebna jest zmienna x_old aby mozna bylo od nowa
			 * rysowac belki od miejsca ktore wczesniej zostalo wyznaczone
			 */
			x_old = x;

			if(obrazek != NULL)
			{
				/* Cien pod obrazkiem */
				rectfill(bufor_glowny, ((SCREEN_WIDTH-2)/2) - (((x*100)/74)/2) - 3, 0, ((SCREEN_WIDTH-2)/2) - (((x*100)/74)/2) + (x*100)/74 + 2, x-1, makecol(19, 19, 19));
				rectfill(bufor_glowny, ((SCREEN_WIDTH-2)/2) - (((x*100)/74)/2) - 2, 1, ((SCREEN_WIDTH-2)/2) - (((x*100)/74)/2) + (x*100)/74 + 1, x-2, makecol(17, 17, 17));
				rectfill(bufor_glowny, ((SCREEN_WIDTH-2)/2) - (((x*100)/74)/2) - 1, 2, ((SCREEN_WIDTH-2)/2) - (((x*100)/74)/2) + (x*100)/74, x-3, makecol(11, 11, 11));
				/* Rysuje obrazek do pytania */			
				stretch_blit(obrazek, bufor_glowny, 0, 0, obrazek->w, obrazek->h, ((SCREEN_WIDTH-2)/2) - (((x*100)/74)/2), 3, (x*100)/74, x-6);
				/* rysuje belke z pytaniem */
			}
			/* rysuje belke z pytaniem */
			x = rysuj_belki(x, pytanie, COLOR_PYT_TLA, COLOR_PYT_OBR, COLOR_PYT_SZKLA);

			/* 
			 * Jezeli belka jest zaznaczona rysuj innym kolorem, 
			 * do tego jezeli jest aktywna rysuje na inny kolor obramowanie
			 * Jezeli belka nie jest zaznaczona rysuja ja normalnymi kolorami
			 */
			if(zaznaczone[1] == 1)
			{
				if(aktywny == 1)
					x = rysuj_belki(x, odpa, COLOR_ODP_ZAZ_TLA, COLOR_ODP_AKT_OBR, COLOR_ODP_ZAZ_SZKLA);
				else
					x = rysuj_belki(x, odpa, COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_OBR, COLOR_ODP_ZAZ_SZKLA);
			}
			else
			{
				if(aktywny == 1)
					x = rysuj_belki(x, odpa, COLOR_ODP_ZWY_TLA, COLOR_ODP_AKT_OBR, COLOR_ODP_ZWY_SZKLA);
				else
					x = rysuj_belki(x, odpa, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
			}

			if(zaznaczone[2] == 1)
			{
				if(aktywny == 2)
					x = rysuj_belki(x, odpb, COLOR_ODP_ZAZ_TLA, COLOR_ODP_AKT_OBR, COLOR_ODP_ZAZ_SZKLA);
				else
					x = rysuj_belki(x, odpb, COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_OBR, COLOR_ODP_ZAZ_SZKLA);
			}
			else
			{
				if(aktywny == 2)
					x = rysuj_belki(x, odpb, COLOR_ODP_ZWY_TLA, COLOR_ODP_AKT_OBR, COLOR_ODP_ZWY_SZKLA);
				else
					x = rysuj_belki(x, odpb, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
			}

			if(zaznaczone[3] == 1)
			{
				if(aktywny == 3)
					x = rysuj_belki(x, odpc, COLOR_ODP_ZAZ_TLA, COLOR_ODP_AKT_OBR, COLOR_ODP_ZAZ_SZKLA);
				else
					x = rysuj_belki(x, odpc, COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_OBR, COLOR_ODP_ZAZ_SZKLA);
			}
			else
			{
				if(aktywny == 3)
					x = rysuj_belki(x, odpc, COLOR_ODP_ZWY_TLA, COLOR_ODP_AKT_OBR, COLOR_ODP_ZWY_SZKLA);
				else
					x = rysuj_belki(x, odpc, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
			}

			/* Dodaje napis ktorej jest aktywane pytani z ilu (dla egzaminiu z 18) */
			textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH, 5, makecol(255, 255, 255), -1, "%d z 18", licznik+1);
			
			/* Ile minut i sekund minelo od rozpoczecia egzamiu */
			minuty = (polgodziny - czas) / 60;
			sekundy = (polgodziny - czas) % 60;
			
			/* 
			 * Jezeli sekundy sa mniejsze od 10 to dodajemy sztuczne 0
			 * aby ladniej wygladalo ;)
			 */
			if(sekundy < 10)
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH, 15, makecol(255, 255, 255), -1, "%d:0%d", minuty, sekundy);
			else
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH, 15, makecol(255, 255, 255), -1, "%d:%d", minuty, sekundy);

			/* Sprawdza czy mielo juz 25minut, jezeli tak, to konczy egzmin */
			if(minuty == 0 && sekundy == 0)
			{
				koniec = 1;
				break;
			}
			
			/* Przycisk L i napis "Pomoc" */
			blit(przycisk_l, bufor_glowny, 0, 0, 0, 0, przycisk_l->w, przycisk_l->h);
			textprintf_ex(bufor_glowny, font, przycisk_l->w, 6, makecol(255, 255, 255), -1, "Pomoc");

			/* Rysuje bufor na ekranie */
			blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);

			if(key[KEY_UP])
			{
				if(aktywny-1 >= 1)
					aktywny--;
			}
			else if(key[KEY_DOWN])
			{
				if(aktywny+1 <= 3)
					aktywny++;
			}
			else if(key[KEY_LEFT])
			{
				if(licznik-1 > -1)
					licznik--;
				
				if(obrazek != NULL)
					destroy_bitmap(obrazek);
				break;
			}
			else if(key[KEY_RIGHT])
			{
				if(licznik+1 < 18)
					licznik++;
					
				if(obrazek != NULL)
					destroy_bitmap(obrazek);
				break;
			}
			
			/* Jezeli zostanie nacisniety przycisk X zaznaczamy odpowiedz */
			if(key[KEY_SPACE])
			{
				clear_key();
				switch(aktywny)
				{
					case 1:
						if(zaznaczone[1] == 0)
							zaznaczone[1] = 1;
						else
							zaznaczone[1] = 0;
					break;
					case 2:
						if(zaznaczone[2] == 0)
							zaznaczone[2] = 1;
						else
							zaznaczone[2] = 0;
					break;
					case 3:
						if(zaznaczone[3] == 0)
							zaznaczone[3] = 1;
						else
							zaznaczone[3] = 0;
					break;
				}
			}
			
			if(key[KEY_LSHIFT])
			{
				pomoc_egzamin();
			}

			/* 
			 * Jezeli zostanie nacisniety przycisk Start zatwierdzamy odpowiedz
			 * i przechodzimy do nowego pytania
			 */
			if(key[KEY_ENTER])
			{
				clear_key();
				/* Na ktore miejsca w odpowiedz2 ma dostawic literke */
				int l = 0;
				int status;
				
				/* 
				 * Sprawdza jakie odpowiedzi zostaly wybrane i 
				 * przygotowuje ciag znakow aby sprawdzic czy uzytkownik 
				 * odpowiedzial poprawnie na pytanie
				 */
				if(zaznaczone[1] == 1)
				{
					odpowiedz2[l] = 'a';
					/* 
					 * Wypelnia pole ze taka odpowiedz zostala zaznaczona, 
					 * dzieki temu mozna odczytac w podsumowaniu egzaminu 
					 * czy uzytkownik zaznaczyl odpowiedz
					 */
					odpow[licznik].odpA = 'a';
					l++;
				}
				else
					odpow[licznik].odpA = ' ';
				
				if(zaznaczone[2] == 1)
				{
					odpowiedz2[l] = 'b';
					odpow[licznik].odpB = 'b';
					l++;
				}
				else
					odpow[licznik].odpB = ' ';
				
				if(zaznaczone[3] == 1)
				{
					odpowiedz2[l] = 'c';
					odpow[licznik].odpC = 'c';
					l++;
				}
				else
					odpow[licznik].odpC = ' ';
				
				odpowiedz2[l] = '\0';

				/* Czy odpowiedz jest prawidlowa? */
				status = strcmp(odpowiedz, odpowiedz2);

				/* Jezeli tak do zwiekszamy licznik poprawnych odpowiedzi */
				/* to chyba trzeba wyzucic i dopiero po egzaminie sprawidzic ;) */
				if(status == 0)
					poprawnie++;

				licznik++;

				if(obrazek != NULL)
					destroy_bitmap(obrazek);
				break;
			}

			if(obrazek != NULL)
			{
			/* 
			 * Jezeli zostanie nacisniety przycisk R to powiekszamy obrazek */
			#if PSP
				if(key[KEY_RSHIFT])
			#else
				if(key[KEY_M])
			#endif
				{
					clear_key();
					/* Czekamy az uzytkownik powtornie nacisnie R aby porworcic do pytania */
					while(TRUE)
					{
						clear_to_color(bufor_glowny, COLOR_TLA);
						blit(obrazek, bufor_glowny, 0, 0, (SCREEN_WIDTH-obrazek->w)/2, 0, obrazek->w, obrazek->h);
						blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
					#if PSP
						if(key[KEY_RSHIFT])
					#else
						if(key[KEY_M])
					#endif
							break;
						clear_key();
						keypressed();
						rest(60);
					}
					clear_key();
				}
			}

			/* Konczy egzamin */
			if(key[KEY_ESC])
			{
				/* 
				 * Zaznaczamy ze na tym pytaniu konczy sie egzamin */
				/* raczej bez sensu, bo mozna zrobic tak, ze jak nie odpowiedzial, 
				 * czy zakonczyl i na jakies nie odpowiedzial to tam 
				 * siedzi zero i w tedy mozna napisac ze na to pytanie 
				 * nie odpowiedzial
				 */
				koniec = 1;
				break;
			}

			clear_key();
			keypressed();
			/* Przywrocenie starej pozycji x */
			x = x_old;
			rest(60);
		}

		if(koniec == 1)
			break;
	}

	free(str);
	remove_int(zegarek);

	return poprawnie;
}
