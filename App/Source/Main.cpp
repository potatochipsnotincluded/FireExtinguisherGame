#include "raylib.h"
#include "Core/Core.h"

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1260, 720, "raylib [core] example - input keys");


	Core::UI::UIFont roboto = Core::UI::LoadFont("Fonts/Roboto/Roboto-Regular.ttf", 50);
    Core::UI::UIFont robotoBold = Core::UI::LoadFont("Fonts/Roboto/Roboto-Bold.ttf", 50);

    Core::UI::SetActiveFont(robotoBold);

    Texture2D player = LoadTexture("Art/player.png");
    SetTextureFilter(player, TEXTURE_FILTER_BILINEAR);

    Vector2 position = { 500, 500 };

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_D)) position.x += 250.0f * GetFrameTime();
        if (IsKeyDown(KEY_A)) position.x -= 250.0f * GetFrameTime();
        if (IsKeyDown(KEY_W)) position.y -= 250.0f * GetFrameTime();
        if (IsKeyDown(KEY_S)) position.y += 250.0f * GetFrameTime();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureEx(player, position, 0.0f, 0.45f, WHITE);

		Core::UI::DrawText("Defeat the evil DJ!", { 1.0f, 1.0f }, Core::UI::Origin::BottomRight, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}