PREFIX = /usr/local

install:
	mkdir -p $(DESTDIR)$(PREFIX)/include/fortify
	cp -rf include/* $(DESTDIR)$(PREFIX)/include/fortify

.PHONY:
	install
