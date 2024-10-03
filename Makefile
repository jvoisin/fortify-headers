VERSION = 2.1
PREFIX = /usr/local

install:
	install -D -t $(DESTDIR)$(PREFIX)/include/fortify \
		include/*.h
	install -D -t $(DESTDIR)$(PREFIX)/include/fortify/sys \
		include/sys/*.h

uninstall:
	rm -rf $(DESTDIR)$(PREFIX)/include/fortify

dist: clean
	mkdir -p fortify-headers-$(VERSION)
	cp -R LICENSE Makefile README include fortify-headers-$(VERSION)
	tar -cf fortify-headers-$(VERSION).tar fortify-headers-$(VERSION)
	gzip fortify-headers-$(VERSION).tar
	rm -rf fortify-headers-$(VERSION)

clean:
	rm -f fortify-headers-$(VERSION).tar.gz

.PHONY:
	install uninstall dist clean
