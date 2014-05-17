#include "HelloWorldScene.h"
//#include "Tools.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        CC_BREAK_IF(! CCLayer::init());

		CCMenuItemFont::setFontName("Thonburi");//���ò˵�����  
        CCMenuItemFont::setFontSize(25);//���ò˵������С  
  
        s = CCDirector::sharedDirector()->getWinSize();  
  
        std::string menuItemStr = "hurry"; 

  
       CCMenuItem *shuenjian = CCMenuItemFont::itemWithString(menuItemStr.c_str(),this,  
            menu_selector(HelloWorld::LJCallback)); //�����˵�����󶨴�������..  
 
        menuItemStr = "keepon";  
 
 
       CCMenuItem* chixu = CCMenuItemFont::itemWithString(menuItemStr.c_str(),this,  
            menu_selector(HelloWorld::CXCallback));  
 
        menuItemStr = "input";  
 
        CCMenuItem* bujian = CCMenuItemFont::itemWithString(menuItemStr.c_str(),this,  
            menu_selector(HelloWorld::BJCallback));  
  
        menuItemStr = "follow";  

        CCMenuItem* genzong = CCMenuItemFont::itemWithString(menuItemStr.c_str(),this,  
            menu_selector(HelloWorld::GZCallback));  
  
        menuItemStr = "progressTimer";  

        CCMenuItem* jingdu = CCMenuItemFont::itemWithString(menuItemStr.c_str(),this,  
            menu_selector(HelloWorld::JDCallback));  
  
        menuItemStr = "init";  

       CCMenuItem* InitItem = CCMenuItemFont::itemWithString(menuItemStr.c_str(),this,  
            menu_selector(HelloWorld::Initback));  
  
  
        CCMenu* pMenu = CCMenu::menuWithItems(shuenjian,chixu,bujian,genzong,jingdu,InitItem,NULL);//�����˵�  
        pMenu->alignItemsVertically();//���ò˵�����ʾΪ��ֱ�б�  
        CC_BREAK_IF(! pMenu);  
        pMenu->setPosition(s.width/2+s.width/4, s.height/2);//���ò˵���ʾλ��  
        this->addChild(pMenu, 1);//��Ӳ˵�����  
  
        //��ʼ������  
        m_tamara = CCSprite::spriteWithFile("yg1.png");  
        m_tamara->retain();  
        addChild(m_tamara,1);  
        m_tamara->setPosition(CCPointMake(s.width/2, s.height/2));  
  
        //��ʼ������ͼƬ,�����õ�ͼƬ��960X360..Ҳ����������Ļ��  
        CCSprite* bg = CCSprite::spriteWithFile("bg_24.png");  
        bg->setPosition(ccp(s.width/2 + s.width/2, s.height/2));  
        this->addChild(bg,-1);

        bRet = true;
    } while (0);

    return bRet;
}

//��������������Ҫʱ�䣬ֱ�����  
void HelloWorld::LJCallback(CCObject* pSender)  
{  
    CCActionInstant* Action1 = CCPlace::actionWithPosition(ccp(100,100));  
    m_tamara->runAction(Action1);  
}  
 
//��������  
void HelloWorld::CXCallback(CCObject* pSender)  
{     
    //����һ��ͬʱ������ͬʱ�ƶ�����ת  
    CCFiniteTimeAction* actionsGo = CCSpawn::actions(  
        CCMoveTo::actionWithDuration(1.0f,ccp(0,0)),  
        CCRotateBy::actionWithDuration(1.0f,360),NULL);  
  
    //����һ��ͬʱ������ͬʱ�ƶ�����ת  
    CCFiniteTimeAction* actionsBack = CCSpawn::actions(  
        CCMoveTo::actionWithDuration(1.0f, CCPointMake(s.width/2,s.height/2)),  
       CCRotateBy::actionWithDuration( 2,  720),NULL);  
  
    //����һ����϶�����ִ�����һ��������ִ����һ��  
    CCFiniteTimeAction* All = CCSequence::actions(actionsGo,actionsBack,NULL);  
  
    //ʹ�ö�����װ����϶����������ѭ��ִ��..��Ҫת����CCActionInterval *  
    m_tamara->runAction(CCRepeatForever::actionWithAction((CCActionInterval*)All));  
}  
 
//���䶯��  
void HelloWorld::BJCallback(CCObject* pSender)  
{  
    CCActionInterval* actionTo = CCRotateBy::actionWithDuration(4.0f,360);  
    m_tamara->runAction(CCEaseBackOut::actionWithAction(actionTo));  
}  
  
//���ٶ���  
void HelloWorld::GZCallback(CCObject* pSender)  
{  
    CCActionInterval* Moveto = CCMoveBy::actionWithDuration(3.0f,CCPointMake(s.width*2+100, 0));  
    CCActionInterval* MoveBack = Moveto->reverse();  
    CCFiniteTimeAction* All = CCSequence::actions(Moveto,MoveBack,NULL);  
    CCAction* rep = CCRepeatForever::actionWithAction((CCActionInterval*)All);//��װ����Ϊ����ѭ��  
  
    m_tamara->runAction(rep);//ִ��rep����  
    this->runAction(CCFollow::actionWithTarget(m_tamara,CCRectMake(0,0,s.width*2, s.height)));//ִ�и��ٶ���  
}  
  
//���ȶ���  
void HelloWorld::JDCallback(CCObject* pSender)  
{  
    CCProgressTo *to1 = CCProgressTo::actionWithDuration(2,100); 
	CCSprite *jl=CCSprite::spriteWithFile("jl.png");

    CCProgressTimer *left = CCProgressTimer::progressWithSprite(jl);  
    left->setType(kCCProgressTimerTypeBar);  
    addChild(left);  
    left->setPosition(CCPointMake(100,s.height/2));  
    left->runAction(CCRepeatForever::actionWithAction(to1));  
}  
 
//��ʼ������  
void HelloWorld::Initback(CCObject* pSender)  
{  
    m_tamara->stopAllActions();//ֹͣ���ж���  
    m_tamara->setRotation(0.0f);//������תΪ0,��Ϊû����ת��״̬  
    m_tamara->setPosition(ccp(s.width/2, s.height/2));//����λ��Ϊ����  
}  
 
void HelloWorld::onExit()  
{  
    m_tamara->release();  
    CCLayer::onExit();  
} 






