TARGET:= util.test

SRCDIR:= src/ test/
OBJDIR:= .objs/
OUTDIR:=
INSTALL_DIR:=
HEADERS:=
LIBS:= -lgtest -lrt
INCLUDE:= -I.

CFLAGS:=
CXXFLAGS:=
LDFLAGS:=

include build.mak
