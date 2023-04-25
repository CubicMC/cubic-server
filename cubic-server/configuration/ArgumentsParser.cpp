#include "ArgumentsParser.hpp"

configuration::ArgumentsParser::ArgumentsParser(const std::string &name, const std::string &version):
    _details::_ArgumentsParser<argparse::ArgumentParser, argparse::Argument, ArgumentHolder>(std::make_shared<argparse::ArgumentParser>(name, version))
{ }

bool configuration::ArgumentsParser::has(const std::string &argument) const
{ return this->_impl->is_used(argument); }

std::string configuration::ArgumentsParser::get(const std::string &argument) const
{ return this->_impl->get<std::string>(argument); }

void configuration::ArgumentsParser::parse(const std::vector<std::string> &args)
{ this->_impl->parse_args(args); }

configuration::ArgumentsParser::Argument &configuration::ArgumentsParser::addArgument(const std::string &argument)
{
    this->_arguments.emplace(std::make_pair(argument, Argument(this->_impl->add_argument(argument))));
    return this->_arguments.at(argument);
}

std::ostream &configuration::operator<<(std::ostream &os, const configuration::ArgumentsParser &parser)
{ return os << *parser._impl; }
