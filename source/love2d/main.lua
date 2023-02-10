
--dimensions for screen
width = 1280;
height = 720;

require "chaste_font"


--this function runs on program startup
function love.load()

 love.window.setTitle("Chastity's Love2D Demo");
 love.window.setMode( width, height);
 love.graphics.setColor(1, 1, 1);
 last_key=' ';
 
 s='Chastity\nWhite\nRose';
 
 word_test(s); --display string to the console
 
 
 font_8=chaste_font_load("font/FreeBASIC Font 8.png");
 main_font=font_8; --set main font to font_8. This is a reference only.

end --end of love.load

--this function draws to the screen every frame
function love.draw()

 love.graphics.print("Love2D Demo", 0, 0)
 love.graphics.print("Key="..last_key, 0, 100)
 
 love.graphics.print(s, 0, 200);
 
 chaste_font_draw_string(s,0,300);
 

end --end of love.draw
    
--function to handle what happens when a key is pressed.
function love.keypressed(k)

 --print("key="..k)
 last_key=k;

 if k == 'escape' then
  love.event.quit()
 end
 
end --end of love.keypressed




