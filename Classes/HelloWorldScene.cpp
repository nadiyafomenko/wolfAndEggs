#include "HelloWorldScene.h"
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
    
    // wolf init
    wolf = Sprite::create("wolf.png");
    wolf->setPosition(Vec2(visibleSize.width/2, 150));
    wolf->setScale(1.4);
    
    this->addChild(background);
    this->addChild(wolf);
    
    this->scheduleUpdate();
    return true;
}


void HelloWorld::update(float delta)
{
    if (right) {
        wolf->setPosition(Vec2(wolf->getPosition().x + 2, wolf->getPosition().y));
        wolf->setFlippedX(false);
    }
    
    if (left) {
        wolf->setPosition(Vec2(wolf->getPosition().x - 2, wolf->getPosition().y));
        wolf->setFlippedX(true);
    }
    
}
