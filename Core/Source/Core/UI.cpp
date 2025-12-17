#include "UI.h"

namespace Core {

	namespace UI {

		UIFont LoadFont(std::filesystem::path filepath, float desiredFontSize)
		{
			UIFont font;
			font.RaylibFont = LoadFontEx(filepath.string().c_str(), desiredFontSize * fontScale, nullptr, 0);
			font.Size = desiredFontSize;

			return font;
		}

		Vector2 AlignmentToPosition(Vector2 alignment)
		{
			Vector2 position;
			Vector2 screenSize = { (float)GetScreenWidth(), (float)GetScreenHeight() };

			position.x = alignment.x * screenSize.x;
			position.y = alignment.y * screenSize.y;

			return position;
		}

		void DrawText(std::string_view text, Vector2 alignment, Origin origin, Colour colour)
		{
			Vector2 position = AlignmentToPosition(alignment);
			Vector2 raylibOrigin;

			if (origin == Origin::Centre) {
				raylibOrigin = { 0.5f, 0.5f };
			}
			else if (origin == Origin::TopLeft) {
				raylibOrigin = { 0.0f, 0.0f };
			}
			else if (origin == Origin::BottomRight) {
				raylibOrigin = { 1.0f, 1.0f };
			}

			//DrawTextPro(activeFont, text.data(), position, raylibOrigin * MeasureTextEx(activeFont, text.data(), size, 0), 0.0f, size, 0.0f, colour);
			DrawTextEx(activeFont.RaylibFont, text.data(), position - (raylibOrigin * MeasureTextEx(activeFont.RaylibFont, text.data(), activeFont.Size, 0)), activeFont.Size, 0.0f, colour);
		}

	}

}