#include "HelloWorldScene.h"
#include "GameOverScene.hpp"
#include "Egg.hpp"
#include "Wolf.hpp"
#include <string>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    if((int)keyCode == 27) {
        wolf->setPosition(cocos2d::Vec2(visibleSize.width / 2 + 220, wolf->getPosition().y));
        right = true;
        left = false;
    }
    
    if((int)keyCode == 26) {
        wolf->setPosition(cocos2d::Vec2(visibleSize.width / 2 - 220, wolf->getPosition().y));
        left = true;
        right = false;
    }
    
    if((int)keyCode == 28) {
        wolf->setPosition(cocos2d::Vec2(wolf->getPosition().x, wolf->getPosition().y + 70));
        top = true;
        bottom = false;
    }
    
    if((int)keyCode == 29) {
        wolf->setPosition(cocos2d::Vec2(wolf->getPosition().x, wolf->getPosition().y - 70));
        bottom = true;
        top = false;
    }

}

void HelloWorld::generateEgg()
{
    Egg::createEgg(this, this->wolf);
}

int HelloWorld::getCounter()
{
    return this->counter;
}

void HelloWorld::setCounter(int count)
{
    this->counter = count;
}

int HelloWorld::getLife()
{
    return this->life;
}

void HelloWorld::setLife(int life)
{
    this->life = life;
}

cocos2d::Sprite*  HelloWorld::createLifeSprite(cocos2d::Vec2 coordinates)
{
    Sprite* heart = Sprite::create("heart.png");
    heart->setScale(0.07);
    heart->setPosition(coordinates);
    return heart;
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    if((int)keyCode == 27) {
        right = false;
    }
    
    if((int)keyCode == 26) {
        left = false;
    }
}


bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Vec2 center = Vec2(visibleSize.width/2, visibleSize.height/2);
    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    //background
    auto background = Sprite::create("bg.png");
    background->setPosition(center);
    
    this->addChild(background);
    
    wolf =  Wolf::createWolf(this, right, left);
    basket = wolf->getBasketRef();
    
    this->schedule(SEL_SCHEDULE(&HelloWorld::generateEgg), 3);

    scoreLabel = Label::createWithTTF("Score: 0", "fonts/arial.ttf", 36);
    scoreLabel->setPosition(Vec2(120, 650));
    
    this->addChild(scoreLabel);
    
    for (int i = 0; i < life; i++) {
        lifes[i] = createLifeSprite(Vec2(600 + i * 50, 650));
        this->addChild(lifes[i]);
    }
    
    this->scheduleUpdate();
    return true;
}


void HelloWorld::update(float delta)
{
    CCLOG("life %d", life);
  
    if (life == 0) {
        Director::getInstance()->replaceScene(GameOverScene::createScene(counter));
    }
    
    if (life > 0 && life < 5 && lifes[life] != NULL) {
        this->removeChild(lifes[life]);
    }
   
    scoreLabel->setString("Score: " + std::to_string(counter));
    wolf->setGoLeft(left);
    wolf->setGoRight(right);
    wolf->setGoTop(top);
    wolf->setGoBottom(bottom);
}
