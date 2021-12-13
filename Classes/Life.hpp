#ifndef Life_hpp
#define Life_hpp

#include "cocos2d.h"
#include <stdio.h>

class Life : public cocos2d::Sprite
{
private:
    cocos2d::Scene* mainSceneRef;
    cocos2d::Vec2 heartPos;
    bool isBroken;
    
public:
    static Life* createLife(cocos2d::Scene* scene,  cocos2d::Vec2 position);
    
    virtual bool init() override;

    void generateLifes();
    
    virtual void update(float delta) override;

    void broke();
        
    bool getIsBroken();
    
    CREATE_FUNC(Life);
};

#endif /* Life_hpp */
