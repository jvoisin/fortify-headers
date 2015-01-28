PREFIX = /usr/local

install:
	mkdir -p $(DESTDIR)$(PREFIX)/include/fortify
	cp -f include/* $(DESTDIR)$(PREFIX)/include/fortify

.PHONY:
	install
