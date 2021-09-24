HEADERS += \
    $$PWD/ioapi.h \
    $$PWD/myjlcompress.h \
    $$PWD/quaadler32.h \
    $$PWD/quachecksum32.h \
    $$PWD/quacrc32.h \
    $$PWD/quagzipfile.h \
    $$PWD/quaziodevice.h \
    $$PWD/quazip.h \
    $$PWD/quazip_global.h \
    $$PWD/quazipdir.h \
    $$PWD/quazipfile.h \
    $$PWD/quazipfileinfo.h \
    $$PWD/quazipnewinfo.h \
    $$PWD/unzip.h \
    $$PWD/zip.h

SOURCES += \
    $$PWD/myjlcompress.cpp \
    $$PWD/qioapi.cpp \
    $$PWD/quaadler32.cpp \
    $$PWD/quacrc32.cpp \
    $$PWD/quagzipfile.cpp \
    $$PWD/quaziodevice.cpp \
    $$PWD/quazip.cpp \
    $$PWD/quazipdir.cpp \
    $$PWD/quazipfile.cpp \
    $$PWD/quazipfileinfo.cpp \
    $$PWD/quazipnewinfo.cpp \
    $$PWD/unzip.c \
    $$PWD/zip.c

LIBS += $$PWD/lib/zlib.lib
