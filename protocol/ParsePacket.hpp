#ifndef A0501C0F_377F_42C5_9420_0833FCD13CFF
#define A0501C0F_377F_42C5_9420_0833FCD13CFF

#include <optional>
#include <memory>
#include <vector>
#include <functional>

namespace Protocol
{

    template <class H>
    class ParsePacket
    {
    private:
        std::vector<std::function<bool(std::vector<uint8_t>&, H&)>> _toParse;

    public:
        ParsePacket()
        {
        }

        template <typename T, typename F>
        ParsePacket<H> &prop(F func, T member)
        {
            _toParse.emplace_back([&](std::vector<uint8_t> &buffer, H &holder){
                auto &ref = std::invoke(member, holder);

                return func(buffer, ref);
            });
            return *this;
        }

        std::optional<std::shared_ptr<H>> parse(std::vector<uint8_t> &buf)
        {
            auto hold = std::make_shared<H>();

            for (const auto &i : _toParse)
                if (!i(buf, *hold))
                    return std::nullopt;
            return std::optional<H>{hold};
        }
    };

}

#endif /* A0501C0F_377F_42C5_9420_0833FCD13CFF */
