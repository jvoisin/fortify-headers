PREFIX = /usr/local

install:
	mkdir -p $(DESTDIR)$(PREFIX)/include/fortify
	cp -r include/* $(DESTDIR)$(PREFIX)/include/fortify

.PHONY:
	install
