/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"
#include <string.h>

/* Funkcja rysuje belke o i napis jaki jej przekazemy
 * Pierwsza zmienna to od jakiej wysokosci ma byc rysowana belka
 * Druga zmienna to wskaznik na napis jaki funkcja ma narysowac
 * Trzecia zmienna to kolor tla belki
 * Czwarta zmienna to kolor obramowania belki
 */
int rysuj_belki(int x, char *napis, int color_tla, int color_obramowania, int color_szkla)
{
	/* Zmienna potrzebna do przetrzymania liczby wierszy z napisu */
	int mnoznik;
	int x_t = x;
	int i = 0;
	int j = 0;
	char bufor[300] = "";
	char bufor_slowo[30];

	mnoznik = liczba_wierszy(napis);

	/* Rysowanie tla belki zaczynamy od y = 0, x = zmiennej x przekazanej przez funkcje
	 * rysujemy do 480 - 2, x + wysokosc_czcionki pomnozona przez liczbe wierzy
	 * Na koniec podajemy kolor tla przekazany przez funkcje
	 */
	rectfill(bufor_glowny, 0, x, SCREEN_WIDTH-2, x + (FONT_HEIGHT * mnoznik), color_tla);
	/* Po tle belki rysujemy szklo */
	rectfill(bufor_glowny, 1, x+1, SCREEN_WIDTH-3, x + (FONT_HEIGHT * mnoznik)/2, color_szkla);
	/* Rysowanie obramowania, zasada taka sama jak przy rysowaniu tla bleki */
	rect(bufor_glowny, 0, x, SCREEN_WIDTH-2, x + (FONT_HEIGHT * mnoznik), color_obramowania);


	if(mnoznik == 1)
	{
		textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", napis);
	}
	else
	{
		while(napis[i] != '\0')
		{
			if(napis[i] != ' ')
			{
				bufor_slowo[j] = napis[i];
				++j;

				if(napis[i+1] == '\0')
				{
					bufor_slowo[j] = '\0';
					if((strlen(bufor)+strlen(bufor_slowo)+1) < LICZBA_SLOW_W_LINI)
					{
						strcat(bufor, bufor_slowo);
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
					}
					else
					{
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
						x_t += FONT_HEIGHT;
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor_slowo);
					}
				}
			}
			else
			{
				bufor_slowo[j] = '\0';
				j = 0;

				if(!(strcmp(bufor_slowo, "\n")))
				{
					textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
					x_t += FONT_HEIGHT;
					strcpy(bufor, "");
				}
				else if(napis[i+1] == '\0')
				{
					if((strlen(bufor)+strlen(bufor_slowo)+1) < LICZBA_SLOW_W_LINI)
					{
						strcat(bufor, bufor_slowo);
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
					}
					else
					{
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
						x_t += FONT_HEIGHT;
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor_slowo);
					}
				}
				else
				{
					if((strlen(bufor)+strlen(bufor_slowo)) < LICZBA_SLOW_W_LINI)
					{
						strcat(bufor, bufor_slowo);
						strcat(bufor, " ");
					}
					else
					{
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
						x_t += FONT_HEIGHT;

						if(napis[i+1] != '\0')
						{
							strcpy(bufor, bufor_slowo);
							strcat(bufor, " ");
						}
						else
							textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor_slowo);
					}
				}
			}
			i++;
		}
	}

	/* Dodaje do zmiennej wysokosc belki i przestrzen miedzy belkami */
	return x + (FONT_HEIGHT * mnoznik) + PRZESTRZEN;
}


int rysuj_belki2(int x, char *napis, int color_tla, int color_tla_szkla, int color_obramowania, int color_pop_tla, int color_pop_szkla)
{
	int mnoznik;
	int x_t = x;
	int i = 0;
	int j = 0;
	char bufor[300] = "";
	char bufor_slowo[30];

	mnoznik = liczba_wierszy(napis);

	rectfill(bufor_glowny, 0, x, SCREEN_WIDTH-2, x + (FONT_HEIGHT * mnoznik), color_tla);
	rectfill(bufor_glowny, 1, x+1, SCREEN_WIDTH-2, x + (FONT_HEIGHT * mnoznik)/2, color_tla_szkla);
	rectfill(bufor_glowny, 0, x, 239, x + (FONT_HEIGHT * mnoznik), color_pop_tla);
	rectfill(bufor_glowny, 1, x+1, 239, x + (FONT_HEIGHT * mnoznik)/2, color_pop_szkla);
	rect(bufor_glowny, 0, x, SCREEN_WIDTH-2, x + (FONT_HEIGHT * mnoznik), color_obramowania);

	if(mnoznik == 1)
	{
		textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", napis);
	}
	else
	{
		while(napis[i] != '\0')
		{
			if(napis[i] != ' ')
			{
				bufor_slowo[j] = napis[i];
				++j;

				if(napis[i+1] == '\0')
				{
					bufor_slowo[j] = '\0';
					if((strlen(bufor)+strlen(bufor_slowo)+1) < LICZBA_SLOW_W_LINI)
					{
						strcat(bufor, bufor_slowo);
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
					}
					else
					{
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
						x_t += FONT_HEIGHT;
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor_slowo);
					}
				}
			}
			else
			{
				bufor_slowo[j] = '\0';
				j = 0;

				if(!(strcmp(bufor_slowo, "\n")))
				{
					textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
					x_t += FONT_HEIGHT;
					strcpy(bufor, "");
				}
				else if(napis[i+1] == '\0')
				{
					if((strlen(bufor)+strlen(bufor_slowo)+1) < LICZBA_SLOW_W_LINI)
					{
						strcat(bufor, bufor_slowo);
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
					}
					else
					{
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
						x_t += FONT_HEIGHT;
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor_slowo);
					}
				}
				else
				{
					if((strlen(bufor)+strlen(bufor_slowo)) < LICZBA_SLOW_W_LINI)
					{
						strcat(bufor, bufor_slowo);
						strcat(bufor, " ");
					}
					else
					{
						textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor);
						x_t += FONT_HEIGHT;

						if(napis[i+1] != '\0')
						{
							strcpy(bufor, bufor_slowo);
							strcat(bufor, " ");
						}
						else
							textprintf_ex(bufor_glowny, font, 5, x_t+3, makecol(255, 255, 255), -1, "%s", bufor_slowo);
					}
				}
			}
			i++;
		}
	}

	return x + (FONT_HEIGHT * mnoznik) + PRZESTRZEN;
}
