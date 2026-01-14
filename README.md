version for mingw
## build
g++ -m32 -shared -o mydll.dll dllmain.cpp functions.cpp -I include/ -L. -lMinHook -static-libgcc -static-libstdc++ -luser32
