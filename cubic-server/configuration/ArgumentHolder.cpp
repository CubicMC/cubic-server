#include "ArgumentHolder.hpp"

configuration::ArgumentHolder &configuration::ArgumentHolder::required()
{
    this->_impl.required();
    return *this;
}

configuration::ArgumentHolder &configuration::ArgumentHolder::help(const std::string &help)
{
    this->_impl.help(help);
    return *this;
}

configuration::ArgumentHolder &configuration::ArgumentHolder::implicit()
{
    this->_impl.default_value(std::string("false")).implicit_value(std::string("true"));
    return *this;
}
