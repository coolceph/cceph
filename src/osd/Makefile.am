libosd_la_SOURCES =        \
	osd/types.c            \
	osd/pg.c               \
	osd/osd_msg_process.c  \
	osd/osd_create.c       \
	osd/osd.c

libosd_la_ADLDD = \
	$(LIBCOMMON)  \
	$(LIBMESSAGE) \
	$(LIBOS)

libosd_la_LIBADD = \
	-lpthread

noinst_LTLIBRARIES += libosd.la
