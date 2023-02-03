#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <math.h>

namespace Tmpl8
{
	void Game::Init() {}
	void Game::Shutdown() {}


    // converts HSV values to RGB
    void Game::HSVtoRGB(float& fR, float& fG, float& fB, float hue, float value, float saturation)
    {
        // explanation on conversion from HSV to RGB: https://youtu.be/hW4gZ4tGwds
        float rgbRange = value * saturation;
        float rgbMax = value;
        float rgbMin = value - rgbRange;
        float hPrime = hue / 60.0f;
        float slopeUp = fmod(hPrime, 1.0f);
        float slopeDown = 1.0f - fmod(hPrime, 1.0f);

        // sets the RGB values based on the hue
        if ((hPrime >= 0) && (hPrime < 1))
        {
            fR = rgbMax;
            fG = (slopeUp * rgbRange) + rgbMin;
            fB = rgbMin;
        }
        else if ((hPrime >= 1) && (hPrime < 2))
        {
            fR = (slopeDown * rgbRange) + rgbMin;;
            fG = rgbMax;
            fB = rgbMin;
        }
        else if ((hPrime >= 2) && (hPrime < 3))
        {
            fR = rgbMin;
            fG = rgbMax;
            fB = (slopeUp * rgbRange) + rgbMin;;
        }
        else if ((hPrime >= 3) && (hPrime < 4))
        {
            fR = rgbMin;
            fG = (slopeDown * rgbRange) + rgbMin;;
            fB = rgbMax;
        }
        else if ((hPrime >= 4) && (hPrime < 5))
        {
            fR = (slopeUp * rgbRange) + rgbMin;;
            fG = rgbMin;
            fB = rgbMax;
        }
        else if ((hPrime >= 5) && (hPrime < 6))
        {
            fR = rgbMax;
            fG = rgbMin;
            fB = (slopeDown * rgbRange) + rgbMin;;
        }
        else
        {
            fR = 0.0f;
            fG = 0.0f;
            fB = 0.0f;
        }
    }


    float h{ 0.0f }; // ranges from 0 - 359.999...
    float s{ 1.0f }; // ranges from 0 - 1
    float v{ 1.0f }; // ranges from 0 - 1
    int frame = 0;

    void Game::Tick(float deltaTime)
    {
        // the copy resets the hue to the original value every tick
        float hCopy = h;
        for (int x = 0; x < screen->GetWidth(); x++)
        {
            // modifies the hue value based on the x position
            hCopy += 360.0f / static_cast<float>(screen->GetWidth());
            hCopy = fmod(hCopy, 360.0f);

            // converts HSV to RGB, then prints the color as a vertical line
            float r = 0.0f, g = 0.0f, b = 0.0f;
            HSVtoRGB(r, g, b, hCopy, s, v);
            r *= 255.0f;
            g *= 255.0f;
            b *= 255.0f;
            int newColor = (static_cast<int>(r) << 16 | static_cast<int>(g) << 8 | static_cast<int>(b));


            screen->Line((x + frame) % screen->GetWidth(), 0, (x + frame) % screen->GetWidth(), screen->GetHeight(), newColor);
        }

        frame += 5;
    }
};