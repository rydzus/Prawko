TARGET = prawko
OBJS = src/prawko.o src/wczytaj_pytanie.o src/rysuj_belki.o src/menu.o \
src/clear_key.o src/nauka.o src/info.o src/podsumowanie.o src/liczba_wierszy.o \
src/oprogramie.o src/wybor.o src/egzamin.o src/pomoc.o

INCDIR =
CFLAGS = -G0 -Wall -O2
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
LIBS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Prawko
PSP_EBOOT_ICON = src_grafika/ICON0.PNG

PSPSDK=$(shell psp-config --pspsdk-path)
PSP_PREFIX = $(shell psp-config --psp-prefix)
PSPBIN = $(PSP_PREFIX)/bin
CFLAGS += $(shell $(PSPBIN)/psp-allegro-config --cflags)
LIBS += $(shell $(PSPBIN)/psp-allegro-config --libs release)
include $(PSPSDK)/lib/build.mak
