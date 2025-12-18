#pragma once
#include "raylib.h"
#include "Maths.h"

#include <string_view>
#include <filesystem>

namespace Core {

	namespace UI {

		using Colour = Color; // <3

		enum class Origin
		{
			Centre = 0,
			TopLeft,
			BottomRight
		};

		struct UIFont
		{
			Font RaylibFont;
			float Size;
		};

		inline constexpr float fontScale = 2.0f;
		inline UIFont activeFont;

		inline void SetActiveFont(const UIFont& font) {
			activeFont = font;
		}
        
        Texture2D LoadFileTexture(const std::string& filepath);
		UIFont LoadFont(const std::string& filepath, float desiredFontSize);

		Vector2 AlignmentToPosition(Vector2 alignment);

		void DrawText(std::string_view text, Vector2 alignment, Origin origin, Colour colour);

	}

}
