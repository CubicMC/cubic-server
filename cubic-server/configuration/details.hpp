#ifndef CONFIGURATION_DETAILS_HPP
#define CONFIGURATION_DETAILS_HPP

#include <memory>

namespace configuration::_details {
template<typename T>
class _Impl {
public:
    _Impl(const T &impl = T()):
        _impl(impl)
    {
    }
    virtual T &getImpl() { return this->_impl; }
    _Impl &operator=(const auto &other) { this->_impl = other; }
    virtual ~_Impl() = default;

protected:
    T _impl;
};

template<typename T>
class _ImplRef {
public:
    _ImplRef(T &impl):
        _impl(impl)
    {
    }
    T &getImpl() { return this->_impl; }
    _ImplRef &operator=(const auto &&other) { this->_impl = std::move(other); }
    virtual ~_ImplRef() = default;

protected:
    T &_impl;
};

template<typename T>
class _ImplShared : public _Impl<std::shared_ptr<T>> {
public:
    _ImplShared(const std::shared_ptr<T> &impl = std::make_shared<T>()):
        _Impl<std::shared_ptr<T>>(impl)
    {
    }
    virtual ~_ImplShared() = default;

    std::shared_ptr<T> &getImpl() override { return this->_impl; }
};

} // namespace _details::configuration

#endif // CONFIGURATION_DETAILS_HPP
