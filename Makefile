all:
	cd src/gui && \
	gcc -Wall  -o googl-gui  `pkg-config --cflags  --libs gtk+-2.0` googl-gui.c

INSTALL = install

PREFIX ?= /usr
BINDIR  = $(PREFIX)/bin
MANDIR  = $(PREFIX)/man

install: src/googl
	cd ../
	$(INSTALL) -d $(BINDIR)
	$(INSTALL) -d $(MANDIR)
	$(INSTALL) -d $(MANDIR)/man1
	$(INSTALL) -m 755 src/googl $(BINDIR)
	$(INSTALL) -m 755 src/gui/googl-gui $(BINDIR)
	$(INSTALL) -m 644 man/googl.1 $(MANDIR)/man1


clean: src/gui
	rm src/gui/googl-gui 
