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
#include "ray_chastefont_scaled.h"

/* this function is now the official welcome screen*/
void chaste_font_demo()
{
 text_x=font_8.char_height*1;
 
 
 /*before the game actually runs, optionally display a start screen*/
 while(!WindowShouldClose()) /*loop runs until key pressed*/
 {
  if(IsKeyPressed(KEY_ENTER)){break;}

  BeginDrawing();
  ClearBackground((Color){0,0,0,255});

  main_font=font_64;
  text_y=main_font.char_height*1;
 
  sprintf(text,"Font 64");
  chaste_font_draw_string(text,text_x,text_y);

  text_y+=main_font.char_height;
  main_font=font_32;

  sprintf(text,"Font 32");
  chaste_font_draw_string(text,text_x,text_y);

  text_y+=main_font.char_height;
  main_font=font_16;

  sprintf(text,"Font 16");
  chaste_font_draw_string(text,text_x,text_y);

  text_y+=main_font.char_height;
  main_font=font_8;

  sprintf(text,"Font 8");
  chaste_font_draw_string(text,text_x,text_y);
  
  
  text_y+=main_font.char_height*2;
    sprintf(text,"Font Scaled");

   chaste_font_draw_string_scaled(text,text_x,text_y,16);
  
  

  EndDrawing();
 }

}






int main(int argc, char **argv)
{



 InitWindow(width,height,"Chastity's Game");
 SetTargetFPS(60);

 
 /*
  call the function to load my custom bitmap font.
  it returns a "chaste_font" structure which is stored in global variable main_font
 */

 font_8=chaste_font_load("./font/FreeBASIC Font 8.png");
 font_16=chaste_font_load("./font/FreeBASIC Font 16.png");
 font_32=chaste_font_load("./font/FreeBASIC Font 32.png");
 font_64=chaste_font_load("./font/FreeBASIC Font 64.png");
 font_128=chaste_font_load("./font/FreeBASIC Font 128.png");


/*finally, run the demo function now that all fonts are loaded*/
chaste_font_demo();

 return 0;
}

/*
raylib_linux:
	gcc -Wall -std=c99 -pedantic main.c -o main -lraylib -lOpenGL -lm -lpthread -ldl -lrt -lX11 && ./main
*/

