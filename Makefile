all:
	g++ -Isrc/Include -Lsrc/lib -o sortingVisual sortingVisual.cpp -lmingw32 -lSDL2main -lSDL2