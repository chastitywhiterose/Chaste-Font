/*
 Chastity font scaled header
 
 This file contains one function which is powerful but that I do not always have need of. If I need scalable fonts in a later game I make, then I will have this file ready.
*/


/*
 This function successfully draws a string of characters from the current loaded main font 
 arguments are: character pointer, character x pos, character y pos, integer scale
 
 It makes use of DrawTexturePro which is quite a complicated function capable of scaling as well as rotating textures.
 Rotation makes no sense when outputting text which is meant to be readable.
 But the scaling abilities of this function mean that it can multiply the font size by whatever you give it.
 Therefore, an 8x8 character font such as the smallest one I have created can literally be scaled to any multiple of 8. So a scale of 3 would result in each character being 24x24.
*/
void chaste_font_draw_string_scaled(char *s,int cx,int cy,int scale)
{
 float rotation=0; /*this should always be zero*/

 int x,y,i,c,cx_start=cx;
 i=0;
 while(s[i]!=0)
 {
  c=s[i];
  if(c=='\n'){ cx=cx_start; cy+=main_font.char_height;}
  else
  {
   x=(c-' ')*main_font.char_width;
   y=0*main_font.char_height;
   Rectangle rect_source = {x,y,main_font.char_width,main_font.char_height};
   Rectangle rect_dest={ cx, cy, main_font.char_width*scale,main_font.char_height*scale };
   Vector2 origin = {0,0};
   DrawTexturePro(main_font.texture, rect_source, rect_dest, origin,rotation, WHITE);
   cx+=main_font.char_width*scale;
  }
  i++;
 }
}

