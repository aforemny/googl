all: install

DESTDIR = /usr
BINDIR  = $(DESTDIR)/bin
MANDIR  = $(DESTDIR)/man

install: src/googl
	cp src/googl $(BINDIR)
	chmod 755 $(BINDIR)/googl
	cp man/googl.1 $(MANDIR)
	chmod 444 $(MANDIR)/googl.1

