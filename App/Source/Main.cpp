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

    Core::GetInputSystem()->BindInput("MoveRight", KEY_D);
    Core::GetInputSystem()->BindInput("MoveLeft", KEY_A);
    Core::GetInputSystem()->BindInput("MoveUp", KEY_W);
    Core::GetInputSystem()->BindInput("MoveDown", KEY_S);

    Core::GetInputSystem()->BindInput("MoveRight", KEY_LEFT);
    Core::GetInputSystem()->BindInput("MoveLeft", KEY_RIGHT);
    Core::GetInputSystem()->BindInput("MoveUp", KEY_UP);
    Core::GetInputSystem()->BindInput("MoveDown", KEY_DOWN);

    while (!WindowShouldClose())
    {
        Core::GetInputSystem()->Poll();

        if (Core::GetInputSystem()->IsPressed("MoveRight")) position.x += 250.0f * GetFrameTime();
        if (Core::GetInputSystem()->IsPressed("MoveLeft")) position.x -= 250.0f * GetFrameTime();
        if (Core::GetInputSystem()->IsPressed("MoveUp")) position.y -= 250.0f * GetFrameTime();
        if (Core::GetInputSystem()->IsPressed("MoveDown")) position.y += 250.0f * GetFrameTime();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureEx(player, position, 0.0f, 0.25f, WHITE);

        Core::UI::DrawText("Defeat the evil DJ!", { 1.0f, 1.0f }, Core::UI::Origin::BottomRight, BLACK);


        EndDrawing();
    }
    
    UnloadTexture(player);
    CloseWindow();

    return 0;
}