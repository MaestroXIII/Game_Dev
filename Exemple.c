#include <stdio.h>
#include "/home/abderrahim/Bureau/DEV/C/raylib-5.5_linux_amd64/include/raylib.h"
#include <math.h>
// #include <__clang_hip_math.h>

#define HEIGHT 450
#define WIDTH  900
#define RADIUS 50
#define MAX_BUILDINGS 10




void GeneratRec(Vector2 *p, Vector2 *p2, Color *p3)
{
    // Vector3 D = { 0 };
    Vector2 *Rectangle_01[MAX_BUILDINGS] = { 0 };
    Vector2 *RecPosition[MAX_BUILDINGS]  = { 0 };
    Color *color[MAX_BUILDINGS]          = { 0 };

    *p = *Rectangle_01[MAX_BUILDINGS];
    *p2= *RecPosition[MAX_BUILDINGS];
    *p3= *color[MAX_BUILDINGS];

    for (int i = 0; i < MAX_BUILDINGS; i++)
    {
        Rectangle_01[i]->x    = GetRandomValue(50, 300);
        Rectangle_01[i]->y    = GetRandomValue(50, 100);
        RecPosition[i]->x  = GetRandomValue(0, WIDTH);
        RecPosition[i]->y  = HEIGHT/2;
        color[i]->a        = GetRandomValue(10,50);
        color[i]->r        = GetRandomValue(0,255);
        color[i]->g        = GetRandomValue(0,255);
        color[i]->b        = GetRandomValue(0,255);

    }  
}

void DrawRec(void)
{
    
}

void CamPosition(Camera2D *Camera)
{
    if (Camera->zoom <  0.8f){Camera->zoom =  0.8f;} /*expf(logf(Camera->zoom*0.1f));}*/
    if (Camera->zoom > 3.0f){Camera->zoom = 3.0f;}/*(logf(Camera->zoom*0.1f));}*/
    if (IsKeyDown(KEY_Q)){if(Camera->rotation > 38.0f){ expf(logf(Camera->rotation*0.01f));} else {Camera->rotation += 2;}}
    if (IsKeyDown(KEY_E)){if(Camera->rotation < -38.0f){expf(logf(Camera->rotation*0.1f));} else {Camera->rotation -= 2;}}
    if (IsKeyDown(KEY_R)){Camera->rotation = 0; Camera->zoom = 1.0f;}
}

int main(void)
{
    
    InitWindow(WIDTH, HEIGHT, "2D Camera");
    Vector2 Rectangle = {WIDTH/2, HEIGHT/2 };
    Vector2 SiezRectangle = {50,100};

    GeneratRec();
    // Rectangle[NumberOfBuilduings] = {0,0};
    // for (int i = 0; i < MAX_BUILDINGS; i++)
    // {
    //     Rectangle_01[i].x = GetRandomValue(50, 300);
    //     Rectangle_01[i].y = GetRandomValue(50, 100);
    //     RecPosition[i].x  = GetRandomValue(0, WIDTH);
    //     RecPosition[i].y  = HEIGHT/2; /*GetRandomValue(HEIGHT/2 - 100, HEIGHT/2);  */
    //     color[i].a        = GetRandomValue(10,50);
    //     color[i].r        = GetRandomValue(0,255);
    //     color[i].g        = GetRandomValue(0,255);
    //     color[i].b        = GetRandomValue(0,255);

    // } 

    // GeneratRec();

    Camera2D Camera = {{WIDTH/2 - 50, HEIGHT/2}, {Rectangle.x, Rectangle.y}, 0, 1.0f};
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {   
        
        Camera.zoom = expf(logf(Camera.zoom) + ((float)GetMouseWheelMove()*0.1f));
        CamPosition(&Camera);
        printf("%d\n", GetRenderWidth());


        BeginDrawing(); 
            ClearBackground(WHITE);
            BeginMode2D(Camera);
                DrawRectangleV(Rectangle, SiezRectangle, RED);
                // DrawLine(0, HEIGHT/2 + 100, WIDTH, HEIGHT/2 + 100, BLUE);
                DrawRectangle(0, HEIGHT/2 + 100, WIDTH, HEIGHT/2 + 100, BLUE);
                for (int i = 0; i < MAX_BUILDINGS; i++)
                {
                    DrawRectangleV(RecPosition[i],Rectangle_01[i], color[i] );
                    /* code */
                }
                
                // DrawCircleLinesV(Cercle, RADIUS, PINK);
            EndMode2D();
        EndDrawing();
                
    }
    

    
    return 0;
}