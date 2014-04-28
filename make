make clean
if [ -e "Prawko/prawko" ] ; then
    rm Prawko/prawko
fi
if [ -e "Prawko/EBOOT.PBP" ] ; then
    rm Prawko/EBOOT.PBP
fi

echo "kompiluje wersje PC"
gcc -Wall -g -o Prawko/prawko src/prawko.c src/wczytaj_pytanie.c \
src/rysuj_belki.c src/menu.c src/clear_key.c src/nauka.c src/info.c \
src/podsumowanie.c src/liczba_wierszy.c src/oprogramie.c src/wybor.c \
src/egzamin.c src/pomoc.c \
`allegro-config --libs --cflags`

echo "kompiluje wersje PSP"
make clean
make -j 2

if [ -e "EBOOT.PBP" ] ; then
	mv EBOOT.PBP Prawko/
fi
