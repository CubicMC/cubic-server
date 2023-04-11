#ifndef CONFIG_ARGUMENTSHOLDER_HPP
#define CONFIG_ARGUMENTSHOLDER_HPP

#include <string>
#include <argparse/argparse.hpp>

namespace configuration
{

/**
 * @brief This class is only usefull if one day we want to change the way we handle arguments
 */
class ArgumentsHolder
{
public:
    typedef argparse::ArgumentParser Parser;

public:
    ArgumentsHolder() = default;

    void init();
    void parseArgs(int argc, char **argv);

    bool has(const std::string &argument) const;

    template<typename T>
    T operator[](const std::string &argument) const;

    template<typename T>
    T get(const std::string &argument) const;

    const Parser &impl() const;

private:
    argparse::ArgumentParser _parser;
};

std::ostream &operator<<(std::ostream &os, const ArgumentsHolder &parser);

} // namespace configuration

#endif // CONFIG_ARGUMENTSHOLDER_HPP
