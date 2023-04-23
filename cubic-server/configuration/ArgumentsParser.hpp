#ifndef CONFIGURATION_ARGUMENTS_PARSER_HPP
#define CONFIGURATION_ARGUMENTS_PARSER_HPP

#include <argparse/argparse.hpp>
#include <string>
#include "details.hpp"
#include "ArgumentHolder.hpp"
#include "concept.hpp"

namespace configuration {
namespace _details {

/**
 * @brief Base class for ArgumentsParser, it is used like an interface
 *
 * @tparam T
 */
template<typename T, typename A, is_base_of<_details::_ArgumentHolder<A&>> H>
class _ArgumentsParser : public _Impl<T> {
public:
    typedef H Argument;
    typedef T Parser;

public:
    virtual ~_ArgumentsParser() = default;
    virtual bool has(const std::string &argument) const = 0;
    virtual std::string get(const std::string &argument) const = 0;
    virtual void parse(int argc, char const * const *argv) = 0;
    virtual Argument &addArgument(const std::string &argument) = 0;

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
    bool has(const std::string &argument) const override;
    std::string get(const std::string &argument) const override;
    void parse(int argc, char const * const *argv) override;
    Argument &addArgument(const std::string &argument) override;
};

std::ostream &operator<<(std::ostream &os, const ArgumentsParser &parser);

} // namespace configuration

#endif // CONFIGURATION_ARGUMENTS_PARSER_HPP
