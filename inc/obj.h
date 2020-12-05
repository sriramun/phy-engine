#ifndef OBJ_H
#define OBJ_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <list>
using namespace sf;
using namespace std;

extern const long long MAXN;
extern const int W;
extern const int H;

class Entity
{
public:
    bool exist;
    Entity();
    virtual void Update(float dt);
    virtual void Draw(RenderWindow& app);
    virtual ~Entity();
};

class point : public Entity
{
public:
    Vertex vertex;

    Vector2f pos, vel, acc;
    float mass;

    point(float mass, Vector2f pos, Vector2f vel, Vector2f acc);
    void Update(float dt);
    void Draw(RenderWindow& app);
    ~point();
};

class rope : public Entity
{
public:
    point *P1, *P2;
    Vertex line[2];
    float ang, T, k, L0, L; // T = -kx

    rope(point& p1, point& p2);
    void Update(float dt);
    void Draw(RenderWindow& app);
    ~rope();
};

#endif
