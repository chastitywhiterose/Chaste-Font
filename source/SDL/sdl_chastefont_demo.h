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

 loop=1;

 while(loop)
 {

  SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,0,0,0));

  main_font=font_64;

  text_x=main_font.char_height*1;

  sprintf(text,"SDL Chaste Font");
  chaste_font_draw_string(text,text_x,main_font.char_height*1);


  main_font=font_32;

  sprintf(text,"This is a DOS pixelated font.");
  chaste_font_draw_string(text,text_x,main_font.char_height*5);

  main_font=font_16;

  sprintf(text,"https://github.com/chastitywhiterose/Chaste-Font/tree/main/source/SDL");
  chaste_font_draw_string(text,text_x,main_font.char_height*14);

  main_font=font_8;

  sprintf(text,"This is the SDL port of the Chaste Font project which was written in Raylib originally.");
  chaste_font_draw_string(text,text_x,main_font.char_height*32);

  sprintf(text,"Scaled DOS font.");
  chaste_font_draw_string_scaled(text,text_x,main_font.char_height*60,8);
 
  main_font=font_pico8;

  sprintf(text,"This font is from PICO-8. I can fit a lot of text on the screen with this tiny font!");
  chaste_font_draw_string(text,text_x,main_font.char_height*48);
 
  sprintf(text,"Scaled PICO-8 font.");
  chaste_font_draw_string_scaled(text,text_x,main_font.char_height*60,8);

  SDL_UpdateWindowSurface(window); /*update the screen*/

  /*test for events and only process if they exist*/
  while(SDL_PollEvent(&e))
  {
   keyboard();
  }

 }

}



void demo_chaste_font_1()
{

 delay=1000/fps;

 loop=1;
 while(loop)
 {

  sdl_time = SDL_GetTicks();
  sdl_time1 = sdl_time+delay;


  SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,0,0,0));

  main_font=font_8;

  text_x=main_font.char_height*5;

  chaste_palette_index=chaste_palette_index1;
  chaste_font_draw_string_scaled_special("Chaste\n  the\nPastels",text_x,main_font.char_height*10,20);
  
  chaste_palette_index1++;
  if(chaste_palette_index1>=chaste_palette_length)
  {
   chaste_palette_index1=0;
  }
 
  SDL_UpdateWindowSurface(window); /*update the screen*/

  /*test for events and only process if they exist*/
  while(SDL_PollEvent(&e))
  {
   keyboard();
  }

 while(sdl_time<sdl_time1)
 {
  sdl_time=SDL_GetTicks();
 }

 }

}

