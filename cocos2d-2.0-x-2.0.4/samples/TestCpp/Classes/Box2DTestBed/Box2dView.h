#ifndef _BOX2D_VIEW_H_
#define _BOX2D_VIEW_H_

//#include "cocos2d.h"
#include "../testBasic.h"

class MenuLayer : public CCLayer
{
    int        m_entryID;//���id

public:
    MenuLayer(void);//������
    virtual ~MenuLayer(void);//����

    bool initWithEntryID(int entryId);//��ʼ��

    void restartCallback(CCObject* sender);//���¿�ʼ�Ļص�����
    void nextCallback(CCObject* sender);//��һ�����ԵĻص�����
    void backCallback(CCObject* sender);//��һ�����ԵĻص�����

    virtual void registerWithTouchDispatcher();//ע�ᴥ������

    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);//�����Ļص�����
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);

public:
    static MenuLayer* menuWithEntryID(int entryId);//��ʼ����ť
};
#endif
struct TestEntry;
class Test;
class Box2DView : public CCLayer
{
    TestEntry*    m_entry; //���ԵĽṹ��
    Test*        m_test;//��ײ������
    int            m_entryID;//���id
public:
    Box2DView(void);//������
    virtual ~Box2DView(void);//����

    bool initWithEntryID(int entryId);//��ʼ��
    std::string title();
    void tick(float dt);//step
    void draw();//�滭����

    virtual void registerWithTouchDispatcher();//�����ص�
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    //virtual void accelerometer(UIAccelerometer* accelerometer, CCAcceleration* acceleration);

    static Box2DView* viewWithEntryID(int entryId);//��ʼ����
};

class Box2dTestBedScene : public TestScene//���Դ�
{
public:
    virtual void runThisTest();
};


