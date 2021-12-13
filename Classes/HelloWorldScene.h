#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Wolf.hpp"
#include "Life.hpp"

class HelloWorld : public cocos2d::Scene
{
private:
    Wolf* wolf;
    cocos2d::Sprite* basket;
    cocos2d::Sprite* lifes[5];
    std::vector<Life*> lifesVector;
    
    cocos2d::Label* scoreLabel;
    cocos2d::Size visibleSize;
    
    int counter = 0;
    double life = 5.0;
    double lifePrev = 5.0;
    
    bool right = true;
    bool left = false;
    bool top = false;
    bool bottom = true;
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init() override;

    virtual void update(float delta) override;

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    
    cocos2d::Sprite* createLifeSprite(cocos2d::Vec2 coordinates, std::string png);
    
    int getCounter();
    
    void setCounter(int count);
    
    double getLife();
    
    void setLife(double life);
    
    void generateEgg();
    
    void generateLifes(cocos2d::Scene* scene, int lifes, bool lastBroken);
    
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
