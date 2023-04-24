#include "ArgumentsParser.hpp"

bool configuration::ArgumentsParser::has(const std::string &argument) const
{ return this->_impl.is_used(argument); }

std::string configuration::ArgumentsParser::get(const std::string &argument) const
{ return this->_impl.get<std::string>(argument); }

void configuration::ArgumentsParser::parse(int argc, char const * const *argv)
{ this->_impl.parse_args(argc, argv); }

configuration::ArgumentsParser::Argument &configuration::ArgumentsParser::addArgument(const std::string &argument)
{
    this->_arguments.emplace(std::make_pair(argument, Argument(this->_impl.add_argument(argument))));
    return this->_arguments.at(argument);
}

std::ostream &configuration::operator<<(std::ostream &os, const configuration::ArgumentsParser &parser)
{ return os << parser._impl; }