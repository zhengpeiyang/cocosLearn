#ifndef _BOX2D_VIEW_H_
#define _BOX2D_VIEW_H_

//#include "cocos2d.h"
#include "../testBasic.h"

class MenuLayer : public CCLayer
{
    int        m_entryID;//入口id

public:
    MenuLayer(void);//构造器
    virtual ~MenuLayer(void);//析构

    bool initWithEntryID(int entryId);//初始化

    void restartCallback(CCObject* sender);//重新开始的回调函数
    void nextCallback(CCObject* sender);//下一个测试的回调函数
    void backCallback(CCObject* sender);//上一个测试的回调函数

    virtual void registerWithTouchDispatcher();//注册触摸监听

    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//触摸的回调函数
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);

public:
    static MenuLayer* menuWithEntryID(int entryId);//初始化按钮
};
#endif
struct TestEntry;
class Test;
class Box2DView : public CCLayer
{
    TestEntry*    m_entry; //测试的结构体
    Test*        m_test;//碰撞监听器
    int            m_entryID;//入口id
public:
    Box2DView(void);//构造器
    virtual ~Box2DView(void);//析构

    bool initWithEntryID(int entryId);//初始化
    std::string title();
    void tick(float dt);//step
    void draw();//绘画方法

    virtual void registerWithTouchDispatcher();//触摸回调
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    //virtual void accelerometer(UIAccelerometer* accelerometer, CCAcceleration* acceleration);

    static Box2DView* viewWithEntryID(int entryId);//初始化层
};

class Box2dTestBedScene : public TestScene//测试床
{
public:
    virtual void runThisTest();
};


