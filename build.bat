set files=src\glad.c src\main.c src\engine\global.c src\engine\render\render.c src\engine\render\render_init.c
set libs=Q:\lib\SDL2main.lib Q:\lib\SDL2.lib Q:\lib\freetype.lib

CL /Zi /I Q:\include %files% /link %libs% /OUT:mygame.exe