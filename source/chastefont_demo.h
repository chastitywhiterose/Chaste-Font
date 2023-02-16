void chaste_font_demo()
{
 int x,font_scale;
 text_x=font_8.char_height*1;
 
 
 /*before the game actually runs, optionally display a start screen*/
 while(!WindowShouldClose()) /*loop runs until key pressed*/
 {
  if(IsKeyPressed(KEY_ENTER)){break;}

  BeginDrawing();
  ClearBackground((Color){0,0,0,255});
  
  text_y=font_8.char_height*1;
  
  main_font=font_128;
  
  sprintf(text,"Font 128");
  chaste_font_draw_string(text,text_x,text_y);

  text_y+=main_font.char_height;
  main_font=font_64;
 
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

  chaste_font_draw_string("Chaste Font Demo\nhttps://github.com/chastitywhiterose/Chaste-Font\n\nBy Chastity White Rose",font_8.char_height*48,text_y);

  text_y+=main_font.char_height;
  main_font=font_8;
  /*main_font=font_pico8;*/

  sprintf(text,"Font 8");
  chaste_font_draw_string(text,text_x,text_y);
  
  
  text_y+=main_font.char_height*8;

  font_scale=1;
  x=0;
  while(x<8)
  {
   sprintf(text,"Font 8*%d",font_scale);
   chaste_font_draw_string_scaled(text,text_x,text_y,font_scale);
   text_y+=main_font.char_height*font_scale;
   font_scale++;
   x++;
  }
  
  EndDrawing();
 }

}



























void chaste_font_demo_pico()
{
 int x,font_scale;
 text_x=font_8.char_height*1;
 
 main_font=font_pico8;
 
 /*before the game actually runs, optionally display a start screen*/
 while(!WindowShouldClose()) /*loop runs until key pressed*/
 {
  if(IsKeyPressed(KEY_ENTER)){break;}

  BeginDrawing();
  ClearBackground((Color){0,0,0,255});
  
  text_y=font_8.char_height*0;
  
  sprintf(text,"Chastity White Rose");
  /*chaste_font_draw_string(text,text_x,text_y);*/

  font_scale=1;
  x=0;
  while(x<=14)
  {
   chaste_font_draw_string_scaled(text,text_x,text_y,font_scale);
   text_y+=main_font.char_height*font_scale;
   font_scale++;
   x++;
  }
  
  EndDrawing();
 }

}


