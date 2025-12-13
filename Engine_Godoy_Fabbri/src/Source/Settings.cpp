#include "Settings.h"

bool Settings::debugMode = false;

bool Settings::getDebugMode()
{
    return debugMode;
}

void Settings::setDebugMode(const bool value)
{
    debugMode = value;
}