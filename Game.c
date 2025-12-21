#include <stdio.h>
#include "/home/abderrahim/Bureau/DEV/C/raylib-5.5_linux_amd64/include/raylib.h"
#include <stdbool.h>

#define YELLOW_01 (Color) {186, 252, 3,200}
#define WIDTH  800
#define HEIGHT 450

void CercleMouvment(Vector2 *p,float speed)
{
  if(IsKeyDown(KEY_W)){p->y -= 1.0f * speed;}
  if(IsKeyDown(KEY_S)){p->y += 1.0f * speed;}
  if(IsKeyDown(KEY_D)){p->x += 1.0f * speed;}
  if(IsKeyDown(KEY_A)){p->x -= 1.0f * speed;}
  // return Cercle;
}

void CercleLimts(Vector2 *p, int radius)
{
  if((p->x + radius) > WIDTH) {p->x = WIDTH - radius;}
  if((p->x - radius) <= 0)    {p->x = radius;}
  if((p->y + radius) > HEIGHT){p->y = HEIGHT- radius;}
  if((p->y - radius) <=0)     {p->y = radius;} 
}



int main(void)
{
  int   radius   = 50;
  float speed    = 10.0f; 
  InitWindow(WIDTH, HEIGHT, "Mouvent Cercle");
  Vector2 Cercle_1 = {(float)radius, (float) HEIGHT/2};
  SetTargetFPS(120);
  while (!WindowShouldClose())
  {
    CercleLimts(&Cercle_1, radius);
    CercleMouvment(&Cercle_1,speed);
    
    DrawFPS(0,10);
    BeginDrawing();
      ClearBackground(BLACK);
      DrawCircleV(Cercle_1,radius,YELLOW_01);
    EndDrawing();
  }
  

  return 0;
}




