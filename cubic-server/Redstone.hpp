#include "Player.hpp"
#include "TickClock.hpp"

namespace Redstone {
    namespace Activated {
        class Piston {
        public:
            Piston(bool ext, bool bud);
            ~Piston(void);

            virtual void extend(void);
            virtual void contract(void);

        private:
            bool _extended;
            bool _budded;
        };
    }

    namespace Activators {
        class Lever {
        public:
            enum Facing {
                Floor,
                Ceiling,
                North,
                South,
                West,
                East
            };
            enum Connection {
                CNorth,
                CSouth,
                CWest,
                CEast
            };

            Lever(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing);
            ~Lever(void);

            virtual void press(void);
            virtual void unpress(void);

            std::shared_ptr<Dimension> _dim;
            Vector3<double> _pos;
            Facing _facing;
            bool _powered;
        };

        class Button : Lever {
        public:
            Button(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing, bool isWooden);
            ~Button();

            virtual void press(void)   override;
            virtual void unpress(void) override;

            bool _duration;
            bool _isWooden;
            TickClock _clock;
        };
    }

    class RedstoneWire {
    public:
        RedstoneWire(uint8_t power, std::vector<bool> connected = {false, false, false, false});
        ~RedstoneWire(void);

        uint8_t _power;
        std::vector<bool> _connected;
    };
}