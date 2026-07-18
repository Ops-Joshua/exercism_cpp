#include <string>

namespace log_line
{
    std::string message(std::string line)
    {
        //unsigned int colon;
        //colon = line.find(":");
        // return the message
        return (line.substr(line.find(":")+ 2));
    }

    std::string log_level(std::string line)
    {        
        //unsigned int open, close;
        //open = line.find("[");
        //close = line.find("]");   
        // return the log level
        return (line.substr(line.find("[") + 1 , line.find("]") - 1 ));
    }

    std::string reformat(std::string line)
    {
        //std::string msg = message(line);
        //std::string llvl = log_level(line);
        // return the reformatted message
        return (message(line) + " (" + log_level(line) + ")");
    }
} // namespace log_line
