#ifndef CUBIC_SERVER_COMMANDLINE_HPP
#define CUBIC_SERVER_COMMANDLINE_HPP

#include <thread>

class CommandLine
{
public:
    CommandLine(): _running(true) {}
    /**
     * @brief Launch a loop that will read stdin and parse the command
     */
    void launch();
    void stop();

private:
    void run();

private:
    std::atomic<bool> _running;
    std::thread _thread;
};

#endif //CUBIC_SERVER_COMMANDLINE_HPP
