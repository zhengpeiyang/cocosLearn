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
    virtual void onEnter();//����������ʱ�����õĺ���

    virtual void runThisTest() = 0;//�Զ�����麯�����������г���

    // The CallBack for back to the main menu scene
    virtual void MainMenuCallback(CCObject* pSender);//����������İ�ť�ص�����
};

#endif
