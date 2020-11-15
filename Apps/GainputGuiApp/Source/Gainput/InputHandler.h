#pragma once

#include <gainput/gainput.h>

namespace GainputHelper
{

constexpr int maxButtons = 50;

class InputState
{
public:
    InputState()
    {
        keyboard = manager.CreateAndGetDevice<gainput::InputDeviceKeyboard>();
    }

    void updateButton(gainput::DeviceButtonSpec& button)
    {
        DBG ("Button pressed " << getButtonName(button));
    }

    char* getButtonName(gainput::DeviceButtonSpec& button)
    {
       keyboard->GetButtonName(button.buttonId, buttonText, maxButtons);
       return buttonText;
    }

    void pollUpdates()
    {
        manager.Update();

        auto size = keyboard->GetAnyButtonDown(buttons, maxButtons);

        for (size_t index = 0; index < size; ++index)
            updateButton(buttons[index]);
    }

private:
    char buttonText[maxButtons];
    gainput::DeviceButtonSpec buttons [maxButtons];

    gainput::InputManager manager;
    gainput::InputDeviceKeyboard* keyboard;
};

} // namespace GainputHelper
