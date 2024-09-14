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
        sf::RectangleShape background;
        sf::Color background_color1;
        sf::Color background_color2;
        void prepareBackgroundRectangle();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    public:
        Button();
        Button(int width, int height);
        ~Button();
        void setString(const sf::String &string);
        void setPosition(int x, int y);
        void setDimensions();
        void setDimensions(int width, int height);
        std::array<int, 2> getDimensions() const;
        void setBackgrounds(const sf::Color b1, const sf::Color b2);
        void hover(int mouseX, int mouseY);
        bool checkOver(int mouseX, int mouseY) const;
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


class Game : public View{
    private:
        GameEngine ge;
        int window_width;
        int window_height;

        Label score_label;

        bool gameFlag = true;
        void drawAll() override;
    public:
        Game();
        Game(sf::RenderWindow *window);
        ~Game();
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

class Pause : public View{
    private:
        int window_width;
        int window_height;

        Label pause_label;
        Button resume_button;
        Button menu_button;
        Button exit_button;

        bool pauseFlag = true;
        void drawAll() override;
    public:
        Pause();
        Pause(sf::RenderWindow *window);
        ~Pause();
        int run() override;
};