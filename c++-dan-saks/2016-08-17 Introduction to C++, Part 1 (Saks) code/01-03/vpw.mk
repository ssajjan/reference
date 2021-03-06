# make greet using Visual Studio
# compile as C++ for Windows
# Copyright (c) 2016 by Dan Saks
# See _readme.txt

SRC = .cpp  # source
OBJ = .obj  # object
EXE = .exe  # executable
MAP = .map  # link map
ASM = .asm  # assembler

CC = cl
CFLAGS = /c /W4
AFLAGS = $(CFLAGS) /FA

LL = $(CC)
LFLAGS = /Fm

$(OBJ)$(EXE):
	$(LL) $(LFLAGS) $**

$(SRC)$(OBJ):
	$(CC) $(CFLAGS) $<

$(SRC)$(ASM):
	$(CC) $(AFLAGS) $<

greet$(EXE): greet$(OBJ) hello$(OBJ)

greet$(OBJ): hello.h

hello$(OBJ): hello.h

clean:
	cmd /c del *.bak *$(EXE) *$(OBJ) *$(MAP) *$(ASM)

