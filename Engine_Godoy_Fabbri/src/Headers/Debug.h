#pragma once
#include <string>

namespace ToToEng
{
    class Debug
    {
        public:
        static void log(const char* text);
        static std::string getFormattedStackTrace();
    };
}
