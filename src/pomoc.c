/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"

void pomoc_nauka()
{
int x;
	/* Odstep tekstu od przycisku */
	int separator_poziomy = 5;
	/* Odstep miedzy przyciskami */
	int separator_pionowy = 10;
	/* Aktywna karta */
	int karta = 1;
	
	BITMAP *obr1 = prawko_load_bitmap("grafika/help/zwykla_odpowiedz.bmp");
	BITMAP *obr2 = prawko_load_bitmap("grafika/help/aktywana_odpowiedz.bmp");
	BITMAP *obr3 = prawko_load_bitmap("grafika/help/zaz_odpowiedz.bmp");
	BITMAP *obr4 = prawko_load_bitmap("grafika/help/pop_odpowiedz.bmp");
	BITMAP *obr5 = prawko_load_bitmap("grafika/help/info_o_zle_odpowiedzi.bmp");
	
	clear_key();
	
	while(TRUE)
	{
		clear_to_color(bufor_glowny, COLOR_TLA);
		
		switch(karta)
		{
			case 1:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Opis");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 3);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				/* Wlasciwy moment na stawienie pomocy */
				x = FONT_HEIGHT+30;

				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Zaznacz prawidłowe odpowiedzi.");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedź zwykłą, aktywną i zaznaczoną można rozróżnić");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "po kolorze.");
				x += FONT_HEIGHT+15;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedź zwykła wyświetlona jest na kolor szary");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "z szarym obramowaniem.");
				x += FONT_HEIGHT-2;
				blit(obr1, bufor_glowny, 0, 0, 0, x, obr1->w, obr1->h);
				x += 15+obr1->h;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedź aktywna wyróżniona została czerwonym obramowaniem.");
				x += FONT_HEIGHT-2;
				blit(obr2, bufor_glowny, 0, 0, 0, x, obr2->w, obr2->h);
				x += 15+obr2->h;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedź zaznaczona (wybrana) wyróżniona jest tym,");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "że jej tło posiada kolor niebieski.");
				x += FONT_HEIGHT-2;
				blit(obr3, bufor_glowny, 0, 0, 0, x, obr3->w, obr3->h);
				x += 15+obr3->h;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, SCREEN_WIDTH-przycisk_strzalka_p->w-1, 250, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-przycisk_strzalka_p->w-3, 256, makecol(255, 255, 255), -1, "Następna karta");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 333, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 334, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 335, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
			case 2:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Opis");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 3);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				
				/* Wlasciwy moment na stawienie pomocy */
				x = 70;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Przyskiem START zatwierdza się odpowiedzi.");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Po jego wciśnięciu zostanie wyświetlona informacja");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "o tym czy dana odpowiedź jest:");
				x += 15+FONT_HEIGHT-2;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "prawidłowa:");
				x += FONT_HEIGHT-2;
				blit(obr4, bufor_glowny, 0, 0, 0, x, obr4->w, obr4->h);
				x += 15+obr4->h;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "błędna, dodatkowo program podaje prawidłową odpowiedź");
				x += FONT_HEIGHT-2;
				blit(obr5, bufor_glowny, 0, 0, 0, x, obr5->w, obr5->h);
				x += 15+obr5->h;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, 250, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+3, 256, makecol(255, 255, 255), -1, "Poprzednia karta");
				
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, SCREEN_WIDTH-przycisk_strzalka_p->w-1, 250, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-przycisk_strzalka_p->w-3, 256, makecol(255, 255, 255), -1, "Następna karta");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 154, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 155, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 156, 254, 266, makecol(48, 48, 48));
				
				vline(bufor_glowny, 333, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 334, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 335, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
			case 3:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Klawiszologia");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 3);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				
				/* Wlasciwy moment na stawienie pomocy */
				x = 40;

				blit(przycisk_l, bufor_glowny, 0, 0, 0, x, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Pomoc");
				x += przycisk_l->h + separator_pionowy;
			
				blit(przycisk_r, bufor_glowny, 0, 0, 0, x, przycisk_r->w, przycisk_r->h);
				textprintf_ex(bufor_glowny, font, przycisk_r->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Powiększenie obrazka");
				x += przycisk_r->h + separator_pionowy;
				
				blit(przycisk_strzalka_g, bufor_glowny, 0, 0, 0, x, przycisk_strzalka_g->w, przycisk_strzalka_g->h);
				blit(przycisk_strzalka_d, bufor_glowny, 0, 0, przycisk_strzalka_g->w, x, przycisk_strzalka_d->w, przycisk_strzalka_d->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_g->w+przycisk_strzalka_d->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Wybór odpowiedzi");
				x += przycisk_strzalka_g->h + separator_pionowy;
			
				blit(przycisk_x, bufor_glowny, 0, 0, 7, x, przycisk_x->w, przycisk_x->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+8, makecol(255, 255, 255), -1, "Zaznaczenie odpowiedzi");
				x += przycisk_x->h + separator_pionowy;
			
				blit(przycisk_st, bufor_glowny, 0, 0, 0, x, przycisk_st->w, przycisk_st->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Zatwierdzenie odpowiedzi");
				x += przycisk_st->h + separator_pionowy;
			
				blit(przycisk_se, bufor_glowny, 0, 0, 0, x, przycisk_se->w, przycisk_se->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Zakończenie nauki");
				x += przycisk_se->h + separator_pionowy;

				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, 250, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+3, 256, makecol(255, 255, 255), -1, "Poprzednia karta");
				
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 154, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 155, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 156, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
		}
		
		if(key[KEY_LSHIFT])
			break;
		else if(key[KEY_LEFT])
		{
			if(karta-1 > 0)
				karta--;
		}
		else if(key[KEY_RIGHT])
		{
			if(karta+1 < 4)
				karta++;
		}
		
		clear_key();
		keypressed();
		rest(60);
	}
	
	destroy_bitmap(obr1);
	destroy_bitmap(obr2);
	destroy_bitmap(obr3);
	destroy_bitmap(obr4);
	destroy_bitmap(obr5);
}

void pomoc_egzamin()
{
	int x;
	/* Odstep tekstu od przycisku */
	int separator_poziomy = 5;
	/* Odstep miedzy przyciskami */
	int separator_pionowy = 10;
	/* Aktywna karta */
	int karta = 1;
	
	BITMAP *obr1 = prawko_load_bitmap("grafika/help/zwykla_odpowiedz.bmp");
	BITMAP *obr2 = prawko_load_bitmap("grafika/help/aktywana_odpowiedz.bmp");
	BITMAP *obr3 = prawko_load_bitmap("grafika/help/zaz_odpowiedz.bmp");
	
	clear_key();
	
	while(TRUE)
	{
		clear_to_color(bufor_glowny, COLOR_TLA);
		
		switch(karta)
		{
			case 1:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Opis");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				/* Wlasciwy moment na stawienie pomocy */
				x = FONT_HEIGHT+30;

				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Zaznacz prawidłowe odpowiedzi.");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedź zwykłą, aktywną i zaznaczoną można rozróżnić");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "po kolorze.");
				x += FONT_HEIGHT+15;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedź zwykła wyświetlona jest na kolor szary");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "z szarym obramowaniem.");
				x += FONT_HEIGHT-2;
				blit(obr1, bufor_glowny, 0, 0, 0, x, obr1->w, obr1->h);
				x += 15+obr1->h;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedź aktywna wyróżniona została czerwonym obramowaniem.");
				x += FONT_HEIGHT-2;
				blit(obr2, bufor_glowny, 0, 0, 0, x, obr2->w, obr2->h);
				x += 15+obr2->h;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedź zaznaczona (wybrana) wyróżniona jest tym,");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "że jej tło posiada kolor niebieski.");
				x += FONT_HEIGHT-2;
				blit(obr3, bufor_glowny, 0, 0, 0, x, obr3->w, obr3->h);
				x += 15+obr3->h;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, SCREEN_WIDTH-przycisk_strzalka_p->w-1, 250, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-przycisk_strzalka_p->w-3, 256, makecol(255, 255, 255), -1, "Następna karta");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 333, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 334, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 335, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
			case 2:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Klawiszologia");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				
				/* Wlasciwy moment na stawienie pomocy */
				x = 25;

				blit(przycisk_l, bufor_glowny, 0, 0, 0, x, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Pomoc");
				x += przycisk_l->h + separator_pionowy;
			
				blit(przycisk_r, bufor_glowny, 0, 0, 0, x, przycisk_r->w, przycisk_r->h);
				textprintf_ex(bufor_glowny, font, przycisk_r->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Powiększenie obrazka");
				x += przycisk_r->h + separator_pionowy;
				
				
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, x, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, przycisk_strzalka_l->w, x, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+przycisk_strzalka_p->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Przełączanie się między odpowiedziami");
				x += przycisk_strzalka_l->h + separator_pionowy;
				
				blit(przycisk_strzalka_g, bufor_glowny, 0, 0, 0, x, przycisk_strzalka_g->w, przycisk_strzalka_g->h);
				blit(przycisk_strzalka_d, bufor_glowny, 0, 0, przycisk_strzalka_g->w, x, przycisk_strzalka_d->w, przycisk_strzalka_d->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_g->w+przycisk_strzalka_d->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Wybór odpowiedzi");
				x += przycisk_strzalka_g->h + separator_pionowy;
			
				blit(przycisk_x, bufor_glowny, 0, 0, 7, x, przycisk_x->w, przycisk_x->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+8, makecol(255, 255, 255), -1, "Zaznaczenie odpowiedzi");
				x += przycisk_x->h + separator_pionowy;
			
				blit(przycisk_st, bufor_glowny, 0, 0, 0, x, przycisk_st->w, przycisk_st->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Zatwierdzenie odpowiedzi");
				x += przycisk_st->h + separator_pionowy;
			
				blit(przycisk_se, bufor_glowny, 0, 0, 0, x, przycisk_se->w, przycisk_se->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Zakończenie egzaminu");
				x += przycisk_se->h + separator_pionowy;

				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, 250, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+3, 256, makecol(255, 255, 255), -1, "Poprzednia karta");
				
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 154, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 155, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 156, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
		}
		
		if(key[KEY_LSHIFT])
			break;
		else if(key[KEY_LEFT])
		{
			if(karta-1 > 0)
				karta--;
		}
		else if(key[KEY_RIGHT])
		{
			if(karta+1 < 3)
				karta++;
		}
		
		clear_key();
		keypressed();
		rest(60);
	}
	
	destroy_bitmap(obr1);
	destroy_bitmap(obr2);
	destroy_bitmap(obr3);
}

void pomoc_prezentacja()
{
	int x;
	/* Odstep tekstu od przycisku */
	int separator_poziomy = 5;
	/* Odstep miedzy przyciskami */
	int separator_pionowy = 10;
	/* Aktywna karta */
	int karta = 1;
	
	BITMAP *obr1 = prawko_load_bitmap("grafika/help/pomoc_prezentacja.bmp");
	
	clear_key();
	
	while(TRUE)
	{
		clear_to_color(bufor_glowny, COLOR_TLA);
		
		switch(karta)
		{
			case 1:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Opis");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				/* Wlasciwy moment na stawienie pomocy */
				x = FONT_HEIGHT+25;

				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Ekran informuje jakie odpowiedzi są poprawne a jakie");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "zostaly zaznaczone");
				x += FONT_HEIGHT+15;
				
				blit(obr1, bufor_glowny, 0, 0, 0, x, obr1->w, obr1->h);
				x += 15+obr1->h;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedzi poprawne zostały zaznaczone na zielono po");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "lewej stronie");
				x += 15+FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Odpowiedzi zaznaczone zostały umieszczone po prawej stronie i");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "wyświetlane sa na kolor niebieski");
				x += 15+FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Informacje na ekranie dodatkowo informuja czy zostały");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "zaznaczone poprawne odpowiedzi");
				x += FONT_HEIGHT-2;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, SCREEN_WIDTH-przycisk_strzalka_p->w-1, 250, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-przycisk_strzalka_p->w-3, 256, makecol(255, 255, 255), -1, "Następna karta");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 333, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 334, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 335, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
			case 2:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Klawiszologia");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				
				/* Wlasciwy moment na stawienie pomocy */
				x = 45;

				blit(przycisk_l, bufor_glowny, 0, 0, 0, x, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Pomoc");
				x += przycisk_l->h + separator_pionowy;
			
				blit(przycisk_r, bufor_glowny, 0, 0, 0, x, przycisk_r->w, przycisk_r->h);
				textprintf_ex(bufor_glowny, font, przycisk_r->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Powiększenie obrazka");
				x += przycisk_r->h + separator_pionowy;
				
				
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, x, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, przycisk_strzalka_l->w, x, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+przycisk_strzalka_p->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Przełączanie się między odpowiedziami");
				x += przycisk_strzalka_l->h + separator_pionowy;
			
				blit(przycisk_st, bufor_glowny, 0, 0, 0, x, przycisk_st->w, przycisk_st->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Przejście do następnego pytania");
				x += przycisk_st->h + separator_pionowy;
			
				blit(przycisk_se, bufor_glowny, 0, 0, 0, x, przycisk_se->w, przycisk_se->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Zakończenie prezentacji");
				x += przycisk_se->h + separator_pionowy;

				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, 250, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+3, 256, makecol(255, 255, 255), -1, "Poprzednia karta");
				
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 154, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 155, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 156, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
		}
		
		if(key[KEY_LSHIFT])
			break;
		else if(key[KEY_LEFT])
		{
			if(karta-1 > 0)
				karta--;
		}
		else if(key[KEY_RIGHT])
		{
			if(karta+1 < 3)
				karta++;
		}
		
		clear_key();
		keypressed();
		rest(60);
	}
	
	destroy_bitmap(obr1);
}

void pomoc_menu(int liczba_pytan)
{
	int x;
	/* Odstep tekstu od przycisku */
	int separator_poziomy = 5;
	/* Odstep miedzy przyciskami */
	int separator_pionowy = 10;
	/* Aktywna karta */
	int karta = 1;
	
	clear_key();
	
	while(TRUE)
	{
		clear_to_color(bufor_glowny, COLOR_TLA);
		
		switch(karta)
		{
			case 1:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Opis");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				/* Wlasciwy moment na stawienie pomocy */
				x = FONT_HEIGHT+30;
				
				if(liczba_pytan == 60)
					x = 7 + rysuj_belki(x, "60 pytań - możliwość wyboru dowolnego pytania z bazy pytań danej kategorii, wskazywanie błędów na bierząco", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
				else if(liczba_pytan == 526)
					x = 7 + rysuj_belki(x, "526 pytań - możliwość wyboru dowolnego pytania z bazy pytań danej kategorii, wskazywanie błędów na bierząco", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
				else if(liczba_pytan == 193)
					x = 7 + rysuj_belki(x, "193 pytań - możliwość wyboru dowolnego pytania z bazy pytań danej kategorii, wskazywanie błędów na bierząco", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
				else if(liczba_pytan == 192)
					x = 7 + rysuj_belki(x, "192 pytań - możliwość wyboru dowolnego pytania z bazy pytań danej kategorii, wskazywanie błędów na bierząco", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
				else if(liczba_pytan == 61)
					x = 7 + rysuj_belki(x, "61 pytań - możliwość wyboru dowolnego pytania z bazy pytań danej kategorii, wskazywanie błędów na bierząco", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
					
				
				x = 7 + rysuj_belki(x, "18 pytań - losowo wybrane osiemnaście pytań spośród zbioru pytań z danej kategorii", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
				x = 7 + rysuj_belki(x, "egzamin - 18 losowych pytań z danej kategorii, limit czasu 25 minut gdzie można popełnić tylko 2 błędy", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
				x = 7 + rysuj_belki(x, "O programie - informacje o programie m.in. wersja, autor itp.", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
				x = 7 + rysuj_belki(x, "Wyjście - wyjście z programu", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, SCREEN_WIDTH-przycisk_strzalka_p->w-1, 250, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-przycisk_strzalka_p->w-3, 256, makecol(255, 255, 255), -1, "Następna karta");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 333, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 334, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 335, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
			case 2:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Klawiszologia");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				
				/* Wlasciwy moment na stawienie pomocy */
				x = 45;

				blit(przycisk_l, bufor_glowny, 0, 0, 0, x, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Pomoc");
				x += przycisk_l->h + separator_pionowy;
			
				
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, x, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, przycisk_strzalka_l->w, x, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+przycisk_strzalka_p->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Przełączenie między kategoriami");
				x += przycisk_strzalka_l->h + separator_pionowy;
				
				blit(przycisk_strzalka_g, bufor_glowny, 0, 0, 0, x, przycisk_strzalka_g->w, przycisk_strzalka_g->h);
				blit(przycisk_strzalka_d, bufor_glowny, 0, 0, przycisk_strzalka_g->w, x, przycisk_strzalka_d->w, przycisk_strzalka_d->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_g->w+przycisk_strzalka_d->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Wybór opcji z menu");
				x += przycisk_strzalka_g->h + separator_pionowy;
			
				blit(przycisk_x, bufor_glowny, 0, 0, 3, x, przycisk_x->w, przycisk_x->h);
				blit(przycisk_st, bufor_glowny, 0, 0, przycisk_x->w+3, x+1, przycisk_st->w, przycisk_st->h);
				textprintf_ex(bufor_glowny, font, przycisk_x->w+przycisk_st->w+separator_poziomy, x+8, makecol(255, 255, 255), -1, "Zatwierdzenie opcji z menu");
				x += przycisk_x->h + separator_pionowy;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, 250, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+3, 256, makecol(255, 255, 255), -1, "Poprzednia karta");
				
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 154, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 155, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 156, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
		}
		
		if(key[KEY_LSHIFT])
			break;
		else if(key[KEY_LEFT])
		{
			if(karta-1 > 0)
				karta--;
		}
		else if(key[KEY_RIGHT])
		{
			if(karta+1 < 3)
				karta++;
		}
		
		clear_key();
		keypressed();
		rest(60);
	}
}


void pomoc_wybor()
{
	int x;
	/* Odstep tekstu od przycisku */
	int separator_poziomy = 5;
	/* Odstep miedzy przyciskami */
	int separator_pionowy = 10;
	/* Aktywna karta */
	int karta = 1;
	
	BITMAP *obr1 = prawko_load_bitmap("grafika/help/wybor_select.bmp");
	BITMAP *obr2 = prawko_load_bitmap("grafika/help/wybor_losowe.bmp");
	
	clear_key();
	
	while(TRUE)
	{
		clear_to_color(bufor_glowny, COLOR_TLA);
		
		switch(karta)
		{
			case 1:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Opis");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				/* Wlasciwy moment na stawienie pomocy */
				x = FONT_HEIGHT+70;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Wybór zakresu pytań z łącznej liczby pytań dla");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "danej kategorii.");
				x += FONT_HEIGHT-2;
				blit(obr1, bufor_glowny, 0, 0, 3, x, obr1->w, obr1->h);
				x += 15+obr1->h;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Zaznaczenie losowego wyboru pytań");
				x += FONT_HEIGHT-2;
				blit(obr2, bufor_glowny, 0, 0, 3, x, obr2->w, obr2->h);
				x += 15+obr2->h;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, SCREEN_WIDTH-przycisk_strzalka_p->w-1, 250, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-przycisk_strzalka_p->w-3, 256, makecol(255, 255, 255), -1, "Następna karta");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 333, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 334, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 335, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
			case 2:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Klawiszologia");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				
				/* Wlasciwy moment na stawienie pomocy */
				x = 40;

				blit(przycisk_l, bufor_glowny, 0, 0, 0, x, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Pomoc");
				x += przycisk_l->h + separator_pionowy;
			
				
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, x, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, przycisk_strzalka_l->w, x, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+przycisk_strzalka_p->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Przechodzenie między liczbami");
				x += przycisk_strzalka_l->h + separator_pionowy;
				
				blit(przycisk_strzalka_g, bufor_glowny, 0, 0, 0, x, przycisk_strzalka_g->w, przycisk_strzalka_g->h);
				blit(przycisk_strzalka_d, bufor_glowny, 0, 0, przycisk_strzalka_g->w, x, przycisk_strzalka_d->w, przycisk_strzalka_d->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_g->w+przycisk_strzalka_d->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Ustawianie liczby od 0 - 9");
				x += przycisk_strzalka_g->h + separator_pionowy;
			
				blit(przycisk_se, bufor_glowny, 0, 0, 0, x, przycisk_se->w, przycisk_se->h);
				textprintf_ex(bufor_glowny, font, przycisk_se->w+separator_poziomy, x+8, makecol(255, 255, 255), -1, "Przejście na opcje losowe");
				x += przycisk_se->h + separator_pionowy;


				blit(przycisk_x, bufor_glowny, 0, 0, 3, x, przycisk_x->w, przycisk_x->h);
				textprintf_ex(bufor_glowny, font, przycisk_x->w+separator_poziomy, x+8, makecol(255, 255, 255), -1, "Włączenie/wyłączenie opcji losowe ");
				x += przycisk_x->h + separator_pionowy;

				blit(przycisk_st, bufor_glowny, 0, 0, 0, x, przycisk_st->w, przycisk_st->h);
				textprintf_ex(bufor_glowny, font, przycisk_st->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Zatwierdzenie wyboru");
				x += przycisk_st->h + separator_pionowy;

				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, 250, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+3, 256, makecol(255, 255, 255), -1, "Poprzednia karta");
				
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 154, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 155, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 156, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
		}
		
		if(key[KEY_LSHIFT])
			break;
		else if(key[KEY_LEFT])
		{
			if(karta-1 > 0)
				karta--;
		}
		else if(key[KEY_RIGHT])
		{
			if(karta+1 < 3)
				karta++;
		}
		
		clear_key();
		keypressed();
		rest(60);
	}
}


void pomoc_podsumowanie()
{
	int x;
	/* Odstep tekstu od przycisku */
	int separator_poziomy = 5;
	/* Odstep miedzy przyciskami */
	int separator_pionowy = 10;
	/* Aktywna karta */
	int karta = 1;
	
	BITMAP *obr1 = prawko_load_bitmap("grafika/help/podsumowanie.bmp");
	
	clear_key();
	
	while(TRUE)
	{
		clear_to_color(bufor_glowny, COLOR_TLA);
		
		switch(karta)
		{
			case 1:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Opis");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				/* Wlasciwy moment na stawienie pomocy */
				x = FONT_HEIGHT+80;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Ilość pytań w teście wraz z podaną liczbą poprawnie");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "udzielonych odpowiedzi");
				x += FONT_HEIGHT-2;
				blit(obr1, bufor_glowny, 0, 0, 3, x, obr1->w, obr1->h);
				x += 15+obr1->h;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, SCREEN_WIDTH-przycisk_strzalka_p->w-1, 250, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-przycisk_strzalka_p->w-3, 256, makecol(255, 255, 255), -1, "Następna karta");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 333, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 334, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 335, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
			case 2:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Klawiszologia");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 2);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				
				/* Wlasciwy moment na stawienie pomocy */
				x = 100;

				blit(przycisk_l, bufor_glowny, 0, 0, 0, x, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Pomoc");
				x += przycisk_l->h + separator_pionowy;

				blit(przycisk_x, bufor_glowny, 0, 0, 3, x, przycisk_x->w, przycisk_x->h);
				blit(przycisk_st, bufor_glowny, 0, 0, przycisk_x->w+3, x+1, przycisk_st->w, przycisk_st->h);
				textprintf_ex(bufor_glowny, font, przycisk_x->w+przycisk_st->w+separator_poziomy, x+8, makecol(255, 255, 255), -1, "Przejście do menu");
				x += przycisk_x->h + separator_pionowy;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, 250, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+3, 256, makecol(255, 255, 255), -1, "Poprzednia karta");
				
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 154, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 155, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 156, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
		}
		
		if(key[KEY_LSHIFT])
			break;
		else if(key[KEY_LEFT])
		{
			if(karta-1 > 0)
				karta--;
		}
		else if(key[KEY_RIGHT])
		{
			if(karta+1 < 3)
				karta++;
		}
		
		clear_key();
		keypressed();
		rest(60);
	}
	
	destroy_bitmap(obr1);
}


void pomoc_podsumowanie_egzaminu()
{
	int x;
	/* Odstep tekstu od przycisku */
	int separator_poziomy = 5;
	/* Odstep miedzy przyciskami */
	int separator_pionowy = 10;
	/* Aktywna karta */
	int karta = 1;
	
	BITMAP *obr1 = prawko_load_bitmap("grafika/help/podsumowanie_egzaminu.bmp");
	BITMAP *obr2 = prawko_load_bitmap("grafika/help/wynik_zaliczony.bmp");
	BITMAP *obr3 = prawko_load_bitmap("grafika/help/wynik_niezaliczony.bmp");
	BITMAP *obr4 = prawko_load_bitmap("grafika/help/prezentacja.bmp");
	
	clear_key();
	
	while(TRUE)
	{
		clear_to_color(bufor_glowny, COLOR_TLA);
		
		switch(karta)
		{
			case 1:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Opis");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 3);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				/* Wlasciwy moment na stawienie pomocy */
				x = FONT_HEIGHT+25;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Ilość pytań w teście wraz z podaną liczbą poprawnie");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "udzielonych odpowiedzi");
				x += FONT_HEIGHT-2;
				blit(obr1, bufor_glowny, 0, 0, 0, x, obr1->w, obr1->h);
				x += 15+obr1->h;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Wynik egzaminu");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "zaliczony:");
				x += FONT_HEIGHT-2;
				blit(obr2, bufor_glowny, 0, 0, 0, x, obr2->w, obr2->h);
				x += 15+obr2->h;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "niezaliczony:");
				x += FONT_HEIGHT-2;
				blit(obr3, bufor_glowny, 0, 0, 0, x, obr3->w, obr3->h);
				x += 15+obr3->h;
				
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, SCREEN_WIDTH-przycisk_strzalka_p->w-1, 250, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-przycisk_strzalka_p->w-3, 256, makecol(255, 255, 255), -1, "Następna karta");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 333, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 334, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 335, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
			case 2:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Opis");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 3);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				
				/* Wlasciwy moment na stawienie pomocy */
				x = 80;
				
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "Po zakończonym egzaminie istnieje możliwość sprawdzenia");
				x += FONT_HEIGHT-2;
				textprintf_ex(bufor_glowny, font, 3, x, makecol(255, 255, 255), -1, "udzielonych odpowiedzi");
				x += FONT_HEIGHT-2;
				blit(obr4, bufor_glowny, 0, 0, 0, x, obr4->w, obr4->h);
				x += 15+obr4->h;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, 250, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+3, 256, makecol(255, 255, 255), -1, "Poprzednia karta");
				
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, SCREEN_WIDTH-przycisk_strzalka_p->w-1, 250, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-przycisk_strzalka_p->w-3, 256, makecol(255, 255, 255), -1, "Następna karta");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 154, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 155, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 156, 254, 266, makecol(48, 48, 48));
				
				vline(bufor_glowny, 333, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 334, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 335, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
			case 3:
			{
				/* Nazwa ekranu i jaka karta jest aktywna + linie poziome */
				textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, 3, makecol(255, 255, 255), -1, "Klawiszologia");
				textprintf_right_ex(bufor_glowny, font, SCREEN_WIDTH-6, 3, makecol(255, 255, 255), -1, "(%d/%d)", karta, 3);
				hline(bufor_glowny, 0, FONT_HEIGHT+1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, FONT_HEIGHT+2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, FONT_HEIGHT+3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				
				/* Wlasciwy moment na stawienie pomocy */
				x = 70;

				blit(przycisk_l, bufor_glowny, 0, 0, 0, x, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_l->w+separator_poziomy, x+6, makecol(255, 255, 255), -1, "Pomoc");
				x += przycisk_l->h + separator_pionowy;

				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, x, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				blit(przycisk_strzalka_p, bufor_glowny, 0, 0, przycisk_strzalka_l->w, x, przycisk_strzalka_p->w, przycisk_strzalka_p->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+przycisk_strzalka_p->w+separator_poziomy, x+7, makecol(255, 255, 255), -1, "Przełaczanie się miedźy Tak/Nie");
				x += przycisk_strzalka_l->h + separator_pionowy;

				blit(przycisk_x, bufor_glowny, 0, 0, 3, x, przycisk_x->w, przycisk_x->h);
				blit(przycisk_st, bufor_glowny, 0, 0, przycisk_x->w+3, x+1, przycisk_st->w, przycisk_st->h);
				textprintf_ex(bufor_glowny, font, przycisk_x->w+przycisk_st->w+separator_poziomy, x+8, makecol(255, 255, 255), -1, "Zatwierdzenie wyboru Tak/Nie");
				x += przycisk_x->h + separator_pionowy;
				/* Koniec tresci pomocy */
				
				/* Linie poziome i klawiszologia do pomocy */
				blit(przycisk_strzalka_l, bufor_glowny, 0, 0, 0, 250, przycisk_strzalka_l->w, przycisk_strzalka_l->h);
				textprintf_ex(bufor_glowny, font, przycisk_strzalka_l->w+3, 256, makecol(255, 255, 255), -1, "Poprzednia karta");
				
				blit(przycisk_l, bufor_glowny, 0, 0, 160, 250, przycisk_l->w, przycisk_l->h);
				textprintf_ex(bufor_glowny, font, 160+przycisk_l->w+3, 256, makecol(255, 255, 255), -1, "Wyjście z pomocy");
				
				hline(bufor_glowny, 0, 248-1, SCREEN_WIDTH, makecol(48, 48, 48));
				hline(bufor_glowny, 0, 248-2, SCREEN_WIDTH, makecol(0, 0, 0));
				hline(bufor_glowny, 0, 248-3, SCREEN_WIDTH, makecol(48, 48, 48));
				
				vline(bufor_glowny, 154, 254, 266, makecol(48, 48, 48));
				vline(bufor_glowny, 155, 254, 266, makecol(0, 0, 0));
				vline(bufor_glowny, 156, 254, 266, makecol(48, 48, 48));
				
				blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);
				break;
			}
		}
		
		if(key[KEY_LSHIFT])
			break;
		else if(key[KEY_LEFT])
		{
			if(karta-1 > 0)
				karta--;
		}
		else if(key[KEY_RIGHT])
		{
			if(karta+1 < 4)
				karta++;
		}
		
		clear_key();
		keypressed();
		rest(60);
	}
	
	destroy_bitmap(obr1);
	destroy_bitmap(obr2);
	destroy_bitmap(obr3);
	destroy_bitmap(obr4);
}
