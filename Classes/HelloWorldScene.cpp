#include "HelloWorldScene.h"
#include "GameOverScene.hpp"
#include "Egg.hpp"
#include "Wolf.hpp"
#include <string>
#include "Life.hpp"

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

double HelloWorld::getLife()
{
    return this->life;
}

void HelloWorld::setLife(double life)
{
    this->life = life;
}

cocos2d::Sprite*  HelloWorld::createLifeSprite(cocos2d::Vec2 coordinates, std::string png)
{
    Sprite* heart = Sprite::create(png);
    heart->setScale(0.07);
    heart->setName("heart");
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

void HelloWorld::generateLifes(cocos2d::Scene* scene, int lifes, bool lastBroken) {
  
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
    
    auto gerb = Sprite::create("gerb.png");
    gerb->setPosition(900, 60);
    gerb->setScale(0.2);
    this->addChild(gerb);
    
    wolf =  Wolf::createWolf(this, right, left);
    
    this->schedule(SEL_SCHEDULE(&HelloWorld::generateEgg), 3);

    scoreLabel = Label::createWithTTF("Score: 0", "fonts/arial.ttf", 36);
    scoreLabel->setPosition(Vec2(120, 650));
    
    this->addChild(scoreLabel);
    
    for (int i = 0; i < 5; i++) {
        Life* lifeSptite = Life::createLife(this, cocos2d::Vec2(600 + i * 50, 650));
        lifesVector.push_back(lifeSptite);
    }
    
    this->scheduleUpdate();
    return true;
}


void HelloWorld::update(float delta)
{
    if (lifesVector.size() == 0) {
        Director::getInstance()->replaceScene(GameOverScene::createScene(counter));
        return;
    }
  
    if (life != lifePrev) {
        if (lifePrev - life == 1 && lifesVector.back()->getIsBroken()) {
            lifesVector.back()->removeFromParent();
            lifesVector.pop_back();
            lifesVector.back()->broke();
            lifePrev = life;
            return;
        }
        if (lifePrev - life == 1 && !lifesVector.back()->getIsBroken()) {
            lifesVector.back()->removeFromParent();
            lifesVector.pop_back();
            lifePrev = life;
            return;
        }
        if (lifePrev - life == 0.5 && !lifesVector.back()->getIsBroken()) {
            lifesVector.back()->broke();
            lifePrev = life;
            return;
        }
        if (lifePrev - life == 0.5 && lifesVector.back()->getIsBroken()) {
            lifesVector.back()->removeFromParent();
            lifesVector.pop_back();
            lifePrev = life;
            return;
        }
    }

    scoreLabel->setString("Score: " + std::to_string(counter));
    wolf->setGoLeft(left);
    wolf->setGoRight(right);
    wolf->setGoTop(top);
    wolf->setGoBottom(bottom);
}
