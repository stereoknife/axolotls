//
//  main.cpp
//  axolotls
//
//  Created by kam on 5.2.2023.
//

#include <iostream>
#include "types.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

void Draw(r::Window win);

int main(int argc, const char * argv[]) {
    r::Window win(SCREEN_WIDTH, SCREEN_HEIGHT, "Axolotls");
    
    SetTargetFPS(60);
    SetExitKey(KEY_DELETE);
    
    while (!win.ShouldClose())
    {
        BeginDrawing();
        Draw(win);
        EndDrawing();
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}

inline void Draw(r::Window win) {
    
}
