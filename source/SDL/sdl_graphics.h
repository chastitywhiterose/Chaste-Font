/*
sdl_graphics.h

this header file is meant to contain all the important functions which write things to the screen
*/



/*
 this function is now the official welcome screen.
 It can show text or other things on a screen that will stay there until I press a key.
*/
void demo_chaste_font()
{
 SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,0,0,0));

 main_font=font_64;

 text_x=main_font.char_height*1;

 sprintf(text,"SDL Chaste Font");
 chaste_font_draw_string(text,text_x,main_font.char_height*1);


 main_font=font_32;

 sprintf(text,"This is a cool pixelated font.");
 chaste_font_draw_string(text,text_x,main_font.char_height*5);


 main_font=font_16;

 sprintf(text,"https://github.com/chastitywhiterose/Chaste-Font/tree/main/source/SDL");
 chaste_font_draw_string(text,text_x,main_font.char_height*14);

 main_font=font_8;

 sprintf(text,"This is the SDL port of the Chaste Font project which was written in Raylib originally.");
 chaste_font_draw_string(text,text_x,main_font.char_height*32);

 SDL_UpdateWindowSurface(window); /*update the screen*/

 while(e.type != SDL_KEYUP) /*wait until any key is pressed and then released*/
 {
  SDL_PollEvent( &e );
 }

}




