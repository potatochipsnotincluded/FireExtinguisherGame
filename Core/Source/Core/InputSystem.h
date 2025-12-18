#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "raylib.h"

namespace Core {

	struct InputBinding
	{
		bool isPressed;
		bool wasJustPressed;
		bool wasJustReleased;

		std::vector<int32_t> keyCodes;
	};

	class InputSystem
	{
	public:
		InputSystem();

		void Poll();

		void BindInput(const std::string& actionName, int32_t keyCode); // Must use const string& instead of string_view due to unordered_map key requirement.

		bool IsPressed(const std::string& actionName);
		bool WasJustPressed(const std::string& actionName);
		bool WasJustReleased(const std::string& actionName);

	private:
		std::unordered_map<std::string, InputBinding> bindings;
	};

	inline std::shared_ptr<InputSystem> g_InputSystem;

	inline std::shared_ptr<InputSystem> GetInputSystem()
	{
		if (!g_InputSystem)
		{
			g_InputSystem = std::make_shared<InputSystem>();
		}

		return g_InputSystem;
	}

}
