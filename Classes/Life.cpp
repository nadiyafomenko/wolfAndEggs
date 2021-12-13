#include "Life.hpp"

Life* Life::createLife(cocos2d::Scene* scene, cocos2d::Vec2 position)
{
    Life* life = Life::create();
    life->setPosition(position);
    scene->addChild(life);
    return life;
}

void Life::broke() {
    this->setTexture("heart-cracked.png");
    isBroken = true;
}

bool Life::getIsBroken() {
    return this->isBroken;
}


bool Life::init()
{
    if ( !Sprite::init() )
    {
        return false;
    }

    this->setScale(0.07);
    this->setPosition(heartPos);
    this->setTexture("heart.png");
    
    this->scheduleUpdate();
    return true;
}

void Life::update(float delta)
{

}
