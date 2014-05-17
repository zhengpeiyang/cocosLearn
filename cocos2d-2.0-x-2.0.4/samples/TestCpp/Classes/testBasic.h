#ifndef _TEST_BASIC_H_
#define _TEST_BASIC_H_

#include "cocos2d.h"
#include "VisibleRect.h"

USING_NS_CC;
using namespace std;

class TestScene : public CCScene
{
public: 
    TestScene(bool bPortrait = false);
    virtual void onEnter();//场景被加载时被调用的函数

    virtual void runThisTest() = 0;//自定义的虚函数，用于运行场景

    // The CallBack for back to the main menu scene
    virtual void MainMenuCallback(CCObject* pSender);//返回主界面的按钮回调函数
};

#endif
