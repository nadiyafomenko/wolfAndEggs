#ifndef GameOverScene_hpp
#define GameOverScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class GameOverScene : public cocos2d::Scene
{
private:
    int score = 0;
    cocos2d::Label* scoreLabel;
    
public:
    static cocos2d::Scene* createScene(int counter);
    
    virtual bool init() override;

    virtual void update(float delta) override;
    
    void setScore(int counter);
    
    int getScore();
    
    CREATE_FUNC(GameOverScene);
};

#endif /* GameOverScene_hpp */
