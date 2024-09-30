
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