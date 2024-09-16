
class VisualObject{
    protected:
        int x;
        int y;
        sf::ConvexShape shape;
        sf::Color color;
        sf::RenderWindow* window;
        virtual void shapeFormation();
    public:
        virtual void draw();
};

class Heart : public VisualObject{
    private:
        void shapeFormation() override;
    public:
        Heart();
        Heart(sf::RenderWindow* window, const sf::Color color, int x, int y);
        ~Heart();
        void makeEmpty();
        void makeFilled();
};

class Hearts : public VisualObject{
    private:
        int n;
        std::vector<Heart> hearts;
        void shapeFormation() override;
    public:
        Hearts();
        Hearts(sf::RenderWindow* window, const sf::Color color, int n);
        Hearts(sf::RenderWindow* window, const sf::Color color, int n, int x, int y);
        ~Hearts();
        void draw() override;
        void setHealth(int hp);
};

class KinematicObject : public VisualObject{
    protected:
        int hp = 1;
        int points = 10;
        int damage = 1;
        float position[2];
        float velocity[2];
        float boundR = 0;
        void updatePositionOnWindow();
        void borderJump();
    public:
        std::array<float, 2> getPosition() const;
        float getBoundRadius() const;
        int getDamage() const;
        int getHp() const;
        bool isDead() const;
        virtual void updateKinematicProperties();
        void draw() override;
        bool hit(int dmg);
        int getPoints() const;
};



class Asteroid : public KinematicObject{
    protected:
        float rotation = 0;
        float rotationSpeed;
        void randomPlacement();
        void asteroidShapeFormation(int n, float r);
    public:
        Asteroid();
        Asteroid(sf::RenderWindow* window, const sf::Color color);
        Asteroid(float positon[], float velocity[], float rotationSpeed, sf::RenderWindow* window, const sf::Color color);
        ~Asteroid();
        void draw() override;
};


class BigAsteroid : public Asteroid{
    private:
        void shapeFormation() override;
    public:
        BigAsteroid();
        BigAsteroid(sf::RenderWindow* window, const sf::Color color);
};


class SmallAsteroid : public Asteroid{
    private:
        void shapeFormation() override;
    public:
        SmallAsteroid();
        SmallAsteroid(sf::RenderWindow* window, const sf::Color color);
};


class Player : public KinematicObject{
    private:
        int score = 0;
        Hearts hearts;
        float hitTimer = playerUntouchableTime+1.0f;
        float acceleration[2];
        float rotation = 0;
        std::vector<FireObject> fire;
        void shapeFormation() override;
        void addNewFire(FireObject& fireObject);
        void checkAndRemoveFire();
    public:
        Player();
        Player(sf::RenderWindow* window, const sf::Color color);
        Player(float positon[], float velocity[], sf::RenderWindow* window, const sf::Color color);
        ~Player();
        bool detectCollisions(std::vector<Asteroid>& asteroids);
        void accelerate(float acceleration);
        void rotate(direction_e direction);
        void updateKinematicProperties() override;
        void updateFireKinematicProperties();
        void draw() override;
        void drawFire();
        void createFire();
        Bullet& shoot();
        std::array<float, 2> getEnginePosition() const;
        std::array<float, 2> getVelocity() const;
        void updateFire(int FPS);
        void updateTimer(int FPS);
        void addToScore(int points);
        int getScore() const;
};



class Bullet : public KinematicObject{
    private:
        float distance = 0.0f;
        Player* player;
        void shapeFormation() override;
    public:
        Bullet();
        Bullet(Player* player, float rotation, sf::RenderWindow* window, const sf::Color color);
        ~Bullet();
        void updateKinematicProperties() override;
        bool detectCollisions(std::vector<Asteroid>& asteroids);
};



class FireObject : public KinematicObject{
    private:
        int durationCounter = 0;
        sf::Color fillingColor;
        Player* player;
        void shapeFormation() override;
    public:
        FireObject();
        FireObject(Player* player, float rotation, sf::RenderWindow* window, const sf::Color color1, const sf::Color color2);
        ~FireObject();
        bool incrementAndCheckDuration(int FPS);
};
