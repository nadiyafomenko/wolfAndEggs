#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Wolf.hpp"

class HelloWorld : public cocos2d::Scene
{
private:
    Wolf* wolf;
    cocos2d::Sprite* basket;
    cocos2d::Label* scoreLabel;
    
    int counter = 0;
    int life = 5;
    
    bool right = false;
    bool left = false;
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init() override;

    virtual void update(float delta) override;

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    
    cocos2d::Sprite* createLifeSprite(cocos2d::Vec2 coordinates);
    
    int getCounter();
    
    void setCounter(int count);
    
    int getLife();
    
    void setLife(int life);
    
    void generateEgg();
    
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
