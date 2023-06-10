#include <vector>
#include <string>

class Logger
{
public:
    void log(std::string logMessage);
    std::vector<std::string> getLogs();
protected:
    std::vector<std::string> buffer;
};