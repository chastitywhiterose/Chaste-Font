/*chastefont.h*/

/*The functions in this file are never actually used for making real image files but could theoretically serve me in some way in the future.*/



/*Print all 95 printable characters on one line*/
void chaste_char_list_line()
{
 int i,n=0;
 i=' ';
 while(i<='~')
 {
  printf("%c",i);
  n++;
  i+=1;
 }
 printf("\n");


 printf("%d characters printed\n",n);

}

/*Print all 95 printable characters.
Each character is on a separate line with it's ASCII number displayed.*/
void chaste_char_list_numbers()
{
 int i;
 i=' ';
 while(i<='~')
 {
  printf("'%c' = %d\n",i,i);
  i+=1;
 }
 printf("\n");
}






/* a function to conveniently lay out characters based on certain criteria */
void chaste_char_list_limited()
{
 int x,y,i;
 i=0;
 y=0;
 while(y<16)
 {
  x=0;
  while(x<16)
  {
   if(i<0x20 || i>0x7E){putchar(' ');}
   else {putchar(i);}
   i+=1;
   x+=1;
  }
  putchar('\n');
  y+=1;
 }
 
}




/*
A function for outputting text in a neat format so I can later possibly create my own bitmap fonts out of it.
Usually called with something like:

BBM_Save_ASCII("o/ascii.txt");

*/
void BBM_Save_ASCII(const char *filename)
{
 int x,y,i;
 FILE* fp;
 fp=fopen(filename,"wb+");
 if(fp==NULL){printf("Failed to create file \"%s\".\n",filename); return;}
 i=0;
 y=0;
 while(y<16)
 {
  x=0;
  while(x<16)
  {
   if(i<0x20 || i>0x7E){fputc(' ',fp);}
   else {fputc(i,fp);}
   i+=1;
   x+=1;
  }
  fputc('\n',fp);
  y+=1;
 }
 
 fclose(fp);
}


/*functions below here use more than the 95 printable bytes*/

/*Print all 256 characters whether or not the operating system or font can print them.
Each character is on a separate line with it's ASCII number displayed.*/
void chaste_char_list_numbers_256()
{
 int i;
 i=0;
 while(i<=255)
 {
  printf("'%c' = %d\n",i,i);
  i+=1;
 }
 printf("\n");
}


/*save all 256 possible bytes to a binary file*/
void BBM_Save_256(const char *filename)
{
 int i;
 FILE* fp;
 fp=fopen(filename,"wb+");
 if(fp==NULL){printf("Failed to create file \"%s\".\n",filename); return;}

 i=0;
 while(i<256)
 {
  fputc(i,fp);
  i+=1;
 }
 
 fclose(fp);
}

