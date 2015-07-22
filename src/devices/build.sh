gcc -Wall -fPIC -I.. -c prova.c
gcc -shared -Wl,-soname,prova.so -o prova.so prova.o -lSDL -lpthread

gcc -Wall -fPIC -I.. -c console.c
gcc -shared -Wl,-soname,console.so -o console.so console.o
