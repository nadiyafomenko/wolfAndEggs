#include "Wolf.hpp"

Wolf* Wolf::createWolf(cocos2d::Scene* scene, bool right, bool left)
{
    Wolf* wolf = Wolf::create();
    wolf->setGoLeft(left);
    wolf->setGoRight(right);
    
    scene->addChild(wolf);
    return wolf;
}

void Wolf::setGoLeft(bool left)
{
    goLeft = left;
}

void Wolf::setGoRight(bool right)
{
    goRight = right;
}

void Wolf::setGoTop(bool top)
{
    goTop = top;
}

void Wolf::setGoBottom(bool bottom)
{
    goBottom = bottom;
}

bool Wolf::isOnBottom(){
    return goBottom;
}

bool Wolf::isOnTop(){
    return goTop;
}

void Wolf::setMainSceneRef(cocos2d::Scene* sceneRef)
{
    mainSceneRef = sceneRef;
}

cocos2d::Sprite* Wolf::getBasketRef()
{
    return basket;
}

bool Wolf::init()
{
    if ( !Sprite::init() )
    {
        return false;
    }
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    this->setTexture("wolf1.png");
   
    this->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 200, 150));
    this->setScale(0.7);
    
    this->scheduleUpdate();
    return true;
}

void Wolf::update(float delta)
{
    cocos2d::Vec2 position = this->getPosition();

    if (goRight) {
        this->setFlippedX(false);
        this->setAnchorPoint(cocos2d::Vec2(1, 0.5));
    }
    
    if (goLeft) {
        this->setFlippedX(true);
        this->setAnchorPoint(cocos2d::Vec2(0, 0.5));
    }
    
    if (goTop) {
        this->setTexture("wolf2.png");
        goBottom = false;
    }
    
    if (goBottom) {
        this->setTexture("wolf1.png");
        goTop = false;
    }
}
