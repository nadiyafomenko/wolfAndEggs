#include "ui/CocosGUI.h"
#include "GameOverScene.hpp"
#include "MenuScene.hpp"
#include <stdio.h>
#include <string.h>

cocos2d::Scene* GameOverScene::createScene(int counter)
{
    auto scene = GameOverScene::create();
    scene->setScore(counter);
    return scene;
}

void GameOverScene::setScore(int counter)
{
    score = counter;
}

int GameOverScene::getScore() {
    return score;
}

bool GameOverScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
    
    cocos2d::Vec2 center = cocos2d::Vec2(visibleSize.width/2, visibleSize.height/2);
    
    //background
    auto background = cocos2d::Sprite::create("bg.png");
    background->setPosition(center);
    background->setOpacity(70);
    
    this->addChild(background);

    cocos2d::Action* zoomIN = cocos2d::ScaleBy::create(2.5f, 2.5f);
    background->runAction(zoomIN);
    
    auto chicken = cocos2d::Sprite::create("chicken.png");
    chicken->setPosition(cocos2d::Vec2(visibleSize.width / 2, 500));
    chicken->setScale(0.001);
    this->addChild(chicken);
    
    cocos2d::Action* chickenAnimation = cocos2d::Sequence::create(cocos2d::DelayTime::create(2), cocos2d::ScaleBy::create(0.2, 35), cocos2d::ScaleBy::create(0.6, 15), NULL);
    chicken->runAction(chickenAnimation);
    
   
    scoreLabel = cocos2d::Label::createWithTTF("", "fonts/arial.ttf", 36);
   
    scoreLabel->setPosition(cocos2d::Vec2(visibleSize.width / 2, 250));
    scoreLabel->setOpacity(1);
    this->addChild(scoreLabel);
    
    cocos2d::Action* scoreAnimation = cocos2d::Sequence::create(cocos2d::DelayTime::create(3), cocos2d::FadeIn::create(0.5), cocos2d::ScaleBy::create(0.2, 1.2), NULL);
    scoreLabel->runAction(scoreAnimation);
    
    auto button = cocos2d::ui::Button::create("restart.png");
    button->setPosition(cocos2d::Vec2(visibleSize.width / 2, 100));
    button->setOpacity(1);
    button->setScale(0.1);
    
    auto zoomInAction = cocos2d::ScaleBy::create(0.5f, 1.3f);
    auto zoomOutAction = zoomInAction->reverse();
    
    auto repeatedAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(zoomInAction, zoomOutAction, NULL));

    cocos2d::Action* buttonAnimation = cocos2d::Sequence::create(cocos2d::DelayTime::create(3.2f), cocos2d::FadeIn::create(1.5f), NULL);
    
    button->runAction(buttonAnimation);
    button->runAction(repeatedAction);
    
    this->addChild(button);
    
    button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
            switch (type)
            {
                case cocos2d::ui::Widget::TouchEventType::BEGAN:
                        break;
                case cocos2d::ui::Widget::TouchEventType::ENDED:
                    {
                        cocos2d::Director::getInstance()->replaceScene(MenuScene::createScene());
                        break;
                    }
                default:
                        break;
            }
    });
  
    this->scheduleUpdate();
    return true;
}


void GameOverScene::update(float delta)
{
    scoreLabel->setString("Your score: " + std::to_string(this->getScore()));
}
