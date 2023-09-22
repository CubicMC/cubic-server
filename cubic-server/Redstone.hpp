#include "Player.hpp"
#include "Dimension.hpp"
#include "TickClock.hpp"

namespace Redstone {
    class RedstoneItem {
    public:
        /**
        * @brief Enumeration of the 6 directions that a redstone item can be facing
        */
        enum Facing {
            Floor,
            Ceiling,
            North,
            South,
            West,
            East
        };

        /**
        * @brief Generic constructor for a redstone-related item
        *
        * @param dim The dimension in which the item is placed
        * @param pos The absolute position of the item in the dimension
        */
        RedstoneItem(std::shared_ptr<Dimension> dim, Position pos);
        ~RedstoneItem(void);

        std::shared_ptr<Dimension> _dim;
        Position _pos;
        std::vector<std::vector<int>> _connectedBlocks;
    };

    class RedstoneWire : RedstoneItem {
    public:
        /**
        * @brief Enumeration of the different directions that a redstone item can be connected to
        */
        enum Connection {
            CNorth,
            CSouth,
            CWest,
            CEast
        };

        /**
        * @brief Piston block constructor
        *
        * @param dim The dimension in which the piston is placed
        * @param pos The absolute position of the block in the dimension
        * @param power The power level of the wire (0 to 15)
        * @param connected A vector of 4 booleans, representing the connections of the wire to the blocks around it
        */
        RedstoneWire(std::shared_ptr<Dimension> dim, Position pos, uint8_t power, std::vector<bool> connected = {false, false, false, false});
        ~RedstoneWire(void);

        /**
        * @brief Feeding power to a specific block
        *
        * @param xOffset +1 or -1 for the x axis, if relevant depending on _facing
        * @param yOffset +1 or -1 for the y axis, if relevant depending on _facing
        * @param zOffset +1 or -1 for the z axis, if relevant depending on _facing
        * @param powerToFeed The amount of power to feed to the block
        */
        void feedPower(int xOffset, int yOffset, int zOffset, int powerToFeed);

        /**
        * @brief Overload of the previous function, a for each loop feeding power to all the _connectedBlocks
        */
        void feedPower(int powerToFeed);

        private:
            uint8_t _power;
            std::vector<bool> _connected;
    };

    namespace Activated {
        class Piston : RedstoneItem {
        public:
            /**
            * @brief Piston block constructor
            *
            * @param dim The dimension in which the piston is placed
            * @param pos The absolute position of the piston in the dimension
            * @param facing The direction that the piston is facing
            * @param ext Whether the piston is extended or not
            * @param bud Whether the piston is budded or not: "block update detector"
            */
            Piston(std::shared_ptr<Dimension> dim, Position pos, Facing facing, bool ext, bool bud);
            ~Piston(void);

            /**
            * @brief When a piston has no power any more, it retracts
            */
            virtual void retract(void);
            /**
             * @brief When a piston is powered, it extends
             */
            virtual void extend(void);

        private:
            Facing _facing;
            bool _extended;
            bool _budded;
        };
    }

    namespace Activators {
        class Lever : public Redstone::RedstoneItem {
        public:
            /**
            * @brief Lever (and lever-like) block constructor
            *
            * @param dim The dimension in which the lever is placed
            * @param pos The absolute position of the lever in the dimension
            * @param facing The direction that the lever is facing
            */
            Lever(std::shared_ptr<Dimension> dim, Position pos, Facing facing);
            ~Lever(void);

            /**
            * @brief Pressing the button, feeding maximum power to the connected blocks
            */
            virtual void press(void) {
                // TODO v awaiting BlockId::power();
                this->feedPower(true);
                this->_powered = true;
                // TODO make activation noise (591)
            }

            /**
            * @brief Unpressing the button, retracting power sources
            */
            virtual void unpress(void) {
                // TODO v awaiting BlockId::power();
                this->feedPower(false);
                this->_powered = false;
                // TODO make deactivation noise (591)
            }

            /**
            * @brief Feeding power to a specific block
            *
            * @param xOffset +1 or -1 for the x axis, if relevant depending on _facing
            * @param yOffset +1 or -1 for the y axis, if relevant depending on _facing
            * @param zOffset +1 or -1 for the z axis, if relevant depending on _facing
            * @param giving Whether the power is given or taken away from the lever (or lever-like) object
            */
            void feedPower(int xOffset, int yOffset, int zOffset, bool giving);

            /**
            * @brief Overload of the previous function, a for each loop feeding power to all the _connectedBlocks
            */
            void feedPower(bool giving);

            Facing _facing;
            bool _powered;
        };

        class Button : Lever {
        public:
            /**
            * @brief Button block constructor
            *
            * @param dim The dimension in which the button is placed
            * @param pos The absolute position of the button in the dimension
            * @param facing The direction that the button is facing
            * @param isWooden Whether the button is wooden or of some other material
            */
            Button(std::shared_ptr<Dimension> dim, Position pos, Facing facing, bool isWooden);
            ~Button();

            void press(void)   override;
            void unpress(void) override;

            bool _isWooden;
            int  _duration; // until automatic unpress
            TickClock _clock;
        };

        class PressurePlate : Lever {
        public:
            /**
            * @brief Pressure plate block constructor
            *
            * @param dim The dimension in which the plate is placed
            * @param pos The absolute position of the plate in the dimension
            * @param facing The direction that the plate is facing
            * @param isWooden Whether the plate is wooden or of some other material
            */
            PressurePlate(std::shared_ptr<Dimension> dim, Position pos, bool isWooden);
            ~PressurePlate();

            void press(void)   override;
            void unpress(void) override;

            bool _isWooden;
            int  _duration; // until automatic unpress after step off
            TickClock _clock;
        };
    }
}