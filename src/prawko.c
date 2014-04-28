/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

#include "prawko.h"

int main(void)
{
	init_allegro();
	srand(time(NULL));

	bufor_glowny = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
	clear_to_color(bufor_glowny, COLOR_TLA);
	textprintf_ex(bufor_glowny, font, 144, 100, makecol(255, 255, 255), -1, "Andrzej \"rydz\" Rydzewski");
	textprintf_ex(bufor_glowny, font, 236, 120, makecol(255, 255, 255), -1, "i");
	textprintf_ex(bufor_glowny, font, 196, 140, makecol(255, 255, 255), -1, "PSPoland.pl");
	textprintf_ex(bufor_glowny, font, 196, 170, makecol(255, 0, 0), -1, "prezentują");
	blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);

	przycisk_x = prawko_load_bitmap("grafika/przyciski/x.bmp");
	przycisk_kw = prawko_load_bitmap("grafika/przyciski/kw.bmp");
	przycisk_tr = prawko_load_bitmap("grafika/przyciski/tr.bmp");
	przycisk_o = prawko_load_bitmap("grafika/przyciski/o.bmp");
	przycisk_l = prawko_load_bitmap("grafika/przyciski/l.bmp");
	przycisk_ln = prawko_load_bitmap("grafika/przyciski/ln.bmp");
	przycisk_r = prawko_load_bitmap("grafika/przyciski/r.bmp");
	przycisk_st = prawko_load_bitmap("grafika/przyciski/st.bmp");
	przycisk_se = prawko_load_bitmap("grafika/przyciski/se.bmp");
	przycisk_strzalka_l = prawko_load_bitmap("grafika/przyciski/lewo.bmp");
	przycisk_strzalka_g = prawko_load_bitmap("grafika/przyciski/gora.bmp");
	przycisk_strzalka_p = prawko_load_bitmap("grafika/przyciski/prawo.bmp");
	przycisk_strzalka_d = prawko_load_bitmap("grafika/przyciski/dol.bmp");
	sleep(1);

	int aktywny;
	int od_pytania;
	int do_pytania;
	int liczba_pytan = 526;
	char znak;
	static char kategoria = 'b';
	Odpowiedzi odpow[18];
	int poprawnie;

	do
	{
		aktywny = menu(&kategoria, &liczba_pytan);
		switch(aktywny)
		{
			case 0:
				wybor(&od_pytania, &do_pytania, &znak, &liczba_pytan);
				nauka((znak == ' ') ? 0 : 2, od_pytania, do_pytania, &kategoria, &liczba_pytan, odpow);
			break;
			case 1:
				nauka(1, 1, liczba_pytan, &kategoria, &liczba_pytan, odpow);
			break;
			case 2:
				poprawnie = egzamin(3, 1, liczba_pytan, &kategoria, &liczba_pytan, odpow);
				podsumowanie_egzaminu(poprawnie, kategoria, odpow);
			break;
			case 3:
				oprogramie();
			break;
		}
		clear_key();
	}
	while(aktywny != 4);

	destroy_bitmap(bufor_glowny);
	deinit_allegro();

	return 0;
}
END_OF_MAIN()


void init_allegro()
{
	if(allegro_init() != 0)
		prawko_blad("Błąd instalizacji allegro");

	if(install_keyboard() != 0)
		prawko_blad("Błąd instalizacji klawiatury");

	if(install_timer() != 0)
		prawko_blad("Błąd instalizacji zegara");

	set_color_depth(32);
#ifdef PSP
	if(set_gfx_mode(GFX_AUTODETECT, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0) != 0)
#else
	if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0) != 0)
#endif
		prawko_blad("Błąd instalizacji grafiki");
}

void deinit_allegro()
{
	allegro_exit();
}

void prawko_blad(char *fmt, ...)
{
	FILE *plik_blad;
	
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	plik_blad = fopen("blad.txt", "a+");
	if(plik_blad == NULL)
	{
		fclose(plik_blad);
		exit(2);
	}
	
	va_start(ap, fmt);
	for(p = fmt; *p; p++)
	{
		if(*p != '%')
		{
			fputc(*p, plik_blad);
			continue;
		}
		
		switch(*++p)
		{
			case 'd':
				ival = va_arg(ap, int);
				fprintf(plik_blad, "%d", ival);
			break;
			case 'f':
				dval = va_arg(ap, double);
				fprintf(plik_blad, "%f", dval);
			break;
			case 's':
				for(sval = va_arg(ap, char *); *sval; sval++)
					fputc(*sval, plik_blad);
			break;
		}
	}
	fprintf(plik_blad, "\n");
	
	fclose(plik_blad);
	exit(1);
}

BITMAP* prawko_load_bitmap(char *bitmapa)
{
	BITMAP *tmp;
	
	tmp = load_bitmap(bitmapa, default_palette);
	
	if(tmp == NULL)
	{
		prawko_blad("Błąd bladowania pliku graficznego: %s", bitmapa);
		exit(2);
	}
	
	return tmp;
}
