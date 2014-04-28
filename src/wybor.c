/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"

void wybor(int *od_pytania, int *do_pytania, char *znak, int *liczba_pytan)
{
	int liczba1[3] = {0, 0, 1};
	int liczba2[3] = {5, 2, 6};
	int wskaznik = 0;
	int y;
	*znak = ' ';

	clear_key();

	while(TRUE)
	{
		y = 80;
		if(key[KEY_UP])
		{
			switch(wskaznik)
			{
				case 0:
					if(liczba1[0]+1 < 10)
						liczba1[0]++;
				break;
				case 1:
					if(liczba1[1]+1 < 10)
						liczba1[1]++;
				break;
				case 2:
					if(liczba1[2]+1 < 10)
						liczba1[2]++;
				break;
				case 3:
					if(liczba2[0]+1 < 10)
						liczba2[0]++;
				break;
				case 4:
					if(liczba2[1]+1 < 10)
						liczba2[1]++;
				break;
				case 5:
					if(liczba2[2]+1 < 10)
						liczba2[2]++;
				break;
			}
		}
		else if(key[KEY_DOWN])
		{
			switch(wskaznik)
			{
				case 0:
					if(liczba1[0]-1 > -1)
						liczba1[0]--;
				break;
				case 1:
					if(liczba1[1]-1 > -1)
						liczba1[1]--;
				break;
				case 2:
					if(liczba1[2]-1 > -1)
						liczba1[2]--;
				break;
				case 3:
					if(liczba2[0]-1 > -1)
						liczba2[0]--;
				break;
				case 4:
					if(liczba2[1]-1 > -1)
						liczba2[1]--;
				break;
				case 5:
					if(liczba2[2]-1 > -1)
						liczba2[2]--;
				break;
			}
		}
		else if(key[KEY_RIGHT])
		{
			if(wskaznik+1 < 6 && wskaznik != -1)
				wskaznik++;
			else if(wskaznik == -1)
				wskaznik = 0;
			else
				wskaznik = -1;
		}
		else if(key[KEY_LEFT])
		{
			if(wskaznik-1 >= 0)
				wskaznik--;
			else if(wskaznik == -1)
				wskaznik = 5;
			else
				wskaznik = -1;
		}
		else if(key[KEY_ESC])
		{
			if(wskaznik != -1)
				wskaznik = -1;
			else
				wskaznik = 0;
		}
		else if(key[KEY_SPACE] && wskaznik == -1)
		{
			if(*znak == ' ')
				*znak = 'X';
			else
				*znak = ' ';
		}
		else if(key[KEY_LSHIFT])
		{
			pomoc_wybor();
		}

		*od_pytania = liczba1[0]*100 + liczba1[1]*10 + liczba1[2];
		*do_pytania = liczba2[0]*100 + liczba2[1]*10 + liczba2[2];

		if(*od_pytania == 0)
		{
			liczba1[0] = 0;
			liczba1[1] = 0;
			liczba1[2] = 1;
		}
		else if(*od_pytania >= *liczba_pytan)
		{
			if(*liczba_pytan == 60)
			{
				liczba1[0] = 0;
				liczba1[1] = 6;
				liczba1[2] = 0;
			}
			else if(*liczba_pytan == 61)
			{
				liczba1[0] = 0;
				liczba1[1] = 6;
				liczba1[2] = 1;
			}
			else if(*liczba_pytan == 193)
			{
				liczba1[0] = 1;
				liczba1[1] = 9;
				liczba1[2] = 3;
			}
			else if(*liczba_pytan == 192)
			{
				liczba1[0] = 1;
				liczba1[1] = 9;
				liczba1[2] = 2;
			}
			else
			{
				liczba1[0] = 5;
				liczba1[1] = 2;
				liczba1[2] = 6;
			}
		}

		if(*do_pytania > *liczba_pytan)
		{
			if(*liczba_pytan == 60)
			{
				liczba2[0] = 0;
				liczba2[1] = 6;
				liczba2[2] = 0;
			}
			else if(*liczba_pytan == 61)
			{
				liczba2[0] = 0;
				liczba2[1] = 6;
				liczba2[2] = 1;
			}
			else if(*liczba_pytan == 193)
			{
				liczba2[0] = 1;
				liczba2[1] = 9;
				liczba2[2] = 3;
			}
			else if(*liczba_pytan == 192)
			{
				liczba2[0] = 1;
				liczba2[1] = 9;
				liczba2[2] = 2;
			}
			else
			{
				liczba2[0] = 5;
				liczba2[1] = 2;
				liczba2[2] = 6;
			}
		}
		else if(*do_pytania == 0)
		{
			liczba2[0] = 0;
			liczba2[1] = 0;
			liczba2[2] = 1;
		}

		clear_to_color(bufor_glowny, COLOR_TLA);
		rectfill(bufor_glowny, 0, 0, SCREEN_WIDTH-2, SCREEN_HEIGHT, COLOR_TLA);
		rect(bufor_glowny, 0, 0, SCREEN_WIDTH-2, SCREEN_HEIGHT, COLOR_OBR);
		rectfill(bufor_glowny, 80, 130, SCREEN_WIDTH-100, 170, COLOR_ODP_ZWY_TLA);
		rectfill(bufor_glowny, 80, 130, SCREEN_WIDTH-100, 150, COLOR_ODP_ZWY_SZKLA);
		rect(bufor_glowny, 80, 130, SCREEN_WIDTH-100, 170, COLOR_ODP_ZWY_OBR);

		textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 255, 255), -1, "od pytania: ");
		if(wskaznik == 0)
			textprintf_ex(bufor_glowny, font, y+=12*8, SCREEN_HEIGHT/2, makecol(255, 0, 0), -1, "%d", liczba1[0]);
		else
			textprintf_ex(bufor_glowny, font, y+=12*8, SCREEN_HEIGHT/2, makecol(255, 255, 255), -1, "%d", liczba1[0]);
		if(wskaznik == 1)
			textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 0, 0), -1, "%d", liczba1[1]);
		else
			textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 255, 255), -1, "%d", liczba1[1]);
		if(wskaznik == 2)
			textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 0, 0), -1, "%d", liczba1[2]);
		else
			textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 255, 255), -1, "%d", liczba1[2]);
		textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 255, 255), -1, ", ");
		textprintf_ex(bufor_glowny, font, y+=2*8, SCREEN_HEIGHT/2, makecol(255, 255, 255), -1, "do pytania: ");
		if(wskaznik == 3)
			textprintf_ex(bufor_glowny, font, y+=12*8, SCREEN_HEIGHT/2, makecol(255, 0, 0), -1, "%d", liczba2[0]);
		else
			textprintf_ex(bufor_glowny, font, y+=12*8, SCREEN_HEIGHT/2, makecol(255, 255, 255), -1, "%d", liczba2[0]);
		if(wskaznik == 4)
			textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 0, 0), -1, "%d", liczba2[1]);
		else
			textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 255, 255), -1, "%d", liczba2[1]);
		if(wskaznik == 5)
			textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 0, 0), -1, "%d", liczba2[2]);
		else
			textprintf_ex(bufor_glowny, font, y+=8, SCREEN_HEIGHT/2, makecol(255, 255, 255), -1, "%d", liczba2[2]);

		if(wskaznik == -1)
			textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, SCREEN_HEIGHT/2+20, makecol(255, 0, 0), -1, "[%c] losowe", *znak);
		else
			textprintf_centre_ex(bufor_glowny, font, SCREEN_WIDTH/2, SCREEN_HEIGHT/2+20, makecol(255, 255, 255), -1, "[%c] losowe", *znak);
			
		blit(przycisk_l, bufor_glowny, 0, 0, 1, 1, przycisk_l->w, przycisk_l->h);
		textprintf_ex(bufor_glowny, font, przycisk_l->w+1, 7, makecol(255, 255, 255), -1, "Pomoc");

		blit(bufor_glowny, screen, 0, 0, 0, 0, bufor_glowny->w, bufor_glowny->h);

		if(key[KEY_ENTER])
		{
			break;
		}
		clear_key();
		keypressed();
		rest(60);
	}
}

