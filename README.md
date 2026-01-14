version for mingw
## build
<<<<<<< HEAD
g++ -m32 -shared -o mydll.dll dllmain.cpp functions.cpp -I include/ -L. -lMinHook -static-libgcc -static-libstdc++ -luser32
=======
g++ -m32 -shared -o mydll.dll dllmain.cpp functions.cpp -I include/ -L. -lMinHook -static-libgcc -static-libstdc++ -luser32
>>>>>>> df5e45565a964f8a2d11b6c4b1068163c5b49981
