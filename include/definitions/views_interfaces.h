
class View{
    protected:
        const int FPS = 60;
        sf::RenderWindow* window;
        virtual void drawAll() {};
        virtual void clean_memory() {};
    public:
        virtual void run() {};
};



class Game : public View{
    private:
        GameEngine ge;
        int window_width;
        int window_height;
        bool gameFlag = true;
        void drawAll() override;
        void clean_memory() override;
    public:
        Game();
        Game(int width, int height);
        ~Game();
        void run() override;
};