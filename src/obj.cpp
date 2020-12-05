#include "../inc/obj.h"
using namespace sf;
using namespace std;

const long long MAXN = 1000000;
const int W = 1200;
const int H = 800;

Entity::Entity(){
    this->exist = true;
}
void Entity::Update(float dt){

}
void Entity::Draw(RenderWindow& app){

}
Entity::~Entity(){

}

point::point(float mass, Vector2f pos, Vector2f vel, Vector2f acc){
    this->mass = mass;
    this->pos = pos;
    this->vel = vel;
    this->acc = acc;

    this->vertex.position = pos;
    this->vertex.color = Color::Red;
}
void point::Update(float dt){
    if(pos.y > H || pos.y < 0){
        pos.y = (pos.y > H) ? H : 0;
        vel.y *= (-0.9);
        if(abs(vel.y) < 2*(abs(acc.y * (dt)))) vel.y = 0;
    } else {
        vel.y += acc.y * (dt);
    }
    if(pos.x > W || pos.x < 0){
        pos.x = (pos.x > W) ? W : 0;
        vel.x *= (-0.9);
        if(abs(vel.x) < 2*(abs(acc.x * (dt)))) vel.x = 0;
    } else {
        vel.x += acc.x * (dt);
    }

    pos.x += vel.x * (dt);
    pos.y += vel.y * (dt);


    //make collision detection func

    vertex.position = pos;
}
void point::Draw(RenderWindow& app){
    app.draw(&vertex, 1, Points);
}
point::~point(){

}

rope::rope(point& p1, point& p2){
    P1 = &p1;
    P2 = &p2;
}
void rope::Update(float dt){
    line[0] = P1->vertex;
    line[1] = P2->vertex;
    ang = atan((P1->pos.y - P2->pos.y)/(P1->pos.x - P2->pos.x));
    cout << ang << endl;
}
void rope::Draw(RenderWindow& app){
    app.draw(line, 2, Lines);
}
rope::~rope(){

}
