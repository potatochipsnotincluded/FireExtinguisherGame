#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "raylib.h"

namespace Core {

	using ActionID = uint32_t;

	struct InputBinding
	{
		bool isPressed;
		bool wasJustPressed;
		bool wasJustReleased;

		std::vector<int32_t> keyCodes;
		std::vector<int32_t> mouseCodes;
	};

	class InputSystem
	{
	public:
		InputSystem();

		void Poll();

		ActionID BindKeyInput(const std::string& actionName, int32_t keyCode); // Must use const string& instead of string_view to make it easier to hash
		ActionID BindMouseInput(const std::string& actionName, int32_t mouseCode);

		bool IsPressed(ActionID actionName);
		bool WasJustPressed(ActionID actionName);
		bool WasJustReleased(ActionID actionName);

	private:
		std::unordered_map<ActionID, InputBinding> bindings;
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
