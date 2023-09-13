#include "Player.hpp"
#include "TickClock.hpp"

namespace Redstone {
    namespace Activated {
        enum Facing {
            Floor,
            Ceiling,
            North,
            South,
            West,
            East
        };

        class Piston {
        public:
            Piston(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing, bool ext, bool bud);
            ~Piston(void);

            virtual void extend(void);
            virtual void contract(void);

        private:
            std::shared_ptr<Dimension> _dim;
            Vector3<double> _pos;
            Facing _facing,
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

            virtual void press(void) {
                // TODO v awaiting BlockId::power();
                this->feedPower(true);
                this->_powered = true;
                // TODO make activation noise (591)
            }
            virtual void unpress(void) {
                // TODO v awaiting BlockId::power();
                this->feedPower(false);
                this->_powered = false;
                // TODO make deactivation noise (591)
            }
            void feedPower(int xOffset, int yOffset, int zOffset, bool giving);
            void feedPower(bool giving);

            std::shared_ptr<Dimension> _dim;
            Vector3<double> _pos;
            Facing _facing;
            std::vector<std::vector<int>> _connectedBlocks;
            bool _powered;
        };

        class Button : Lever {
        public:
            Button(std::shared_ptr<Dimension> dim, Vector3<double> pos, Facing facing, bool isWooden);
            ~Button();

            void press(void)   override;
            void unpress(void) override;

            int  _duration;
            bool _isWooden;
            TickClock _clock;
        };

        class PressurePlate : Lever {
        public:
            PressurePlate(std::shared_ptr<Dimension> dim, Vector3<double> pos, bool isWooden);
            ~PressurePlate();

            void press(void)   override;
            void unpress(void) override;

            int  _duration; // until step off
            bool _isWooden;
            TickClock _clock;
        };
    }

    class RedstoneWire {
    public:
        enum Connection {
            CNorth,
            CSouth,
            CWest,
            CEast
        };

        RedstoneWire(uint8_t power, std::vector<bool> connected = {false, false, false, false});
        ~RedstoneWire(void);

        void feedPower(int xOffset, int yOffset, int zOffset, int powerToFeed);
        void feedPower(int powerToFeed);

        std::shared_ptr<Dimension> _dim;
        Vector3<double> _pos;
        uint8_t _power;
        std::vector<std::vector<int>> _connectedBlocks;
        std::vector<bool> _connected;
    };
}