#ifndef MenuScene_hpp
#define MenuScene_hpp

#include <stdio.h>

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene
{
private:
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init() override;

    virtual void update(float delta) override;
    
    CREATE_FUNC(MenuScene);
};

#endif /* MenuScene_hpp */
