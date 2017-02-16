#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int check(int x0,int y0,int x1,int y1){
  int A,B,C,A1,B1;
  C = 0;
  A = y1 - y0;
  B = x1 - x0;
  A1 = y0-y1;
  B1 = x0-x1;
  printf("A:%d,B:%d\n",A,B);
  //Oct 1
  if(B>0&&A>0){
    if(B>=A){
      C=1;
    }
  }
  //Oct 2
  if(B>0 && A>0){
    if(A>B){
      C=2;
    }
  }
  //Oct 8
  if(A1>0 &&B>0){
    if(B>=A1){
      C=8;
    }
  }
  //Oct 7
  if(A1>0 && B>0){
    if(A1>B){
      C = 7;
    }
  }
  //Other Oct
  if(B1>0){
    C= 9;
  }
  //horizontal
  if(!A){
    C=10;
  }
  printf("%d\n",C);  
  return C;
}
void draw_line2(int x0,int y0,int x1,int y1,screen s,color c){
  int A,B,D,x,y,m;
  x = x0;
  y = y0;
  m = check(x0,y0,x1,y1);
  //plot(s,c,x,y);
  if(m == 1){
    //OCT 1
    A = (y1 - y);
    B = -1*(x1- x);
    D = (2*A + B);
    while(x < x1){
      plot(s,c,x,y);
      // printf("%d,%d,%d\n",x,y,c);
      if(D>0){
	y++;
	D+= 2*B;
      }
      x++;
      D+=2*A;
    }
  }

  if(m == 2){
    //OCT 2
    A = (y1-y);
    B = -1 * (x1-x);
    D = (2*B + A);
    while(y < y1){
      plot(s,c,x,y);
      if(D<0){
	x++;
	D+= 2 * A;
      }
      y++;
      D+=2*B;
    }
  }
  if(m == 8){
    //OCT 8
    A = (y1-y);
    B = -1 * (x1-x);
    D = (2*A -B);
    while(x < x1){
      plot(s,c,x,y);
      if(D<0){
	y--;
	D+=2*B;
      }
      x++;
      D+=2*A;
    }
  }
  if(m == 7){
    //OCT 7
    A = (y1 -y);
    B = -1 * (x1-x);
    D = A - (2 * B);
    while(y > y1){
      plot(s,c,x,y);
      if(D>0){
	x++;
	D+= 2 * A;
      }
      y--;
      D-=2 * B;
    }
  }
  if(m == 9){
    draw_line2(x1,y1,x0,y0,s,c);
  }
  if(m==0){
    while(y<y1){
      plot(s,c,x,y);
      y++;
    }
  }
  if(m==10){
    while(x<x1){
      plot(s,c,x,y);
      x++;
    }
  }
}
  
//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int A,B,D,x,y,m;
  x = x0;
  y = y0;
  m = check(x0,y0,x1,y1);
  //plot(s,c,x,y);
  if(m == 1){
    //OCT 1
    A = (y1 - y);
    B = -1*(x1- x);
    D = (2*A + B);
    while(x < x1){
      plot(s,c,x,y);
      // printf("%d,%d,%d\n",x,y,c);
      if(D>0){
	y++;
	D+= 2*B;
      }
      x++;
      D+=2*A;
    }
  }

  if(m == 2){
    //OCT 2
    A = (y1-y);
    B = -1 * (x1-x);
    D = (2*B + A);
    while(y < y1){
      plot(s,c,x,y);
      if(D<0){
	x++;
	D+= 2 * A;
      }
      y++;
      D+=2*B;
    }
  }
  if(m == 8){
    //OCT 8
    A = (y1-y);
    B = -1 * (x1-x);
    D = (2*A -B);
    while(x < x1){
      plot(s,c,x,y);
      if(D<0){
	y--;
	D+=2*B;
      }
      x++;
      D+=2*A;
    }
  }
  if(m == 7){
    //OCT 7
    A = (y1 -y);
    B = -1 * (x1-x);
    D = A - (2 * B);
    while(y > y1){
      plot(s,c,x,y);
      if(D>0){
	x++;
	D+= 2 * A;
      }
      y--;
      D-=2 * B;
    }
  }
  if(m == 9){
    draw_line2(x1,y1,x0,y0,s,c);
  }
  if(m==0){
    if(y1>y){
      while(y<y1){
	plot(s,c,x,y);
	y++;
      }
    }
    else{
      draw_line2(x1,y1,x0,y0,s,c);
    }
  }
  if(m==10){
    if(x1>x){
      while(x<x1){
	plot(s,c,x,y);
	x++;
      }
    }
    else{
      draw_line2(x1,y1,x0,y0,s,c);
    }
  }
}
