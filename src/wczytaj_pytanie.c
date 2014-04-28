/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"

void wczytaj_pytanie(char *nazwa_pliku, char *pytanie, char *odpa, char *odpb, char *odpc, char *odpowiedz)
{
	FILE *plik;
	char bufor[300];
	char c;
	int licznik;


	if((plik = fopen(nazwa_pliku, "r")) == NULL)
	{
		printf("%s\n", nazwa_pliku);
		prawko_blad("Błąd w ładowaniu pliku z pytaniem: %s", nazwa_pliku);
	}

	licznik = 0;
	while((c = fgetc(plik)) != '\n')
	{
		bufor[licznik] = c;
		licznik++;
	}
	bufor[licznik] = '\0';
	strcpy(pytanie, bufor);


	licznik = 0;
	while((c = fgetc(plik)) != '\n')
	{
		bufor[licznik] = c;
		licznik++;
	}
	bufor[licznik] = '\0';
	strcpy(odpa, bufor);


	licznik = 0;
	while((c = fgetc(plik)) != '\n')
	{
		bufor[licznik] = c;
		licznik++;
	}
	bufor[licznik] = '\0';
	strcpy(odpb, bufor);


	licznik = 0;
	while((c = fgetc(plik)) != '\n')
	{
		bufor[licznik] = c;
		licznik++;
	}
	bufor[licznik] = '\0';
	strcpy(odpc, bufor);


	licznik = 0;
	while((c = fgetc(plik)) != '\n' && (c != EOF))
	{
		bufor[licznik] = c;
		licznik++;
	}
	bufor[licznik] = '\0';
	strcpy(odpowiedz, bufor);

	fclose(plik);
}
