/* Random grid of colors that fill an 8.5 x 11 page */
/* Eric Li */
double L = 8.5; /* Length */
double W = 11; /* Width */
int DPI = 72; /* DPI */

int n = 40; /* Dimensions of square */ 

int r,g,b; /* R G B values */ 

boolean animate = false; /* true to animate */

/* Sets up the canvas */
void setup() {
  size((int)(L*DPI),(int)(W*DPI));
  background(255);
 
   /* X, Y coord system */
  for (int x = 15; x < width-n; x+=n+n/2.) 
  {
    for (int y = 15; y < height-n; y+=n+n/2.)
    {
      stroke(255);
      r = (int)random(255);
      g = (int)random(255);
      b = (int)random(255);
      fill(r,g,b);
      rect(x,y,n,n);
    } 
  }
 
  save("output.png"); 
}

void draw()
{
  if (animate)
  {
    frameRate(25);
     /* X, Y coord system */
    for (int x = 15; x < width-n; x+=n+n/2.) 
    {
      for (int y = 15; y < height-n; y+=n+n/2.)
      {
        stroke(255);
        r = (int)random(255);
        g = (int)random(255);
        b = (int)random(255);
        fill(r,g,b);
        rect(x,y,n,n);
      } 
    }
  }
}
