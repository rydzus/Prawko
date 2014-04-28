/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"

int liczba_wierszy(char *napis)
{
	int i = 0;
	int j = 0;
	char bufor[300] = "";
	char bufor_slowo[30];
	int mnoznik = 0;

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
					++mnoznik;
				}
				else
				{
					++mnoznik;
					++mnoznik;
				}
			}
		}
		else
		{
			bufor_slowo[j] = '\0';
			j = 0;

			if(!(strcmp(bufor_slowo, "\n")))
			{
				++mnoznik;
				strcpy(bufor, "");
			}
			else
			{
				if((strlen(bufor)+strlen(bufor_slowo)) < LICZBA_SLOW_W_LINI)
				{
					strcat(bufor, bufor_slowo);
					strcat(bufor, " ");
					if(napis[i+1] == '\0')
						++mnoznik;
				}
				else
				{
					++mnoznik;

					if(napis[i+1] != '\0')
					{
						strcpy(bufor, bufor_slowo);
						strcat(bufor, " ");
						if(napis[i+1] == '\0')
							++mnoznik;
					}
					else
						++mnoznik;
				}
			}
		}
		i++;
	}

	return mnoznik;
}
