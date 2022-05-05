#include <iostream>
#include "raylib.h"
#include "Game.h"

int main()
{
    //Creates a new Game type that is actually a TanksGame type (which is essentially a Game
            //  type but more specific.
    Game* game = new Game();

    //Setting how wany frames per second the game should be running at.
    SetTargetFPS(120);
    //Sets the size of the game window and the name of the window.
    InitWindow(1280, 720, "Pong");

    //Initialises the game to run the init code found in the game.cs
    game->Init();

    //While the window is open..keep updating and drawing whatever is being requested from
    //  other classes.
    while (!WindowShouldClose())
    {
        game->Update();
        game->Draw();
    }

    //Calls upon the shutdown function.
    game->Shutdown();

    //Closes the game.
    CloseWindow();
}