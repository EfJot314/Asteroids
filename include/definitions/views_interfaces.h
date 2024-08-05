
class View{
    protected:
        int FPS;
        sf::RenderWindow* window;
        virtual void drawAll() {};
    public:
        virtual void run() {};
};



class Game : public View{
    private:
        GameEngine ge;
        int window_width;
        int window_height;
        bool gameFlag;
        void drawAll() override;
    public:
        Game();
        Game(int width, int height);
        ~Game();
        void run() override;
};