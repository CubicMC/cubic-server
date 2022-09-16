#ifndef A0501C0F_377F_42C5_9420_0833FCD13CFF
#define A0501C0F_377F_42C5_9420_0833FCD13CFF

#include <optional>
#include <memory>
#include <vector>
#include <functional>

namespace protocol
{

    template <class H>
    class ParsePacket
    {
    private:
        std::vector<std::function<bool(std::vector<uint8_t> &, H *)>> _toParse;

    public:
        ParsePacket()
        {
        }

        template <typename T>
        ParsePacket<H> &prop(std::function<bool(std::vector<uint8_t> &, T &)> func, int offset)
        {
            _toParse.emplace_back([func, offset](std::vector<uint8_t> &buffer, H *holder)
                                  {
                T *ref = (T *) (((char *)holder) + offset);
                return func(buffer, *ref); });
            return *this;
        }

        std::optional<std::shared_ptr<H>> parse(std::vector<uint8_t> &buf) const
        {
            std::shared_ptr<H> hold = std::make_shared<H>();

            for (const auto &i : _toParse)
                if (!i(buf, hold.get()))
                    return std::nullopt;
            return std::optional<std::shared_ptr<H>>(hold);
        }
    };
}

#endif /* A0501C0F_377F_42C5_9420_0833FCD13CFF */
