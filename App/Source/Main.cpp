#include "raylib.h"
#include "Core/Core.h"

#include "Player.h"
#include "DJ.h"

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1260, 720, "raylib [core] example - input keys");

	Core::UI::UIFont roboto = Core::UI::LoadFont("/Fonts/Roboto/Roboto-Regular.ttf", 50);
    Core::UI::UIFont robotoBold = Core::UI::LoadFont("/Fonts/Roboto/Roboto-Bold.ttf", 50);

    Core::UI::SetActiveFont(robotoBold);

    Player player;
    DJ dj;

    while (!WindowShouldClose())
    {
        Core::GetInputSystem()->Poll();

        dj.Update();
        player.Update();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        player.Render();
        dj.Render();

        Core::UI::DrawText("Defeat the evil DJ!", { 1.0f, 1.0f }, Core::UI::Origin::BottomRight, BLACK);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
