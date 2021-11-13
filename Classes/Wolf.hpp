#ifndef Wolf_hpp
#define Wolf_hpp

#include "cocos2d.h"

class Wolf : public cocos2d::Sprite
{
private:
    bool goRight;
    bool goLeft;
    
    cocos2d::Sprite* basket;
    cocos2d::Scene* mainSceneRef;
    
public:
    static Wolf* createWolf(cocos2d::Scene* scene, bool right, bool left);
    
    virtual bool init() override;

    virtual void update(float delta) override;
    
    void setGoRight(bool right);
    
    void setGoLeft(bool left);
    
    void setMainSceneRef(cocos2d::Scene* sceneRef);
    
    cocos2d::Sprite* getBasketRef();
    
    CREATE_FUNC(Wolf);
};


#endif /* Wolf_hpp */
