#include "Debug.h"

#include <iostream>
#include <string>
#include <boost/stacktrace.hpp>
#include <sstream>

#include "GameTime.h"

namespace ToToEng
{
    // ANSI escape codes for colors
    static const char* reset = "\033[0m";
    static const char* yellow = "\033[33m";
    static const char* gray = "\033[90m";

    void Debug::log(const char* text)
    {
        const std::string time = GameTime::formatTime(GameTime::getTime());
        const std::string stacktrace = getFormattedStackTrace();

        std::cout << yellow << "[" << time << "] " << reset << text
                  << gray << "\nat:\n\t" << stacktrace << reset << "\n\n";
    }

    std::string Debug::getFormattedStackTrace()
    {
        std::stringstream ss;
        ss << boost::stacktrace::stacktrace(1, 10); // Skip this function, max 10 frames

        std::string stacktrace = ss.str();
        
        // Trim trailing newline if it exists
        if (!stacktrace.empty() && stacktrace.back() == '\n')
        {
            stacktrace.pop_back();
        }

        size_t startPos = 0;
        while((startPos = stacktrace.find('\n', startPos)) != std::string::npos) {
            stacktrace.replace(startPos, 1, "\n\t");
            startPos += 2;
        }

        return stacktrace;
    }
}
