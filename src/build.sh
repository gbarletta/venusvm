gcc -Wall -I. main.c vm.c memory.c registers.c stack.c opcodes.c symbols.c devices.c -o venusvm -ldl 
cd devices
sh build.sh
cd ..
