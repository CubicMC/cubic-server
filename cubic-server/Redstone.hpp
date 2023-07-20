namespace Redsone {
    class Lever {
    public:
        Lever(void);
        ~Lever(void);
        virtual void press(void);
    protected:
        bool _pressed;
    };

    class Button : Lever {
    public:
        Button(std::string material);
        ~Button();
    private:
        bool _duration;
    };
}