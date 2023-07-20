namespace Redsone {
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

            bool _activated;
        };

        class Button : Lever {
        public:
            Button(std::string material);
            ~Button();

            virtual void activate(void)   override;
            virtual void deactivate(void) override;

            bool _duration;
            std::string _material;
        };
    }
}