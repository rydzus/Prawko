/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"

void info(int status, int x, char *odpowiedz)
{
	while(TRUE)
	{
		if(status == 0)
		{
			rectfill(bufor_glowny, 0, x - FONT_HEIGHT - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN, COLOR_ODP_POP_TLA);
			rectfill(bufor_glowny, 0, x - FONT_HEIGHT - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN - FONT_HEIGHT/2, COLOR_ODP_POP_SZKLA);
			rect(bufor_glowny, 0, x - FONT_HEIGHT - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN, COLOR_ODP_POP_OBR);
			textprintf_centre_ex(bufor_glowny, font, (SCREEN_WIDTH-2)/2, (x - FONT_HEIGHT - PRZESTRZEN)+3, makecol(255, 255, 255), -1, "Brawo! Odpowiedziałeś/aś prawidłowo.");
		}
		else
		{
			rectfill(bufor_glowny, 0, x - (FONT_HEIGHT * 2) - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN, COLOR_ODP_NOP_TLA);
			rectfill(bufor_glowny, 0, x - (FONT_HEIGHT * 2) - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN - FONT_HEIGHT, COLOR_ODP_NOP_SZKLA);
			rect(bufor_glowny, 0, x - (FONT_HEIGHT * 2) - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN, COLOR_ODP_NOP_OBR);
			textprintf_centre_ex(bufor_glowny, font, (SCREEN_WIDTH-2)/2, (x - (FONT_HEIGHT * 2) - PRZESTRZEN)+3, makecol(255, 255, 255), -1, "Niestety, odpowiedziałeś/aś nieprawidłowo.");
			textprintf_centre_ex(bufor_glowny, font, (SCREEN_WIDTH-2)/2, x - FONT_HEIGHT - PRZESTRZEN + 2, makecol(255, 255, 255), -1, "Poprawna odpowiedz to: %s", odpowiedz);
		}

		blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);

		if(key[KEY_ENTER] || key[KEY_SPACE])
			break;
		clear_key();
		keypressed();
		rest(60);
	}
}

void info2(int status, int x)
{
		if(status == 0)
		{
			rectfill(bufor_glowny, 0, x - FONT_HEIGHT - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN, COLOR_ODP_POP_TLA);
			rectfill(bufor_glowny, 0, x - FONT_HEIGHT - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN - FONT_HEIGHT/2, COLOR_ODP_POP_SZKLA);
			rect(bufor_glowny, 0, x - FONT_HEIGHT - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN, COLOR_ODP_POP_OBR);
			textprintf_centre_ex(bufor_glowny, font, (SCREEN_WIDTH-2)/2, (x - FONT_HEIGHT - PRZESTRZEN)+3, makecol(255, 255, 255), -1, "Podales/as poprawna odpowiedz.");
		}
		else
		{
			rectfill(bufor_glowny, 0, x - FONT_HEIGHT - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN, COLOR_ODP_NOP_TLA);
			rectfill(bufor_glowny, 0, x - FONT_HEIGHT - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN - FONT_HEIGHT/2, COLOR_ODP_NOP_SZKLA);
			rect(bufor_glowny, 0, x - FONT_HEIGHT - PRZESTRZEN, SCREEN_WIDTH-2, x - PRZESTRZEN, COLOR_ODP_NOP_OBR);
			textprintf_centre_ex(bufor_glowny, font, (SCREEN_WIDTH-2)/2, (x - FONT_HEIGHT - PRZESTRZEN)+3, makecol(255, 255, 255), -1, "Podales/as niepoprawna odpowiedz.");
		}
}
