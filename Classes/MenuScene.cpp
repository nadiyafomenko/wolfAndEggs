#include "MenuScene.hpp"
#include "HelloWorldScene.h"

#include <string>
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

bool MenuScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Vec2 center = Vec2(visibleSize.width/2, visibleSize.height/2);
    
    //background
    auto background = Sprite::create("bg.png");
    background->setPosition(center);
    background->setOpacity(70);
    
    this->addChild(background);
    
    auto header = Label::createWithTTF("Wolf and eggs", "fonts/arial.ttf", 90);
    header->setPosition(cocos2d::Vec2(visibleSize.width / 2, 500));
    
    auto button = cocos2d::ui::Button::create("play.png");
    button->setPosition(cocos2d::Vec2(visibleSize.width / 2, 200));
    button->setOpacity(1);
    button->setScale(0.3);
    
    auto zoomInAction = cocos2d::ScaleBy::create(0.5f, 1.3f);
    auto zoomOutAction = zoomInAction->reverse();
    
    auto repeatedAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(zoomInAction, zoomOutAction, NULL));
    cocos2d::Action* buttonAnimation = cocos2d::Sequence::create(cocos2d::DelayTime::create(0.5f), cocos2d::FadeIn::create(1.45f), NULL);
    
    button->runAction(buttonAnimation);
    button->runAction(repeatedAction);
    
    button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
            switch (type)
            {
                    case ui::Widget::TouchEventType::BEGAN:
                            break;
                    case ui::Widget::TouchEventType::ENDED:
                        {
                            Director::getInstance()->replaceScene(HelloWorld::createScene());
                            break;
                        }
                    default:
                            break;
            }
    });

    this->addChild(button);
    
    this->addChild(header);
    
    this->scheduleUpdate();
    return true;
}


void MenuScene::update(float delta)
{

}
