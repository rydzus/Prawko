/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"

void oprogramie()
{
	clear_key();
	int x;

	while(TRUE)
	{
		x = 2;
		clear_to_color(bufor_glowny, COLOR_TLA);
		x = 4 + rysuj_belki(x, "Program w wersji 1.2a", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
		x = 4 + rysuj_belki(x, "Program \"Prawko\" został napisany z myślą o użytkownikach portalu pspoland.pl oraz wszystkich użytkowników PSP", COLOR_ODP_ZAZ_TLA, COLOR_ODP_ZAZ_OBR, COLOR_ODP_ZAZ_SZKLA);
		x = 4 + rysuj_belki(x, "Autor programu: Andrzej (rydz) Rydzewski \n Kontakt: rydzus@gmail.com \n Strona domowa: http://rydz.glt.pl", COLOR_ODP_POP_TLA, COLOR_ODP_POP_OBR, COLOR_ODP_POP_SZKLA);
		x = 4 + rysuj_belki(x, "Osoby które pomogły w realizacji projektu: \n - Deekin - dostarczenie pytań i zdjęć \n - Semiranis - liczne wskazywanie błędów i podpowiedzi w rozwiązaniach ich \n - Bebechy15 - wskazanie błędów \n - rei-u - testowanie, wskazywanie błędów, pożyczanie konsoli, upiększenie menu \n - Ma3iek - wskazanie błędów \n - lozahimowicz - zaktualizowanie oraz dodanie nowych pytań i obrazków", COLOR_ODP_ZWY_TLA, COLOR_ODP_ZWY_OBR, COLOR_ODP_ZWY_SZKLA);
		x = 4 + rysuj_belki(x, "Pytania i zdjęcia użyte w programie, zostały opracowane przez Ministerstwo Infrastruktury", COLOR_ODP_NOP_TLA, COLOR_ODP_NOP_OBR, COLOR_ODP_NOP_SZKLA);
		x = 4 + rysuj_belki(x, "Program udostępniony na licencji GPL v3", COLOR_ODP_POP_TLA, COLOR_ODP_POP_OBR, COLOR_ODP_POP_SZKLA);

		blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);

		if(key[KEY_ENTER] || key[KEY_SPACE])
			break;
		clear_key();
		keypressed();
		rest(60);
	}
}
