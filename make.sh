rm levels.dat
xxd -r -p levels.txt levels.dat
gcc -c main.c -o main.o -lSDL2 -g -Wall
gcc -c atlas.c -o atlas.o -g -Wall
gcc -c levels.c -o levels.o -g -Wall
gcc -c entity.c -o entity.o -g -Wall
gcc -c player.c -o player.o -g -Wall
gcc -c clock.c -o clock.o -lSDL2 -lm -g -Wall
gcc -c input.c -o input.o -lSDL2 -lm -g -Wall
gcc -c render.c -o render.o -lSDL2 -lm -g -Wall
gcc -c image.c -o image.o -g -Wall
gcc -o main main.o image.o atlas.o input.o entity.o render.o levels.o player.o clock.o -lm -lSDL2 -g
