rm levels.dat
xxd -r -p levels.txt levels.dat
gcc -c main.c -o main.o -lSDL2 -g 
gcc -c atlas.c -o atlas.o -g
gcc -c levels.c -o levels.o -g
gcc -c entity.c -o entity.o -g
gcc -c player.c -o player.o -g
gcc -c clock.c -o clock.o -lSDL2 -lm -g
gcc -c input.c -o input.o -lSDL2 -lm -g
gcc -c render.c -o render.o -lSDL2 -lm -g
gcc -c image.c -o image.o -g
gcc -o main main.o image.o atlas.o input.o entity.o render.o levels.o player.o clock.o -lm -lSDL2 -g
