#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

/*
most variables in the program are global. Unless I create temporary variables in other functions.
*/
int width=1280,height=720;
int loop=1;
SDL_Window *window = NULL;
SDL_Surface *surface;
SDL_Event e;
SDL_Rect rect;

int rect_color;

int frame=0,lastframe=0,fps=60,delay,framelimit=1; /*only used for animation demos*/
int time,time1;
int sdl_time,sdl_time1;

char text[0x200];
char movetext[256],move_id;
int text_x; /*the x position of where text will go*/

FILE *fp; /*to save a file of moves played*/
char filename[256]; /*name of move log file*/
FILE *fp_input; /*file to get input from instead of the keyboard*/

#include "chaste_the_rainbow.h"
#include "sdl_chastefont.h"
#include "sdl_input.h"
#include "sdl_chastefont_demo.h"


int main(int argc, char* args[])
{
 /*set up colors first*/
 /*chaste_palette_rainbow(40);*/
 chaste_palette_rainbow_pastel(80);

 /*chaste_palette_view();*/

 /*return 0;*/

 if(SDL_Init(SDL_INIT_VIDEO)){printf( "SDL could not initialize! SDL_Error: %s\n",SDL_GetError());return -1;}
 window=SDL_CreateWindow( "SDL Chaste Font",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN );
 if(window==NULL){printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );return -1;}

 /*set up the screen*/
 surface = SDL_GetWindowSurface( window );

 SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,0x80,0x80,0x80));
 SDL_UpdateWindowSurface(window);

 
 font_pico8=chaste_font_load("./font/PICO-8_4x6.bmp");
 
 font_8=chaste_font_load("./font/FreeBASIC Font 8.bmp");
 font_16=chaste_font_load("./font/FreeBASIC Font 16.bmp");
 font_32=chaste_font_load("./font/FreeBASIC Font 32.bmp");
 font_64=chaste_font_load("./font/FreeBASIC Font 64.bmp");



 demo_chaste_font_2();

 main_font=font_64;

 SDL_DestroyWindow(window);
 SDL_Quit();

 SDL_FreeSurface(font_pico8.surface);
 SDL_FreeSurface(font_8.surface);
 SDL_FreeSurface(font_16.surface);
 SDL_FreeSurface(font_32.surface);
 SDL_FreeSurface(font_64.surface);

 return 0;
}























/*
Compile within Unix/Linux/msys
gcc -Wall -ansi -pedantic main.c -o main `sdl2-config --cflags --libs` && ./main

Static Compile within Unix/Linux/msys
gcc -Wall -ansi -pedantic main.c -o main `sdl2-config --cflags --static-libs` && ./main

Compiling on Windows:

can dynamic link with my msys install
set PATH=C:\msys64\mingw32\bin;
gcc -Wall -ansi -pedantic main.c -o main -IC:\msys64\mingw32\include\SDL2 -Dmain=SDL_main -LC:\msys64\mingw32\lib -lmingw32 -lSDL2main -lSDL2 && main

More frequently, I compile with my official Windows install in C:\SDL
set PATH=C:\TDM-GCC-32\bin;C:\SDL\bin;
gcc -Wall -ansi -pedantic main.c -o main -IC:\SDL\include\SDL2 -Dmain=SDL_main -LC:\SDL\lib -lmingw32 -lSDL2main -lSDL2 && main

can static compile too. (only works with my install in C:\SDL)
gcc -Wall -ansi -pedantic main.c -o main -IC:\SDL\include\SDL2 -Dmain=SDL_main -LC:\SDL\lib -lmingw32 -lSDL2main -lSDL2 -mwindows  -Wl,--no-undefined -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid -static-libgcc -static && main
*/
