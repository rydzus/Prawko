/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"

void podsumowanie(int poprawnie, int wszystkich)
{
	clear_key();
	while(TRUE)
	{
		clear_to_color(bufor_glowny, COLOR_TLA);
		rectfill(bufor_glowny, 0, 0, SCREEN_WIDTH-2, SCREEN_HEIGHT, COLOR_TLA);
		rect(bufor_glowny, 0, 0, SCREEN_WIDTH-2, SCREEN_HEIGHT, COLOR_OBR);
		rectfill(bufor_glowny, 90, 110, SCREEN_WIDTH-80, 160, COLOR_ODP_ZWY_TLA);
		rectfill(bufor_glowny, 90, 110, SCREEN_WIDTH-80, 135, COLOR_ODP_ZWY_SZKLA);
		rect(bufor_glowny, 90, 110, SCREEN_WIDTH-80, 160, COLOR_ODP_ZWY_OBR);
		
		textprintf_ex(bufor_glowny, font, 100, 120, makecol(255, 255, 255), -1, "Wszystkich pytań było: %d", wszystkich);
		if(poprawnie == 1)
			textprintf_ex(bufor_glowny, font, 100, 140, makecol(255, 255, 255), -1, "Odpowiedziałes/aś poprawnie: 1 raz.");
		else
			textprintf_ex(bufor_glowny, font, 100, 140, makecol(255, 255, 255), -1, "Odpowiedziałes/aś poprawnie: %d razy.", poprawnie);
		
		blit(przycisk_l, bufor_glowny, 0, 0, 1, 1, przycisk_l->w, przycisk_l->h);
		textprintf_ex(bufor_glowny, font, przycisk_l->w+1, 6, makecol(255, 255, 255), -1, "Pomoc");
		
		blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
		
		if(key[KEY_LSHIFT])
		{
			pomoc_podsumowanie();
		}

		if(key[KEY_ENTER] || key[KEY_SPACE])
			break;
		clear_key();
		keypressed();
		rest(60);
	}
}

void podsumowanie_egzaminu(int poprawnie, char kategoria, Odpowiedzi *odpow)
{
	int aktywny = 1;
	clear_key();
	while(TRUE)
	{
		clear_to_color(bufor_glowny, COLOR_ODP_ZWY_TLA);
		rectfill(bufor_glowny, 0, 0, SCREEN_WIDTH-2, SCREEN_HEIGHT, COLOR_TLA);
		rect(bufor_glowny, 0, 0, SCREEN_WIDTH-2, SCREEN_HEIGHT, COLOR_OBR);
		rectfill(bufor_glowny, 90, 70, SCREEN_WIDTH-70, 200, COLOR_ODP_ZWY_TLA);
		rectfill(bufor_glowny, 90, 70, SCREEN_WIDTH-70, 140, COLOR_ODP_ZWY_SZKLA);
		rect(bufor_glowny, 90, 70, SCREEN_WIDTH-70, 200, COLOR_ODP_ZWY_OBR);
		
		textprintf_ex(bufor_glowny, font, 100, 80, makecol(255, 255, 255), -1, "Wszystkich pytań było: 18");
		textprintf_ex(bufor_glowny, font, 100, 100, makecol(255, 255, 255), -1, "Odpowiedziałeś/aś poprawnie: %d razy.", poprawnie);
		if(poprawnie < 16)
			textprintf_ex(bufor_glowny, font, 100, 120, COLOR_ODP_NOP_OBR, -1, "Niestety nie zaliczyłeś/aś egzaminu.");
		else
			textprintf_ex(bufor_glowny, font, 100, 120, COLOR_ODP_POP_OBR, -1, "Gratuluje! Zaliczyłeś/aś egzamin.");
	

		textprintf_ex(bufor_glowny, font, 100, 160, makecol(255, 255, 255), -1, "Czy chcesz zobaczyć odpowiedzi testu?");
		if(aktywny == 0)
			textprintf_ex(bufor_glowny, font, 100, 180, makecol(255, 0, 0), -1, "Tak");
		else
			textprintf_ex(bufor_glowny, font, 100, 180, makecol(255, 255, 255), -1, "Tak");

		textprintf_ex(bufor_glowny, font, 124, 180, makecol(255, 255, 255), -1, "/");

		if(aktywny == 1)
			textprintf_ex(bufor_glowny, font, 132, 180, makecol(255, 0, 0), -1, "Nie");
		else
			textprintf_ex(bufor_glowny, font, 132, 180, makecol(255, 255, 255), -1, "Nie");
			
		blit(przycisk_l, bufor_glowny, 0, 0, 1, 1, przycisk_l->w, przycisk_l->h);
		textprintf_ex(bufor_glowny, font, przycisk_l->w+1, 6, makecol(255, 255, 255), -1, "Pomoc");

		blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);

		if(key[KEY_LEFT])
			aktywny = 0;
		else if(key[KEY_RIGHT])
			aktywny = 1;
		
		if(key[KEY_LSHIFT])
			pomoc_podsumowanie_egzaminu();

		if(key[KEY_ENTER] || key[KEY_SPACE])
			break;
		clear_key();
		keypressed();
		rest(60);
	}

	if(aktywny == 0)
	{
		int i;

		int s;
		for(i=0; i<18; i++)
		{
			s = prezentacja(kategoria, i, odpow);
			if(s == 1)
				break;
			if(s == -1)
			{
				if(i-1 > -1)
					i -= 2;
				else
					i -= 1;
			}
			else
			{
				if(s != 2)
					if(i+1 > 17)
						i--;
			}
		}
	}
}

int prezentacja(char kategoria, int numer_pytania, Odpowiedzi *odpow)
{
	BITMAP *obrazek = NULL;
	char pytanie[300];
	char odpa[300];
	char odpb[300];
	char odpc[300];
	char odpowiedz[4];
	char odpowiedz2[4];
	int odpowiedz3[4];
	int zaznaczone[4];
	int wysokosc_belek;
	int x;
	int x_old;
	int aktywny = 0;
	int koniec = 0;
	int status;
	int i;
	for(i=0; i<4; i++)
		odpowiedz3[i] = 0;
	int koniec2 = 0;

	int numer;
	char plik_txt[30];
	char plik_bmp[30];
	char *str;

	str = (char *)malloc(4 * sizeof(char));

	while(TRUE)
	{
		numer = odpow[numer_pytania].numer_pytania;
		zaznaczone[1] = (odpow[numer_pytania].odpA == 'a') ? 1 : 0;
		zaznaczone[2] = (odpow[numer_pytania].odpB == 'b') ? 1 : 0;
		zaznaczone[3] = (odpow[numer_pytania].odpC == 'c') ? 1 : 0;

		odpowiedz2[0] = 0;
		odpowiedz2[1] = 0;
		odpowiedz2[2] = 0;

		if(kategoria == 'a')
		{
			strcpy(plik_txt, "kategorie/A/pyt/pyt");
			strcpy(plik_bmp, "kategorie/A/rys/pyt");
		}
		else if(kategoria == 'b')
		{
			strcpy(plik_txt, "kategorie/B/pyt/pyt");
			strcpy(plik_bmp, "kategorie/B/rys/pyt");
		}
		else if(kategoria == 'c')
		{
			strcpy(plik_txt, "kategorie/C/pyt/pyt");
			strcpy(plik_bmp, "kategorie/C/rys/pyt");
		}
		else if(kategoria == 'd')
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

		clear_key();
		aktywny = 1;
		clear_to_color(bufor_glowny, COLOR_TLA);

		obrazek = NULL;
		obrazek = load_bmp(plik_bmp, default_palette);

		wczytaj_pytanie(plik_txt, pytanie, odpa, odpb, odpc, odpowiedz);
		for(i=0; odpowiedz[i] != '\0'; i++)
		{
			switch(odpowiedz[i])
			{
				case 'a':
					odpowiedz3[1] = 1;
				break;
				case 'b':
					odpowiedz3[2] = 1;
				break;
				case 'c':
					odpowiedz3[3] = 1;
				break;
			}
		}

		int l = 0;
		if(odpow[numer_pytania].odpA == 'a')
		{
			odpowiedz2[l] = 'a';
			l++;
		}
		if(odpow[numer_pytania].odpB == 'b')
		{
			odpowiedz2[l] = 'b';
			l++;
		}
		if(odpow[numer_pytania].odpC == 'c')
		{
			odpowiedz2[l] = 'c';
			l++;
		}
		odpowiedz2[l] = '\0';

		status = strcmp(odpowiedz, odpowiedz2);

		wysokosc_belek = (liczba_wierszy(pytanie) * FONT_HEIGHT) + (liczba_wierszy(odpa) * FONT_HEIGHT) + \
		(liczba_wierszy(odpb) * FONT_HEIGHT) + (liczba_wierszy(odpc) * FONT_HEIGHT) + (4 * PRZESTRZEN);
		x = SCREEN_HEIGHT - wysokosc_belek;

		while(TRUE)
		{
			clear_to_color(bufor_glowny, COLOR_TLA);

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
			x = rysuj_belki(x, pytanie, COLOR_PYT_TLA, COLOR_PYT_OBR, COLOR_PYT_SZKLA);

			if(zaznaczone[1] == 1)
			{
				if(odpowiedz3[1] == 1)
					x = rysuj_belki2(x, odpa, COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_SZKLA, COLOR_ODP_POP_OBR, COLOR_ODP_POP_TLA, COLOR_ODP_POP_SZKLA);
				else
					x = rysuj_belki2(x, odpa, COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_SZKLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA);
			}
			else
			{
				if(odpowiedz3[1] == 1)
					x = rysuj_belki2(x, odpa, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA,COLOR_ODP_POP_OBR, COLOR_ODP_POP_TLA, COLOR_ODP_POP_SZKLA);
				else
					x = rysuj_belki2(x, odpa, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA,COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA);
			}

			if(zaznaczone[2] == 1)
			{
				if(odpowiedz3[2] == 1)
					x = rysuj_belki2(x, odpb, COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_SZKLA, COLOR_ODP_POP_OBR, COLOR_ODP_POP_TLA, COLOR_ODP_POP_SZKLA);
				else
					x = rysuj_belki2(x, odpb, COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_SZKLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA);
			}
			else
			{
				if(odpowiedz3[2] == 1)
					x = rysuj_belki2(x, odpb, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA, COLOR_ODP_POP_OBR, COLOR_ODP_POP_TLA, COLOR_ODP_POP_SZKLA);
				else
					x = rysuj_belki2(x, odpb, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA);
			}

			if(zaznaczone[3] == 1)
			{
				if(odpowiedz3[3] == 1)
					x = rysuj_belki2(x, odpc, COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_SZKLA, COLOR_ODP_POP_OBR, COLOR_ODP_POP_TLA, COLOR_ODP_POP_SZKLA);
				else
					x = rysuj_belki2(x, odpc, COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_SZKLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA);
			}
			else
			{
				if(odpowiedz3[3] == 1)
					x = rysuj_belki2(x, odpc, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA, COLOR_ODP_POP_OBR, COLOR_ODP_POP_TLA, COLOR_ODP_POP_SZKLA);
				else
					x = rysuj_belki2(x, odpc, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_SZKLA);
			}

			textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH, 5, makecol(255, 255, 255), -1, "%d z 18", numer_pytania+1);
			
			info2(status, SCREEN_HEIGHT - wysokosc_belek);
			
			blit(przycisk_l, bufor_glowny, 0, 0, 1, 1, przycisk_l->w, przycisk_l->h);
			textprintf_ex(bufor_glowny, font, przycisk_l->w+1, 6, makecol(255, 255, 255), -1, "Pomoc");

			blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);

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

			if(key[KEY_ENTER])
			{
				clear_key();
				destroy_bitmap(obrazek);
				koniec = 1;
				koniec2 = 2;

				break;
			}
			else if(key[KEY_LEFT])
			{
				clear_key();
				destroy_bitmap(obrazek);
				koniec = 1;
				koniec2 = -1;
				
				break;
			}
			else if(key[KEY_RIGHT])
			{
				clear_key();
				destroy_bitmap(obrazek);
				koniec = 1;
				koniec2 = 0;
				
				break;
			}
			
			if(key[KEY_LSHIFT])
			{
				pomoc_prezentacja();
			}

			if(key[KEY_ESC])
			{
				clear_key();
				if(obrazek != NULL)
					destroy_bitmap(obrazek);
				koniec = 1;
				koniec2 = 1;

				break;
			}

			clear_key();
			keypressed();
			x = x_old;
			rest(60);
		}

		if(koniec == 1)
			break;
	}
	
	free(str);

	return koniec2;
}
