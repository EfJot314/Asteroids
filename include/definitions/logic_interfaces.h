
class GameEngine{
    private:
        Player player;
        std::vector<Asteroid*> asteroids;
        std::vector<Bullet*> bullets;
        void asteroidExplosions();
        void checkAndRemoveAsteroids();
        void checkAndRemoveBullets();
    public:
        GameEngine();
        GameEngine(Player& player);
        ~GameEngine();
        void addPlayer(Player& player);
        Player& getPlayer();
        void moveAll();
        void checkCollisions();
        void drawAll();
        void addAsteroid(Asteroid *asteroid);
        void addBullet(Bullet *bullet);
};

class CollisionBody{
    private:
        float boundRadius = 0.0f;
        float rotation = 0.0f;
        std::array<float, 2> position;
        std::vector<std::array<float, 2>> points;
        float findBoundRadius() const;
        void updatePoints();
    public:
        CollisionBody();
        CollisionBody(std::array<float, 2>& position, std::vector<std::array<float, 2>>& points);
        ~CollisionBody();
        void setPosition(std::array<float, 2>& position);
        void setPoints(std::vector<std::array<float, 2>>& points);
        void addPoint(std::array<float, 2>& point);
        void rotate(float rotation);
        std::array<float, 2> getPosition() const;
        int getNoPoints() const;
        float getBoundRadius() const;
        std::vector<std::array<float, 2>> getPoints() const;
        bool checkCollision(CollisionBody* other) const;
};