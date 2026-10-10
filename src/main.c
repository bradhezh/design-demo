#include "raylib.h"

int main(void) {
    // Initialize a display window (Width, Height, Title)
    InitWindow(800, 450, "raylib [core] - minimal window");
    
    // Cap the framerate loop at 60 FPS
    SetTargetFPS(60);

    // Core Event Loop
    while (!WindowShouldClose()) {
        // --- 1. Event / State Updates (Put logic here later) ---

        // --- 2. Frame Rendering Loop ---
        BeginDrawing();
            // Clear out the previous frame graphics
            ClearBackground(RAYWHITE);
            
            // Render text centered relative to its font spacing
            DrawText("Congrats! Your first raylib app works.", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    // Destroy the context and release display hardware hooks
    CloseWindow();
    return 0;
}

