VERSION = 0.0
PREFIX = /usr/local

install:
	mkdir -p $(DESTDIR)$(PREFIX)/include/fortify
	cp -R include/* $(DESTDIR)$(PREFIX)/include/fortify

uninstall:
	rm -rf $(DESTDIR)$(PREFIX)/include/fortify

dist: clean
	mkdir -p fortify-$(VERSION)
	cp -R LICENSE Makefile include fortify-$(VERSION)
	tar -cf fortify-$(VERSION).tar fortify-$(VERSION)
	gzip fortify-$(VERSION).tar
	rm -rf fortify-$(VERSION)

clean:
	rm -f fortify-$(VERSION).tar.gz

.PHONY:
	install uninstall dist clean
