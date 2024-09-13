class Label : public sf::Text{
    private:
        sf::Font font;
    protected:
        int getWidth() const;
        int getHeight() const;
    public:
        void setFont(std::string font); 
        void setPosition(int x, int y);
        std::array<int, 2> getPosition() const;
        std::array<int, 2> getDimensions() const;
};


class Button : public Label{
    private:
        int width;
        int height;
        sf::Color background1;
        sf::Color background2;
    public:
        Button();
        Button(int width, int height);
        ~Button();
        void setString(const sf::String &string);
        void setPosition(int x, int y);
        void setDimensions();
        void setDimensions(int width, int height);
        std::array<int, 2> getDimensions() const;
        void setBackgrounds(sf::Color b1, sf::Color b2);
        bool checkOver(int mouseX, int mouseY);
};


class View{
    protected:
        const int FPS = 60;
        sf::RenderWindow *window;
        sf::Vector2i mousePosition;
        virtual void drawAll() {};
        virtual void clean_memory() {};
    public:
        virtual int run() {
            return 0;
        };
};


class Game : public View{
    private:
        GameEngine ge;
        int window_width;
        int window_height;
        bool gameFlag = true;
        void drawAll() override;
    public:
        Game();
        Game(sf::RenderWindow *window);
        ~Game();
        int run() override;
};

class Menu : public View{
    private:
        int window_width;
        int window_height;

        Label title_label;
        Button play_button;
        Button exit_button;

        bool menuFlag = true;
        void drawAll() override;
        void run_game();
        void clean_memory() override;
    public:
        Menu();
        Menu(int width, int height);
        ~Menu();
        int run() override;
};

class GameOver : public View{
    private:
        int window_width;
        int window_height;

        Label game_over_label;
        Button play_button;
        Button menu_button;
        Button exit_button;

        bool gameOverFlag = true;
        void drawAll() override;
    public:
        GameOver();
        GameOver(sf::RenderWindow *window);
        ~GameOver();
        int run() override;
};