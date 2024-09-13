class Label{
    protected:
        sf::Font font;
        sf::Text text;
        int getWidth() const;
        int getHeight() const;
    public:
        Label();
        Label(std::string font, std::string text);
        Label(std::string font, std::string text, int size);
        Label(std::string font, std::string text, int size, sf::Color color);
        ~Label();
        void setFont(std::string font);
        sf::Font getFont() const;
        void setText(std::string text);
        std::string getText() const;
        void setSize(int size);
        int getSize() const;
        void setColor(sf::Color color);
        sf::Color getColor() const;
        void setPosition(int x, int y);
        std::array<int, 2> getPosition() const;
        std::array<int, 2> getDimensions() const;
        void draw(sf::RenderWindow *window) const;
};


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

class Menu : public View{
    private:
        Label title_label;
        int window_width;
        int window_height;
        bool menuFlag = true;
        void drawAll() override;
        void clean_memory() override;
    public:
        Menu();
        Menu(int width, int height);
        ~Menu();
        void run() override;
};