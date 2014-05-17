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

		CCMenuItemFont::setFontName("Thonburi");//设置菜单字体  
        CCMenuItemFont::setFontSize(25);//设置菜单字体大小  
  
        s = CCDirector::sharedDirector()->getWinSize();  
  
        std::string menuItemStr = "hurry"; 

  
       CCMenuItem *shuenjian = CCMenuItemFont::itemWithString(menuItemStr.c_str(),this,  
            menu_selector(HelloWorld::LJCallback)); //创建菜单项，并绑定触发函数..  
 
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
  
  
        CCMenu* pMenu = CCMenu::menuWithItems(shuenjian,chixu,bujian,genzong,jingdu,InitItem,NULL);//创建菜单  
        pMenu->alignItemsVertically();//设置菜单的显示为垂直列表  
        CC_BREAK_IF(! pMenu);  
        pMenu->setPosition(s.width/2+s.width/4, s.height/2);//设置菜单显示位置  
        this->addChild(pMenu, 1);//添加菜单进入  
  
        //初始化精灵  
        m_tamara = CCSprite::spriteWithFile("yg1.png");  
        m_tamara->retain();  
        addChild(m_tamara,1);  
        m_tamara->setPosition(CCPointMake(s.width/2, s.height/2));  
  
        //初始化背景图片,这里用的图片是960X360..也就是两个屏幕宽  
        CCSprite* bg = CCSprite::spriteWithFile("bg_24.png");  
        bg->setPosition(ccp(s.width/2 + s.width/2, s.height/2));  
        this->addChild(bg,-1);

        bRet = true;
    } while (0);

    return bRet;
}

//立即动画，不需要时间，直接完成  
void HelloWorld::LJCallback(CCObject* pSender)  
{  
    CCActionInstant* Action1 = CCPlace::actionWithPosition(ccp(100,100));  
    m_tamara->runAction(Action1);  
}  
 
//持续动画  
void HelloWorld::CXCallback(CCObject* pSender)  
{     
    //创建一个同时动作，同时移动和旋转  
    CCFiniteTimeAction* actionsGo = CCSpawn::actions(  
        CCMoveTo::actionWithDuration(1.0f,ccp(0,0)),  
        CCRotateBy::actionWithDuration(1.0f,360),NULL);  
  
    //创建一个同时动作，同时移动和旋转  
    CCFiniteTimeAction* actionsBack = CCSpawn::actions(  
        CCMoveTo::actionWithDuration(1.0f, CCPointMake(s.width/2,s.height/2)),  
       CCRotateBy::actionWithDuration( 2,  720),NULL);  
  
    //创建一个组合动作，执行完第一个动作后执行下一个  
    CCFiniteTimeAction* All = CCSequence::actions(actionsGo,actionsBack,NULL);  
  
    //使用动作包装把组合动作变成永久循环执行..需要转换成CCActionInterval *  
    m_tamara->runAction(CCRepeatForever::actionWithAction((CCActionInterval*)All));  
}  
 
//补间动画  
void HelloWorld::BJCallback(CCObject* pSender)  
{  
    CCActionInterval* actionTo = CCRotateBy::actionWithDuration(4.0f,360);  
    m_tamara->runAction(CCEaseBackOut::actionWithAction(actionTo));  
}  
  
//跟踪动画  
void HelloWorld::GZCallback(CCObject* pSender)  
{  
    CCActionInterval* Moveto = CCMoveBy::actionWithDuration(3.0f,CCPointMake(s.width*2+100, 0));  
    CCActionInterval* MoveBack = Moveto->reverse();  
    CCFiniteTimeAction* All = CCSequence::actions(Moveto,MoveBack,NULL);  
    CCAction* rep = CCRepeatForever::actionWithAction((CCActionInterval*)All);//包装动作为永久循环  
  
    m_tamara->runAction(rep);//执行rep动作  
    this->runAction(CCFollow::actionWithTarget(m_tamara,CCRectMake(0,0,s.width*2, s.height)));//执行跟踪动作  
}  
  
//进度动作  
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
 
//初始化精灵  
void HelloWorld::Initback(CCObject* pSender)  
{  
    m_tamara->stopAllActions();//停止所有动作  
    m_tamara->setRotation(0.0f);//设置旋转为0,即为没有旋转的状态  
    m_tamara->setPosition(ccp(s.width/2, s.height/2));//设置位置为中心  
}  
 
void HelloWorld::onExit()  
{  
    m_tamara->release();  
    CCLayer::onExit();  
} 






