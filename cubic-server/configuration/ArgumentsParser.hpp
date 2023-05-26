#ifndef CONFIGURATION_ARGUMENTS_PARSER_HPP
#define CONFIGURATION_ARGUMENTS_PARSER_HPP

#include "ArgumentHolder.hpp"
#include "concept.hpp"
#include "details.hpp"
#include <argparse/argparse.hpp>
#include <string>

namespace configuration {
namespace _details {

/**
 * @brief Base class for ArgumentsParser, it is used like an interface
 *
 * @tparam T The parser
 * @tparam A The argument
 * @tparam H The argument encapsulation class, derived from _ArgumentHolder
 */
template<typename T, typename A, isBaseOf<_details::_ArgumentHolder<A>> H>
class _ArgumentsParser : public _ImplShared<T> {
public:
    typedef H Argument;
    typedef T Parser;

public:
    _ArgumentsParser(const std::shared_ptr<T> &parser):
        _ImplShared<T>(parser)
    {
    }

    virtual ~_ArgumentsParser() = default;
    virtual bool has(const std::string &argument) const = 0;
    virtual std::string get(const std::string &argument) const = 0;
    virtual void parse(const std::vector<std::string> &args) = 0;
    virtual Argument &addArgument(const std::string &argument) = 0;

    void parse(int argc, const char *const *argv);

protected:
    std::unordered_map<std::string, Argument> _arguments;
};
} // namespace _details

/**
 * @brief Actual implementation of the current parser: argparse
 */
class ArgumentsParser : public _details::_ArgumentsParser<argparse::ArgumentParser, argparse::Argument, ArgumentHolder> {
public:
    friend std::ostream &operator<<(std::ostream &os, const ArgumentsParser &parser);

public:
    ArgumentsParser(const std::string &name, const std::string &version);
    bool has(const std::string &argument) const override;
    std::string get(const std::string &argument) const override;
    void parse(const std::vector<std::string> &args) override;
    Argument &addArgument(const std::string &argument) override;
};

std::ostream &operator<<(std::ostream &os, const ArgumentsParser &parser);

} // namespace configuration

template<typename T, typename A, isBaseOf<configuration::_details::_ArgumentHolder<A>> H>
void configuration::_details::_ArgumentsParser<T, A, H>::parse(int argc, const char *const *argv)
{
    this->parse({argv, argv + argc});
}

#endif // CONFIGURATION_ARGUMENTS_PARSER_HPP
