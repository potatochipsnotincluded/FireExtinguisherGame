#include "InputSystem.h"

namespace Core {

	InputSystem::InputSystem()
	{

	}

	void InputSystem::Poll()
	{
		for (auto it = bindings.begin(); it != bindings.end(); ++it)
		{
			bool down = false;
			bool pressed = false;
			bool released = false;

			for (int32_t code : it->second.keyCodes)
			{
				down |= IsKeyDown(code);
				pressed |= IsKeyPressed(code);
				released |= IsKeyReleased(code);
			}

			it->second.isPressed = down;
			it->second.wasJustPressed = pressed;
			it->second.wasJustReleased = released;
		}
	}

	void InputSystem::BindInput(const std::string& actionName, int32_t keyCode)
	{
		const std::string& name = actionName;

		if (bindings.find(name) == bindings.end())
		{
			InputBinding binding{};
			bindings[name] = binding;
		}

		bindings[name].keyCodes.push_back(keyCode);
	}

	bool InputSystem::IsPressed(const std::string& actionName)
	{
		return bindings[actionName].isPressed;
	}

	bool InputSystem::WasJustPressed(const std::string& actionName)
	{
		return bindings[actionName].wasJustPressed;
	}

	bool InputSystem::WasJustReleased(const std::string& actionName)
	{
		return bindings[actionName].wasJustReleased;
	}


}
