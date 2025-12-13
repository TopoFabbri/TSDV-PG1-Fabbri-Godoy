#pragma once
#include "Exports.h"

class TOTO_API Settings
{
    static bool debugMode;
    
public:
    static bool getDebugMode();
    
    static void setDebugMode(bool value);
};
