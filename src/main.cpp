#include "../inc/obj.h"
using namespace sf;
using namespace std;

int main()
{
    list < Entity* > entities;

    point *P1 = new point(5, Vector2f(W/2, H/2), Vector2f(0,-100), Vector2f(0,0));
    entities.push_back(P1);

    point *P2 = new point(5, Vector2f(W/3, H/3), Vector2f(0,100), Vector2f(0,0));
    entities.push_back(P2);

    rope *R1 = new rope(*P1, *P2);
    entities.push_back(R1);

    RenderWindow app(VideoMode(W, H), "LOL");
    app.setFramerateLimit(60);

    Clock deltaClock;

    while(app.isOpen())
    {
        Time dt = deltaClock.restart();

        Event event;
        while(app.pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                    app.close();
                    break;


                default:
                    break;
            }
        }

        app.clear();
        for(auto e : entities){
            e->Update(dt.asSeconds());
            e->Draw(app);
        }
        app.display();
    }

    return 0;
}
