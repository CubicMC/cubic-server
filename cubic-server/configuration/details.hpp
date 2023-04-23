#ifndef CONFIGURATION_DETAILS_HPP
#define CONFIGURATION_DETAILS_HPP

namespace configuration::_details {
template<typename T>
class _Impl {
public:
    _Impl(const T &impl = T()):
        _impl(impl) {}
    T &getImpl()
    { return this->_impl; }
    virtual ~_Impl() = default;

protected:
    T _impl;
};
} // namespace _details::configuration

#endif // CONFIGURATION_DETAILS_HPP
