#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);
  int i,k;
  i = 0;
  k = 0;
  for(i;i<500;i++){
    for(k;k<500;k++){
      c.green = 0;
      c.red = 0;
      c.green +=i;
      c.blue = k;
      draw_line(300,300,i,k,s,c);
      c.green += (i+k);
      c.red = MAX_COLOR;
      c.blue = 0;
      draw_line(i,k,498-k,498-i,s,c);
      
    }
  }
  /* draw_line(0,0,400,400,s,c);
  draw_line(400,400,500,300,s,c);
  draw_line(200,100,250,150,s,c);
  draw_line(0,0,100,200,s,c);
  draw_line(330,100,400,70,s,c);
  draw_line(0,100,10,0,s,c);
  draw_line(250,250,0,250,s,c);
  draw_line(100,400,100,100,s,c);
  display(s);
  */
  save_extension(s, "lines.png");
}  
