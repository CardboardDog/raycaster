xxd -r -p levels.txt levels.dat
gcc -c main.c -o main.o -lSDL2 -IETP/libetp
gcc -c ETP/libetp/etp.c -o etp.o -IETP/libetp 
gcc -c atlas.c -o atlas.o -IETP/libetp
gcc -c levels.c -o levels.o
gcc -c entity.c -o entity.o
gcc -o main main.o etp.o atlas.o entity.o levels.o -lSDL2
