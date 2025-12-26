#include <stdio.h>
#include "/home/abderrahim/Bureau/DEV/C/raylib-5.5_linux_amd64/include/raylib.h"
#include <math.h>
// #include <__clang_hip_math.h>

#define HEIGHT 450
#define WIDTH  900
#define MAX_BUILDINGS 100
#define FLAG_WINDOW_RESIZABLE 0x00000004
// SetConfigFlags(FLAG_WINDOW_RESIZABLE);




// void GeneratRec(Vector2 *p, Vector2 *p2, Color *p3)
// {
//     // Vector3 D = { 0 };
//     Vector2 *Rectangle_01[MAX_BUILDINGS] = { 0 };
//     Vector2 *RecPosition[MAX_BUILDINGS]  = { 0 };
//     Color *color[MAX_BUILDINGS]          = { 0 };

//     *p = *Rectangle_01[MAX_BUILDINGS];
//     *p2= *RecPosition[MAX_BUILDINGS];
//     *p3= *color[MAX_BUILDINGS];

//     for (int i = 0; i < MAX_BUILDINGS; i++)
//     {
//         Rectangle_01[i]->x    = GetRandomValue(50, 300);
//         Rectangle_01[i]->y    = GetRandomValue(50, 100);
//         RecPosition[i]->x  = GetRandomValue(0, WIDTH);
//         RecPosition[i]->y  = HEIGHT/2;
//         color[i]->a        = GetRandomValue(10,50);
//         color[i]->r        = GetRandomValue(0,255);
//         color[i]->g        = GetRandomValue(0,255);
//         color[i]->b        = GetRandomValue(0,255);

//     }  
// }

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
    Rectangle Mainplayer               = {WIDTH/2,HEIGHT/2,50,50 };
    Rectangle Buildings[MAX_BUILDINGS] = { 0 };
    Color color[MAX_BUILDINGS]         = { 0 };
    int Spacing = 0;
    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    for (int i = 0; i < MAX_BUILDINGS; i++)
    {
        Buildings[i].width  = (float) GetRandomValue(50, 100);
        Buildings[i].height = (float)GetRandomValue(100, 200);
        Buildings[i].x      = -100.0f + Spacing;
        Buildings[i].y      = HEIGHT/2 - Buildings[i].height + 50; 
        Spacing            += (int)Buildings[i].width;

        color[i].a        = GetRandomValue(10,60);
        color[i].r        = GetRandomValue(0,255);
        color[i].g        = GetRandomValue(0,255);
        color[i].b        = GetRandomValue(0,255);

    } 

    // GeneratRec();

    Camera2D Camera = {{WIDTH/2, HEIGHT/2}, {Mainplayer.x, Mainplayer.y}, 0.0f, 1.0f};
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {   
        
        Camera.zoom = expf(logf(Camera.zoom) + ((float)GetMouseWheelMove()*0.1f));
        Camera.target = (Vector2){Mainplayer.x + 25, Mainplayer.y + 25};
        CamPosition(&Camera);


        BeginDrawing(); 
            ClearBackground(WHITE);
            BeginMode2D(Camera);
            DrawRectangleRec(Mainplayer, RED);
            for ( int i = 0; i < MAX_BUILDINGS; i++){DrawRectangleRec(Buildings[i], color[i]); }
            
                
                // DrawCircleLinesV(Cercle, RADIUS, PINK);
            EndMode2D();
        EndDrawing();
                
    }
    

    
    return 0;
}