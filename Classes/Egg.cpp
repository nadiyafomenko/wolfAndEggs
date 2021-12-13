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
    this->setTexture("egg-normal.png");
    this->setScale(0.15);
    
    if (this->eggPosition == 1) {
        this->setPosition(cocos2d::Vec2(-10, 540));
    }

    if (this->eggPosition == 2) {
        this->setPosition(cocos2d::Vec2(-10, 320));
    }
    
    if (this->eggPosition == 3) {
        this->setPosition(cocos2d::Vec2(970, 540));
    }
    
    if (this->eggPosition == 4) {
        this->setPosition(cocos2d::Vec2(970, 320));
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
    
    // egg move
    if (position.y >= 60) {
        if (this->eggPosition == 1 || this->eggPosition == 2) {
            if (position.x >= 290) {
                this->setPosition(cocos2d::Vec2(position.x, position.y - 1));
            } else {
                this->setPosition(cocos2d::Vec2(position.x + 1, position.y - 0.3));
            }
        } else {
            if (position.x <= 660) {
                this->setPosition(cocos2d::Vec2(position.x, position.y - 1));
            } else {
                this->setPosition(cocos2d::Vec2(position.x - 1, position.y - 0.3));
            }
        }
        
    }

    if (catched) {
        return;
    }
    
    // egg with position 1 or 3
    if (eggPosition == 1 || eggPosition == 3) {
        if (this->getPosition().y < 300) {
            halfCracked = true;
            this->setTexture("egg-cracked.png");
        }
        
        if (wolfRef->getPosition().getDistance(position) < 105 && wolfRef->isOnTop() && !halfCracked) {
            catched = true;
            sceneRef->setCounter(sceneRef->getCounter() + 2);
            this->removeFromParent();
            return;
        }
        
        if (wolfRef->getPosition().getDistance(position) < 60 && wolfRef->isOnBottom() && halfCracked) {
            catched = true;
            sceneRef->setLife(sceneRef->getLife() - 0.5);
            sceneRef->setCounter(sceneRef->getCounter() + 1);
            this->removeFromParent();
            return;
        }
    }

    
    // egg with position 2 or 4
    if (eggPosition == 2 || eggPosition == 4) {
        if (wolfRef->getPosition().getDistance(position) < 80 && position.y > 200 && wolfRef->isOnBottom()) {
            catched = true;
            sceneRef->setCounter(sceneRef->getCounter() + 2);
            this->removeFromParent();
        }
    }

  
    
    if (position.y <= 60 && !catched) {
        auto texture = this->getTexture();
        this->setTexture("egg2.png");
        sceneRef->setLife(sceneRef->getLife() - 1);
        this->stopAllActions();
        this->runAction(cocos2d::DelayTime::create(2));
        this->removeFromParentAndCleanup(true);
    }
    
}
