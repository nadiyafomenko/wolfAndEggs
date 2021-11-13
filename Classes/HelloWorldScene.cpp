#include "HelloWorldScene.h"
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
        right = true;
    }
    
    if((int)keyCode == 26) {
        left = true;
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
    heart->setTag(2);
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

    auto visibleSize = Director::getInstance()->getVisibleSize();
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
   
    this->schedule(SEL_SCHEDULE(&HelloWorld::generateEgg), 2);

    scoreLabel = Label::createWithTTF("Score: 0", "fonts/arial.ttf", 36);
    scoreLabel->setPosition(Vec2(120, 650));
    
    this->addChild(scoreLabel);
    
    this->scheduleUpdate();
    return true;
}


void HelloWorld::update(float delta)
{
//    this->removeChildByTag(2);
//    CCLOG("life %d", life);
//    for (int i = 0; i <= life; i++) {
//        this->addChild(createLifeSprite(Vec2(600 + i * 50, 650)));
//    }
    scoreLabel->setString("Score: " + std::to_string(counter));
    wolf->setGoLeft(left);
    wolf->setGoRight(right);
}
