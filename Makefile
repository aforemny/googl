all: install

INSTALL = install

PREFIX ?= /usr
BINDIR  = $(PREFIX)/bin
MANDIR  = $(PREFIX)/man

install: src/googl
	$(INSTALL) -d $(BINDIR)
	$(INSTALL) -d $(MANDIR)
	$(INSTALL) -m 755 src/googl $(BINDIR)
	$(INSTALL) -m 644 man/googl.1 $(MANDIR)

