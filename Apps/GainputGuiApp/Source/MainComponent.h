#pragma once

#include "CommonHeader.h"
#include "Gainput/InputHandler.h"

class MainComponent
    : public Component
    , public Timer
{
public:
    MainComponent()
    {
        setSize(600, 400);
        startTimerHz(200);
    }

    void timerCallback() override
    {
        input.pollUpdates();
    }

    void paint(Graphics& g) override
    {
        g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
    }

private:

    Label label;
    GainputHelper::InputState input;
};
