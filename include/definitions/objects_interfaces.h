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

class CollisionBody{
    private:
        float boundRadius = 0.0f;
        float rotation = 0.0f;
        Vector2D position;
        std::vector<Vector2D> points;
        float findBoundRadius() const;
        bool checkIntersection(const std::array<Vector2D, 2>& AB, const std::array<Vector2D, 2>& CD) const;
        std::vector<std::array<Vector2D, 2>> getSectionsRel() const;
    public:
        CollisionBody();
        CollisionBody(Vector2D& position, std::vector<Vector2D>& points);
        ~CollisionBody();
        void setPosition(Vector2D position);
        void setPoints(std::vector<Vector2D>& points);
        void addPoint(Vector2D point);
        void rotate(float rotation);
        void updatePoints();
        Vector2D getPosition() const;
        int getNoPoints() const;
        float getBoundRadius() const;
        std::vector<Vector2D> getPoints() const;
        std::vector<std::array<Vector2D, 2>> getSectionsGlob() const;
        bool checkCollision(CollisionBody other);
};

class KinematicObject : public VisualObject{
    protected:
        CollisionBody body;
        int hp = 1;
        int points = 10;
        int damage = 1;
        Vector2D position;
        Vector2D velocity;
        void updatePositionOnWindow();
        void borderJump();
    public:
        Vector2D getPosition() const;
        Vector2D getVelocity() const;
        CollisionBody getBody() const;
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
        void randomPosition();
        void randomMovement(Vector2D velocity);
        void randomPlacement();
        void asteroidShapeFormation(int n, float r);
        virtual void shapeFormation() override;
    public:
        Asteroid();
        Asteroid(sf::RenderWindow* window, const sf::Color color);
        Asteroid(const Asteroid* const father, sf::RenderWindow* window, const sf::Color color);
        ~Asteroid();
        void updateKinematicProperties() override;
        virtual std::vector<Asteroid*> explode() const;
};


class BigAsteroid : public Asteroid{
    public:
        BigAsteroid();
        BigAsteroid(sf::RenderWindow* window, const sf::Color color);
        BigAsteroid(const Asteroid* const father, sf::RenderWindow* window, const sf::Color color);
        std::vector<Asteroid*> explode() const override;
};


class SmallAsteroid : public Asteroid{
    private:
        void shapeFormation() override;
    public:
        SmallAsteroid();
        SmallAsteroid(sf::RenderWindow* window, const sf::Color color);
        SmallAsteroid(const Asteroid* const father, sf::RenderWindow* window, const sf::Color color);
        std::vector<Asteroid*> explode() const override;
};


class Player : public KinematicObject{
    private:
        int score = 0;
        Hearts hearts;
        float hitTimer = playerUntouchableTime+1.0f;
        Vector2D acceleration;
        float rotation = 0;
        std::vector<FireObject> fire;
        void shapeFormation() override;
        void addNewFire(FireObject& fireObject);
        void checkAndRemoveFire();
        void drawFire();
    public:
        Player();
        Player(sf::RenderWindow* window, const sf::Color color);
        Player(Vector2D positon, Vector2D velocity, sf::RenderWindow* window, const sf::Color color);
        ~Player();
        bool detectCollisions(std::vector<Asteroid*>& asteroids);
        void accelerate(float acceleration);
        void rotate(direction_e direction);
        void updateKinematicProperties() override;
        void updateFireKinematicProperties();
        void draw() override;
        void createFire();
        Bullet* shoot();
        Vector2D getEnginePosition() const;
        Vector2D getVelocity() const;
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
        bool detectCollisions(std::vector<Asteroid*>& asteroids);
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
