all: libomap3camd.so.0.0.0

libomap3camd.so.0.0.0: omap3cam.c Makefile
	gcc -shared -fPIC -o libomap3camd.so.0.0.0 omap3cam.c -Wl,-soname=libomap3camd.so.0

install:
	mkdir -p $(DESTDIR)/usr/lib/
	cp libomap3camd.so.0.0.0 $(DESTDIR)/usr/lib/
	ln -sf /usr/lib/libomap3camd.so.0.0.0 $(DESTDIR)/usr/lib/libomap3camd.so.0
	ln -sf /usr/lib/libomap3camd.so.0.0.0 $(DESTDIR)/usr/lib/libomap3camd.so
	mkdir -p $(DESTDIR)/usr/include/omap3cam/
	cp omap3cam.h $(DESTDIR)/usr/include/omap3cam/
	mkdir -p $(DESTDIR)/usr/lib/pkgconfig/
	cp libomap3camd.pc $(DESTDIR)/usr/lib/pkgconfig/

clean:
	rm -rf libomap3camd.so.0.0.0
