
# This file is temporary until I move this project to cmake, make, or scons

rm levels.dat
xxd -r -p levels.txt levels.dat
clang -c main.c -o main.o -lSDL2 -g -Wall
clang -c atlas.c -o atlas.o -g -Wall
clang -c levels.c -o levels.o -g -Wall
clang -c entity.c -o entity.o -g -Wall
clang -c player.c -o player.o -g -Wall
clang -c clock.c -o clock.o -lSDL2 -lm -g -Wall
clang -c input.c -o input.o -lSDL2 -lm -g -Wall
clang -c render.c -o render.o -lSDL2 -lm -g -Wall
clang -c image.c -o image.o -g -Wall
clang -o main main.o image.o atlas.o input.o entity.o render.o levels.o player.o clock.o -lm -lSDL2 -g
