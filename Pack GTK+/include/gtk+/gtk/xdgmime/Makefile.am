INCLUDES = -DXDG_PREFIX=_gtk_xdg

noinst_LTLIBRARIES = libxdgmime.la

libxdgmime_la_SOURCES = \
	xdgmime.c 	\
	xdgmime.h	\
	xdgmimealias.c	\
	xdgmimealias.h	\
	xdgmimecache.c	\
	xdgmimecache.h	\
	xdgmimeglob.c 	\
	xdgmimeglob.h 	\
	xdgmimeint.c 	\
	xdgmimeint.h 	\
	xdgmimemagic.c  \
	xdgmimemagic.h	\
	xdgmimeparent.c	\
	xdgmimeparent.h

noinst_PROGRAMS = test-mime

test_mime_LDADD = libxdgmime.la
test_mime_SOURCES = test-mime.c

