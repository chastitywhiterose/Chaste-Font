--lua version of chaste font functions

function word_test(s)

 --s='Chastity';
 
 print("string="..s);
 print("length="..string.len(s) );
 
 x=1;
 while( x<=string.len(s) )
 do
  print( string.sub(s,x,x) ..'='.. string.byte(s, x) );
  x=x+1;
 end

end



function  chaste_font_load(f)

 new_font={};
 print("This function tries to load a font.");
 print("Loading font \""..f.."\"");

 new_font.texture=love.graphics.newImage(f);
 --by default,font size is detected by original image height
 new_font.char_width=new_font.texture:getHeight();
 new_font.char_height=new_font.texture:getHeight();

 if(new_font.char_height==0)
 then
  printf("Something went horribly wrong loading the font from file:\n%s\n",s);
 else
  print("Font loaded correctly");
  print("Size of loaded font is "..new_font.char_height);

  --print("width of loaded image is "..new_font.texture:getWidth());
  --print("height of loaded image is "..new_font.texture:getHeight());
  
 end

 return new_font;
 
end










-- this function successfully draws a string of characters from the loaded font
-- arguments are: character pointer, character x pos, character y pos

function chaste_font_draw_string(s,cx,cy)

 
 cx_start=cx;
 
 length=string.len(s);
 
 i=1;
 while(i<=length)
 do
  c=string.byte(s,i);
  --print("char="..c);
  if(c==string.byte('\n'))
   then
    cx=cx_start;
    cy=cy+main_font.char_height;
  else
   x=(c-string.byte(' '))*main_font.char_width;
   y=0*main_font.char_height;
   quad=love.graphics.newQuad(x, y, main_font.char_width,main_font.char_height, main_font.texture)
   love.graphics.draw(main_font.texture, quad, cx, cy);
   cx=cx+main_font.char_width;
  end
  i=i+1;
 end
 
end



