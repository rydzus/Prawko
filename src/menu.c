/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"

int menu(char *kategoria, int *liczba_pytan)
{
	BITMAP *tlo = prawko_load_bitmap("grafika/tlo.bmp");
	BITMAP *kategoria_bmp = create_bitmap(1, 1);
	BITMAP *dodatek = create_bitmap(1, 1);
	BITMAP *pytania = create_bitmap(1, 1);
	BITMAP *pytania_statyczne = create_bitmap(1, 1);
	BITMAP *losowe = prawko_load_bitmap("grafika/losowe.bmp");
	BITMAP *egzamin = prawko_load_bitmap("grafika/egzamin.bmp");
	BITMAP *oprogramie = prawko_load_bitmap("grafika/oprogramie.bmp");
	BITMAP *wyjscie = prawko_load_bitmap("grafika/wyjscie.bmp");
	
	static int aktywny = 0;
	int wczytaj = 2;

	while(TRUE)
	{
		if(wczytaj == 1 || wczytaj == 2)
		{
			if(wczytaj == 1)
			{
				destroy_bitmap(kategoria_bmp);
				destroy_bitmap(dodatek);
				destroy_bitmap(pytania);
				destroy_bitmap(pytania_statyczne);
			}
			
			switch(*kategoria)
			{
				case 'a':
					kategoria_bmp = prawko_load_bitmap("grafika/A/kategoria.bmp");
					dodatek = prawko_load_bitmap("grafika/A/dodatek.bmp");
					pytania = prawko_load_bitmap("grafika/A/pytania.bmp");
					pytania_statyczne = prawko_load_bitmap("grafika/A/pytania_statyczne.bmp");
					wczytaj = 0;
					*liczba_pytan = 60;
				break;
				case 'b':
					kategoria_bmp = prawko_load_bitmap("grafika/B/kategoria.bmp");
					dodatek = prawko_load_bitmap("grafika/B/dodatek.bmp");
					pytania = prawko_load_bitmap("grafika/B/pytania.bmp");
					pytania_statyczne = prawko_load_bitmap("grafika/B/pytania_statyczne.bmp");
					wczytaj = 0;
					*liczba_pytan = 526;
				break;
				case 'c':
					kategoria_bmp = prawko_load_bitmap("grafika/C/kategoria.bmp");
					dodatek = prawko_load_bitmap("grafika/C/dodatek.bmp");
					pytania = prawko_load_bitmap("grafika/C/pytania.bmp");
					pytania_statyczne = prawko_load_bitmap("grafika/C/pytania_statyczne.bmp");
					wczytaj = 0;
					*liczba_pytan = 193;
				break;
				case 'd':
					kategoria_bmp = prawko_load_bitmap("grafika/D/kategoria.bmp");
					dodatek = prawko_load_bitmap("grafika/D/dodatek.bmp");
					pytania = prawko_load_bitmap("grafika/D/pytania.bmp");
					pytania_statyczne = prawko_load_bitmap("grafika/D/pytania_statyczne.bmp");
					wczytaj = 0;
					*liczba_pytan = 192;
				break;
				case 't':
					kategoria_bmp = prawko_load_bitmap("grafika/T/kategoria.bmp");
					dodatek = prawko_load_bitmap("grafika/T/dodatek.bmp");
					pytania = prawko_load_bitmap("grafika/T/pytania.bmp");
					pytania_statyczne = prawko_load_bitmap("grafika/T/pytania_statyczne.bmp");
					wczytaj = 0;
					*liczba_pytan = 61;
				break;	
			}
		}
			
		clear_to_color(bufor_glowny, COLOR_TLA);
		blit(tlo, bufor_glowny, 0, 0, 0, 0, tlo->w, tlo->h);
		blit(kategoria_bmp, bufor_glowny, 0, 0, 52, 36, kategoria_bmp->w, kategoria_bmp->h);
		blit(dodatek, bufor_glowny, 0, 0, 300, 149, dodatek->w, dodatek->h);
		blit(pytania_statyczne, bufor_glowny, 0, 0, 288, 52, pytania_statyczne->w, pytania_statyczne->h);
		
		if(aktywny == 0)
			blit(pytania, bufor_glowny, 0, 0, 288, 52, pytania->w, pytania->h);
		else if(aktywny == 1)
			blit(losowe, bufor_glowny, 0, 0, 244, 91, losowe->w, losowe->h);
		else if(aktywny == 2)
			blit(egzamin, bufor_glowny, 0, 0, 197, 132, egzamin->w, egzamin->h);
		else if(aktywny == 3)
			blit(oprogramie, bufor_glowny, 0, 0, 148, 171, oprogramie->w, oprogramie->h);
		else if(aktywny == 4)
			blit(wyjscie, bufor_glowny, 0, 0, 106, 209, wyjscie->w, wyjscie->h);
		
		if(key[KEY_UP])
		{
			if(aktywny-1 > -1)
				aktywny--;
			else
				aktywny = 4;
		}
		else if(key[KEY_DOWN])
		{
			if(aktywny+1 < 5)
				aktywny++;
			else
				aktywny = 0;
		}
		else if(key[KEY_RIGHT])
		{
			if((*kategoria)+1 < 'a'+4)
			{
				(*kategoria)++;
				wczytaj = 1;
			}
			else if(*kategoria == 'd')
			{
				*kategoria = 't';
				wczytaj = 1;
			}
			
		}
		else if(key[KEY_LSHIFT])
		{
			pomoc_menu(*liczba_pytan);
		}
		else if(key[KEY_LEFT])
		{
			if(*kategoria == 't')
			{
				*kategoria = 'd';
				wczytaj = 1;
			}
			else if((*kategoria)-1 > 'a'-1)
			{
				(*kategoria)--;
				wczytaj = 1;
			}
		}
		else if(key[KEY_SPACE] || key[KEY_ENTER])
		{
			break;
		}
		
		blit(przycisk_ln, bufor_glowny, 0, 0, 10, 243, przycisk_ln->w, przycisk_ln->h);
		textprintf_ex(bufor_glowny, font, 10+przycisk_l->w, 249, makecol(255, 255, 255), -1, "Pomoc");
		
		blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);

		clear_key();
		keypressed();
		rest(60);
	}

	destroy_bitmap(tlo);
	destroy_bitmap(kategoria_bmp);
	destroy_bitmap(dodatek);
	destroy_bitmap(pytania);
	destroy_bitmap(pytania_statyczne);
	destroy_bitmap(losowe);
	destroy_bitmap(egzamin);
	destroy_bitmap(oprogramie);
	destroy_bitmap(wyjscie);

	return aktywny;
}
