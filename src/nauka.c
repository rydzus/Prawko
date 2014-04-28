/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"


/*
 * mode == 0 - normalny od pytania, do pytania
 * mode == 1 - losowy od pytania, do pytania
 * mode == 2 - losowy od pytania, do pytania (zakres uzytkownika)
 */

int nauka(int mode, int od_pytania, int do_pytania, char *kategoria, int *liczba_pytan, Odpowiedzi *odpow)
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

	int numer = od_pytania - 1;
	char plik_txt[30];
	char plik_bmp[30];
	char *str;

	str = (char *)malloc(4 * sizeof(char));

	for(ii=0; ii<=526; ii++)
		tab_pyt[ii] = 0;
	tab_pyt[0] = 1;

	for(ii=0; ii<18; ii++)
	{
		odpow[ii].numer_pytania = 0;
		odpow[ii].odpA = ' ';
		odpow[ii].odpB = ' ';
		odpow[ii].odpC = ' ';
	}

	while(TRUE)
	{
		zaznaczone[1] = 0;
		zaznaczone[2] = 0;
		zaznaczone[3] = 0;

		odpowiedz2[0] = 0;
		odpowiedz2[1] = 0;
		odpowiedz2[2] = 0;

		if(mode == 0)
		{
			if(numer+1 > do_pytania)
				break;
			else
				numer++;
		}
		else if(mode == 1)
		{
			if(licznik+1 > 18)
				break;

			do
			{
				numer = rand()%((do_pytania-od_pytania)+1) + od_pytania;
				if(numer > *liczba_pytan || numer < 1)
					numer = 0;
			}
			while(tab_pyt[numer] == 1);
		}
		else if(mode == 2)
		{
			if(licznik > do_pytania - od_pytania)
				break;

			do
			{
				numer = rand()%((do_pytania-od_pytania)+1) + od_pytania;
				if(numer > *liczba_pytan || numer < 1)
					numer = 0;
			}
			while(tab_pyt[numer] == 1);
		}
		tab_pyt[numer] = 1;

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

		clear_key();
		aktywny = 1;
		clear_to_color(bufor_glowny, COLOR_TLA);

		obrazek = NULL;
		obrazek = load_bmp(plik_bmp, default_palette);

		wczytaj_pytanie(plik_txt, pytanie, odpa, odpb, odpc, odpowiedz);

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

			if(mode == 1)
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH, 5, makecol(255, 255, 255), -1, "%d z 18", licznik+1);
			else
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH, 5, makecol(255, 255, 255), -1, "%d z %d", licznik+1, do_pytania-od_pytania+1);
			
			blit(przycisk_l, bufor_glowny, 0, 0, 0, 0, przycisk_l->w, przycisk_l->h);
			textprintf_ex(bufor_glowny, font, przycisk_l->w, 6, makecol(255, 255, 255), -1, "Pomoc");
			
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

			if(key[KEY_ENTER])
			{
				clear_key();
				int l = 0;
				int status;
				if(zaznaczone[1] == 1)
				{
					odpowiedz2[l] = 'a';
					l++;
				}
				if(zaznaczone[2] == 1)
				{
					odpowiedz2[l] = 'b';
					l++;
				}
				if(zaznaczone[3] == 1)
				{
					odpowiedz2[l] = 'c';
					l++;
				}
				odpowiedz2[l] = '\0';

				status = strcmp(odpowiedz, odpowiedz2);

				if(status == 0)
					poprawnie++;

				if(mode != 3)
					info(status, SCREEN_HEIGHT - wysokosc_belek, odpowiedz);
				
				if(obrazek != NULL)
					destroy_bitmap(obrazek);
				break;
			}
			
			if(key[KEY_LSHIFT])
			{
				pomoc_nauka();
			}

			if(obrazek != NULL)
			{
			#if PSP
				if(key[KEY_RSHIFT])
			#else
				if(key[KEY_M])
			#endif
				{
					clear_key();
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

			if(key[KEY_ESC])
			{
				koniec = 1;
				break;
			}

			clear_key();
			keypressed();
			x = x_old;
			rest(60);
		}
		licznik++;

		if(koniec == 1)
			break;
	}

	if(mode != 3)
	{
		if(licznik == 0)
			podsumowanie(poprawnie, licznik);
		else
		{
			if(koniec == 0)
				podsumowanie(poprawnie, licznik);
			else if(koniec == 1)
				podsumowanie(poprawnie, licznik-1);
		}
	}

	free(str);

	return poprawnie;
}
