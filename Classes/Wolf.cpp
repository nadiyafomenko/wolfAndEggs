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
    
    this->setTexture("wolff.png");
    
    basket = cocos2d::Sprite::create("basket.png");
    basket->setPosition(cocos2d::Vec2(165, 170));
    auto center = basket->getAnchorPoint();
    
    this->setAnchorPoint(center);
    this->setPosition(cocos2d::Vec2(visibleSize.width / 2, 150));
    this->setScale(1.4);
    

    basket->setRotation(20);
    basket->setScale(0.08);
    
     this->addChild(basket);
    
    this->scheduleUpdate();
    return true;
}

void Wolf::update(float delta)
{
    cocos2d::Vec2 position = this->getPosition();

    if (goRight) {
        this->setPosition(cocos2d::Vec2(position.x + 2, position.y));
        this->setFlippedX(false);
        basket->setPosition(cocos2d::Vec2(165, 170));
        basket->setRotation(20);
        basket->setFlippedX(false);
    }
    
    if (goLeft) {
        this->setPosition(cocos2d::Vec2(position.x - 2, position.y));
        this->setFlippedX(true);
        basket->setPosition(cocos2d::Vec2(75, 170));
        basket->setRotation(-20);
        basket->setFlippedX(true);
    }
    
}
