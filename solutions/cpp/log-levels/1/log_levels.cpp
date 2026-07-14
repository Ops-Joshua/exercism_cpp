#include <string>

namespace log_line
{
    std::string message(std::string line)
    {
        unsigned int colon;
        colon = line.find(":");
        // return the message
        return (line.substr(colon + 2));
    }

    std::string log_level(std::string line)
    {
        unsigned int open, close;
        open = line.find("[");
        close = line.find("]");        
        // return the log level
        return (line.substr(open + 1, close-1-open));
    }

    std::string reformat(std::string line)
    {
        std::string msg = message(line);
        std::string llvl = log_level(line);
        std::string newline;
        // return the reformatted message
        return msg + " (" + llvl + ")";
    }
} // namespace log_line
