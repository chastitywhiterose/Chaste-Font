/*sdl_input.h*/


/*this function is an SDL port of the keyboard function from the Raylib version of Chaste Tris*/
void keyboard()
{
 int key;
 SDL_PollEvent( &e );
  if( e.type == SDL_QUIT ){loop=0; printf("X clicked! This program will close!\n");}
  if (e.type == SDL_KEYDOWN && e.key.repeat==0)
  {
   key=e.key.keysym.sym;

   switch(key)
   {
    case SDLK_ESCAPE:
    loop=0;
    break;
  }

 }
}






