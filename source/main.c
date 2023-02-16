#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <raylib.h>
#include <math.h>

const int width = 1280;
const int height = 720;

int text_x; /*the x position of where text will go*/
int text_y; /*the y position of where text will go*/
char text[0x200]; /*where text data is stored sometimes*/

#include "ray_chastefont.h"
#include "chastefont_demo.h"



int main(int argc, char **argv)
{

 InitWindow(width,height,"Chastity's Game");
 SetTargetFPS(60);

 
 /*
  call the function to load my custom bitmap font.
  it returns a "chaste_font" structure which is stored in global variable main_font
 */

 font_pico8=chaste_font_load("./font/PICO-8_4x6.png");

 font_8=chaste_font_load("./font/FreeBASIC Font 8.png");
 font_16=chaste_font_load("./font/FreeBASIC Font 16.png");
 font_32=chaste_font_load("./font/FreeBASIC Font 32.png");
 font_64=chaste_font_load("./font/FreeBASIC Font 64.png");
 font_128=chaste_font_load("./font/FreeBASIC Font 128.png");


/*finally, run the demo function now that all fonts are loaded*/
chaste_font_demo_pico();

 return 0;
}

/*
raylib_linux:
	gcc -Wall -std=c99 -pedantic main.c -o main -lraylib -lOpenGL -lm -lpthread -ldl -lrt -lX11 && ./main
*/

