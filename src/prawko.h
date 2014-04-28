/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include <stdio.h>
#include <string.h>
#include <allegro.h>

#define SCREEN_WIDTH 478
#define SCREEN_HEIGHT 272

#define FONT_HEIGHT 12
#define PRZESTRZEN 5
#define LICZBA_SLOW_W_LINI 59

/* Kolory dla pytania */
#define COLOR_PYT_TLA makecol(68, 86, 0)
#define COLOR_PYT_OBR makecol(200, 255, 0)
#define COLOR_PYT_SZKLA makecol(111, 124, 58)
/* Kolory dla odpowiedzi zwyklej */
#define COLOR_ODP_ZWY_TLA makecol(77, 77, 77)
#define COLOR_ODP_ZWY_OBR makecol(209, 209, 209)
#define COLOR_ODP_ZWY_SZKLA makecol(117, 117, 117)
/* Kolory dla odpowiedzi zaznaczonej */
#define COLOR_ODP_ZAZ_TLA makecol(23, 92, 135)
#define COLOR_ODP_ZAZ_OBR makecol(101, 194, 252)
#define COLOR_ODP_ZAZ_SZKLA makecol(74, 129, 162)
/* Kolor obramowania dla odpowiedzi aktywnej */
#define COLOR_ODP_AKT_OBR makecol(255, 0, 0)
/* Kolory dla poprawnej odpowiedzi */
#define COLOR_ODP_POP_TLA makecol(52, 110, 52)
#define COLOR_ODP_POP_OBR makecol(114, 238, 144)
#define COLOR_ODP_POP_SZKLA makecol(98, 143, 98)
/* Kolory dla niepoprawnej odpowiedzi */
#define COLOR_ODP_NOP_TLA makecol(151, 14, 14)
#define COLOR_ODP_NOP_OBR makecol(255, 0, 0)
#define COLOR_ODP_NOP_SZKLA makecol(175, 69, 69)
/* Kolor tla dla ekranu */
#define COLOR_TLA makecol(26, 26, 26)
#define COLOR_OBR makecol(58, 58, 58)

typedef struct Odpowiedz
{
	int numer_pytania;
	char odpA;
	char odpB;
	char odpC;
} Odpowiedzi;

BITMAP *bufor_glowny;
BITMAP *przycisk_x;
BITMAP *przycisk_kw;
BITMAP *przycisk_tr;
BITMAP *przycisk_o;
BITMAP *przycisk_l;
BITMAP *przycisk_ln;
BITMAP *przycisk_r;
BITMAP *przycisk_st;
BITMAP *przycisk_se;
/* Zastapic jedna strzelka i funkcja ja obracac */
BITMAP *przycisk_strzalka_l;
BITMAP *przycisk_strzalka_g;
BITMAP *przycisk_strzalka_p;
BITMAP *przycisk_strzalka_d;

void init_allegro();
void deinit_allegro();
void prawko_blad(char *fmt, ...);
BITMAP* prawko_load_bitmap(char *bitmapa);

void clear_key();
int menu(char *kategoria, int *liczba_pytan);
int nauka(int mode, int od_pytania, int do_pytania, char *kategoria, int *liczba_pytan, Odpowiedzi *odpow);
int liczba_wierszy(char *napis);
void wczytaj_pytanie(char *nazwa_pliku, char *pytanie, char *odpa, char *odpb, char *odpc, char *odpowiedz);
void info(int status, int y, char *odpowiedz);
void podsumowanie(int poprawnie, int wszystkich);
void oprogramie();
void wybor(int *od_pytania, int *do_pytania, char *znak, int *liczba_pytan);
int egzamin(int mode, int od_pytania, int do_pytania, char *kategoria, int *liczba_pytan, Odpowiedzi *odpow);

void podsumowanie_egzaminu(int poprawnie, char kategoria, Odpowiedzi *odpow);
int rysuj_belki(int x, char *napis, int color_tla, int color_obramowania, int color_szkla);
int rysuj_belki2(int x, char *napis, int color_tla, int color_tla_szkla, int color_obramowania, int color_pop_tla, int color_pop_szkla);
int prezentacja(char kategoria, int numer_pytania, Odpowiedzi *odpw);
void info2(int status, int y);

void pomoc_nauka();
void pomoc_egzamin();
void pomoc_prezentacja();
void pomoc_menu(int liczba_pytan);
void pomoc_wybor();
void pomoc_podsumowanie();
void pomoc_podsumowanie_egzaminu();
