
if ENABLE_REMOTE
SUBDIRS = protocol
if ENABLE_SERVER 
SUBDIRS += server
endif # ENABLE_SERVER
endif # ENABLE_REMOTE

AM_CPPFLAGS = -I../include -I$(top_builddir)/3rdparty/aes

lib_LTLIBRARIES = libhamsterdb.la

EXTRA_DIST = os_win32.c

libhamsterdb_la_SOURCES = log.c \
			blob.c \
			btree.c \
			btree_check.c \
			btree_enum.c \
			btree_erase.c \
			btree_find.c \
			btree_insert.c \
			cache.c \
			db.c \
			env.c \
			error.c \
			extkeys.c \
			freelist.c \
			freelist_v2.c \
			freelist_statistics.c \
			hamsterdb.c \
			remote.c \
			keys.c \
			mem.c \
			os_posix.c \
			page.c \
			statistics.c \
			txn.c \
			util.c \
			btree_cursor.c \
			device.c

libhamsterdb_la_LDFLAGS = -version-info 2:0:0

if ENABLE_ENCRYPTION
libhamsterdb_la_LDFLAGS += $(top_builddir)/3rdparty/aes/libaes.la
endif

if ENABLE_COMPRESSION
if SYSTEM_ZLIB
libhamsterdb_la_LDFLAGS += -lz
else
libhamsterdb_la_LDFLAGS += $(top_builddir)/3rdparty/zlib/libzlib.la
endif
endif

if ENABLE_REMOTE
libhamsterdb_la_LDFLAGS += -lcurl
libhamsterdb_la_LDFLAGS += $(top_builddir)/src/protocol/libprotocol.la
CFLAGS += -DHAM_ENABLE_REMOTE
endif

