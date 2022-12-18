CC = gcc
CFLAGS = -Iinclude -Iinclude/gba

src_files := src/mdgba.c src/gba/gba.c src/gba/arm/arm.c src/gba/bus.c

mdgba: $(src_files)
	$(CC) $(CFLAGS) $^ -o mdgba