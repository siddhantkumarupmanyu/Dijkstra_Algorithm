CC=g++

CFLAGS = -I. -lstdc++fs

BITMAP_FLAGS = -I../lib -L../lib -Wl,-rpath=../lib

TempFile: TempFile.cpp
	$(CC) -o TempFile TempFile.cpp $(CFLAGS) && ./TempFile

bitmap: Bitmap.cpp
	$(CC) -o bitmap Bitmap.cpp $(CFLAGS) $(BITMAP_FLAGS) -lezdib && ./bitmap