#ifndef Egg_hpp
#define Egg_hpp

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "Wolf.hpp"

class Egg : public cocos2d::Sprite
{
private:
    Wolf* wolfRef;
    int eggPosition = rand() % 4 + 1;
    // int eggPosition = 2;
    bool catched = false;
    bool halfCracked = false;
    
    HelloWorld* sceneRef;
    
public:

    static Egg* createEgg(HelloWorld* scene, Wolf* wolf);
    
    void setWolfRef(Wolf* wolf);
    
    void setSceneRef(HelloWorld* sceneRef);
    
    virtual bool init() override;

    virtual void update(float delta) override;
    
    CREATE_FUNC(Egg);
};


#endif /* Egg_hpp */
