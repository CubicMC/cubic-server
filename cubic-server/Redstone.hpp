namespace Redstone {
    namespace Activated {
        class Piston {
        public:
            Piston(bool ext, bool bud);
            ~Piston(void);

            virtual void push(void);
            virtual void retract(void);

        private:
            bool _extended;
            bool _budded;
        };
    }

    namespace Activators {
        class Lever {
        public:
            Lever(void);
            ~Lever(void);

            virtual void activate(void);
            virtual void deactivate(void);

            bool _powered;
        };

        class Button : Lever {
        public:
            Button(bool isWooden);
            ~Button();

            virtual void activate(void)   override;
            virtual void deactivate(void) override;

            bool _duration;
            bool _isWooden;
        };
    }

    class RedstoneCircuit {
    public:
        RedstoneCircuit(void);
        ~RedstoneCircuit(void);

        int power;
    };
}