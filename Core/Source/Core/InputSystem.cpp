#include "InputSystem.h"

uint32_t HashName(const std::string& str)
{
	uint32_t hash = 2166136261u; // FNV offset basis
	for (char c : str)
	{
		hash ^= static_cast<uint8_t>(c);
		hash *= 16777619u;       // FNV prime
	}
	return hash;
}

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
			
			for (int32_t code : it->second.mouseCodes)
			{
				down |= IsMouseButtonDown(code);
				pressed |= IsMouseButtonPressed(code);
				released |= IsMouseButtonReleased(code);
			}

			it->second.isPressed = down;
			it->second.wasJustPressed = pressed;
			it->second.wasJustReleased = released;
		}
	}

	ActionID InputSystem::BindKeyInput(const std::string& actionName, int32_t keyCode)
	{
		ActionID name = HashName(actionName);

		if (bindings.find(name) == bindings.end())
		{
			InputBinding binding{};
			bindings[name] = binding;
		}

		bindings[name].keyCodes.push_back(keyCode);

		return name;
	}

	ActionID InputSystem::BindMouseInput(const std::string& actionName, int32_t mouseCode)
	{
		ActionID name = HashName(actionName);

		if (bindings.find(name) == bindings.end())
		{
			InputBinding binding{};
			bindings[name] = binding;
		}

		bindings[name].mouseCodes.push_back(mouseCode);

		return name;
	}

	bool InputSystem::IsPressed(ActionID actionName)
	{
		return bindings[actionName].isPressed;
	}

	bool InputSystem::WasJustPressed(ActionID actionName)
	{
		return bindings[actionName].wasJustPressed;
	}

	bool InputSystem::WasJustReleased(ActionID actionName)
	{
		return bindings[actionName].wasJustReleased;
	}


}
