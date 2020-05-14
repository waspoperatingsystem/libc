CC ?= cc
HOSTCC ?= cc
AR ?= ar

INCLUDE = $(PWD)/include
SRC = $(PWD)/src
CRT = $(PWD)/crt
BUILD = $(PWD)/build
INT_CFLAGS = -I$(INCLUDE) -Os -g0 -pipe

OBJ = $(SRC)/abort.o \
	$(SRC)/memcmp.o \
	$(SRC)/memcpy.o \
	$(SRC)/memmove.o \
	$(SRC)/memset.o \
	$(SRC)/printf.o \
	$(SRC)/putchar.o \
	$(SRC)/puts.o \
	$(SRC)/strlcat.o \
	$(SRC)/strlcpy.o \
	$(SRC)/strlen.o

CRT0 = $(CRT)/$(ARCH)/crt0.o

all: create_build crts libc.a

create_build: clean
	mkdir -p $(BUILD)

.c.o:
	$(CC) -MD -c $< -o $@ $(CPPFLAGS) $(INT_CFLAGS) $(CFLAGS)
 
.S.o:
	$(CC) -MD -c $< -o $@ $(CPPFLAGS) $(INT_CFLAGS) $(CFLAGS)

libc.a: $(OBJ)
	$(AR) rcs $(BUILD)/$@ $(OBJ)

crts: $(CRT0)

clean:
	rm -f $(OBJ)
	rm -rf $(BUILD)
