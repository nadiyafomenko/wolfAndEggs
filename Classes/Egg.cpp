#include "Egg.hpp"
#include "Wolf.hpp"

Egg*  Egg::createEgg(HelloWorld* scene, Wolf* wolf)
{
    Egg* egg = Egg::create();
    egg->setWolfRef(wolf);
    egg->setSceneRef(scene);
    
    scene->addChild(egg);
    return egg;
}

void Egg::setWolfRef(Wolf* wolf)
{
    wolfRef = wolf;
}

void Egg::setSceneRef(HelloWorld* sceneRef)
{
    this->sceneRef = sceneRef;
}

bool Egg::init()
{
    if ( !Sprite::init() )
    {
        return false;
    }
    this->setTexture("egg1.png");
    this->setScale(1.2);
    
    if (this->eggPosition == 1) {
        this->setPosition(cocos2d::Vec2(-10, 530));
    }

    if (this->eggPosition == 2) {
        this->setPosition(cocos2d::Vec2(-10, 300));
    }
    
    if (this->eggPosition == 3) {
        this->setPosition(cocos2d::Vec2(970, 530));
    }
    
    if (this->eggPosition == 4) {
        this->setPosition(cocos2d::Vec2(970, 300));
    }
    
    if (this->eggPosition == 3 || this->eggPosition == 3) {
        this->runAction(cocos2d::RepeatForever::create(cocos2d::RotateBy::create(1.5f, -360)));
    } else {
        this->runAction(cocos2d::RepeatForever::create(cocos2d::RotateBy::create(1.5f, 360)));
    }
    
    
    this->scheduleUpdate();
    return true;
}

void Egg::update(float delta)
{
    cocos2d::Vec2 position = this->getPosition();
    
    if (position.y >= 60) {
        if (this->eggPosition == 1 || this->eggPosition == 2) {
            if (position.x >= 270) {
                this->setPosition(cocos2d::Vec2(position.x, position.y - 1));
            } else {
                this->setPosition(cocos2d::Vec2(position.x + 1, position.y - 0.3));
            }
        } else {
            if (position.x <= 690) {
                this->setPosition(cocos2d::Vec2(position.x, position.y - 1));
            } else {
                this->setPosition(cocos2d::Vec2(position.x - 1, position.y - 0.3));
            }
        }
        
    }

    
    if (position.y <= 60) {
        this->setTexture("egg2.png");
        sceneRef->setLife(sceneRef->getLife() - 1);
        this->stopAllActions();
    }

    if (wolfRef->getPosition().getDistance(position) < 110 && position.y > 150) {
        sceneRef->setCounter(sceneRef->getCounter() + 1);
        this->removeFromParent();
    }
}
