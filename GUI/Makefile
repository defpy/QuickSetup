# QuickSetup MAakefile
# Pretty primitive, but hey, it's my first one

CC       = gcc 
LIBS     = `pkg-config --cflags --libs gtk+-2.0 gmodule-export-2.0` 
INCLUDES = ./Include/QuickSetup.h ./Include/Callbacks.h
SOURCES  = ./Source/QuickSetup.c ./Source/Callbacks.c ./Source/Scripts.c

QuickSetup : $(SOURCES) $(INCLUDES)
	$(CC) $(LIBS) -fno-stack-protector -o QuickSetup $(SOURCES)

