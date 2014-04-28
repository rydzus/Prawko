/*
 * Autor programu: Andrzej Rydzewski - rydz (rydzus +at+ gmail.com)
 * WWW: http://rydz.glt.pl
 * Program na licencji GPL v3
 */
#include "prawko.h"

void clear_key()
{
	key[KEY_UP] = 0;
	key[KEY_DOWN] = 0;
	key[KEY_LEFT] = 0;
	key[KEY_RIGHT] = 0;
	key[KEY_ALT] = 0;
	key[KEY_TAB] = 0;
	key[KEY_SPACE] = 0;
	key[KEY_LCONTROL] = 0;
	key[KEY_ENTER] = 0;
	key[KEY_ESC] = 0;
	key[KEY_RSHIFT] = 0;
	key[KEY_LSHIFT] = 0;
}
