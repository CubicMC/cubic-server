#ifndef UTILITY_SHARED_FROM_THIS_HPP
#define UTILITY_SHARED_FROM_THIS_HPP

#include <memory>

namespace utility {

template<typename Base>
class SharedFromThis : public std::enable_shared_from_this<Base> {
public:
    template<typename T>
    std::shared_ptr<T> dynamicSharedFromThis()
    {
        return std::dynamic_pointer_cast<T>(this->shared_from_this());
    }

    template<typename T>
    std::shared_ptr<const T> dynamicSharedFromThis() const
    {
        return std::dynamic_pointer_cast<const T>(this->shared_from_this());
    }

    template<typename T>
    std::weak_ptr<T> dynamicWeakFromThis()
    {
        return std::dynamic_pointer_cast<T>(this->shared_from_this());
    }

    template<typename T>
    std::weak_ptr<const T> dynamicWeakFromThis() const
    {
        return std::dynamic_pointer_cast<const T>(this->shared_from_this());
    }
};

} // namespace utility

#endif // UTILITY_SHARED_FROM_THIS_HPP
